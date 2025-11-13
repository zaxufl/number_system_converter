cmake_minimum_required(VERSION 3.19)
project(projekt LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core LinguistTools)

qt_standard_project_setup()

qt_add_executable(projekt
    main.cpp
    systemnumber.h systemnumber.cpp
)

qt_add_translations(
    TARGETS projekt
    TS_FILES projekt_pl_PL.ts
)

target_link_libraries(projekt
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS projekt
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

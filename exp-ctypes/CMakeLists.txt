cmake_minimum_required(VERSION 3.9)
project(mixedarray
    VERSION 1.0.1
    DESCRIPTION "example mixed type array"
    )

add_library(diffrec SHARED
    DiffRec.cpp
    )
set_target_properties(diffrec PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(diffrec PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
#install(TARGETS diffremylibc
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

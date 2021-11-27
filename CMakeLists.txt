cmake_minimum_required(VERSION 3.15)

project(testpkg VERSION 0.1 LANGUAGES CXX)


add_library(mymodule SHARED src/libmymodule/libheader.cpp)
target_include_directories(mymodule PUBLIC src/libmymodule)


set(PYBIND11_FINDPYTHON TRUE)
find_package(pybind11 CONFIG PATHS ${pybind11_SEARCH_PATH} REQUIRED)

pybind11_add_module(_pkg src/pkg/module.cpp)
set_target_properties(_pkg PROPERTIES CXX_STANDARD 17)
target_include_directories(_pkg PRIVATE ${pybind11_INCLUDE_DIRS})
target_link_libraries(_pkg PRIVATE mymodule)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_MACOSX_RPATH TRUE)
set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX})
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

install(TARGETS _pkg LIBRARY DESTINATION .)
install(TARGETS mymodule LIBRARY DESTINATION .)
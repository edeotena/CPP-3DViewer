cmake_minimum_required(VERSION 3.26)
project(3d_viewer_template)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(app
        src/main.cc
        src/view/MainWindow.cc
        src/view/MainWindow.h
        src/controller/VisualizationController.cc
        src/controller/VisualizationController.h
        src/model/ObjectModel.cc
        src/model/ObjectModel.h
        src/model/ParserModel.cc
        src/model/ParserModel.h
        src/model/AffineModel.h
        src/model/AffineModel.cc
        src/model/FacadeModel.h
        src/model/FacadeModel.cc
        src/model/utils.cc
        src/model/utils.h
        src/model/GnuPlotSingleton.cc
        src/model/GnuPlotSingleton.h
        src/model/RequestBuilder.cc
        src/model/RequestBuilder.h)

add_executable(test
        src/model/utils.cc
        src/model/utils.h
        src/model/FacadeModel.h
        src/model/FacadeModel.cc
        src/model/AffineModel.h
        src/model/AffineModel.cc
        src/model/ObjectModel.cc
        src/model/ObjectModel.h
        src/model/RequestBuilder.cc
        src/model/RequestBuilder.h
        src/model/GnuPlotSingleton.cc
        src/model/GnuPlotSingleton.h
        src/model/ParserModel.cc
        src/model/ParserModel.h
        src/tests/affine_suite.cc
        src/tests/tests_main.cc
        src/tests/file_parsing_suite.cc)

target_link_libraries(app ${GTKMM_LIBRARIES} boost_iostreams)
target_link_libraries(test gtest boost_iostreams)

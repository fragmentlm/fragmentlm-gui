cmake_minimum_required(VERSION 3.10)

project(fragmentlm-gui VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# nikgub: locate Qt5
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Sql)

file(GLOB_RECURSE API_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE PROJECT_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE QRCS "${CMAKE_CURRENT_SOURCE_DIR}/resources/*.qrc")
file(GLOB_RECURSE UIS "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui")

#nikgub: add main executable
set(ENTRY_POINT "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
add_executable(${PROJECT_NAME} ${ENTRY_POINT} ${UIS} ${API_HEADERS} ${PROJECT_HEADERS} ${PROJECT_SOURCES} ${QRCS})

target_include_directories(${PROJECT_NAME} PRIVATE "include")
target_include_directories(${PROJECT_NAME} PRIVATE "${Qt5Core_INCLUDE_DIRS}")
target_include_directories(${PROJECT_NAME} PRIVATE "${Qt5Widgets_INCLUDE_DIRS}")
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Widgets)

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()



cmake_minimum_required(VERSION 3.10.0)

project(FiztechSimulator LANGUAGES C CXX)

set(CMAKE_CXX_VERSION 17)

# find_package(SFML COMPONENTS graphics window system REQUIRED)



set(BASE_DIR "D:/cpplibs")

set(SFML_BASE_DIR "${BASE_DIR}/SFML-3.0.0")
set(SFML_INCLUDE_DIR "${SFML_BASE_DIR}/include")
set(SFML_LIBRARY_DIR "${SFML_BASE_DIR}/lib")

include_directories(${SFML_INCLUDE_DIR})

set(SOURCES main.cpp Intro.cpp)
set(HEADERS Tasks.h Character.h youdead.h Action.h Achieve.h Intro.h endofgame.h )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_directories(${PROJECT_NAME} PRIVATE ${SFML_LIBRARY_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)

configure_file(${CMAKE_SOURCE_DIR}/arial.ttf ${CMAKE_BINARY_DIR}/arial.ttf COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/background.png ${CMAKE_BINARY_DIR}/background.png COPYONLY)

include(CTest)
enable_testing()

cmake_minimum_required (VERSION 3.11)

set (CMAKE_CXX_COMPILER g++)
set (CMAKE_C_COMPILER gcc)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-Wall -pedantic -Wextra")

project (KMeansClustering)

enable_language (CXX)

set (SOURCE_FILES
	src/main.cpp
	src/Init.cpp
	src/KMeans.cpp
	src/ReadData.cpp
	src/WriteData.cpp
)

add_executable (KMeansClustering ${SOURCE_FILES})

target_include_directories (KMeansClustering PUBLIC include)

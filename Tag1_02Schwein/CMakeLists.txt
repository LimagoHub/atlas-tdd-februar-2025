cmake_minimum_required (VERSION 3.12)

project(SchweineProject)

set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)

enable_testing()

add_executable(
	SchweineProject 
	source/main.cpp
		source/tiere/Schwein.h
		source/services/Dependency.h
		source/services/DependencyImpl.h
		source/services/MyServiceUsingDependency.h
		source/services/UniqueDependency.h
		source/services/UniqueService.h
)


# Add tests
add_subdirectory(tests)


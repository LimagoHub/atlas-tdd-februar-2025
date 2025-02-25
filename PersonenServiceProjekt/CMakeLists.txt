cmake_minimum_required (VERSION 3.14)

project(PersonenServiceProjekt)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)


add_executable(
	PersonenServiceProjekt 
	source/main.cpp
		source/persistence/person.h source/persistence/personen_repository.h source/services/personen_service.h source/services/personen_service_exception.h source/services/personen_service_impl.h
		"../../../../../../../../Program Files/JetBrains/CLion 2024.1/bin/mingw/lib/gcc/x86_64-w64-mingw32/13.1.0/include/c++/bits/exception.h"
)


# Add tests
add_subdirectory(tests)


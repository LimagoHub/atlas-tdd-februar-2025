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
		source/services/BlackListService.h

)


# Add tests
add_subdirectory(tests)


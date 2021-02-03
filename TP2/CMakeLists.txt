cmake_minimum_required(VERSION 3.19)
project(IsoSurface)
find_package(VTK REQUIRED)

include_directories(".")

include(${VTK_USE_FILE})

file(GLOB SOURCES
	sources/*.hpp
	sources/*.cpp)

add_executable(IsoSurface
main.cpp ${SOURCES})	

set_target_properties(IsoSurface
	PROPERTIES
	COMPILE_FLAGS
	"-march=native -O3")

target_link_libraries(IsoSurface
	${VTK_LIBRARIES})

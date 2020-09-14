# CMakeList.txt : CMake project for keygen, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Include sub-projects.
add_subdirectory ("base")

add_subdirectory ("os")


# Add source to this project's executable.
add_executable (keygen "keygen.cpp" "keygen.h" "machineid.cpp" "machineid.h" 
	$<TARGET_OBJECTS:os>
    $<TARGET_OBJECTS:base>)

# TODO: Add tests and install targets if needed.

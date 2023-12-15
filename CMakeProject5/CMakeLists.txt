# CMakeList.txt : CMake project for CMakeProject5, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CMakeProject5 "CMakeProject5.c" "CMakeProject5.h")
target_link_executable (CMakeProject5 m)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject5 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

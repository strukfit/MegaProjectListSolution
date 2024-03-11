# CMakeList.txt : CMake project for UnitConverter, include source and define
# project specific logic here.
#

file(GLOB_RECURSE SOURCES "src/*.cpp"  "include/*.h")

if(WIN32)
    execute_process(COMMAND cmd /c echo %USERPROFILE% OUTPUT_VARIABLE USER_PROFILE)
    string(STRIP "${USER_PROFILE}" USER_PROFILE)
else()
    message(FATAL_ERROR "This script is designed for Windows only.")
endif()

set(VCPKG_TARGET_TRIPLET "x64-windows")
set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-4.0)

# Add source to this project's executable.
add_executable (UnitConverter "src/main.cpp" "include/main.h" "src/Window.cpp" "include/Window.h")

target_include_directories(UnitConverter PRIVATE "include")

target_link_libraries(UnitConverter PRIVATE PkgConfig::GTKMM)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/UnitConverter/css)
set(DESTINATION_DIR ${CMAKE_BINARY_DIR}/UnitConverter)
file(COPY ${SOURCE_DIR} DESTINATION ${DESTINATION_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET UnitConverter PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

cmake_minimum_required(VERSION 3.28)
Project(Game)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")


# Find SFML. Requires SFML to be installed.
# On Windows, you might need to set SFML_DIR to the cmake folder of your SFML installation.
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)



# Gather all source files from the src directory
file(GLOB SOURCES "src/*.cpp" "src/Managers/*.cpp" "src/Systems/*.cpp")

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Specify the include directories
target_include_directories(${PROJECT_NAME} PRIVATE includes includes/Systems includes/Managers)

# Link SFML to the executable
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

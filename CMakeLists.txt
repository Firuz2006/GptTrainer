cmake_minimum_required(VERSION 3.28)
project(GptTrainer)

set(CMAKE_CXX_STANDARD 17)

add_executable(GptTrainer main.cpp)

# Add subdirectories for libraries
add_subdirectory(GptTrainerFileReader)
add_subdirectory(GptTrainerApiCommunicator)
add_subdirectory(GptTrainerSettingsManager)

# Link libraries to the executable
target_link_libraries(GptTrainer
        PUBLIC
        GptTrainerSettingsManager  # Automatically includes nlohmann_json via SettingsManager
        GptTrainerApiCommunicator  # Link other libraries as needed
        GptTrainerFileReader
)

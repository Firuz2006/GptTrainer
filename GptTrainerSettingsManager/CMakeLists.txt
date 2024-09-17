cmake_minimum_required(VERSION 3.10)

project(GptTrainerSettingsManager)

add_library(GptTrainerSettingsManager STATIC
        SettingsManager.cpp
        Settings/Settings.cpp
        Settings/SettingsName.h
)

target_include_directories(GptTrainerSettingsManager PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Settings
)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(GptTrainerSettingsManager PUBLIC nlohmann_json::nlohmann_json)

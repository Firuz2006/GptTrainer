//
// Created by Firuz Isoboev on 9/13/2024.
//
#ifdef _WIN32
#include <windows.h>
#include <Lmcons.h>
#endif


#include "SettingsManager.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>


// Function to get application data path based on the OS
std::string GetAppDataPath() {
    std::string appDataPath;

#ifdef _WIN32
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    GetUserName(username, &username_len);
    const filesystem::path usersPath = "C:\\Users\\";
    filesystem::path roamingPath = usersPath / username / "Appdata" / "Roaming";
    appDataPath = roamingPath.string();
#elif __APPLE__
    const char* homeDir = std::getenv("HOME");
    if (homeDir != nullptr) {
        appDataPath = std::string(homeDir) + "/Library/Application Support";
    }
#else
    const char* homeDir = std::getenv("HOME");
    if (homeDir != nullptr) {
        appDataPath = std::string(homeDir) + "/.local/share";
    }
#endif

    return appDataPath;
}

void GptTrainerSettingsManager::SettingsManager::LoadSettings() {
    const filesystem::path appDataPath = GetAppDataPath();

    const filesystem::path settingsFile = appDataPath / "GptTrainer" / "settings.json";

    if (!exists(settingsFile)) {
        _settings = std::make_unique<Settings>();
    } else {
        std::string jsonContent;
        std::ifstream settingsStream(settingsFile);

        if (!settingsStream) {
            cerr << "Error opening settings file for reading" << endl;
            _settings = std::make_unique<Settings>();
            return;
        }

        std::string line;
        while (std::getline(settingsStream, line)) {
            jsonContent += line;
        }

        settingsStream.close();

        try {
            json jsonObject = json::parse(jsonContent);

            _settings = std::make_unique<Settings>(jsonObject.get<Settings>());
        } catch (json::parse_error &e) {
            cerr << "Error parsing settings file: " << e.what() << endl;
            _settings = std::make_unique<Settings>();
        }
    }
}

void GptTrainerSettingsManager::SettingsManager::SaveSettings() const {
    const filesystem::path appDataPath = GetAppDataPath();
    const filesystem::path settingsDirectory = appDataPath / "GptTrainer";

    if (!exists(settingsDirectory)) {
        create_directory(settingsDirectory);
    }

    const filesystem::path settingsFile = settingsDirectory / "settings.json";

    std::ofstream settingsStream(settingsFile);

    try {
        Settings *settings = _settings.get();
        json settingsJson = *settings;
        string jsonContent = settingsJson.dump(4);
        settingsStream << jsonContent;
        settingsStream.close();
    } catch (json::parse_error &e) {
        cerr << "Error parsing settings file: " << e.what() << endl;
    }
}

string GptTrainerSettingsManager::SettingsManager::GetValue(const SettingsName &settingName) const {
    switch (settingName) {
        case ApiKey:
            return _settings->ApiKey;
        default:
            cerr << "GetValue - Invalid setting: " << settingName << endl;
            return "";
    }
}

void GptTrainerSettingsManager::SettingsManager::SetValue(const SettingsName &settingName,
                                                          const string &settingValue) const {
    switch (settingName) {
        case ApiKey:
            _settings->ApiKey = settingValue;
            break;
        default:
            cerr << "SetValue - Invalid setting: " << settingName << endl;
    }
}

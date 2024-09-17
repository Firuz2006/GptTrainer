//
// Created by Firuz Isoboev on 9/13/2024.
//

#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include "Settings/Settings.h"
#include <memory>
#include <string>

#include "SettingsName.h"

using namespace GtpTrainerSettingsManager::Settings;

namespace GptTrainerSettingsManager {
    class SettingsManager {
    public:
        SettingsManager() = default;

        ~SettingsManager() = default;

        void LoadSettings();

        void SaveSettings() const;

        string GetValue(const SettingsName &settingName) const;

        void SetValue(const SettingsName &settingName, const string &settingValue) const;

    private:
        unique_ptr<Settings> _settings = nullptr; // Use smart pointer
    };
}

#endif // SETTINGSMANAGER_H

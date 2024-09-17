#include <iostream>

#include "GptTrainerSettingsManager/SettingsManager.h"

int main() {
    GptTrainerSettingsManager::SettingsManager settingsManager;
    settingsManager.LoadSettings();
    cout << settingsManager.GetValue(ApiKey);
    settingsManager.SetValue(ApiKey, settingsManager.GetValue(ApiKey)+" 1");
    settingsManager.SaveSettings();
    return 0;
}

//
// Created by Firuz Isoboev on 8/22/2024.
//

#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using namespace nlohmann;

namespace GtpTrainerSettingsManager::Settings {
    class Settings {
    public:
        string ApiKey;
    };

    void from_json(const json &j, Settings &s);

    void to_json(json &j, const Settings &s);
}

#endif //SETTINGS_H

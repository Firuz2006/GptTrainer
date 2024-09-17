//
// Created by Firuz Isoboev on 9/12/2024.
//

#include "Settings.h"
#include <nlohmann/json.hpp>

namespace GtpTrainerSettingsManager::Settings {
    void to_json(json &j, const Settings &s) {
        j["ApiKey"] = s.ApiKey;
    }

    void from_json(const json &j, Settings &s) {
        s.ApiKey = j.at("ApiKey").get<std::string>();
    }
}

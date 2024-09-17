//
// Created by Firuz Isoboev on 8/22/2024.
//

#include "GptFileReader.h"

#include <fstream>

namespace GptTrainerRileReader {
        vector<string> GptFileReader::ReadFile(const string fileName) {
            auto file = ifstream(fileName);
            return vector<string>(0);
    };
} // GptTrainerRileReader

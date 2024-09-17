//
// Created by Firuz Isoboev on 8/22/2024.
//

#ifndef GPTFILEREADER_H
#define GPTFILEREADER_H
#include <string>
#include <vector>
using namespace std;

namespace GptTrainerRileReader {
    class GptFileReader {
    public:
        vector<std::string> ReadFile(string filename);
    };
} // GptTrainerRileReader

#endif //GPTFILEREADER_H

//
// Created by maxhe on 11/22/2025.
//

#include "../include/Settings.h"

bool isSetTo(std::string line) {
    int delimeterPos = line.find_first_of("=");
    if (delimeterPos != std::string::npos) {
        std::string value = line.substr(delimeterPos + 1);
        if (value == "1")return true;

    }
    return false;

}

bool Settings::loadFromFile(const std::string& fileName) { // ok so we read in the file name, I assume we would have to use a helper function to parse in the full directory? hmm
    std::ifstream file(fileName);
    if (!file.is_open()) return false;

    // right so we open the file, check to see if its open return false, returning early otherwise we jump down and read line by line the settings
    std::string line;

    while (std::getline(file, line)) {
       if (line.find("fullscreen") != std::string::npos) {
           fullscreen = isSetTo(line);
       }
       if (line.find("vsync") != std::string::npos) {
           vsync = isSetTo(line);
       }
        if (line.find("showFPS") != std::string::npos) {
            showFPS = isSetTo(line);
        }
    }

    return true;
    

}

bool Settings::findLine(const std::string &searchString, std::string& fileName) {


}



bool Settings::saveToFile(const std::string& fileName) { // so we do the inverse of load
    std::ofstream file(fileName);
    if (!file.is_open()) return false;
    std::string line;
    /* I am hard coding this for now, need to see it work first, yeah I am aware technical debt aint good*/
    file << "fullscreen=" << fullscreen << std::endl;
    file << "vsync=" << vsync << std::endl;
    file << "showFPS=" << showFPS;
    file.close();//something will go wrong here




}
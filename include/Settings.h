//
// Created by maxhe on 11/22/2025.
//

#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H
#include <fstream>


class Settings {
public:
    bool fullscreen = false;
    bool vsync = false;
    bool showFPS = false;

    bool loadFromFile(const std::string& fileName);
    bool saveToFile(const std::string& fileName);

};



#endif //SETTINGSMENU_H

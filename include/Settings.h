//
// Created by maxhe on 11/22/2025.
//

#ifndef SETTING_H // so this name was changed
#define SETTING_H
#include <fstream>



class Settings { //ok I'm starting to remember now.  but why are those three bools already set to false?
public:
    bool fullscreen = false; //could make a settings struct
    bool vsync = false;
    bool showFPS = false;

    bool loadFromFile(const std::string& fileName);
    bool saveToFile(const std::string& fileName);

};


/*commented out because... why?*/
#endif //SETTINGSMENU_H

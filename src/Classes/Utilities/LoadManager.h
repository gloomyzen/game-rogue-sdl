/* Created by efreyu on 19.05.2020. */

#ifndef ROGUE_SDL_LOADMANAGER_H
#define ROGUE_SDL_LOADMANAGER_H

#include "JsonLoadManager.h"
//#include "../Scenes/Scenes.h"
//#include "../GameObjects/GameObject.h"
#include <map>

class LoadManager {
private:
    bool mLoaded;
    JsonLoadManager* pJsonManager;
//    std::map<std::string, Scene> mScenes;
//    std::map<std::string, GameObject> mGameObjects;

    void Parse() {
        //TODO recursive for loop for get all scenes and game objects
    }



public:
    explicit LoadManager(const char* &filePath) {
        mLoaded = false;
        pJsonManager->loadFile(filePath);
        if (pJsonManager->isLoaded()) {
            Parse();
        }
    }

    ~LoadManager() {
        mLoaded = false;
        delete pJsonManager;
    }

    bool isLoaded() const { return mLoaded; }

};


#endif //ROGUE_SDL_LOADMANAGER_H

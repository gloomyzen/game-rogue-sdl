/* Created by efreyu on 19.05.2020. */

#ifndef ROGUE_SDL_LOADMANAGER_H
#define ROGUE_SDL_LOADMANAGER_H

#include "JsonLoadManager.h"

class LoadManager {
private:
    bool mLoaded;
    JsonLoadManager* pJsonManager;

    void Parse() {
        //
    }

public:
    explicit LoadManager(const char* &filePath) {
        mLoaded = false;
        pJsonManager->loadFile(filePath);
        if (pJsonManager->isLoaded()) {
//            Parse();
        }
    }

    ~LoadManager() {
        mLoaded = false;
        delete pJsonManager;
    }

    bool isLoaded() const { return mLoaded; }

};


#endif //ROGUE_SDL_LOADMANAGER_H

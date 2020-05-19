/* Created by efreyu on 19.05.2020. */

#ifndef ROGUE_SDL_LOADMANAGER_H
#define ROGUE_SDL_LOADMANAGER_H


class LoadManager {
private:
    bool mLoaded;
public:
    LoadManager(const char* &filePath) {
        mLoaded = false;
    }

};


#endif //ROGUE_SDL_LOADMANAGER_H

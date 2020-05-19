/* Created by efreyu on 19.05.2020. */

#ifndef ROGUE_SDL_JSONLOADMANAGER_H
#define ROGUE_SDL_JSONLOADMANAGER_H

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <fstream>

/*
 * Expected logic: load resources.json -> load the desired level -> load the objects indicated in the level list (objects, tiles, items)
 */
class JsonLoadManager {
private:
    const char* mPath;
    bool mLoaded;
    rapidjson::Document mDocument;

public:
    JsonLoadManager() {
        mLoaded = false;
    };

    explicit JsonLoadManager(const char* &filePath);

    void loadFile(const char* &filePath);

    const char* getPath() { return mPath; }

    bool isLoaded() const { return mLoaded; }

    rapidjson::Document &getDocument() { return mDocument; }

};


#endif //ROGUE_SDL_JSONLOADMANAGER_H

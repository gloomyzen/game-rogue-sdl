/* Created by efreyu on 19.05.2020. */

#ifndef ROGUE_SDL_JSONLOADMANAGER_H
#define ROGUE_SDL_JSONLOADMANAGER_H

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <fstream>

class JsonLoadManager {
private:
    const char* mPath{};
    bool mLoaded = false;
    rapidjson::Document mDocument;

public:
    JsonLoadManager() = default;
    explicit JsonLoadManager(const char* filePath);;

    void loadFile(const char* filePath);

    const char* getPath() { return mPath; }

    [[nodiscard]] bool isLoaded() const { return mLoaded; }

    rapidjson::Document &getDocument() { return mDocument; }

};


#endif //ROGUE_SDL_JSONLOADMANAGER_H

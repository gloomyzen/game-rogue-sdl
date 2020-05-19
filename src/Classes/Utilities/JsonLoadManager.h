/* Created by efreyu on 19.05.2020. */

#ifndef ROGUE_SDL_JSONLOADMANAGER_H
#define ROGUE_SDL_JSONLOADMANAGER_H

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <fstream>

class JsonLoadManager {
private:
    const char* mPath;
    bool mLoaded = false;
    rapidjson::Document mDocument;

public:
    JsonLoadManager() {}
    JsonLoadManager(const char* filePath) : mPath(filePath) {
        loadFile(mPath);
    };
    void loadFile(const char* filePath) {
        mPath = filePath;
        std::ifstream ifs(mPath);
        rapidjson::IStreamWrapper isw(ifs);
        mDocument.ParseStream(isw);
        if (mDocument.HasParseError()) return;
        if (mDocument.GetType() != 0) mLoaded = true;
    }

    const char* getPath() {
        return mPath;
    }

    bool isLoaded() const { return mLoaded; }

    rapidjson::Document &getDocument() { return mDocument; }


};


#endif //ROGUE_SDL_JSONLOADMANAGER_H

/* Created by efreyu on 19.05.2020. */

#include "JsonLoadManager.h"

JsonLoadManager::JsonLoadManager(const char *filePath) : mPath(filePath) {
    loadFile(mPath);
}

void JsonLoadManager::loadFile(const char *filePath) {
    mPath = filePath;
    std::ifstream ifs(mPath);
    rapidjson::IStreamWrapper isw(ifs);
    mDocument.ParseStream(isw);
    if (mDocument.HasParseError()) return;
    if (mDocument.GetType() != 0) mLoaded = true;
}

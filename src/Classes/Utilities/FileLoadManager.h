/* Created by efreyu on 19.05.2020. */

#ifndef ROGUE_SDL_FILELOADMANAGER_H
#define ROGUE_SDL_FILELOADMANAGER_H


class FileLoadManager {
private:
    const char* path;

public:
    bool loadFile(const char* filePath) {
        path = filePath;
    }

    constexpr const char* getPath() {
        return path;
    }
};


#endif //ROGUE_SDL_FILELOADMANAGER_H

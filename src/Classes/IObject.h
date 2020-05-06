#ifndef ROGUE_SDL_IOBJECT_H
#define ROGUE_SDL_IOBJECT_H

class IObject {
private:
    bool isActive = false;

public:
    virtual void init()=0;
    virtual void update()=0;
    virtual void draw()=0;
    virtual void destroy()=0;

    bool getActive() { return isActive; };
    void setActive(bool active) { isActive = active; };
};

#endif //ROGUE_SDL_IOBJECT_H

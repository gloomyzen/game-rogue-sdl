![Linux build](https://github.com/gloomyzen/game-rogue-sdl/workflows/Linux%20build/badge.svg?branch=master)
![Webassembly build](https://github.com/gloomyzen/game-rogue-sdl/workflows/Webassembly%20build/badge.svg?branch=master)

##### My simple [Rogue-like game](https://en.wikipedia.org/wiki/Roguelike) in C++ compatible with WebAssembly using SDL2. This is a student project and does not claim to be the standard of Game development.

English | [Russian](https://github.com/gloomyzen/game-rogue-sdl/blob/master/README_RU.md)

[Click to play on web](https://gloomyzen.github.io/game-rogue-sdl/)

#### First of all, be sure to clone all submodules:
```bash
git clone --recurse-submodules git@github.com:gloomyzen/game-rogue-sdl.git game-rogue-sdl 
cd game-rogue-sdl
```

#### Usage (WebAssembly) :
Install emscripten, then
```bash
mkdir public
cd public
cmake -DBUILD_TYPE=webassembly ..
make -j$(nproc)
```

#### Usage (Linux) :

```bash
mkdir build
cd build
cmake ..
make -j$(nproc)
./main
```

#### Simple way to up and run local development (docker and bash required) :
```bash 
./game.sh -r
./game.sh -o ubuntu bash
build_in_container
```
Now, visit https://localhost:8080/.

The project uses external assets "[Rogue Dungeon Tileset 16x16](https://secrethideout.itch.io/rogue-dungeon-tileset-16x16)" to save the copyright of the author in the repository of these assets.
The author of the assets has done a great and outstanding work, it inspired me to create this project, so please read the author’s [official page](https://secrethideout.itch.io/rogue-dungeon-tileset-16x16)



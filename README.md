![Linux build](https://github.com/gloomyzen/game-rogue-sdl/workflows/Linux%20build/badge.svg?branch=master)
![Webassembly build](https://github.com/gloomyzen/game-rogue-sdl/workflows/Webassembly%20build/badge.svg?branch=master)

#### My simple rogue like game in C++ compatible with WebAssembly using SDL2.

[Play on web](https://gloomyzen.github.io/game-rogue-sdl/)

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



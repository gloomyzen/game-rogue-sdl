![Linux](https://github.com/gloomyzen/game-rogue-sdl/workflows/Linux/badge.svg?branch=master)

My simple rogue like game in C++ compatible with WebAssembly using SDL2.

[Play on web](https://gloomyzen.github.io/game-rogue-sdl/)

#####usage (WebAssembly) :
Install emscripten, then
```bash
mkdir public
cd public
cmake -DBUILD_TYPE=webassembly ..
make -j$(nproc)
```

#####usage (Linux) :

```bash
mkdir build
cd build
cmake ..
make -j$(nproc)
./main
```



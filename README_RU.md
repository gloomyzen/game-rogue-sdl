![Linux build](https://github.com/gloomyzen/game-rogue-sdl/workflows/Linux%20build/badge.svg?branch=master)
![Webassembly build](https://github.com/gloomyzen/game-rogue-sdl/workflows/Webassembly%20build/badge.svg?branch=master)

##### Простая игра в стиле [Rogue-like](https://ru.wikipedia.org/wiki/Roguelike), написанная на C++ и SDL2, совместимая с WebAssembly. Это учебный проект и не претендует на эталон геймдев разработки.

[English](https://github.com/gloomyzen/game-rogue-sdl/blob/master/README.md) | Russian

[Click to play on web](https://gloomyzen.github.io/game-rogue-sdl/)

#### В самом начале вам необходимо установить все гит модули
```bash
git clone --recurse-submodules git@github.com:gloomyzen/game-rogue-sdl.git game-rogue-sdl 
cd game-rogue-sdl
```

#### Сбора WebAssembly:
Для работы нужно установить компилятор emscripten
```bash
mkdir public
cd public
cmake -DBUILD_TYPE=webassembly ..
make -j$(nproc)
```

#### Сборка десктоп версии Linux/MacOs:

```bash
mkdir build
cd build
cmake ..
make -j$(nproc)
./main
```

В проекте используются внешние ассеты "[Rogue Dungeon Tileset 16x16](https://secrethideout.itch.io/rogue-dungeon-tileset-16x16)", для сохранения авторских прав автора в репозитории этих ассетов.
Автор ассетов проделал большую и выдающуюся работу, она вдохновила меня на создание данного проекта, по этому прошу ознакомиться с [официальной страничкой](https://secrethideout.itch.io/rogue-dungeon-tileset-16x16) автора.



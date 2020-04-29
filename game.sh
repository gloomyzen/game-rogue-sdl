#!/usr/bin/env bash
#/usr/bin/env bash

##Variables
if [ "${OS}" == "Windows_NT" ]; then
    OS_TYPE="windows";
    DOCKERCMD="winpty docker-compose.exe"
    DOCKERCORE="winpty docker.exe"
elif [ "${OSTYPE}" == "linux-gnu" ]; then
    OS_TYPE="linux";
    DOCKERCMD="docker-compose"
    DOCKERCORE="docker"
else
    OS_TYPE="macos";
    DOCKERCMD="docker-compose"
    DOCKERCORE="docker"
fi
## Constants
GREEN_OUTPUT='\033[0;32m'
RED_OUTPUT='\033[0;31m'
YELLOW_OUTPUT='\033[1;33m'
CLEAR_OUTPUT='\033[0m'
## Colored output
pc() {
    RES=""
    case "$1" in
        green)
            RES="${GREEN_OUTPUT}$2${CLEAR_OUTPUT}"
            ;;

        red)
            RES="${RED_OUTPUT}$2${CLEAR_OUTPUT}"
            ;;

        yellow)
            RES="${YELLOW_OUTPUT}$2${CLEAR_OUTPUT}"
            ;;

        *)
            RES="${CLEAR_OUTPUT}$2${CLEAR_OUTPUT}"
            ;;

    esac

    printf "${RES}"
}

fix_perm_data() {
    if [ "${OS_TYPE}" != "windows" ]; then
        if [ -d "$(pwd)/node_modules" ]; then own_commands ubuntu chmod -R 777 /var/www/node_modules; fi; \
    fi
}

own_commands() {
    eval ${DOCKERCORE} exec -it $1 $2 $3 $4 $5 $6 $7 $8
}

help_legend() {
    pc "green" "Usage: $0 {--build|--run|--down|--own|--test|--remove|--help} CMD\n"
}

general_help() {
    case "$1" in
        --build|-b|build|b)
            pc "green" "$0 --build "
            pc "none" "сбилдить все контейнеры, "
            pc "green" "$0 --build container-name "
            pc "none" "для сборки одного контейнера\n"
        ;;
        --run|-r|run|r)
            pc "green" "$0 --run "
            pc "none" "запустить все контейнеры, "
            pc "green" "$0 --run container-name "
            pc "none" "для запуска одного контейнера\n"
        ;;
        --down|-d|down|d)
            pc "green" "$0 --down "
            pc "none" "остановить все контейнеры, "
            pc "green" "$0 --down container-name "
            pc "none" "для остановки одного контейнера\n"
        ;;
        --own|-o|own|o)
            pc "green" "$0 --own container-name cmd"
            pc "none" "выполнить произвольную команду в контейнере\n"
        ;;
        --remove|remove)
            pc "green" "$0 --remove "
            pc "none" "Удалить все контейнеры внутри системы\n"
        ;;
        *)
            if [ $1 ]; then
                pc "yellow" "Command \"$1\" is not correct.\n"
            else
                pc "yellow" "Nothing caused.\n"
            fi
            $0 --help build
            $0 --help run
            $0 --help down
            $0 --help own
            $0 --help remove
            help_legend
            exit 1
    esac
}

run() {
    if [ "$1" == "build" ]; then
        eval ${DOCKERCMD} up -d --build $2 $3
    else
        eval ${DOCKERCMD} up -d $2 $3
    fi
    fix_perm_data
    ## Running tests
#    $0 -t
}

case "$1" in
    --build|-b)
        run 'build' $2 $3
        ;;
    --run|-r)
        run 'run' $2 $3
        ;;
    --down|-d)
        fix_perm_data
        eval ${DOCKERCMD} down
        ;;
    --own|-o)
        own_commands $2 $3 $4 $5 $6 $7 $8
        ;;
    --wasm-build)
        eval ${DOCKERCORE} exec -it ubuntu bash # cd /var/www && rm -rf public && mkdir public && cd public && source /etc/profile && cmake -DBUILD_TYPE=webassembly .. && make -j$(nproc)
        ;;
    --remove)
        eval ${DOCKERCORE} system prune -a
        ;;
    --test|-t)
        eval ${DOCKERCMD} exec php-cli php vendor/bin/phpunit
        ;;
    --help|-h)
        general_help $2 $3
        ;;
    *)
        pc "yellow" "Nothing caused.\n"
        help_legend
        exit 1

esac

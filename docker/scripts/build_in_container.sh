#!/usr/bin/env bash

##Variables
PROJECT_PATH=/var/www
BUILD_FOLDER=public

cd ${PROJECT_PATH} && rm -rf ${BUILD_FOLDER} && mkdir ${BUILD_FOLDER} && cd ${BUILD_FOLDER} && source /etc/profile && cmake -DBUILD_TYPE=webassembly .. && make -j$(nproc)
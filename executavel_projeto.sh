#!/bin/bash
## Script de build e execução
# ATENÇÂO: Esse script deve permanecer na raiz do projeto para que possa ser executado corretamente
PROJECT_NAME="Metodos-Numericos-I"
PROJECT_ROOT_PATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"

# Checagem para saber se o script se encontra na raiz do projeto
if [ "$PROJECT_NAME" != "$(basename $PROJECT_ROOT_PATH)" ]; then
    exit 1
fi

BUILD_DIR="build"
BUILD_PATH=$PROJECT_ROOT_PATH/$BUILD_DIR

# Checa se o diretório de build é presente
if [ ! -d "$BUILD_PATH" ]; then
    echo "Criando o diretório $BUILD_DIR"
    mkdir "$BUILD_PATH"
fi

# Entra no diretório de build, gera os arquivos de build, faz ação de build e faz a execução do programa 
(cd $BUILD_PATH &&
    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. &&
    cmake --build . &&
    "$BUILD_PATH/metodos"
)

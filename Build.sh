#!/bin/bash

./Insert.sh

emcc pikchr.c --target=wasm32-unknown-unknown -s ERROR_ON_UNDEFINED_SYMBOLS=0 -o pikchr.wasm -s STANDALONE_WASM=1 -s EXPORTED_FUNCTIONS=["_PikchrRender"] --no-entry

# for getting wat represntation.
wasm2wat pikchr.wasm -o pikchr.wat

./Patch.sh

wat2wasm pikchr_patched.wat -o pikchr.wasm

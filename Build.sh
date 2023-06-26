#!/bin/bash
emcc pikchr/pikchr.c -o pikchr.wasm -s EXPORTED_FUNCTIONS="_pikchr" --no-entry

# for getting wat represntation.
wasm2wat pikchr.wasm -o pikchr.wat

./Patch.sh

wat2wasm pikchrNoImp.wat -o pikchrNoImp.wasm
#!/bin/bash

./Insert.sh

emcc pikchr.c -o pikchr.wasm -s EXPORTED_FUNCTIONS=["_PikchrRender","_wasm_minimal_protocol_internal_function_get_storage_pointer","_wasm_minimal_protocol_internal_function_allocate_storage","_wasm_minimal_protocol_internal_function_get_storage_len"] --no-entry

# for getting wat represntation.
wasm2wat pikchr.wasm -o pikchr.wat

./Patch.sh

wat2wasm pikchrNoImp.wat -o pikchrNoImp.wasm


#for testing
cp pikchrNoImp.wasm ../TestGround/
cd ../TestGround
./testpik.sh

cd ../pkchr-wasm-typst
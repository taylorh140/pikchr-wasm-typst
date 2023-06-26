#!/bin/python3

#this replaces implicit functions with stubs.
#  (import "wasi_snapshot_preview1" "proc_exit" (func (;0;) (type 5)))
#  (import "wasi_snapshot_preview1" "fd_close" (func (;1;) (type 2)))
#  (import "wasi_snapshot_preview1" "fd_write" (func (;2;) (type 9)))
#  (import "wasi_snapshot_preview1" "fd_seek" (func (;3;) (type 30)))

# becomes

#  (func (;0;) (param i32) )
#  (func (;1;) (param i32) (result i32))
#  (func (;2;) (param i32 i32 i32 i32) (result i32))
#  (func (;3;) (param i32 i64 i32 i32) (result i32))


from pathlib import Path
import re

wat = Path('pikchr.wat').read_text()

types={}
for _ in re.findall(r"\s*\(type \(;(\d+);\) \(func ?(\(param ([^\)]+)\))? ?(\(result ([^\)]+)\))?\)\)",wat):
    types[_[0]]=(_[1],_[3],_[4])

for _ in re.findall(r"(\(import [^\(]+\(func \(;(\d+);\) \(type (\d+)\)\)\))",wat):

    rep=f"(func (;{_[1]};) {types[_[2]][0]} {types[_[2]][1]} {'' if types[_[2]][2]=='' else types[_[2]][2]+'.const 0 return '} )"

    if _[0] in wat:
        print("replacing:",_[0],"with",rep)
    wat=wat.replace(_[0],rep)

Path('pikchrNoImp.wat').write_text(wat)
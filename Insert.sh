#!/bin/python3

#this adds the additions to the pikchr.c file.
from pathlib import Path

source = Path('pikchr/pikchr.c').read_text()
extra = Path('src/additions.c').read_text()

source = source.replace("\n#endif\n", "\n#endif\n"+extra, 1)

Path('pikchr.c').write_text(source)
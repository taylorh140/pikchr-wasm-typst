= Purpose

Draw Pikchr diagrams in typst.

= Usage
make sure pikchr.wasm is somewhere accessable, and you can use the following:

```typst
#let pikchr-module = plugin("pikchr.wasm")

#let Pikchr(body)={
	image.decode(
	  str(pikchr-module.PikchrRender(bytes(body)))
	)
}

#Pikchr(`
box "Hello World!"
`.text)
```
Should produce:

<img src="https://github.com/taylorh140/pikchr-wasm-typst/assets/10996543/659c6511-9117-4496-a79b-41e4c49e646c" width="300">

= Build

tools
- linux/wsl
  - emcc (for compileing things.)
  - wabt (for manually hacking the assembly)
  - python (automate imp substitutions since i can't make emcc do it.)





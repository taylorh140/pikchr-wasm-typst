#include <stdint.h>

__attribute__((import_module("typst_env"))) extern void wasm_minimal_protocol_send_result_to_host(uint8_t const* ptr, size_t len);

__attribute__((import_module("typst_env"))) extern void wasm_minimal_protocol_write_args_to_buffer(uint8_t* ptr);

typedef struct {
    uint8_t* ptr;
    size_t cap;
    size_t len;
} RustString;


//Need the prototype for forward reference.
char *pikchr(
  const char *zText,     /* Input PIKCHR source text.  zero-terminated */
  const char *zClass,    /* Add class="%s" to <svg> markup */
  unsigned int mFlags,   /* Flags used to influence rendering behavior */
  int *pnWidth,          /* OUT: Write width of <svg> here, if not NULL */
  int *pnHeight          /* OUT: Write height here, if not NULL */
);

int PikchrRender(size_t len){

    //Convert input string

    char * inputbuffer = (char *)calloc( len+1 , sizeof(char)); //guarantee null byte ending

    wasm_minimal_protocol_write_args_to_buffer((uint8_t *)inputbuffer);
    inputbuffer[len] = 0;

    char * data = pikchr(inputbuffer,0,0,0,0);                            // call function

    free(inputbuffer);                                                    // I dont need the memory anymore

    wasm_minimal_protocol_send_result_to_host( (uint8_t*) data, strlen(data));

    free(data);
    return 0; // this indicates that everything is fine
}


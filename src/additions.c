typedef struct {
    uint8_t* ptr;
    size_t cap;
    size_t len;
} Vector;

static Vector __RESULT = { NULL, 0, 0 };

uint8_t* wasm_minimal_protocol_internal_function_get_storage_pointer() {
    return __RESULT.ptr;
}

void wasm_minimal_protocol_internal_function_allocate_storage(size_t length) {
    // Clear the existing storage
    free(__RESULT.ptr);
    
    // Allocate new storage
    __RESULT.ptr = (uint8_t*)malloc(length * sizeof(uint8_t));
    __RESULT.len = length;
    __RESULT.cap = length;
}

size_t wasm_minimal_protocol_internal_function_get_storage_len() {
    return __RESULT.cap;
}

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

void PikchrRender(RustString * Input){

    //Convert input string
    char * inputbuffer = (char *)calloc( __RESULT.len+1 , sizeof(uint8_t)); //guarentee null byte ending
    memcpy(inputbuffer,__RESULT.ptr,__RESULT.len);                            // copy all but the last byte

    char * data = pikchr(inputbuffer,0,0,0,0);                            // call function
    free(inputbuffer);                                                    // I dont need the memory anymore

    //data=inputbuffer;
    __RESULT.ptr=(char*)data;
    __RESULT.len=strlen(data); //get length of output string
    __RESULT.cap= __RESULT.len;                           

    // RustString * rtn = (RustString*)malloc(sizeof(RustString));           //get memory to send across barrier
    // rtn->cap=rtnlen+1;
    // rtn->len=rtnlen;
    // rtn->ptr=(uint8_t*)data; //same as a char pointer...

    // return rtn;
}


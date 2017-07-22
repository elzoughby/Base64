#include <stdio.h>
#include "base46.h"

int main() {

    printf( base64_encode("Have to deal with Base64 format? Then this module is made for you. Welcome!") );
    printf("\n");
    printf( base64_decode("SGF2ZSB0byBkZWFsIHdpdGggQmFzZTY0IGZvcm1hdD8gVGhlbiB0aGlzIG1vZHVsZSBpcyBtYWRlIGZvciB5b3UuIFdlbGNvbWUh") );

    return 0;
}

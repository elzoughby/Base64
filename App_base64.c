#include <stdio.h>
#include "base46.h"


void print_usage();


int main(int argc, char** argv) {

    if (argc == 1) {

        /* Have to deal with Base64 format? Welcome! */
        printf( base64_decode("SGF2ZSB0byBkZWFsIHdpdGggQmFzZTY0IGZvcm1hdD8gV2VsY29tZSE="));
        printf("\n");
        printf( base64_decode( base64_encode("www.linkedin.com/in/elzoughby")));
        printf("\n=========================================\n\n");
        print_usage();

    } else if (argc == 3) {

        

    } else {

        printf("Wrong Parameters! \n\n");
        print_usage();

    }
}


void print_usage() {
    printf("Usage: base64 [options] [arguments] \n\n"
                   "Options: \n\t"
                   "encode \t Convert ASCII string into Base64 format string \n\t"
                   "decode \t Convert Base64 format string into ASCII string \n"
                   "Arguments: \n\t"
                   "ASCII String \n\t"
                   "Base64 String \n\n"
    );
}
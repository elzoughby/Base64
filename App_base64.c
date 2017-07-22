#include <stdio.h>
#include "base46.h"


void print_usage();


int main(int argc, char** argv) {

    printf("argc = %d \n arg1 = %s \n arg2 = %s \n arg3 = %s \n", argc, argv[0], argv[1], argv[2]);

    if (argc == 1) {

        /* Have to deal with Base64 format? Welcome! */
        printf( base64_decode("SGF2ZSB0byBkZWFsIHdpdGggQmFzZTY0IGZvcm1hdD8gV2VsY29tZSE="));
        printf("\n");
        printf( base64_decode( base64_encode("www.linkedin.com/in/elzoughby")));
        printf("\n=========================================\n\n");
        print_usage();

    } else if (argc == 3) {

        if(argv[1] == (char*)"encode") {
            printf(base64_encode(argv[2]));
        } else if(argv[1] == (char*)"decode") {
            printf(base64_decode(argv[2]));
        } else {
            printf("Wrong Parameters! \n");
            print_usage();
        }

    } else {

        printf("Wrong Parameters! \n");
        print_usage();

    }

    return 0;
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
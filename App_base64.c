#include <stdio.h>
#include <stdbool.h>
#include "base64.h"


void usage();
void welcome();
void three_args(char* opt, char* src);
void four_args(char* opt, char* src, char* dest);
bool file_exists(char* path);
void args_error();


int main(int argc, char* argv[]) {

    if (argc == 1)
        welcome();
    else if (argc == 3)
        three_args(argv[1], argv[2]);
    else if (argc == 4)
        four_args(argv[1], argv[2], argv[3]);
    else
        args_error();

    return 0;
}


void welcome() {
    printf("===============================================================\n");
    printf( base64_decode("SGF2ZSB0byBkZWFsIHdpdGggQmFzZTY0IGZvcm1hdD8gV2VsY29tZSE="));
    printf("\n===============================================================\n\n");
    usage();
    printf("\n===============================================================\n");
    printf( base64_decode( base64_encode("www.linkedin.com/in/elzoughby")));
    printf("\n===============================================================\n");
}


void usage() {
    printf("Usage: base64 (encode | decode) <source> [<destination>] \n\n"
                   "Options: \n\t"
                   "encode \t\t\t Convert ASCII string into Base64 format \n\t"
                   "decode \t\t\t Convert Base64 format into ASCII string \n"
                   "Arguments: \n\t"
                   "source \t\t\t String or the path/to/file to be converted  \n\t"
                   "destination \t path/to/converted/file \n"
    );
}


void three_args(char* opt, char* src) {

    if(file_exists(src)) {
        FILE* file = fopen(src, "r");
        char* line = NULL;
        size_t len = 0;
        if(file == NULL)  exit(1);
        if(strcmp("encode", opt) == 0)
            while(getline(&line, &len, file) != -1)
                printf("%s\n", base64_encode(line));
        else if(strcmp("decode", opt) == 0)
            while(getline(&line, &len, file) != -1)
                printf("%s\n", base64_decode(line));
        else
            args_error();
        fclose(file);
        if(line) free(line);
    } else {
        if(strcmp("encode", opt) == 0)
            printf(base64_encode(src));
        else if(strcmp("decode", opt) == 0)
            printf(base64_decode(src));
        else
            args_error();
    }
}


void four_args(char *opt, char *src, char *dest) {
    FILE* dest_file = fopen(dest, "w");
    if(dest_file == NULL) exit(1);
    if(file_exists(src)) {
        FILE* src_file = fopen(src, "r");
        char* line = NULL;
        size_t len = 0;
        if(src_file == NULL)  exit(1);
        if(strcmp("encode", opt) == 0)
            while (getline(&line, &len, src_file) != -1)
                fprintf(dest_file, "%s\n" ,base64_encode(line));
        else if(strcmp("decode", opt) == 0)
            while (getline(&line, &len, src_file) != -1)
                fprintf(dest_file, "%s\n" ,base64_decode(line));
        else
            args_error();
        fclose(src_file);
        if(line) free(line);
    } else {
        if(strcmp("encode", opt) == 0)
            fprintf(dest_file, base64_encode(src));
        else if(strcmp("decode", opt) == 0)
            fprintf(dest_file ,base64_decode(src));
        else
            args_error();
    }
    fclose(dest_file);
}


bool file_exists(char* path) {
    bool result = false;
    FILE* file;
    if(file = fopen(path, "r")) {
        fclose(file);
        result = true;
    }
    return result;
}


void args_error() {
    printf("Wrong Parameters! \n");
    usage();
}
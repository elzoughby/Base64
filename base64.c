#include "base46.h"


char base46_map[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                     'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                     'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};


char* base64_encode(char* plain) {

    char counts = 0;
    char buffer[4];
    char* cipher = malloc(strlen(plain) * 4 / 3 + 4);
    int i = 0;
    int c = 0;

    while(plain[i] != '\0') {

        if(counts == 0) {
            buffer[0] = plain[i] >> 2;
            counts++;
        } else if(counts == 1) {
            buffer[1] = ((plain[i - 1] & 0x03) << 4) + (plain[i] >> 4);
            counts++;
        } else if(counts == 2) {
            buffer[2] = ((plain[i - 1] & 0x0f) << 2) + (plain[i] >> 6);
            buffer[3] = plain[i] & 0x3f;
            for(int j = 0; j < 4; j++) {
                cipher[c] = base46_map[buffer[j]];
                c++;
            }
            counts = 0;
        } else {
            //do nothing
        }

        i++;
    }

    if(counts > 0) {
        if (counts == 1) {
            buffer[1] = (plain[i - 1] & 0x03) << 4;
            buffer[2] = '\0';
            buffer[3] = '\0';
        } else if (counts == 2) {
            buffer[2] = ((plain[i - 1] & 0x0f) << 2);
            buffer[3] = '\0';
        }

        for (int j = 0; j < 4; j++) {
            if (buffer[j] != '\0')
                cipher[c] = base46_map[buffer[j]];
            else
                cipher[c] = '=';
            c++;
        }
    }

    return cipher;
}


char* base64_decode(char* cipher) {

    char* plain = malloc(strlen(cipher) * 3 / 4);
    char buffer[4];
    char counts = 0;
    int p = 0;

    for(int i = 0; cipher[i] != '\0'; i++) {

        int k;
        for(k = 0 ; k < 64 && base46_map[k] != cipher[i]; k++);
        buffer[counts++] = k;
        if(counts == 4) {

            plain[p++] = (buffer[0] << 2) + (buffer[1] >> 4);
            if(buffer[2] != 64)
                plain[p++] = (buffer[1] << 4) + (buffer[2] >> 2);
            if(buffer[3] != 64)
                plain[p++] = (buffer[2] << 6) + buffer[3];

            counts = 0;
        }
    }

    return plain;
}

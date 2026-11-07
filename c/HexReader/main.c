#include <stdio.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage: hexviewer %s \n", "<filename>");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }
    else{
        unsigned char buffer[16];
        size_t bytesRead;
        size_t offset = 0;

        while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            printf("%08zx  ", offset);
            for (size_t i = 0; i < bytesRead; i++) {
                printf("%02X ", buffer[i]);
            }
            for (size_t i = bytesRead; i < sizeof(buffer); i++) {
                printf("   ");
            }
            printf(" |");
            for (size_t i = 0; i < bytesRead; i++) {
                if (buffer[i] >= 32 && buffer[i] <= 126) {
                    printf("%c", buffer[i]);
                } else {
                    printf(".");
                }
            }
            printf("|\n");
            offset += bytesRead;
        }

        fclose(file);
    }




    return 0;
}
#include<stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[]) {

    if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
    }
    FILE *file = fopen(argv[1], "r");
    char line[512];
    char *keyword[] = {"failed","404","error","unauthorized","denied"};
    int line_number = 0;
    int alert_count = 0;

    if (file != NULL) {
        while (fgets(line, sizeof(line), file) != NULL) {
            line_number++;
            char linetolower[512];
            size_t line_length = strlen(line);

            for (size_t i = 0; i < line_length; i++) {
                linetolower[i] = (char)tolower((unsigned char)line[i]);
            }
            linetolower[line_length] = '\0';

            for (size_t i = 0; i < sizeof(keyword) / sizeof(keyword[0]); i++) {
                if (strstr(linetolower, keyword[i]) != NULL) {
                    alert_count++;
                    printf("Line %d: %s \n", line_number, line);
                    break;
                }
            }
        }

        fclose(file);
    } else {
        printf("Failed to open the file.\n");
    }

    printf("Total alerts found: %d\n", alert_count);
    return 0;
}

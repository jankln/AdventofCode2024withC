#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int extrahiere_mul(const char *text) {
    int summe = 0;
    const char *start = text;
    while ((start = strstr(start, "mul(")) != NULL) {
        const char *ende = strchr(start, ')');
        if (ende) {
            char inhalt[100];
            strncpy(inhalt, start + 4, ende - start - 4);
            inhalt[ende - start - 4] = '\0';
            char *trennung = strchr(inhalt, ',');
            if (trennung) {
                *trennung = '\0';
                const char *x_text = inhalt, *y_text = trennung + 1;
                if (strspn(x_text, "0123456789") == strlen(x_text) &&
                    strspn(y_text, "0123456789") == strlen(y_text)) {
                    summe += atoi(x_text) * atoi(y_text);
                }
            }
        }
        start++;
    }
    return summe;
}

int main() {
    char speicher[100000];
    FILE *datei = fopen("speicher.txt", "r");
    if (!datei) return 1;
    fread(speicher, sizeof(char), 100000, datei);
    fclose(datei);
    printf("%d\n", extrahiere_mul(speicher));
    return 0;
}

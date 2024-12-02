#include <stdio.h>
#include <stdlib.h>

// heufigkeit
int zaehleHaeufigkeit(int Liste[], int size, int wert) {
    int zaehler = 0;
    for (int i = 0; i < size; i++) {
        if (Liste[i] == wert) {
            zaehler++;
        }
    }
    return zaehler;
}

// aehnlichkeitswert
int berechneAehnlichkeitswert(int Liste1[], int Liste2[], int size1, int size2) {
    int aehnlichkeitswert = 0;

    for (int i = 0; i < size1; i++) {
        int wert = Liste1[i];
        int haeufigkeit = zaehleHaeufigkeit(Liste2, size2, wert);
        aehnlichkeitswert += wert * haeufigkeit;
    }

    return aehnlichkeitswert;
}

int main() {
    FILE *file = fopen("../Day1/listen.txt", "r");

    int Liste1[1000], Liste2[1000];
    int size1 = 0, size2 = 0;

    while (fscanf(file, "%d %d", &Liste1[size1], &Liste2[size2]) == 2) {
        size1++;
        size2++;
    }

    fclose(file);

    int aehnlichkeitswert = berechneAehnlichkeitswert(Liste1, Liste2, size1, size2);
    printf("Der Aehnlichkeitswert ist: %d\n", aehnlichkeitswert);

    return 0;
}

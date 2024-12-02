#include <stdio.h>
#include <stdlib.h>

//  tsauschen von zwei Elementen
void tausche(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort
void sortiere(int Liste[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (Liste[j] > Liste[j + 1]) {
                tausche(&Liste[j], &Liste[j + 1]);
            }
        }
    }
}

int getGesamtabstand(int Liste1[], int Liste2[], int size) {
    sortiere(Liste1, size);
    sortiere(Liste2, size);

    int gesamtabstand = 0;
    for (int i = 0; i < size; i++) {
        gesamtabstand += abs(Liste1[i] - Liste2[i]);
    }
    return gesamtabstand;
}

int main() {
    //txt read
    FILE *file = fopen("listen.txt", "r");

    int Liste1[1000], Liste2[1000];
    int size = 0;

    while (fscanf(file, "%d %d", &Liste1[size], &Liste2[size]) == 2) {
        size++;
    }

    fclose(file);

    int gesamtabstand = getGesamtabstand(Liste1, Liste2, size);
    printf("Der Gesamtabstand ist: %d\n", gesamtabstand);

    return 0;
}

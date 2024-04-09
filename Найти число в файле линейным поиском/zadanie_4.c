#include <stdio.h>

int NumberF(const char *filename, int number) {
    FILE *fh = fopen(filename, "r");
    int x;

    if (fh == NULL) {
        printf("Ошибка\n");
        return -1; 
    }

    int index = 0;
    while (fscanf(fh, "%d", &x) != EOF) {
        if (x == number) {
            fclose(fh);
            return index; 
        }
        index++;
    }

    fclose(fh);
    return -1;
}

int main() {
    const char *filename = "1.dat";
    int n = 7; // Число которое нужно найти

    int index = NumberF(filename, n);

    if (index != -1) {
        printf("Число %d найдено в файле с индексом %d\n", n, index);
    } else {
        printf("Число %d не найдено в файле\n", n);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void NumberF(const char *filename, long count) {
    FILE *fh = fopen(filename, "wb+");
    if (fh == NULL) {
        printf("Ошибка\n");
        return;
    }

    for (long i = 1; i <= count; i++)
        fwrite(&i, sizeof(long), 1, fh);

    fclose(fh);
}

int binaryS(const char *filename, long count, long num) {
    FILE *fh = fopen(filename, "rb");
    if (fh == NULL) {
        printf("Ошибкa\n");
        return -1;
    }

    long left = 0;
    long right = count - 1;
    long mid;
    long x;

    while (left <= right) {
        mid = left + (right - left) / 2;
        fseek(fh, mid * sizeof(long), SEEK_SET);
        fread(&x, sizeof(long), 1, fh);

        if (x == num) {
            fclose(fh);
            return mid; 
        } else if (x < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    fclose(fh);
    return -1; 
}

int main() {
    const char *filename = "sor_n.dat";
    long count = 10; // Количество чисел для записи в файл
    long n = 7; // Число которое нужно найти

    NumberF(filename, count);
    int index = binaryS(filename, count, n);

    if (index != -1) {
        printf("Число %ld найдено в файле с индексом %d\n", n, index);
    } else {
        printf("Число %ld не найдено в файле\n", n);
    }

    return 0;
}

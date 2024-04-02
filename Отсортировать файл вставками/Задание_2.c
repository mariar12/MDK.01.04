#include <stdio.h>

int main() {
    FILE *fh = fopen("1.dat", "wb+");
    int x = 0;
    long i, j;
    long isize = sizeof(int);
    long fsize;

    for (i = 1; i <= 10; i++)
        fwrite(&i, isize, 1, fh);

    fseek(fh, 0, SEEK_END);
    fsize = ftell(fh) / sizeof(int);

    fseek(fh, 0, SEEK_SET);
    for (i = 0; i < fsize; i++) {
        fread(&x, isize, 1, fh);
        printf("%d ", x);
    }
    putchar('\n');

    fseek(fh, 0, SEEK_SET);
    for (i = 0; i < fsize; i++) {
        fseek(fh, isize * i, SEEK_SET);
        fread(&x, isize, 1, fh);
        if (x % 2 != 0) {
            x = -x;
            fseek(fh, isize * i, SEEK_SET);
            fwrite(&x, isize, 1, fh);
        }
        fseek(fh, 0, SEEK_SET); 
        
        for (j = i; j > 0; j--) {
            int prev, current;
            fseek(fh, isize * (j - 1), SEEK_SET);
            fread(&prev, isize, 1, fh);
            fseek(fh, isize * j, SEEK_SET);
            fread(&current, isize, 1, fh);
            if (prev > current) {
                fseek(fh, isize * (j - 1), SEEK_SET);
                fwrite(&current, isize, 1, fh);
                fseek(fh, isize * j, SEEK_SET);
                fwrite(&prev, isize, 1, fh);
            }
        }
    }

    fseek(fh, 0, SEEK_SET);
    for (i = 0; i < fsize; i++) {
        fread(&x, isize, 1, fh);
        printf("%d ", x);
    }
    putchar('\n');

    fclose(fh);
    return 0;
}
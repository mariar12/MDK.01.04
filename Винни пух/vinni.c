#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A 100

struct Trip {
    char loc[A];
    char vod[A];
    char car[A];
    char tim[A];
};

int main() {
    FILE *input_file = fopen("in.txt", "r");
    FILE *output_file = fopen("out.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Ошибка\n");
        return 1;
    }

    char l[A];
    struct Trip trips[100]; 
    int num_t = 0;

    while (fgets(l, A, input_file) != NULL) {
        sscanf(l, "%s %s %s %s", trips[num_t].loc, trips[num_t].vod, trips[num_t].car, trips[num_t].tim);
        num_t++;
    }

    fprintf(output_file, "Пункт\tАвтомобиль\tВремя выезда\n");
    for (int i = 0; i < num_t; i++) {
        if (strcmp(trips[i].vod, "Винни-Пух") == 0) {
            fprintf(output_file, "%s\t%s\t%s\n", trips[i].loc, trips[i].car, trips[i].tim);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}



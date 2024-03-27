#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A 100

typedef struct {
    int id;
    char loc[A];
    char vod[A];
    char tim[A]; 
} Trips;

typedef struct {
    int id;
    char car[A];
    char tim[A]; 
} Cars;

int compare_tim(const void *a, const void *b) {
    const Cars *carA = (const Cars *)a;
    const Cars *carB = (const Cars *)b;
    return strcmp(carA->tim, carB->tim);
}

int main() {
    FILE *tripFile1, *carFile2, *outFile;
    char line[A];

    tripFile1 = fopen("trip.txt", "r");
    carFile2 = fopen("car.txt", "r");
    outFile = fopen("out.txt", "w");

    if (tripFile1 == NULL || carFile2 == NULL || outFile == NULL) {
        printf("Ошибка при открытии файлов.\n");
        return 1;
    }

    Trips trips[100];
    Cars cars[100];
    int num_t = 0, num_c = 0; 
    
    while (fgets(line, sizeof(line), tripFile1)) {
        Trips trip;
        sscanf(line, "%d;%[^;];%s", &trip.id, trip.loc, trip.vod);
        strcpy(trip.tim, "");
        trips[num_t++] = trip;
    }

    while (fgets(line, sizeof(line), carFile2)) {
        Cars car;
        sscanf(line, "%d;%[^;];%s", &car.id, car.car, car.tim);
        cars[num_c++] = car;
    }

    qsort(cars, num_c, sizeof(Cars), compare_tim);

    for (int i = 0; i < num_t && i < num_t; i++) {
        Trips trip = trips[i];
        Cars car = cars[i];
        fprintf(outFile, "%d;%s;%s;%s;%s\n", trip.id, trip.loc, trip.vod, car.car, car.tim);
    }

    fclose(tripFile1);
    fclose(carFile2);
    fclose(outFile);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int room_num;
    char category[50];
} Room;

typedef struct {
    int id;
    char date[11]; 
    char surname[50]; 
    int room_num; 
} Entry;

int func(const void *a, const void *b) {
    Entry *entry1 = (Entry *)a;
    Entry *entry2 = (Entry *)b;
    return strcmp(entry1->surname, entry2->surname);
}

int main() {
    FILE *name_file = fopen("name.txt", "r");
    FILE *num_file = fopen("num.txt", "r");
    FILE *out_file = fopen("out.txt", "w");


    if (name_file == NULL || num_file == NULL || out_file == NULL) {
        printf("Ошибка\n");
        return 1;
    }
    
    Room rooms[100];
    Entry entries[100];
    int room_c = 0;
    int entry_c = 0;

    while (fscanf(num_file, "%d;%d;%s", &rooms[room_c].id, &rooms[room_c].room_num, rooms[room_c].category) == 3) {
        room_c++;
    }

    while (fscanf(name_file, "%d;%10s;%49s", &entries[entry_c].id, entries[entry_c].date, entries[entry_c].surname) == 3) {
        entry_c++;
    }
    
    printf("Фамилия\tНомер\n");
    fprintf(out_file, "Фамилия\tНомер\n");
    for (int i = 0; i < entry_c; i++) {
        int room_num = -1;
        for (int j = 0; j < room_c; j++) {
            if (entries[i].id == rooms[j].id) {
                room_num = rooms[j].room_num;
                break;
            }
        }
        if (strcmp(rooms[i].category, "Люкс") == 0) {
            printf("%s;%d\n", entries[i].surname, room_num);
            fprintf(out_file, "%s;%d\n", entries[i].surname, room_num);

        }
        
    }

    fclose(name_file);
    fclose(num_file);
    fclose(out_file);

    return 0;
}


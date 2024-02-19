/******************************************************************************
Подвиг 8. Продолжите программу. Прочитайте из входного потока целые числа в переменные var_1, var_2 и var_3, записанные в одну строчку через запятую. Побайтно занесите их значения в массив типа char (в порядке var_1, var_2, var_3). Выведите в одну строчку по порядку значения массива в виде беззнаковых десятичных чисел.
Sample Input:
7356, 6575729, 100433564

Sample Output:
188 28 113 86 100 0 156 126 252 5 0 0 0 0
*******************************************************************************/
#include <stdio.h>

int main(void) {
    short var_1;
    int var_2;
    long long var_3;

    scanf("%hd, %d, %lld", &var_1, &var_2, &var_3);

    char bytes[sizeof(var_1) + sizeof(var_2) + sizeof(var_3)];
    for (int i = 0; i < sizeof(var_1); i++) {
        bytes[i] = (char)((var_1 >> (8 * i)) & 0xFF);
    }
    for (int i = 0; i < sizeof(var_2); i++) {
        bytes[sizeof(var_1) + i] = (char)((var_2 >> (8 * i)) & 0xFF);
    }
    for (int i = 0; i < sizeof(var_3); i++) {
        bytes[sizeof(var_1) + sizeof(var_2) + i] = (char)((var_3 >> (8 * i)) & 0xFF);
    }

    for (int i = 0; i < sizeof(bytes); i++) {
        printf("%u ", (unsigned char)bytes[i]);
    }
    printf("\n");

    return 0;
}
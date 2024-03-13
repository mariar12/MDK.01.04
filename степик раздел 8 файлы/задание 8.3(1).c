/******************************************************************************
 Продолжите программу. Необходимо прочитать из потока fp с помощью функции fgets или fputs (подумайте какой) строку в массив buff. Подсчитайте количество слов в строке (слова разделяются одним или несколькими пробелами). Выведите в консоль количество слов в виде одного целого числа.

Sample Input:
Moscow   Ufa Samara  Ulianovsk

Sample Output:
4
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {
    char buff[512];
    int count = 0;

    FILE* fp = stdin;
    fgets(buff, sizeof(buff), fp);

    char* token = strtok(buff, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    printf("%d\n", count);

    // fclose(fp); закрывать стандартный поток не нужно

    return 0;
}
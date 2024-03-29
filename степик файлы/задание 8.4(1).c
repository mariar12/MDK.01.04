/******************************************************************************
 . Продолжите программу. Необходимо из потока fp читать строки целиком (до символа переноса строки или символа EOF) и сохранять их в массиве text. При чтении следует контролировать количество читаемых строк, чтобы оно не превосходило значения max_lines. Гарантируется, что строки не длиннее значения max_string_len. В конце каждой строки не должно быть символа перевода строки. Выведите в консоль все полученные в массиве text строки (каждая с новой строки).

Sample Input:
Язык Си. Рождение легенды
Структура и понимание работы программы "Hello, World!"
Арифметические операции деления по модулю, инкремента и декремента
Функция printf() для форматированного вывода
Булевый тип. Операции сравнения. Логические И, ИЛИ, НЕ

Sample Output:
Язык Си. Рождение легенды
Структура и понимание работы программы "Hello, World!"
Арифметические операции деления по модулю, инкремента и декремента
Функция printf() для форматированного вывода
Булевый тип. Операции сравнения. Логические И, ИЛИ, НЕ
*******************************************************************************/
#include <stdio.h>
#include <string.h>

enum { max_lines = 10, max_string_len = 200 };

int main(void) {
    char text[max_lines][max_string_len];

    FILE* fp = stdin;

    int i = 0;
    while (i < max_lines && fgets(text[i], sizeof(text[i]), fp) != NULL) {
        text[i][strcspn(text[i], "\n")] = '\0';
        i++;
    }

    for (int j = 0; j < i; j++) {
        printf("%s\n", text[j]);
    }

    // fclose(fp); закрывать стандартный поток не нужно

    return 0;
}
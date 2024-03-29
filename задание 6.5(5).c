/******************************************************************************
Продолжите программу. Необходимо объявить четыре критериальных функции для отбора целочисленных значений при суммировании в функции sum_ar. Все критериальные функции должны иметь сигнатуру:

int <имя функции>(int );
и быть следующими:

is_odd: возвращает 1 для нечетных значений и 0 для четных;
is_positive: возвращает 1 для неотрицательных значений и 0 для отрицательных;
is_negative: возвращает 1 для отрицательных значений и 0 для неотрицательных;
deflt: возвращает 1 для любых значений.
В функции sum_ar реализовать подсчет целых чисел переданного массива ar, для которых критериальная функция (переданная через указатель) возвращает истину (не нулевое значение). Функция sum_ar должна возвращать вычисленную сумму.

В функции main объявить массив указателей с именем funcs на объявленные критериальные функции (в порядке их перечисления в задании). Затем, сформировать массив marks из прочитанных целочисленных значений в количестве не более 20 (необходима проверка на максимальное количество записываемых данных). После этого в операторе switch выполнить подсчет суммы с указанием соответствующей критериальной функции из массива funcs.

Sample Input:

1 5 4 3 5 6 78 89 56  43  456 45 645 45 44 3 1 4
Sample Output:

884
*******************************************************************************/
#include <stdio.h>

int is_odd(int num) {
    return num % 2 != 0;
}

int is_positive(int num) {
    return num >= 0;
}

int is_negative(int num) {
    return num < 0;
}

int deflt(int num) {
    return 1;
}

int sum_ar(const int *ar, size_t len_ar, int (*check_func)(int)) {
    int sum = 0;
    for (size_t i = 0; i < len_ar; ++i) {
        if (check_func(ar[i])) {
            sum += ar[i];
        }
    }
    return sum;
}

int main(void) {
    int (*funcs[])(int) = {is_odd, is_positive, is_negative, deflt};

    int marks[20] = {0};
    int item = 0;
    size_t count = 0;
    
    scanf("%d", &item);

    int x;
    while (count < 20 && scanf("%d", &x) == 1) {
        marks[count++] = x;
    }

    int result = 0;
    switch (item) {
        case 1:
        case 2:
        case 3:
        case 4:
            result = sum_ar(marks, count, funcs[item - 1]);
            break;
        default:
            result = sum_ar(marks, count, deflt);
    }
    
    printf("%d\n", result);

    return 0;
}
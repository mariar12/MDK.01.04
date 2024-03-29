/******************************************************************************
Подвиг 6. Напишите программу, которая читает целочисленные значения из входного потока в массив, записанных в одну строчку через пробел. Чтение происходит до тех пор, пока либо не закончатся данные, либо не будет прочитано 10 чисел. После этого выполните проверку: если прочитанные числа неотрицательны (больше или равны 0) и нечетны, то выведите в консоль число 1, иначе - число 0. Попробуйте реализовать эту программу без применения условных операторов.
Sample Input:
3 5 7 11 13 15 17 19 23 25 43 36

Sample Output:
1
*******************************************************************************/

#include <stdio.h>

int main(void) {
    int num[10]; 
    int count = 0; 
    while (count < 10 && scanf("%d", &num[count]) == 1) {
        count++;
    }
    int res = 1; 
    
    for (int i = 0; i < count; i++) {
        res &= (num[i] & 1) | (num[i] < 0);
    }
    printf("%d\n", res);

    return 0;
}
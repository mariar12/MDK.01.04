/******************************************************************************
 Продолжите программу. Перед функцией main объявите прототип функции с именем get_geom, которая принимает два целочисленных параметра, вычисляет их среднее геометрическое по формуле:


и возвращает вычисленное значение g. Реализацию функции get_geom пропишите после функции main. В функции main вызовите функцию get_geom для переменных a и b. Вычисленное значение выведите в консоль в виде вещественного числа с точностью до сотых.

Sample Input:

5, 7
Sample Output:

5.92
*******************************************************************************/
#include <stdio.h>
#include <math.h>

double get_geom(int a, int b);

int main() {
    int a, b;
    scanf("%d, %d", &a, &b); 
    double res = get_geom(a, b);
    printf("%.2lf\n", res);
    return 0;
}

double get_geom(int a, int b) {
    return sqrt((double)a * b);
}



/******************************************************************************
Подвиг 8. Продолжите программу. Необходимо прочитать из входного потока пять целых чисел, 
записанных в одну строчку через пробел, в массив с именем digits длиной пять элементов типа int. 
Используя оператор цикла for, выведите в консоль все значения элементов массива digits в одну 
строчку через пробел.
Sample Input:
3 6 78 4 101

Sample Output:
3 6 78 4 101
*******************************************************************************/
#include <stdio.h>

extern char buff_1[];
extern char buff_2[];

int main(void) {
    char buffer[128];
    char *ptr_ar = buffer;

    char *begin_1 = buff_1;
    int len_1 = sizeof(buff_1) / sizeof(char);
    char *end_1 = buff_1 + len_1;
    for (; begin_1 < end_1; ptr_ar++, begin_1++) { 
        *ptr_ar = *begin_1; 
    }

    char *begin_2 = buff_2;
    int len_2 = sizeof(buff_2) / sizeof(char);
    char *end_2 = buff_2 + len_2;
    for (; begin_2 < end_2; ptr_ar++, begin_2++) { 
        *ptr_ar = *begin_2; 
    }

    __ASSERT_TESTS__
    return 0;
}

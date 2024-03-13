/******************************************************************************
Форматируемый ввод
*******************************************************************************/
#include <stdio.h>
 
int main(void)
{   
    char *filename = "file.dat"; 
    char name[20];  // Массив для считывания имени
    int age;        // Переменная для считывания возраста
    // Открытие файла для чтения
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Произошла ошибка при открытии файла\n");
        return 1; // Возврат кода ошибки
    }
    // Чтение данных из файла до достижения конца файла 
    while ((fscanf(fp, "%20s %d\n", name, &age)) != EOF)
    {
        printf("%s %d\n", name, age); // Вывод считанных данных
    }

    // Закрытие файла 
    fclose(fp);
    
    return 0; 
}
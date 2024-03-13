/******************************************************************************
Запись текстового файла
*******************************************************************************/
#include <stdio.h>
  
int main(void)
{
    // Строка с текстом который нужно записать в файл
    char *message = "Привет!\nКак у тебя дела?";
    char *filename = "file.txt"; // Имя файла
    FILE *fp = fopen(filename, "w"); // Файловый указатель для работы с файлом
    
    if(fp)
    {
        fputs(message, fp); // Запись текста в файл
        fclose(fp); // Закрытие файла после записи
        printf("Файл был записан\n"); // Вывод сообщения
    }

    return 0;
}


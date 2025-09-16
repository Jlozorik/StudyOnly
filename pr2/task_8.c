#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp, *temp_fp;
    char filename[100];
    char findStr[100], replaceStr[100];
    char buffer[1024]; 

    printf("Введите имя файла: ");
    scanf("%s", filename);

    printf("Введите строку для поиска: ");
    scanf("%s", findStr);

    printf("Введите строку для замены: ");
    scanf("%s", replaceStr);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    temp_fp = fopen("temp.tmp", "w");
    if (temp_fp == NULL) {
        perror("Ошибка при создании временного файла");
        fclose(fp);
        return 1;
    }
    
    while (fscanf(fp, "%s", buffer) != EOF) {
        if (strcmp(buffer, findStr) == 0) {
            fprintf(temp_fp, "%s ", replaceStr);
        } else {
            fprintf(temp_fp, "%s ", buffer);
        }
    }

    fclose(fp);
    fclose(temp_fp);

    remove(filename);
    rename("temp.tmp", filename);
    
    printf("Все вхождения строки заменены.\n");

    return 0;
}
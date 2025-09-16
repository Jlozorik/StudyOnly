#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp, *temp_fp;
    char filename[100];
    char findStr[100], replaceStr[100];
    char line[1024];
    
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
    
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *pos;
        while ((pos = strstr(line, findStr)) != NULL) {
            char temp_line[1024];
            int len_prefix = pos - line;
            strncpy(temp_line, line, len_prefix);
            temp_line[len_prefix] = '\0';
            strcat(temp_line, replaceStr);
            strcat(temp_line, pos + strlen(findStr));
            strcpy(line, temp_line);
        }
        fputs(line, temp_fp);
    }

    fclose(fp);
    fclose(temp_fp);

    remove(filename);
    rename("temp.tmp", filename);
    
    printf("Все вхождения строки заменены.\n");

    return 0;
}
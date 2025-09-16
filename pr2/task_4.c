#include <stdio.h>

int main() {
    FILE *fp1, *fp2;
    char filename1[100], filename2[100]; 
    int ch1, ch2;
    long line_num = 1;
    long char_num = 0;
    int diff_found = 0;
    int eof1 = 0, eof2 = 0;

    printf("Введите имя первого файла: ");
    fgets(filename1, sizeof(filename1), stdin);
    filename1[strcspn(filename1, "\n")] = 0; 

    printf("Введите имя второго файла: ");
    fgets(filename2, sizeof(filename2), stdin);
    filename2[strcspn(filename2, "\n")] = 0;

    fp1 = fopen(filename1, "r");
    if (fp1 == NULL) {
        perror("Ошибка при открытии первого файла");
        return 1;
    }

    fp2 = fopen(filename2, "r");
    if (fp2 == NULL) {
        perror("Ошибка при открытии второго файла");
        fclose(fp1);
        return 1;
    }

    while (1) {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);
        char_num++;

        if (ch1 == EOF) eof1 = 1;
        if (ch2 == EOF) eof2 = 1;

        if (ch1 == '\n') {
            line_num++;
            char_num = 0;
        }

        if (eof1 && eof2) {
            if (!diff_found) {
                printf("Содержимое файлов полностью совпадает.\n");
            }
            break;
        }

        if (ch1 != ch2) {
            printf("Различие найдено в строке %ld, символе %ld.\n", line_num, char_num);
            diff_found = 1;
            break;
        }

        if (eof1 && !eof2) {
            printf("Первый файл является началом второго файла.\n");
            break;
        }
        if (!eof1 && eof2) {
            printf("Второй файл является началом первого файла.\n");
            break;
        }
    }
    
    fclose(fp1);
    fclose(fp2);

    return 0;
}
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp_in, *fp_out;
    char filename_in[100], filename_out[100];
    int ch;

    printf("Введите имя исходного файла (f): ");
    scanf("%s", filename_in);

    printf("Введите имя результирующего файла (newf): ");
    scanf("%s", filename_out);

    fp_in = fopen(filename_in, "r");
    if (fp_in == NULL) {
        perror("Ошибка при открытии исходного файла");
        return 1;
    }

    fp_out = fopen(filename_out, "w");
    if (fp_out == NULL) {
        perror("Ошибка при создании результирующего файла");
        fclose(fp_in);
        return 1;
    }

    while ((ch = fgetc(fp_in)) != EOF) {
        fputc(tolower(ch), fp_out);
    }

    printf("Файл 'newf' создан с заменой прописных букв.\n");
    
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
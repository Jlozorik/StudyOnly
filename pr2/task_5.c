#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];
    int number;
    int count = 0;

    printf("Введите имя файла: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    while (fscanf(file, "%d", &number) == 1) {
        if (number > 0 && number % 2 == 0) {
            count++;
        }
    }

    printf("Количество четных положительных чисел: %d\n", count);

    fclose(file);
    return 0;
}
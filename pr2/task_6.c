#include <stdio.h>
#include <string.h>

int main() {
    FILE *outFile, *inFile;
    char outFilename[100], inFilename[100];
    char ch;

    printf("Введите имя файла-результата: ");
    scanf("%s", outFilename);

    outFile = fopen(outFilename, "w");
    if (outFile == NULL) {
        perror("Ошибка при создании файла-результата");
        return 1;
    }

    printf("Введите имена файлов для конкатенации (для завершения введите 'end'):\n");
    while (1) {
        scanf("%s", inFilename);
        if (strcmp(inFilename, "end") == 0) {
            break;
        }

        inFile = fopen(inFilename, "r");
        if (inFile == NULL) {
            perror("Ошибка при открытии файла");
            continue;
        }

        while ((ch = fgetc(inFile)) != EOF) {
            fputc(ch, outFile);
        }

        fclose(inFile);
    }

    fclose(outFile);
    printf("Конкатенация завершена.\n");
    return 0;
}
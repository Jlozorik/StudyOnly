#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *file = fopen("nonexistent_file.txt", "r");
    if (file == NULL) {
        perror("Ошибка открытия файла в main");
        fprintf(stderr, "Код ошибки (errno): %d\n", errno);

        return errno;
    }
    
    printf("Файл успешно открыт. Продолжение работы...\n");
    fclose(file);
    return 0;
}
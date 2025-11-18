#include <stdio.h>
#include <fcntl.h>   // Для open()
#include <unistd.h>  // Для read(), write(), close()
#include <stdlib.h>  // Для exit()

int main(int argc, char *argv[]) {
    // Проверяем, что передано два имени файла
    if (argc != 3) {
        write(STDOUT_FILENO, "Использование: ./compare file1.txt file2.txt\n", 48);
        exit(1);
    }

    // Открываем файлы только для чтения
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        perror("Ошибка открытия первого файла");
        exit(1);
    }

    int fd2 = open(argv[2], O_RDONLY);
    if (fd2 == -1) {
        perror("Ошибка открытия второго файла");
        close(fd1);
        exit(1);
    }

    char buf1, buf2;
    ssize_t bytes_read1, bytes_read2;
    long line_num = 1;
    long char_num = 1;

    while (1) {
        // Читаем по одному байту из каждого файла
        bytes_read1 = read(fd1, &buf1, 1);
        bytes_read2 = read(fd2, &buf2, 1);

        // Если один файл закончился, а другой нет
        if (bytes_read1 != bytes_read2) {
            write(STDOUT_FILENO, "Один файл является началом другого.\n", 60);
            break;
        }

        // Если оба файла закончились одновременно
        if (bytes_read1 == 0 && bytes_read2 == 0) {
            write(STDOUT_FILENO, "Файлы полностью совпадают.\n", 51);
            break;
        }

        // Сравниваем прочитанные байты
        if (buf1 != buf2) {
            char buffer[100];
            int len = sprintf(buffer, "Файлы отличаются. Строка: %ld, Символ: %ld\n", line_num, char_num);
            write(STDOUT_FILENO, buffer, len);
            break;
        }

        // Обновляем счетчики строк и символов
        if (buf1 == '\n') {
            line_num++;
            char_num = 1;
        } else {
            char_num++;
        }
    }

    // Закрываем файлы
    close(fd1);
    close(fd2);

    return 0;
}
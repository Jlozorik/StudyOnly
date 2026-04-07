#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define LOG_FILENAME "log.txt"

int main() {
    FILE *log_file;
    time_t timer;
    struct tm *tm_info;
    char buffer[26];

    printf("Logger запущен. Запись времени в %s каждую секунду. Нажмите Ctrl+C для остановки.\n", LOG_FILENAME);
    remove(LOG_FILENAME);

    while (1) {
        timer = time(NULL);
        tm_info = localtime(&timer);
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S\n", tm_info);

        log_file = fopen(LOG_FILENAME, "a");
        if (log_file == NULL) {
            perror("Ошибка открытия файла логов");
            return 1;
        }
        fprintf(log_file, "%s", buffer);

        fclose(log_file);

        sleep(1);
    }

    return 0;
}
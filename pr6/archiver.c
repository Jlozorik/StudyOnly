#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>

#define SOURCE_FILENAME "log.txt"
#define ARCHIVE_DIR "logs_archive"

// asojdhaksjdhakjsdhajs

void get_file_time_and_create_archive_name(const char *filename, char *archive_name, size_t max_len) {
    struct stat file_stat;
    time_t file_mtime;
    struct tm *tm_info;

    if (stat(filename, &file_stat) == 0) {
        file_mtime = file_stat.st_mtime;
    } else {
        file_mtime = time(NULL);
    }

    tm_info = localtime(&file_mtime);

    strftime(archive_name, max_len, "%Y%m%d_%H%M%S.tar.gz", tm_info);
}

int main() {
    char archive_name[50];
    char command_buffer[256];

    printf("Archiver запущен. Архивирование %s раз в 5 секунд.\n", SOURCE_FILENAME);
    mkdir(ARCHIVE_DIR, 0777);

    while (1) {
        if (access(SOURCE_FILENAME, F_OK) != 0) {
            printf("Файл %s не найден. Ожидание.\n", SOURCE_FILENAME);
            sleep(5);
            continue;
        }
        get_file_time_and_create_archive_name(SOURCE_FILENAME, archive_name, sizeof(archive_name));

        snprintf(command_buffer, sizeof(command_buffer),
                 "tar -czf %s/%s %s --remove-files",
                 ARCHIVE_DIR, archive_name, SOURCE_FILENAME);

        printf("Архивирование в %s/%s...\n", ARCHIVE_DIR, archive_name);

        if (system(command_buffer) == 0) {
            printf("Успешно заархивировано и перемещено.\n");
        } else {
            printf("Ошибка выполнения команды архивирования.\n");
        }

        sleep(5);
    }

    return 0;
}
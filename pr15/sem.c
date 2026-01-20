#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int buf = 0;
sem_t empty, full;

void *producer(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        // sem_wait(&empty); // Ждем место
        buf = i + 1;
        printf("Записал: %d\n", buf);
        // sem_post(&full); // Сообщаем, что есть данные
    }
    return NULL;
}

void *consumer(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        // sem_wait(&full); // Ждем данные
        printf("Прочитал: %d\n", buf);
        // sem_post(&empty); // Сообщаем, что место свободно
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    sem_init(&empty, 0, 1); // 1 свободное место
    sem_init(&full, 0, 0);  // 0 занятых мест

    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
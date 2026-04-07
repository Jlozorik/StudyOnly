#include <stdio.h>
#include <pthread.h>

#define MAX 1000000
int count = 0;
pthread_mutex_t m;

void *func(void *arg)
{
    for (int i = 0; i < MAX; i++)
    {
        // pthread_mutex_lock(&m);
        count++;
        // pthread_mutex_unlock(&m);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    pthread_mutex_init(&m, NULL);

    pthread_create(&t1, NULL, func, NULL);
    pthread_create(&t2, NULL, func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Результат: %d (Ожидалось: %d)\n", count, MAX * 2);
    pthread_mutex_destroy(&m);
    return 0;
}
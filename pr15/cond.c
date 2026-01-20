#include <stdio.h>
#include <pthread.h>

int ready = 0;
pthread_mutex_t m;
pthread_cond_t c;

void *wait_func(void *arg)
{
    pthread_mutex_lock(&m);
    while (ready == 0)
    {
        printf("Жду сигнал...\n");
        // pthread_cond_wait(&c, &m);
    }
    printf("Сигнал получен!\n");
    pthread_mutex_unlock(&m);
    return NULL;
}

void *signal_func(void *arg)
{
    pthread_mutex_lock(&m);
    ready = 1;
    printf("Отправляю сигнал.\n");
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&m);
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    pthread_mutex_init(&m, NULL);
    pthread_cond_init(&c, NULL);

    pthread_create(&t1, NULL, wait_func, NULL);
    for (int i = 0; i < 1000000; i++)
        ;
    pthread_create(&t2, NULL, signal_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
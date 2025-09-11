#include <stdio.h>

void task1();
void task2();
void task3();
void task4();
void task5();

int main() {
    printf("Задание 1:\n");
    task1();
    printf("\n");

    printf("Задание 2:\n");
    task2();
    printf("\n");

    printf("Задание 3:\n");
    task3();
    printf("\n");

    printf("Задание 4:\n");
    task4();
    printf("\n");

    printf("Задание 5:\n");
    task5();
    
    return 0;
}

void task1() {
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void task2() {
    for (int i = 1; i <= 10; i++) {
        printf("5 x %d = %d\n", i, 5 * i);
    }
}

void task3() {
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("Сумма чисел от 1 до 100: %d\n", sum);
}

void task4() {
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void task5() {
    int num;
    printf("Введите число: ");
    scanf("%d", &num);
    printf("Делители числа %d: ", num);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}


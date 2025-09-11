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
    int num;
    printf("Введите число: ");
    scanf("%d", &num);
    if (num % 2 == 0) {
        printf("Число %d является четным.\n", num);
    } else {
        printf("Число %d является нечетным.\n", num);
    }
}

void task2() {
    int num;
    printf("Введите число: ");
    scanf("%d", &num);
    if (num > 0) {
        printf("Число %d является положительным.\n", num);
    } else if (num < 0) {
        printf("Число %d является отрицательным.\n", num);
    } else {
        printf("Число равно нулю.\n");
    }
}

void task3() {
    int num;
    printf("Введите число: ");
    scanf("%d", &num);
    if (num % 3 == 0) {
        printf("Число %d кратно 3.\n", num);
    } else {
        printf("Число %d не кратно 3.\n", num);
    }
}

void task4() {
    double num1, num2;
    printf("Введите два числа: ");
    scanf("%lf %lf", &num1, &num2);
    if (num1 > num2) {
        printf("Большее число: %.2lf\n", num1);
    } else if (num2 > num1) {
        printf("Большее число: %.2lf\n", num2);
    } else {
        printf("Числа равны.\n");
    }
}

void task5() {
    double num1, num2;
    printf("Введите два числа: ");
    scanf("%lf %lf", &num1, &num2);
    if (num1 == num2) {
        printf("Числа равны.\n");
    } else {
        printf("Числа не равны.\n");
    }
}

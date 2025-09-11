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
    printf("Вы ввели: %d\n", num);
}

void task2() {
    double num1, num2;
    printf("Введите два числа: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Сумма: %.2lf\n", num1 + num2);
    printf("Разность: %.2lf\n", num1 - num2);
    printf("Произведение: %.2lf\n", num1 * num2);
    if (num2 != 0) {
        printf("Частное: %.2lf\n", num1 / num2);
    } else {
        printf("Деление на ноль невозможно.\n");
    }
}

void task3() {
    double num1, num2, num3;
    printf("Введите три числа: ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);
    printf("Среднее арифметическое: %.2lf\n", (num1 + num2 + num3) / 3);
}

void task4() {
    char name[50];
    printf("Введите ваше имя: ");
    scanf("%s", name);
    printf("Привет, %s!\n", name);
}

void task5() {
    int birthYear, currentYear = 2025; // Установлен текущий год 2025
    printf("Введите ваш год рождения: ");
    scanf("%d", &birthYear);
    int age = currentYear - birthYear;
    printf("Ваш возраст: %d\n", age);
}


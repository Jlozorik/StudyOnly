#include <stdio.h>

void task1();
void task2();
void task3();
void task4();
void task5();

int main() {
    // Задание 1
    int num1;
    printf("Введите число для вычисления факториала: ");
    scanf("%d", &num1);
    long long fact = factorial(num1);
    
    printf("Факториал числа %d: %lld\n", num1, fact);
    
    printf("\n");

    // Задание 2
    int num2;
    printf("Введите число для проверки на простоту: ");
    scanf("%d", &num2);
    if (isPrime(num2)) {
        printf("Число %d является простым.\n", num2);
    } else {
        printf("Число %d не является простым.\n", num2);
    }
    printf("\n");

    // Задание 3
    int num3;
    printf("Введите число для вывода делителей: ");
    scanf("%d", &num3);
    printDivisors(num3);
    printf("\n");

    // Задание 4
    int num4_1, num4_2;
    printf("Введите два числа: ");
    scanf("%d %d", &num4_1, &num4_2);
    printNumbersBetween(num4_1, num4_2);
    printf("\n");

    // Задание 5
    int num5_1, num5_2;
    printf("Введите два числа для проверки на дружественность: ");
    scanf("%d %d", &num5_1, &num5_2);
    if (areAmicable(num5_1, num5_2)) {
        printf("Числа %d и %d являются дружественными.\n", num5_1, num5_2);
    } else {
        printf("Числа %d и %d не являются дружественными.\n", num5_1, num5_2);
    }
    
    return 0;
}

// 1. Функция для вычисления факториала
long long factorial(int n) {
    if (n < 0) {
        return -1; // Возвращаем -1 для отрицательных чисел
    }
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 2. Функция для проверки на простое число
int isPrime(int n) {
    if (n <= 1) {
        return 0; // Не является простым
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; // Не является простым
        }
    }
    return 1; // Является простым
}

// 3. Функция для вывода делителей
void printDivisors(int n) {
    printf("Делители числа %d: ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// 4. Функция для вывода чисел между двумя
void printNumbersBetween(int a, int b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    printf("Числа между %d и %d: ", a, b);
    for (int i = a + 1; i < b; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

// Вспомогательная функция для вычисления суммы делителей
int sumDivisors(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

// 5. Функция для проверки на дружественные числа
int areAmicable(int a, int b) {
    if (sumDivisors(a) == b && sumDivisors(b) == a) {
        return 1; // Являются дружественными
    }
    return 0; // Не являются дружественными
}


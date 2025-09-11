#include <stdio.h>

void task_1() {
    int n, i;
    long long factorial = 1;
    printf("Введите число для вычисления факториала: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Факториал отрицательного числа не существует.\n");
    } else {
        for (i = 1; i <= n; ++i) {
            factorial *= i;
        }
        printf("Факториал числа %d: %lld\n", n, factorial);
    }
}

void task_2() {
    int n, i, is_prime = 1;
    printf("Введите число для проверки на простоту: ");
    scanf("%d", &n);
    if (n <= 1) {
        is_prime = 0;
    } else {
        for (i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }
    if (is_prime) {
        printf("Число %d является простым.\n", n);
    } else {
        printf("Число %d не является простым.\n", n);
    }
}

void task_3() {
    int n, i;
    printf("Введите число для вывода его делителей: ");
    scanf("%d", &n);
    printf("Делители числа %d: ", n);
    for (i = 1; i <= n; ++i) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void task_4() {
    int a, b, i;
    printf("Введите два числа: ");
    scanf("%d %d", &a, &b);
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    printf("Числа между %d и %d: ", a, b);
    for (i = a + 1; i < b; ++i) {
        printf("%d ", i);
    }
    printf("\n");
}

int sum_divisors(int n) {
    int sum = 1, i;
    if (n <= 1) return 0;
    for (i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) {
                sum += n / i;
            }
        }
    }
    return sum;
}

void task_5() {
    int a, b, sum_a, sum_b;
    printf("Введите два числа для проверки на дружественность: ");
    scanf("%d %d", &a, &b);
    if (a == b) {
        printf("Числа не могут быть дружественными, так как они одинаковы.\n");
        return;
    }
    sum_a = sum_divisors(a);
    sum_b = sum_divisors(b);
    if (sum_a == b && sum_b == a) {
        printf("Числа %d и %d являются дружественными.\n", a, b);
    } else {
        printf("Числа %d и %d не являются дружественными.\n", a, b);
    }
}

int main() {
    task_1();
    printf("\n");
    task_2();
    printf("\n");
    task_3();
    printf("\n");
    task_4();
    printf("\n");
    task_5();
    return 0;
}
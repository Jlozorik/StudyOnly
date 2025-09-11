#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

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
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Элементы массива:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void task2() {
    int arr[10];
    srand(time(NULL)); // Инициализация генератора случайных чисел
    printf("Элементы массива со случайными значениями:\n");
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100; // Случайное число от 0 до 99
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void task3() {
    int arr[10];
    printf("Введите 10 чисел:\n");
    for (int i = 0; i < 10; i++) {
        printf("Элемент %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Элементы массива:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void task4() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += arr[i];
    }
    printf("Сумма элементов массива: %d\n", sum);
}

void task5() {
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int result[10];

    printf("Сумма двух массивов:\n");
    for (int i = 0; i < 10; i++) {
        result[i] = arr1[i] + arr2[i];
        printf("%d ", result[i]);
    }
    printf("\n");
}


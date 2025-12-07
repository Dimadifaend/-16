#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define MAX_SIZE 100

double* full_elements(double* ptr_array, int n);
void delete_element(double arr[], int* size, int index);
double* process_lab16(double* arr, int* n);
double process_poiskOtr(double* arr, int n, int* index_otr);
double* process_task14(double* a, int n, double* b, int m, double* C, int sizeC, int* result_size);
double process_task11(double* arr, int n, int* index_otr);

int main() {
    setlocale(LC_ALL, "RUS");
    printf("Объединённая программа:\n");

    double arr[MAX_SIZE];
    int size;
    int otr_index;
    double sum_result;

    printf("\n=== Лабораторная 16 ===\n");
    printf("Введите размер массива (до %d): ", MAX_SIZE);
    scanf("%d", &size);

    full_elements(arr, size);

    int delIndex;
    printf("Введите индекс для удаления: ");
    scanf("%d", &delIndex);
    delete_element(arr, &size, delIndex);

    printf("Массив после удаления:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n");

    printf("\n=== Поиск отрицательного ===\n");
    printf("Введите размер массива: ");
    scanf("%d", &size);
    full_elements(arr, size);

    sum_result = process_poiskOtr(arr, size, &otr_index);
    if (otr_index == -1) {
        printf("Отрицательных элементов нет\n");
    }
    else {
        printf("Сумма модулей после первого отрицательного: %.2lf\n", sum_result);
    }

    printf("\n=== Задание 14 ===\n");
    int n, m, sizeC;
    printf("Введите размеры массивов a, b, C:\n");
    printf("a: "); scanf("%d", &n);
    printf("b: "); scanf("%d", &m);
    printf("C: "); scanf("%d", &sizeC);

    double* a = (double*)malloc(n * sizeof(double));
    double* b = (double*)malloc(m * sizeof(double));
    double* C = (double*)malloc(sizeC * sizeof(double));

    printf("Введите массив a:\n");
    full_elements(a, n);
    printf("Введите массив b:\n");
    full_elements(b, m);
    printf("Введите массив C:\n");
    full_elements(C, sizeC);

    int result_size;
    double* result = process_task14(a, n, b, m, C, sizeC, &result_size);

    printf("Средние значения:\n");
    for (int i = 0; i < result_size; i++) {
        printf("result[%d] = %.2f\n", i, result[i]);
    }
    free(a); free(b); free(C); free(result);

    printf("\n=== Работа 11 ===\n");
    printf("Введите размер массива: ");
    scanf("%d", &size);
    full_elements(arr, size);

    sum_result = process_task11(arr, size, &otr_index);
    if (otr_index == -1) {
        printf("Отрицательных элементов нет\n");
    }
    else {
        printf("Сумма модулей после первого отрицательного: %.2lf\n", sum_result);
    }

    return 0;
}

double* full_elements(double* ptr_array, int n) {
    printf("Введите %d чисел:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Элемент %d: ", i + 1);
        scanf("%lf", &ptr_array[i]);
    }
    return ptr_array;
}

void delete_element(double arr[], int* size, int index) {
    if (index < 0 || index >= *size) return;
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

double process_poiskOtr(double* arr, int n, int* index_otr) {
    *index_otr = -1;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0 && *index_otr == -1) {
            *index_otr = i;
        }
    }

    if (*index_otr != -1) {
        for (int i = *index_otr + 1; i < n; i++) {
            sum += fabs(arr[i]);
        }
    }

    return sum;
}

double* process_task14(double* a, int n, double* b, int m, double* C, int sizeC, int* result_size) {
    *result_size = n < m ? n : m;
    *result_size = *result_size < sizeC ? *result_size : sizeC;

    double* result = (double*)malloc(*result_size * sizeof(double));
    for (int i = 0; i < *result_size; i++) {
        result[i] = (a[i] + b[i] + C[i]) / 3.0;
    }

    return result;
}

double process_task11(double* arr, int n, int* index_otr) {
    *index_otr = -1;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0 && *index_otr == -1) {
            *index_otr = i;
        }
    }

    if (*index_otr != -1) {
        for (int i = *index_otr + 1; i < n; i++) {
            sum += fabs(arr[i]);
        }
    }

    return sum;
}
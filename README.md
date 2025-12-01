# Работа с массивами в С

## 📋задание к лаб. 11
1. Заполнение массива с консоли

         float A[10];
         printf("=== Заполнение массива из 10 элементов ===\n");
         for(int i = 0; i < 10; i++) {
         printf("A[%d] = ", i);
         scanf("%f", &A[i]);
        printf("\n=== Преобразование массива: замена знака каждого элемента ===\n");
        for(int i = 0; i < 10; i++) {
2. Преобразование массива

        A[i] = -A[i];  
        printf("A[%d]: %.2f -> %.2f\n", i, original[i], A[i]);
        }
3. Печать массива

          printf("+----------+---------------------+\n");
          printf("|  Индекс  |     Значение        |\n");
          printf("+----------+---------------------+\n");
          
          for(int i = 0; i < 10; i++) {
              printf("|   %2d     | %19.2f |\n", i, A[i]);
          }
          
          printf("+----------+---------------------+\n");

4. Дз  
      
    Условие:
    
    Сумма модулей элементов массива, расположенных после первого отрицательного элемента.
      
    Решение:

        #include <math.h>
        #include <stdio.h>
        #include <locale.h>
        
        #define MAX_SIZE 100  
        
        int main()
        {
            setlocale(LC_ALL, "RUS");
            int n, i, otr = -1;
            double sum = 0;
            double arr[MAX_SIZE];
        
            printf("Введите размер массива (не более %d): ", MAX_SIZE);
            scanf("%d", &n);
        
        
            
        
            printf("Введите элементы массива:\n");
            for (i = 0; i < n; i++)
            {
                scanf("%lf", &arr[i]);
                if (arr[i] < 0 && otr == -1)
                {
                    otr = i;
                }
            }
        
            if (otr == -1)
            {
                printf("Отрицательных элементов нет");
                return 0;
            }
        
            for (i = otr + 1; i < n; i++)
            {
                sum = sum + fabs(arr[i]);
            }
            printf("Сумма модулей элементов после первого отрицательного: %lf", sum);
        
            return 0;
        }

## 📋задание к лаб. 14
1.Заполнение массива значениями из функции Func(x)

    double formula(double x) {
        return x * x; 
    }
    
    void zapolnenie(double *a, int n) {
        for(int i = 0; i < n; i++) {
            a[i] = formula(i);
        }
    }

2.Печать массива 
  
      void print_array(double *a, int n) {
      printf("Содержимое массива:\n");
      for(int i = 0; i < n; i++) {
          printf("a[%d] = %.2f\n", i, a[i]);
      }
      }

3.Вычисление суммы элементов массива

    double sum_elements(double *arr, int start, int finish) {
    double s = 0;
    for(int i = start; i <= finish; i++) {
        s += arr[i];
    }
    return s;
   }

4.Поиск в массиве значения равного a

    int poick(double *mas, int kol, double isk) {
      for(int i = 0; i < kol; i++) {
          if(mas[i] == isk) {
              return i;
          }
      }
      return -1;
      }
5. ДЗ

        Условие: 
        Поиск порядкового номера минимального значения элементов, кратных k.
        Решение:
        #include <stdio.h>
        #include <limits.h>
        #include <locale.h>
        
        int findMin(int* a, int n, int K) {
            int min = INT_MAX;
            for (int i = K - 1; i < n; i += K) {
                if (a[i] < min) {
                    min = a[i];
                }
            }
            return min;
        }
        
        int main() {
            setlocale(LC_ALL, "RUS");
            int arr[] = { 5, 2, 8, 1, 9, 3, 7, 4 };
            int size = sizeof(arr) / sizeof(arr[0]);
            int K = 3;
        
            int result = findMin(arr, size, K);
            printf("Мин. среди элементов с номерами, кратными %d: %d\n", K, result);
        
            return 0;
        }
# 📋 Задания к лаб. 16
## 📁 Структура проекта
      #include <stdio.h>
      #include <stdlib.h>
      #include <math.h>
      #include <locale.h>
      
      #define MAX_SIZE 100
      
      void lab16();
      void poiskOtr();
      void task14();
      void task11();
      void delete_element(double arr[], int* size, int index);
      double* full_elements(double* ptr_array, int n);
      
      int main() {
          setlocale(LC_ALL, "RUS");
          printf("Объединённая программа:\n");
          lab16();
          poiskOtr();
          task14();
          task11();
          return 0;
      }
      
      void delete_element(double arr[], int* size, int index) {
          if (index < 0 || index >= *size) return;
          for (int i = index; i < *size - 1; i++) {
              arr[i] = arr[i + 1];
          }
          (*size)--;
      }
      
      void lab16() {
          int n;
          double arr[MAX_SIZE];
          printf("\n=====================================\n");
          printf("Лабораторная 16:\n");
          printf("Введите размер массива (до %d): ", MAX_SIZE);
          scanf("%d", &n);
          printf("Заполнение массива (функция full_elements):\n");
          full_elements(arr, n);
          int delIndex;
          printf("Введите индекс элемента для удаления (от 0 до %d): ", n - 1);
          scanf("%d", &delIndex);
          delete_element(arr, &n, delIndex);
      
          printf("Массив после удаления:\n");
          for (int i = 0; i < n; i++) {
              printf("%.2lf ", arr[i]);
          }
          printf("\n=====================================\n");
      }
      
      double* full_elements(double* ptr_array, int n) {
          printf("Введите %d чисел:\n", n);
          for (int i = 0; i < n; i++) {
              printf("Элемент %d: ", i + 1);
              scanf("%lf", &ptr_array[i]);
          }
          return ptr_array;
      }
      
      void poiskOtr() {
          int n;
          double arr[MAX_SIZE];
          int otr = -1;
          double sum = 0;
          printf("\n=====================================\n");
          printf("Поиск отрицательного:\n");
          printf("Введите размер массива (не более %d): ", MAX_SIZE);
          scanf("%d", &n);
          full_elements(arr, n);
          for (int i = 0; i < n; i++) {
              if (arr[i] < 0 && otr == -1)
                  otr = i;
          }
          if (otr == -1) {
              printf("Отрицательных элементов нет\n");
          }
          else {
              for (int i = otr + 1; i < n; i++) {
                  sum += fabs(arr[i]);
              }
              printf("Сумма модулей элементов после первого отрицательного: %.2lf\n", sum);
          }
          printf("=====================================\n");
      }
      
      void task14() {
          int n, m, sizeC;
          printf("\n=====================================\n");
          printf("Задание 14:\n");
          printf("Введите размеры массивов a, b, C:\n");
          printf("a: ");
          scanf("%d", &n);
          printf("b: ");
          scanf("%d", &m);
          printf("C: ");
          scanf("%d", &sizeC);
          double* a = (double*)malloc(n * sizeof(double));
          double* b = (double*)malloc(m * sizeof(double));
          double* C = (double*)malloc(sizeC * sizeof(double));
          printf("Введите элементы массива a:\n");
          for (int i = 0; i < n; i++) {
              printf("a[%d]: ", i);
              scanf("%lf", &a[i]);
          }
          printf("Введите элементы массива b:\n");
          for (int i = 0; i < m; i++) {
              printf("b[%d]: ", i);
              scanf("%lf", &b[i]);
          }
          printf("Введите элементы массива C:\n");
          for (int i = 0; i < sizeC; i++) {
              printf("C[%d]: ", i);
              scanf("%lf", &C[i]);
          }
          int min_size = n < m ? n : m;
          min_size = min_size < sizeC ? min_size : sizeC;
      
          double* result = (double*)malloc(min_size * sizeof(double));
          for (int i = 0; i < min_size; i++) {
              result[i] = (a[i] + b[i] + C[i]) / 3.0;
          }
          printf("Результат (среднее арифметическое):\n");
          for (int i = 0; i < min_size; i++) {
              printf("result[%d] = %.2f\n", i, result[i]);
          }
          free(a);
          free(b);
          free(C);
          free(result);
          printf("=====================================\n");
      }
      
      void task11() {
          int n, i, otr = -1;
          double sum = 0;
          double arr[MAX_SIZE];
      
          printf("\n=====================================\n");
          printf("Работа 11:\n");
          printf("Введите размер массива (не более %d): ", MAX_SIZE);
          scanf("%d", &n);
      
          full_elements(arr, n);
      
          for (i = 0; i < n; i++) {
              if (arr[i] < 0 && otr == -1) {
                  otr = i;
              }
          }
      
          if (otr == -1) {
              printf("Отрицательных элементов нет\n");
          }
          else {
              for (i = otr + 1; i < n; i++) {
                  sum += fabs(arr[i]);
              }
              printf("Сумма модулей элементов после первого отрицательного: %.2lf\n", sum);
          }
          printf("=====================================\n");
      }


## 🔧 Реализованные функции

      void lab16();
      void poiskOtr();
      void task14();
      void task11();
      void delete_element(double arr[], int* size, int index);
      double* full_elements(double* ptr_array, int n);
      

     

#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;

const int SIZE_ARRAY=100;
int globalArray[SIZE_ARRAY];

int* RandomArray (int*);
void PrintArray (int*);
void DoTask1 ();
int* BubbleSort (int*);
void DoTask2 ();
int FindMax (int*);
void FindMaxInRandomArray (int*);
void FindMaxInSortArray (int*);
int FindMin (int*);
void FindMinInRandomArray (int*);
void FindMinInSortArray (int*);
void DoTask3 ();
void DoTask4 (int*);
void DoTask5 (int*);
void DoTask6 (int*);
void SwapIndex (int*, int, int);
void DoTask8 ();
void DoTask7();
int MenuTasks ();
void DoTasks (int);
void DoLabWork2 ();
int* QuickSort (int*, int, int);
void printQuickSort ();
bool NormalSearch (int*,int);
void TimeNormalSearch (int);
bool BinarySearch (int*, int);
void TimeBinarySearch (int);
void PrintNumberSearch (bool);



int main() {

    setlocale( LC_ALL, "Russian");

    DoLabWork2();

    return 0;
}

/*
 * Заполнение массива. Рандом
 */
int* RandomArray (int* randArr) {

    srand(time(NULL));
    for (int i=0; i<SIZE_ARRAY; i++) {
        randArr[i] = (rand() % 199) - 99;
    }
    return randArr;
}

/*
 * Вывод созданного массива
 */
void PrintArray (int printArr[]) {

    for (int i=0; i<SIZE_ARRAY; i++) {
        cout << setw(8) << left << printArr[i];
    }
}

/*
 * Выполнение задачи 1
 * Вывод рандомного массива
 */
void DoTask1 () {
    cout << "Исходный массив:\n";
    PrintArray(RandomArray(globalArray));
    cout << "\n\n";
}

/*
 * Bubble sort (пузырьковая сортировка)
 */
int* BubbleSort (int* bubbleSortArr) {

    for (int i=0; i<SIZE_ARRAY-1; i++) {
        for (int j=0; j<SIZE_ARRAY-1; j++) {
            if (bubbleSortArr[j+1] < bubbleSortArr[j]){
                swap(bubbleSortArr[j], bubbleSortArr[j+1]);
            }
        }
    }
    return bubbleSortArr;
}

/*
 * Выполнение задачи 2
 * Вывод отсортированного массива + тайминг
 */
void DoTask2 () {
    cout << "Отсортированный массив:\n";
    system_clock::time_point start = system_clock::now();
    PrintArray(BubbleSort(globalArray));
    system_clock::time_point end = system_clock:: now();
    cout << "\n";
    duration<double> sec = end - start;
    cout << "Время затраченное на сортировку: " << sec.count() << "\n\n";
    cout << "\n\n";
}

/*
 * Нахождение МАКС в массиве
 */
int FindMax (int* findMaxArr) {

    int findMax=-99;
    for (int i=0; i<SIZE_ARRAY-1; i++){
        if (findMaxArr[i]>findMax) {
            findMax=findMaxArr[i];
        }
    }
    return findMax;
}

/*
 * Нахождение МАКС в неотсортированном массиве
 */
void FindMaxInRandomArray (int* findMaxRandArr) {

    system_clock::time_point start = system_clock::now();
    cout << "Максимум: " << FindMax(findMaxRandArr) << "\n";
    system_clock::time_point end = system_clock:: now();
    duration<double> sec = end - start;
    cout << "Время затраченное на поиск максимума в неотсортированном массиве: " << sec.count() << "\n\n";
}

/*
 * Нахождение МАКС в отсортированном массиве
 */
void FindMaxInSortArray (int* findMaxSortArr) {

    system_clock::time_point start = system_clock::now();
    cout << "Максимум: " << FindMax(findMaxSortArr) << "\n";
    system_clock::time_point end = system_clock:: now();
    duration<double> sec = end - start;
    cout << "Время затраченное на поиск максимума в отсортированном массиве: " << sec.count() << "\n\n";
}

/*
 * Нахождение МИН
 */
int FindMin (int* findMinArr) {

    int findMin=99;
    for (int i=0; i<SIZE_ARRAY-1; i++){
        if (findMinArr[i]<findMin) {
            findMin=findMinArr[i];
        }
    }
    return findMin;
}

/*
 * Нахождение МИН в неотсортированном массиве
 */
void FindMinInRandomArray (int* findMinRandArr) {

    system_clock::time_point start = system_clock::now();
    cout << "Минимум: " << FindMin(findMinRandArr) << "\n";
    system_clock::time_point end = system_clock:: now();
    duration<double> sec = end - start;
    cout << "Время затраченное на поиск минимума в неотсортированном массиве: " << sec.count() << "\n\n";
}

/*
 * Нахождение МИН в отсортированном массиве
 */
void FindMinInSortArray (int* findMinSortArr) {

    system_clock::time_point start = system_clock::now();
    cout << "Минимум: " << FindMin(findMinSortArr) << "\n";
    system_clock::time_point end = system_clock:: now();
    duration<double> sec = end - start;
    cout << "Время затраченное на поиск минимума в отсортированном массиве: " << sec.count() << "\n\n";
}

/*
 * Выполнение задачи 3
 * Поиск МАКС и МИН в неотсортированном и отсортированном массиве
 */
void DoTask3 () {

    cout << "***Задание 3***\n\n";
    cout << "Поиск max и min  в неотсортированном массиве: \n";
    FindMaxInRandomArray(RandomArray(globalArray));
    FindMinInRandomArray(RandomArray(globalArray));
    cout << "\n\n";
    cout << "Поиск max и min  в отсортированном массиве: \n";
    FindMaxInSortArray(BubbleSort(globalArray));
    FindMinInSortArray(BubbleSort(globalArray));
    cout << "***Конец Задание 3***\n\n";
    cout << "\n\n";
}

/*
 * Выполнение задачи 4
 * Среднее знач МАКС и МИН
 * Индексы элементов, значения которых равны среднему значению МАКС и МИН
 */
void DoTask4 (int* meanMaxMinArr) {

    cout << "***Задание 4***\n\n";
    int midMaxMin = round((FindMax(meanMaxMinArr)+FindMin(meanMaxMinArr))/2);
    cout << "Среднее значение Max и Min: " << midMaxMin << "\n";

    int countMean = 0;
    cout << "Индексы элементов, значения которых равны среднему значению Max и Min: ";
    for (int i=0; i<SIZE_ARRAY; i++) {
        if (meanMaxMinArr[i]==midMaxMin) {
            countMean++;
            cout << i << " ";
        }
    }
    cout << "\nКоличество элементов, значения которых равны среднему значению Max и Min: " << countMean << "\n\n";

    cout << "***Конец Задание 4***\n\n";
    cout << "\n\n";
}

/*
 * Выполнение задачи 5
 * Элементы меньше введенного числа
 */
void DoTask5 (int* lessThanArr) {

    cout << "***Задание 5***\n\n";

    int lessThan;
    cout << "Введите число a: ";
    cin >> lessThan;

    int countLessThan=0;
    for (int i=0; i<SIZE_ARRAY; i++) {
        if (lessThanArr[i]<lessThan) {
            countLessThan++;
        }
    }

    cout << "Количество элементов в отсортированном массиве, которые меньше числа a:  " << countLessThan <<"\n\n";

    cout << "***Конец Задание 5***\n\n";
    cout << "\n\n";
}

/*
 * Выполнение задачи 6
 * Элементы больше введенного числа
 */
void DoTask6 (int* moreThanArr) {

    cout << "***Задание 6***\n\n";

    int moreThan;
    cout << "Введите число b: ";
    cin >> moreThan;

    int countMoreThan=0;
    for (int i=0; i<SIZE_ARRAY; i++) {
        if (moreThanArr[i]>moreThan) {
            countMoreThan++;
        }
    }

    cout << "Количество элементов в отсортированном массиве, которые меньше числа a: " << countMoreThan <<"\n\n";

    cout << "***Конец Задание 6***\n\n";
    cout << "\n\n";
}

/*
 * Обмен месатми элементов, индексы которых введены
 */
void SwapIndex (int* swapIndexArr, int index1Copy, int index2Copy) {

    int t;
    for (int i=0; i<SIZE_ARRAY; i++) {
        if (i == index1Copy) {
            t=swapIndexArr[i];
            swapIndexArr[i]=swapIndexArr[index2Copy];
            swapIndexArr[index2Copy]=t;
        }
    }
    PrintArray(swapIndexArr);
}

/*
 * Выполнение задачи 8
 * Ввывод обмена месатми элементов, индексы которых введены, в отсортированном массиве + тайминг
 */
void DoTask8 () {

    cout << "***Задание 8***\n\n";

    int index1;
    int index2;
    cout << "Введите индексы элементов массива, которые хотите поменять местами: ";
    cin >> index1 >> index2;

    system_clock::time_point start = system_clock::now();
    SwapIndex(BubbleSort(globalArray), index1, index2);
    system_clock::time_point end = system_clock:: now();
    duration<double> sec = end - start;
    cout << "\n";
    cout << "Скорость обмена: " << sec.count() << "\n\n";

    cout << "***?***Конец Задание 8***\n\n";
    cout << "\n\n";
}

/*
 * Задачи Лабораторной работы 2
 */
int MenuTasks () {

    int numberTask;
    cout << "\n\n";
    cout << "***\n";
    cout << "Введите номер задачи:\n";
    cout << "1) Создать рандомно массив: \n";
    cout << "2) Отсортировать заданный массив: \n";
    cout << "3) Вывод максимального и минимального элемента массива\n";
    cout << "4) Вывод среднего значения максимального и минимального элемента массива \n";
    cout << "5) Количество, элементов, меньше числа a\n";
    cout << "6) Количество, элементов, больше числа b\n";
    cout << "7) Вывод информации о том, есть ли заданное число в массиве\n";
    cout << "8)  Поменять местами элементы, индексы которых заданы\n";

    while (true) {

        cin >> numberTask;
        if ( (numberTask > 0) && (numberTask <= 8) )
            break;
        else
            cout << "Error: Неверно введены данные  \n";
    }
    cout << "\n";
    return numberTask;
}

/*
 * Выбор выполнения задач лаборатной работы 2
 */
void DoTasks (int option) {

    switch (option) {
        case 1: {
            DoTask1();
            break;
        }
        case 2: {
            DoTask2();
            break;
        }
        case 3: {
            DoTask3();
            break;
        }
        case 4: {
            DoTask4 (BubbleSort(globalArray));
            break;
        }
        case 5: {
            DoTask5 (BubbleSort(globalArray));
            break;
        }
        case 6: {
            DoTask6 (BubbleSort(globalArray));
            break;
        }
        case 7: {
            DoTask7();
            break;
        }
        case 8: {
            DoTask8();
            break;
        }
    }
}

/*
 * Выполнение лаборатоной работы 2
 */
void DoLabWork2 () {

    while (true) {
        DoTasks(MenuTasks());
    }
}

/*
 * Выполнение задачи 7
 * Есть ли введенное пользователем число в массиве
 * Бинарный поиск и обычный поиск с таймингами
 */
void DoTask7 () {
    printQuickSort();

    int num;
    cout << "Введите число, которое хотите найти в массиве: ";
    cin >> num;


    TimeBinarySearch(num);
    TimeNormalSearch (num);

}

/*
 * Quick sort (быстрая сортировка)
 */
int* QuickSort (int* quickSortArr, int end, int begin) {

    int mid;
    int f = begin;
    int l = end;
    mid = quickSortArr[(f + l )/ 2];
    while (f < l)
    {
        while (quickSortArr[f] < mid) f++;
        while (quickSortArr[l]> mid) l--;
        if (f <= l)
        {
            swap(quickSortArr[f], quickSortArr[l]);
            f++;
            l--;
        }
    }
    if (begin < l) QuickSort(quickSortArr, l, begin);
    if (f < end) QuickSort(quickSortArr, end, f);

    return quickSortArr;
}

/*
 * Вывод массива после Quick sort + тайминг
 */
void printQuickSort () {

    cout << "Отсортированный массив:\n";
    system_clock::time_point start = system_clock::now();
    PrintArray(BubbleSort(QuickSort(globalArray, SIZE_ARRAY-1, 0)));
    system_clock::time_point end = system_clock:: now();
    cout << "\n";
    duration<double> sec = end - start;
    cout << "Время затраченное на сортировку Quick Sort:" << sec.count() << "\n\n";
    cout << "\n\n";
}

/*
 * Обычный поиск введенного пользователем числа в массиве
 */
bool NormalSearch (int* normalSearchArr,int number) {

    bool flag= false;
    for (int i=0; i<SIZE_ARRAY; i++) {
        if (normalSearchArr[i]==number) {
            flag= true;
        }
    }
    return flag;
}

/*
 * Тайминг бычного поиска введенного пользователем числа в массиве
 */
void TimeNormalSearch (int timeNum) {

    system_clock::time_point start = system_clock::now();
    PrintNumberSearch(NormalSearch(QuickSort(globalArray,SIZE_ARRAY, 0), timeNum));
    system_clock::time_point end = system_clock:: now();
    cout << "\n";
    duration<double> sec = end - start;
    cout << "Скорость работы обычного перебора:" << sec.count() << "\n\n";
    cout << "\n\n";
}

/*
 *Бинарный поиск введенного пользователем числа в массиве
 */
bool BinarySearch (int* binarySearchArr, int number2) {

    bool flag = false;
    int l = 0;
    int r = SIZE_ARRAY-1;
    int mid;

    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2;

        if (binarySearchArr[mid] == number2) {
            flag = true;
        }
        if (binarySearchArr[mid] > number2) {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return flag;
}

/*
 * Тайминг бинарного поиска введенного пользователем числа в массиве
 */
void TimeBinarySearch (int timeNum) {

    system_clock::time_point start = system_clock::now();
    PrintNumberSearch(BinarySearch(QuickSort(globalArray,SIZE_ARRAY, 0), timeNum));
    system_clock::time_point end = system_clock:: now();
    cout << "\n";
    duration<double> sec = end - start;
    cout << "Скорость работы бинарного поиска:" << sec.count() << "\n\n";
    cout << "\n\n";
}

/*
 * Вывод есть ли введенное пользователем число в массиве
 */
void PrintNumberSearch (bool flag) {

    if (flag) {
        cout << "Введенное число есть в массиве\n";
    }
    else cout << "Введенное число отсутствует в массиве\n";
}


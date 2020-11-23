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
 * ���������� �������. ������
 */
int* RandomArray (int* randArr) {

    srand(time(NULL));
    for (int i=0; i<SIZE_ARRAY; i++) {
        randArr[i] = (rand() % 199) - 99;
    }
    return randArr;
}

/*
 * ����� ���������� �������
 */
void PrintArray (int printArr[]) {

    for (int i=0; i<SIZE_ARRAY; i++) {
        cout << setw(8) << left << printArr[i];
    }
}

/*
 * ���������� ������ 1
 * ����� ���������� �������
 */
void DoTask1 () {
    cout << "�������� ������:\n";
    PrintArray(RandomArray(globalArray));
    cout << "\n\n";
}

/*
 * Bubble sort (����������� ����������)
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
 * ���������� ������ 2
 * ����� ���������������� ������� + �������
 */
void DoTask2 () {
    cout << "��������������� ������:\n";
    system_clock::time_point start = system_clock::now();
    PrintArray(BubbleSort(globalArray));
    system_clock::time_point end = system_clock:: now();
    cout << "\n";
    duration<double> sec = end - start;
    cout << "����� ����������� �� ����������: " << sec.count() << "\n\n";
    cout << "\n\n";
}

/*
 * ���������� ���� � �������
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
 * ���������� ���� � ����������������� �������
 */
void FindMaxInRandomArray (int* findMaxRandArr) {

    system_clock::time_point start = system_clock::now();
    cout << "��������: " << FindMax(findMaxRandArr) << "\n";
    system_clock::time_point end = system_clock:: now();
    duration<double> sec = end - start;
    cout << "����� ����������� �� ����� ��������� � ����������������� �������: " << sec.count() << "\n\n";
}

/*
 * ���������� ���� � ��������������� �������
 */
void FindMaxInSortArray (int* findMaxSortArr) {

    system_clock::time_point start = system_clock::now();
    cout << "��������: " << FindMax(findMaxSortArr) << "\n";
    system_clock::time_point end = system_clock:: now();
    duration<double> sec = end - start;
    cout << "����� ����������� �� ����� ��������� � ��������������� �������: " << sec.count() << "\n\n";
}

/*
 * ���������� ���
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
 * ���������� ��� � ����������������� �������
 */
void FindMinInRandomArray (int* findMinRandArr) {

    system_clock::time_point start = system_clock::now();
    cout << "�������: " << FindMin(findMinRandArr) << "\n";
    system_clock::time_point end = system_clock:: now();
    duration<double> sec = end - start;
    cout << "����� ����������� �� ����� �������� � ����������������� �������: " << sec.count() << "\n\n";
}

/*
 * ���������� ��� � ��������������� �������
 */
void FindMinInSortArray (int* findMinSortArr) {

    system_clock::time_point start = system_clock::now();
    cout << "�������: " << FindMin(findMinSortArr) << "\n";
    system_clock::time_point end = system_clock:: now();
    duration<double> sec = end - start;
    cout << "����� ����������� �� ����� �������� � ��������������� �������: " << sec.count() << "\n\n";
}

/*
 * ���������� ������ 3
 * ����� ���� � ��� � ����������������� � ��������������� �������
 */
void DoTask3 () {

    cout << "***������� 3***\n\n";
    cout << "����� max � min  � ����������������� �������: \n";
    FindMaxInRandomArray(RandomArray(globalArray));
    FindMinInRandomArray(RandomArray(globalArray));
    cout << "\n\n";
    cout << "����� max � min  � ��������������� �������: \n";
    FindMaxInSortArray(BubbleSort(globalArray));
    FindMinInSortArray(BubbleSort(globalArray));
    cout << "***����� ������� 3***\n\n";
    cout << "\n\n";
}

/*
 * ���������� ������ 4
 * ������� ���� ���� � ���
 * ������� ���������, �������� ������� ����� �������� �������� ���� � ���
 */
void DoTask4 (int* meanMaxMinArr) {

    cout << "***������� 4***\n\n";
    int midMaxMin = round((FindMax(meanMaxMinArr)+FindMin(meanMaxMinArr))/2);
    cout << "������� �������� Max � Min: " << midMaxMin << "\n";

    int countMean = 0;
    cout << "������� ���������, �������� ������� ����� �������� �������� Max � Min: ";
    for (int i=0; i<SIZE_ARRAY; i++) {
        if (meanMaxMinArr[i]==midMaxMin) {
            countMean++;
            cout << i << " ";
        }
    }
    cout << "\n���������� ���������, �������� ������� ����� �������� �������� Max � Min: " << countMean << "\n\n";

    cout << "***����� ������� 4***\n\n";
    cout << "\n\n";
}

/*
 * ���������� ������ 5
 * �������� ������ ���������� �����
 */
void DoTask5 (int* lessThanArr) {

    cout << "***������� 5***\n\n";

    int lessThan;
    cout << "������� ����� a: ";
    cin >> lessThan;

    int countLessThan=0;
    for (int i=0; i<SIZE_ARRAY; i++) {
        if (lessThanArr[i]<lessThan) {
            countLessThan++;
        }
    }

    cout << "���������� ��������� � ��������������� �������, ������� ������ ����� a:  " << countLessThan <<"\n\n";

    cout << "***����� ������� 5***\n\n";
    cout << "\n\n";
}

/*
 * ���������� ������ 6
 * �������� ������ ���������� �����
 */
void DoTask6 (int* moreThanArr) {

    cout << "***������� 6***\n\n";

    int moreThan;
    cout << "������� ����� b: ";
    cin >> moreThan;

    int countMoreThan=0;
    for (int i=0; i<SIZE_ARRAY; i++) {
        if (moreThanArr[i]>moreThan) {
            countMoreThan++;
        }
    }

    cout << "���������� ��������� � ��������������� �������, ������� ������ ����� a: " << countMoreThan <<"\n\n";

    cout << "***����� ������� 6***\n\n";
    cout << "\n\n";
}

/*
 * ����� ������� ���������, ������� ������� �������
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
 * ���������� ������ 8
 * ������ ������ ������� ���������, ������� ������� �������, � ��������������� ������� + �������
 */
void DoTask8 () {

    cout << "***������� 8***\n\n";

    int index1;
    int index2;
    cout << "������� ������� ��������� �������, ������� ������ �������� �������: ";
    cin >> index1 >> index2;

    system_clock::time_point start = system_clock::now();
    SwapIndex(BubbleSort(globalArray), index1, index2);
    system_clock::time_point end = system_clock:: now();
    duration<double> sec = end - start;
    cout << "\n";
    cout << "�������� ������: " << sec.count() << "\n\n";

    cout << "***?***����� ������� 8***\n\n";
    cout << "\n\n";
}

/*
 * ������ ������������ ������ 2
 */
int MenuTasks () {

    int numberTask;
    cout << "\n\n";
    cout << "***\n";
    cout << "������� ����� ������:\n";
    cout << "1) ������� �������� ������: \n";
    cout << "2) ������������� �������� ������: \n";
    cout << "3) ����� ������������� � ������������ �������� �������\n";
    cout << "4) ����� �������� �������� ������������� � ������������ �������� ������� \n";
    cout << "5) ����������, ���������, ������ ����� a\n";
    cout << "6) ����������, ���������, ������ ����� b\n";
    cout << "7) ����� ���������� � ���, ���� �� �������� ����� � �������\n";
    cout << "8)  �������� ������� ��������, ������� ������� ������\n";

    while (true) {

        cin >> numberTask;
        if ( (numberTask > 0) && (numberTask <= 8) )
            break;
        else
            cout << "Error: ������� ������� ������  \n";
    }
    cout << "\n";
    return numberTask;
}

/*
 * ����� ���������� ����� ���������� ������ 2
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
 * ���������� ����������� ������ 2
 */
void DoLabWork2 () {

    while (true) {
        DoTasks(MenuTasks());
    }
}

/*
 * ���������� ������ 7
 * ���� �� ��������� ������������� ����� � �������
 * �������� ����� � ������� ����� � ����������
 */
void DoTask7 () {
    printQuickSort();

    int num;
    cout << "������� �����, ������� ������ ����� � �������: ";
    cin >> num;


    TimeBinarySearch(num);
    TimeNormalSearch (num);

}

/*
 * Quick sort (������� ����������)
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
 * ����� ������� ����� Quick sort + �������
 */
void printQuickSort () {

    cout << "��������������� ������:\n";
    system_clock::time_point start = system_clock::now();
    PrintArray(BubbleSort(QuickSort(globalArray, SIZE_ARRAY-1, 0)));
    system_clock::time_point end = system_clock:: now();
    cout << "\n";
    duration<double> sec = end - start;
    cout << "����� ����������� �� ���������� Quick Sort:" << sec.count() << "\n\n";
    cout << "\n\n";
}

/*
 * ������� ����� ���������� ������������� ����� � �������
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
 * ������� ������� ������ ���������� ������������� ����� � �������
 */
void TimeNormalSearch (int timeNum) {

    system_clock::time_point start = system_clock::now();
    PrintNumberSearch(NormalSearch(QuickSort(globalArray,SIZE_ARRAY, 0), timeNum));
    system_clock::time_point end = system_clock:: now();
    cout << "\n";
    duration<double> sec = end - start;
    cout << "�������� ������ �������� ��������:" << sec.count() << "\n\n";
    cout << "\n\n";
}

/*
 *�������� ����� ���������� ������������� ����� � �������
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
 * ������� ��������� ������ ���������� ������������� ����� � �������
 */
void TimeBinarySearch (int timeNum) {

    system_clock::time_point start = system_clock::now();
    PrintNumberSearch(BinarySearch(QuickSort(globalArray,SIZE_ARRAY, 0), timeNum));
    system_clock::time_point end = system_clock:: now();
    cout << "\n";
    duration<double> sec = end - start;
    cout << "�������� ������ ��������� ������:" << sec.count() << "\n\n";
    cout << "\n\n";
}

/*
 * ����� ���� �� ��������� ������������� ����� � �������
 */
void PrintNumberSearch (bool flag) {

    if (flag) {
        cout << "��������� ����� ���� � �������\n";
    }
    else cout << "��������� ����� ����������� � �������\n";
}


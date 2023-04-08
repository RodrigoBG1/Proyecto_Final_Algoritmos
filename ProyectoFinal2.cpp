#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Bubble sort (con interruptor)
void BubbleSort(int vector[], int n){
    int i, j, aux;
    bool interruptor = true;

    for (i = 0; i < n && interruptor; i++){
        interruptor = false;
        for (j = 0; j < n-1; j++){
            if (vector[j] > vector[j+1]){
                interruptor = true;
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
    for (i = 0; i < n; i++)
        cout << vector[i] << " ";
    cout << "\n";
}

//Selection sort
void SelectionSort(int vector[], int n){
    int i, j, aux, min;

    for (i = 0; i < n-1; i++){
        min = i;
        for(j = i+1; j < n; j++){
            if (vector[j] < vector[min])
                min = j;
        }
        aux = vector[i];
        vector[i] = vector[min];
        vector[min] = aux;
    }
    for (i = 0; i < n; i++)
        cout << vector[i] << " ";
    cout << "\n";
}

//Insertion sort
void InsertionSort(int vector[], int n){
    int i, aux, pos;

    for (i = 1; i < n; i++){
        pos = i;
        aux = vector[i];

        while ((pos > 0) && vector[pos - 1] > aux){
            vector[pos] = vector[pos -1];
            pos--;
        }
        vector[pos] = aux;
    }
    for (i = 0; i < n; i++)
        cout << vector[i] << " ";
    cout << "\n";
}

//Counting sort
void countingSort(int vector[], int n)
{
    int maxVal = *max_element(vector, vector + n);
    int minVal = *min_element(vector, vector + n);

    int cuenta[maxVal - minVal + 1] = {0}; // inicializamos todos los elementos en cero

    for (int i = 0; i < n; i++)
    {
        cuenta[vector[i] - minVal]++; // incrementa la cuenta de con cada siguiente elemento
    }

    for (int i = 1; i <= maxVal - minVal; i++)
    {
        cuenta[i] += cuenta[i - 1]; // acumula el conteo para obtener la cposición correcta de cadad elemento
    }

    int ordenado[n];
    for (int i = n - 1; i >= 0; i--)
    {
        ordenado[--cuenta[vector[i] - minVal]] = vector[i]; // ubica cada elemento en su posición correcta en el arreglo acomodado
    }

    for (int i = 0; i < n; i++)
    {
        vector[i] = ordenado[i]; // copia el areglo ordenado en el arreglo original
    }
        for (int i = 0; i < n; i++)
            cout << vector[i] << " ";
        cout << "\n";
}

//Shell sort
void shellSort(int vector[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = vector[i];
            int j;
            for (j = i; j >= gap && vector[j - gap] > temp; j -= gap){
                vector[j] = vector[j - gap];
            }
            vector[j] = temp;
        }
    }
    for (int i = 0; i < n; i++)
        cout << vector[i] << " ";
    cout << "\n";
}
//Quick sort
int partition(int vector[], int start, int end)
{
    int pivot = vector[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (vector[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(vector[pivotIndex], vector[start]);
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (vector[i] <= pivot) {
            i++;
        }

        while (vector[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(vector[i++], vector[j--]);
        }
    }
    return pivotIndex;
}

//Quick sort
void quickSort(int vector[], int start, int end)
{
    if (start >= end)
        return;
    int p = partition(vector, start, end);
    quickSort(vector, start, p - 1);
    quickSort(vector, p + 1, end);
}


int main (){
    int vector[20];
    srand(time(NULL));
    for (int i = 0; i < 20; i++){
        vector[i] = rand() % 16;
        cout << vector[i] << " ";
    }
    cout << "\n\n";
    
    unsigned t0, t1;
    double time;

    cout << "Bubble sort: ";
    t0 = clock();
    BubbleSort(vector, 20);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    printf("Tiempo de ordenacion: %f\n", time);

    cout << "Selection sort: ";
    t0 = clock();
    SelectionSort(vector, 20);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    printf("Tiempo de ordenacion: %f\n", time);

    cout << "Insertion sort: ";
    t0 = clock();
    InsertionSort(vector, 20);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    printf("Tiempo de ordenacion: %f\n", time);
    
    //Counting sort
    cout << "Counting sort: ";
    t0 = clock();
    countingSort(vector, 20);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    printf("Tiempo de ordenacion: %f\n", time);

    //Shell sort
    cout << "Shell sort: ";
    t0 = clock();
    shellSort(vector, 20);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    printf("Tiempo de ordenacion: %f\n", time);

    //Quick sort
    cout << "Quick sort: ";
    t0 = clock();
    quickSort(vector, 0, 19);
    for (int i = 0; i < 20; i++) {
        cout << vector[i] << " ";
    }
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    printf("Tiempo de ordenacion: %f\n", time);

    return 0;
}

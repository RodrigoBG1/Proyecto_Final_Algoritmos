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
    

    return 0;
}
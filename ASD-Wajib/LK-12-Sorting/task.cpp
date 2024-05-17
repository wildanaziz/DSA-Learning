#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip> // Library for setting width of output
using namespace std;

int* generate_random_int(int n) {
    int* data = new int[n];
    for (int i = 0; i < n; i++) {
        data[i] = rand();
    }
    return data;
}

bool is_sorted(int* data, int n) {
    for (int i = 1; i < n; i++) {
        if (data[i - 1] > data[i]) {
            return false;
        }
    }
    return true;
}

void bubbleSort(int x[], int j, int option) {
    int temp;
    switch(option) {
        case 1: // Descending order
            for (int i = 0; i < j; i++) {
                for (int k = 0; k < j - 1; k++) {
                    if (x[k] < x[k + 1]) {
                        temp = x[k];
                        x[k] = x[k + 1];
                        x[k + 1] = temp;
                    }
                }
            }
            break;
        case 2: // Ascending order
            for (int i = 0; i < j; i++) {
                for (int k = 0; k < j - 1; k++) {
                    if (x[k] > x[k + 1]) {
                        temp = x[k];
                        x[k] = x[k + 1];
                        x[k + 1] = temp;
                    }
                }
            }
            break;
    }
}

void insertionSort(int x[], int j, int option){
    int temp;
    
    //sorting
    switch(option){
        case 1:
            for(int i=1; i<j; i++){
                for(int k=i; k>0; k--){
                    if(x[k] > x[k-1]){
                        temp = x[k];
                        x[k] = x[k-1];
                        x[k-1] = temp;
                    }
                }
            }
            break;
        case 2:
            for(int i=1; i<j; i++){
                for(int k=i; k>0; k--){
                    if(x[k] < x[k-1]){
                        temp = x[k];
                        x[k] = x[k-1];
                        x[k-1] = temp;
                    }
                }
            }
            break;
    }
    
}

void selectionSort(int x[], int j, int option){
    int temp;
    int pos;
    int rand;

    switch (option)
    {
    case 1:
        for (int i = 0; i < j; i++)
        {
        temp = x[i];
        pos = i;
        for (int k = i; k < j; k++)
        {
            if (x[k] > temp)
            {
                temp = x[k];
                pos = k;
                rand++;
            }

            if (rand == 0)
            {
                break;
            }
        }

        x[pos] = x[i];
        x[i] = temp;

        }
    
        break;
    
    case 2:
        for (int i = 0; i < j; i++)
        {
        temp = x[i];
        pos = i;
        for (int k = i; k < j; k++)
        {
            if (x[k] < temp)
            {
                temp = x[k];
                pos = k;
            }
            
        }

        x[pos] = x[i];
        x[i] = temp;

        }
    
        break;
    }
        
}

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int* l = new int[n1];
    int* m = new int[n2];

    for (int i = 0; i < n1; i++) {
        l[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        m[j] = arr[q + 1 + j];
    }

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (l[i] <= m[j]) {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = m[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = l[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = m[j];
        j++;
        k++;
    }

    delete[] l;
    delete[] m;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int partition(int array[], int low, int high){
    // membuat pivot
    int pivot = array[high];
    int x = low-1;

    for(int y = low; y < high; y++){
        if(array[y] < pivot){
            x++;
            swap(array[x], array[y]);
        }
    }

    swap(array[x+1], array[high]);
    return x+1;
}

void quick_sort(int array[], int low, int high){
    if (low < high){
        int array_partition = partition(array, low, high);

        //rekursif quick sort bagian kiri
        quick_sort(array, low, array_partition-1);

        //rekursif quick sort bagian kanan
        quick_sort(array, array_partition+1, high);
    }
}

void sort(int* data, int n, int option, int algorithm) {
    if (algorithm == 1) {
        bubbleSort(data, n, option);
    } else if (algorithm == 2) {
        insertionSort(data, n, option);
    } else if (algorithm == 3) {
        selectionSort(data, n, option);
    } else if (algorithm == 4) {
        mergeSort(data, 0, n - 1);
    } else if (algorithm == 5){
        quick_sort(data, 0, n-1);
    }
}


int main() {
    int num_of_experiments = 100;
    int* data;
    int n;

    cout << "--bubble sort--" << "                    " << "--insertion sort--" << "                    " << "--selection sort--" << "                    " << "--merge sort--" << "                    " << "--quick sort--" << endl;
    cout << setw(15) << "data, time (ms)" << "                    " << setw(15) << "data, time (ms)" << "                    " << setw(18) << "data, time (ms)" << "                    " << setw(18) << "data, time (ms)" << "                    " << setw(7) << "data, time (ms)" << endl;

    for (int i = 1; i <= num_of_experiments; i++) {
        n = i * 1000;

        // Bubble Sort
        data = generate_random_int(n);
        auto start = chrono::high_resolution_clock::now();
        sort(data, n, 2, 1); // sort ascending using bubble sort
        auto stop = chrono::high_resolution_clock::now();
        auto duration_bubble = chrono::duration_cast<chrono::milliseconds>(stop - start);
        delete[] data;

        // Insertion Sort
        data = generate_random_int(n);
        start = chrono::high_resolution_clock::now();
        sort(data, n, 2, 2); // sort ascending using insertion sort
        stop = chrono::high_resolution_clock::now();
        auto duration_insertion = chrono::duration_cast<chrono::milliseconds>(stop - start);
        delete[] data;

        // Selection Sort
        data = generate_random_int(n);
        start = chrono::high_resolution_clock::now();
        sort(data, n, 2, 3); // sort ascending using selection sort
        stop = chrono::high_resolution_clock::now();
        auto duration_selection = chrono::duration_cast<chrono::milliseconds>(stop - start);
        delete[] data;

        // Merge Sort
        data = generate_random_int(n);
        start = chrono::high_resolution_clock::now();
        sort(data, n, 2, 4); // sort ascending using merge sort
        stop = chrono::high_resolution_clock::now();
        auto duration_merge = chrono::duration_cast<chrono::milliseconds>(stop - start);
        delete[] data;

        // Quick Sort
        data = generate_random_int(n);
        start = chrono::high_resolution_clock::now();
        sort(data, n, 2, 5); // sort ascending using merge sort
        stop = chrono::high_resolution_clock::now();
        auto duration_quick = chrono::duration_cast<chrono::milliseconds>(stop - start);
        delete[] data;

        // Print the results in formatted columns
        cout << setw(7) << n << ", " << setw(4) << duration_bubble.count();
        cout << "                    ";
        cout << setw(7) << n << ", " << setw(4) << duration_insertion.count();
        cout << "                    ";
        cout << setw(11) << n << ", " << setw(4) << duration_selection.count();
        cout << "                    ";
        cout << setw(12) << n << ", " << setw(4) << duration_merge.count();
        cout << "                    ";
        cout << setw(8) << n << ", " << setw(4) << duration_quick.count() << endl;
    }

    return 0;
}

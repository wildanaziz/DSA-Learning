/* ASD Kelompok 5 Queue
Anggota:
1. Hanna Lailatul Islamiyah (235150301111024)
2. Nisrina Indriani Jatmiko (235150307111022)
3. Wildan Aziz Hidayat (235150301111028)
*/

#include <iostream>

void insertionSort(int x[], int j, int option);
void printArr(int x[], int j);
void selectionSort(int x[], int j, int option);

int main() {
    int optOrder;
    int optSort;
    int d = 1;
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int x[size];

    for (int i = 0; i < size; i++) {
        std::cout << "Enter " << d++ << " elements of the array: ";
        std::cin >> x[i];
    }
    
    printArr(x, size);
    
    std::cout << "Choose sort" << std::endl;
    std::cout << "\n1. Insertion Sort\n2. Selection Sort\nYour option [1-3]: ";
    std::cin >> optSort;

    enum {INSERT = 1, SELECTION};
    switch (optSort)
    {
    
    case INSERT:
        std::cout << "\n\nChoose your option\n1. Descending order\n2. Ascending order\nYour Option [1-2]: ";
        std::cin >> optOrder;
        insertionSort(x, size, optOrder);
        break;
    
    case SELECTION:
        std::cout << "\n\nChoose your option\n1. Descending order\n2. Ascending order\nYour Option [1-2]: ";
        std::cin >> optOrder;
        selectionSort(x, size, optOrder);
        break;

    default:

        std::cout << "your input doesnt match" << std::endl;
        break;
    }
}

void printArr(int x[], int j){
    std::cout << "Show: ";
    for (int i = 0; i < j; i++) {
        std::cout << x[i] << " ";
    }
}

void insertionSort(int x[], int j, int option) {
    int temp, shifts = 0, comparisons = 0;

    switch (option) {
        case 1: // Descending order
            for (int i = 1; i < j; i++) {
                for (int k = i; k > 0 && x[k] > x[k - 1]; k--) {
                    comparisons++;
                    temp = x[k];
                    x[k] = x[k - 1];
                    x[k - 1] = temp;
                    shifts++;
                }
                if (i > 1 && x[i - 1] <= x[i]) comparisons++;

                std::cout << "Step " << i << ": ";
                for (int a = 0; a < j; a++) {
                    std::cout << x[a] << " ";
                }
                std::cout << std::endl;
            }
            break;

        case 2: // Ascending order
            for (int i = 1; i < j; i++) {
                for (int k = i; k > 0 && x[k] < x[k - 1]; k--) {
                    comparisons++;
                    temp = x[k];
                    x[k] = x[k - 1];
                    x[k - 1] = temp;
                    shifts++;
                }
                if (i > 1 && x[i - 1] >= x[i]) comparisons++;

                std::cout << "Step " << i << ": ";
                for (int a = 0; a < j; a++) {
                    std::cout << x[a] << " ";
                }
                std::cout << std::endl;
            }
            break;
    }

    std::cout << "<------------------>" << std::endl;
    std::cout << "Comparisons: " << comparisons << ", Shifts: " << shifts << std::endl;
    std::cout << "Result: ";
    for (int a = 0; a < j; a++) {
        std::cout << x[a] << " ";
    }
}


void selectionSort(int x[], int j, int option) {
    int temp, pos, comparisons = 0, swaps = 0;

    switch (option) {
        case 1: // Descending order
            for (int i = 0; i < j - 1; i++) {
                temp = x[i];
                pos = i;
                for (int k = i + 1; k < j; k++) {
                    comparisons++;
                    if (x[k] > temp) {
                        temp = x[k];
                        pos = k;
                    }
                }
                if (pos != i) {
                    x[pos] = x[i];
                    x[i] = temp;
                    swaps++;
                }
                std::cout << "Step " << i + 1 << ": ";
                for (int a = 0; a < j; a++) {
                    std::cout << x[a] << " ";
                }
                std::cout << std::endl;
            }
            break;

        case 2: // Ascending order
            for (int i = 0; i < j - 1; i++) {
                temp = x[i];
                pos = i;
                for (int k = i + 1; k < j; k++) {
                    comparisons++;
                    if (x[k] < temp) {
                        temp = x[k];
                        pos = k;
                    }
                }
                if (pos != i) {
                    x[pos] = x[i];
                    x[i] = temp;
                    swaps++;
                }
                std::cout << "Step " << i + 1 << ": ";
                for (int a = 0; a < j; a++) {
                    std::cout << x[a] << " ";
                }
                std::cout << std::endl;
            }
            break;
    }

    std::cout << "<------------------>" << std::endl;
    std::cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << std::endl;
    std::cout << "Result: ";
    for (int n = 0; n < j; n++) {
        std::cout << x[n] << " ";
    }
}

#include <iostream>
using namespace std; 

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//=======================================
int partition(int arr[], int low, int high, int pass, int &comps) {
    int pivot = arr[high];

    for (int j = 0; j < pass; j++) {
        cout << "\t";
    }
    cout << "pivot = " << pivot << ": ";
    printArray(arr + low, high - low + 1);

    int i = low - 1;
    int j = low;
    int temp;
    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            if (i != j) {
                if ((high - low) + 1 == 8) {
                    cout << "i = " << i << ", j = " << j << ", ";
                }
                for (int j = 0; j < pass; j++) {
                    cout << "\t";
                }
                cout << "pivot = " << pivot << ": ";
                printArray(arr + low, high - low + 1);
            }
        }
        comps++;
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    if ((i + 1) != high) {
        if ((high - low) + 1 == 8) {
            cout << "i = " << i << ", j = " << j << ", ";
        }
        for (int j = 0; j < pass; j++) {
            cout << "\t";
        }
        cout << "pivot = " << pivot << ": ";
        printArray(arr + low, high - low + 1);
    }
    return i + 1;
}
//=======================================
void quickSort(int arr[], int low, int high, int pass, int &comps) {
    if (low < high) {
        int p = partition(arr, low, high, pass, comps);
        pass++;
        quickSort(arr, low, p - 1, pass, comps);
        quickSort(arr, p + 1, high, pass, comps);
    }
}
//=======================================
int main() {
    int arr[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int pass = 0;
    int comps = 0;
    std::cout << "=== Run 1: original array A ===" << endl;
    cout << "Original: ";
    printArray(arr, n);
    quickSort(arr, 0, 7, pass, comps);
    cout << "Sorted: ";
    printArray(arr, n);
    cout << "Comparisons: " << comps << endl;
    cout << endl;
    
    std::cout << "=== Run 2: already sorted copy of A ===" << endl;
    pass = 0;
    comps = 0;
    cout << "Original: ";
    printArray(arr, n);
    quickSort(arr, 0, 7, pass, comps);
    cout << "Sorted: ";
    printArray(arr, n);
    cout << "Comparisons: " << comps << endl;
    cout << endl;

    std::cout << "=== Run 3: reverse sorted copy of A ===" << endl;
    int revArr[] = {62, 34, 32, 23, 19, 14, 7, 5};
    pass = 0;
    comps = 0;
    cout << "Original: ";
    printArray(revArr, n);
    quickSort(revArr, 0, 7, pass, comps);
    cout << "Sorted: ";
    printArray(revArr, n);
    cout << "Comparisons: " << comps << endl;
    return 0;
}
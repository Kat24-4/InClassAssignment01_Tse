#include <iostream>
#include <algorithm>
using namespace std; 

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//=======================================
void merge(int arr[], int low, int mid, int high, int &comps, int &final) {
    int L[mid - low + 1];
    for (int l = 0; l < (mid - low + 1); l++) {
        L[l] = arr[low + l];
    }

    int R[high - mid];
    for (int r = 0; r < (high - mid); r++) {
        R[r] = arr[mid + 1 + r];
    }

    int i = 0, j = 0, k = low; 
    while ((i < (mid - low + 1)) && (j < (high - mid))) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        comps++;
        if ((high - low + 1) == 8) {
            final++;
        }
    }
    while (i < (mid - low + 1)) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < (high - mid)) {
        arr[k] = R[j];
        j++;
        k++;
    }
    cout << "merged: "; 
    printArray(arr + low, high - low + 1);
}
//=======================================
void mergeSort(int arr[], int low, int high, int &comps, int &final) {
    if (low < high) {
        int mid = (low + high) / 2;

        cout << "split: "; 
        printArray(arr + low, mid - low + 1);
        mergeSort(arr, low, mid, comps, final);
        
        cout << "split: "; 
        printArray(arr + mid + 1, high - mid);
        mergeSort(arr, mid + 1, high, comps, final);
        
        merge(arr, low , mid, high, comps, final);
    }
}
//=======================================
int main() {
    int arr[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int comps = 0;
    int finalComps = 0;

    std::cout << "=== Run 1: original array A ===" << endl;
    cout << "Original: ";
    printArray(arr, n);
    mergeSort(arr, 0, n - 1, comps, finalComps);
    cout << "Sorted: ";
    printArray(arr, n);
    cout << "Comparisons: " << comps << " (final merge: " << finalComps << ")" << endl; 
    cout << endl;

    comps = 0;
    finalComps = 0;
    std::cout << "=== Run 2: already sorted copy of A ===" << endl;
    cout << "Original: ";
    printArray(arr, n);
    mergeSort(arr, 0, n - 1, comps, finalComps);
    cout << "Sorted: ";
    printArray(arr, n);
    cout << "Comparisons: " << comps << " (final merge: " << finalComps << ")" << endl;
    cout << endl;

    comps = 0;
    finalComps = 0;
    std::cout << "=== Run 3: reverse sorted array A ===" << endl;
    int reversed[] = {62, 34, 32, 23, 19, 14, 7, 5};
    cout << "Original: ";
    printArray(reversed, n);
    mergeSort(reversed, 0, n - 1, comps, finalComps);
    cout << "Sorted: ";
    printArray(reversed, n);
    cout << "Comparisons: " << comps << " (final merge: " << finalComps << ")" << endl;

    return 0;
}
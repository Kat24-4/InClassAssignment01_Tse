#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//=======================================
void insertSort(int arr[], int n, int &comps, int &shifts) {
    cout << "Original: ";
    printArray(arr, n);
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comps++;
            shifts++;
        }
        if (!(j < 0)) {
            comps++;
        }
        arr[j + 1] = key; 
        cout << "i = " << i << ", key = " << key << ": ";
        printArray(arr, n);
    }
    cout << "Sorted: ";
    printArray(arr, n);
}
//=======================================
int main() {
    int arr[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int comps = 0;
    int shifts = 0;
    std::cout << "=== Run 1: original array A ===" << endl;
    insertSort(arr, n, comps, shifts);
    cout << "Comparisons: " << comps << " | Shifts: " << shifts << endl;
    std::cout << endl;

    comps = 0;
    shifts = 0;
    std::cout << "=== Run 2: fewest shifts ===" << endl;
    insertSort(arr, n, comps, shifts);
    cout << "Comparisons: " << comps << " | Shifts: " << shifts << endl;
    std::cout << endl;

    comps = 0;
    shifts = 0;
    int maxArr[] = {62, 34, 32, 23, 19, 14, 7, 5};
    std::cout << "=== Run 3: most shifts ===" << endl;
    insertSort(maxArr, n, comps, shifts);
    cout << "Comparisons: " << comps << " | Shifts: " << shifts << endl;

    return 0;
}
#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//=======================================
void selectSort(int arr[], int n, int &comps, int &swaps) {
    cout << "Original: ";
    printArray(arr, n);
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
            comps++;
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            swaps++;
        }
        cout << "Pass " << i + 1 << ": min = " << arr[i] << " at index " << minIdx << " -> ";
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
    int swaps = 0;
    std::cout << "=== Run 1: original array A ===" << endl;
    selectSort(arr, n, comps, swaps);
    cout << "Comparisons: " << comps << " | Swaps: " << swaps << endl;
    cout << endl;

    comps = 0;
    swaps = 0;
    std::cout << "=== Run 2: already sorted array A ===" << endl;
    selectSort(arr, n, comps, swaps);
    cout << "Comparisons: " << comps << " | Swaps: " << swaps << endl;
    cout << endl;

    comps = 0;
    swaps = 0;
    int revArr[] = {62, 34, 32, 23, 19, 14, 7, 5};
    std::cout << "=== Run 3: reverse sorted array A ===" << endl;
    selectSort(revArr, n, comps, swaps);
    cout << "Comparisons: " << comps << " | Swaps: " << swaps << endl;
    return 0;
}
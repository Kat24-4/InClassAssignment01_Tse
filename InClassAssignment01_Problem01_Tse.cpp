#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//=======================================
void bubbleSort(int arr[], int n, int &comps, int &swaps) {
    cout << "Original: ";
    printArray(arr, n);
    int pass;
    
    for (pass = 0; pass < n - 1 ; pass++) {
        bool swapped = false;
        for (int i = 0; i < n - pass - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true; 
                swaps++;
            }
            comps++;
        }
        cout << "Pass " << (pass + 1) << ": ";
        printArray(arr, n);
        if (swapped == false) {
            cout << "Sorted: ";
            printArray(arr, n);
            cout << "Passes: " << pass + 1;
            break;
        }
    }

    if (pass == n - 1) {
        cout << "Passes: " << pass;
    }
}
//=======================================
int main() {
    int arr[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int comps = 0, swaps = 0;
    std::cout << "=== Run 1: original array A ===" << endl;
    bubbleSort(arr, n, comps, swaps);
    cout << " | Comparisons: " << comps << " | Swaps: " << swaps << endl;
    std::cout << endl;
    
    comps = 0;
    swaps = 0;
    std::cout << "=== Run 2: already sorted copy of A ===" << endl;
    bubbleSort(arr, n, comps, swaps);
    cout << " | Comparisons: " << comps << " | Swaps: " << swaps << endl;
    cout << endl;

    int revArr[] = {62, 34, 32, 23, 19, 14, 7, 5};
    comps = 0;
    swaps = 0;
    std::cout << "=== Run 3: reverse sorted copy of A ===" << endl;
    bubbleSort(revArr, n, comps, swaps);
    cout << " | Comparisons: " << comps << " | Swaps: " << swaps << endl;
    return 0;
}
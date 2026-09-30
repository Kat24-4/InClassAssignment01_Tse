#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
//=======================================
void siftDown(int arr[], int root, int size, int &swaps, int &comps) {
    int child;
    int temp;
    while(2 * root + 1 < size) {
        child = 2 * root + 1;
        if ((child + 1 < size) && (arr[child + 1] > arr[child])) {
            child = child + 1; 
        }
        comps++;
        if (arr[root] >= arr[child]) {
            break;
        }
        comps++;
        temp = arr[root];
        arr[root] = arr[child];
        arr[child] = temp;
        root = child; 
        swaps++;
    }
}
//=======================================
void heapSort(int arr[], int n, int &swaps, int &comps) {
    int temp;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        siftDown(arr, i, n, swaps, comps);
    }
    cout << "Heap: ";
    printArray(arr, n);
    cout << endl;
    for (int end = n - 1; end >= 1; end--) {
        temp = arr[0];
        arr[0] = arr[end];
        arr[end] = temp;
        siftDown(arr, 0, end, swaps, comps);

        cout << "end = " << end << ":\theap: ";
        printArray(arr, end);
        cout << "\tsorted: ";
        printArray(arr + end, n - end);
        cout << endl; 
    }
}
//=======================================
int main() {
    int arr[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int swaps = 0; 
    int comps = 0;
    
    std::cout << "=== Run 1: original array A ===" << endl;
    cout << "Original: ";
    printArray(arr, n);
    cout << endl;
    heapSort(arr, n, swaps, comps);
    cout << "Sorted: ";
    printArray(arr, n);
    cout << endl;
    cout << "Swaps in siftDown: " << swaps << " | Comparisons: " << comps << endl; 
    cout << endl;

    swaps = 0;
    comps = 0;
    std::cout << "=== Run 2: array with duplicate value ===" << endl;
    int dupArr[] = {34, 7, 23, 34, 5, 62, 14, 19};
    cout << "Original: ";
    printArray(dupArr, n);
    cout << endl;
    heapSort(dupArr, n, swaps, comps);
    cout << "Sorted: ";
    printArray(dupArr, n);
    cout << endl;
    cout << "Swaps in siftDown: " << swaps << " | Comparisons: " << comps << endl; 
    cout << endl;

    swaps = 0;
    comps = 0;
    std::cout << "=== Run 3: sorted array A ===" << endl;
    cout << "Original: ";
    printArray(arr, n);
    cout << endl;
    heapSort(arr, n, swaps, comps);
    cout << "Sorted: ";
    printArray(arr, n);
    cout << endl;
    cout << "Swaps in siftDown: " << swaps << " | Comparisons: " << comps << endl; 
    cout << endl;

    int revArr[] = {62, 34, 32, 23, 19, 14, 7, 5};
    swaps = 0;
    comps = 0;
    std::cout << "=== Run 4: reverse array A ===" << endl;
    cout << "Original: ";
    printArray(revArr, n);
    cout << endl;
    heapSort(revArr, n, swaps, comps);
    cout << "Sorted: ";
    printArray(revArr, n);
    cout << endl;
    cout << "Swaps in siftDown: " << swaps << " | Comparisons: " << comps << endl; 
    return 0;
}
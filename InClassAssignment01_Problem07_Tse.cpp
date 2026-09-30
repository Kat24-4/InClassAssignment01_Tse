#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>

using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//=======================================
void bubbleSort(int arr[], int n) {
    int pass;
    
    for (pass = 0; pass < n - 1 ; pass++) {
        bool swapped = false;
        for (int i = 0; i < n - pass - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true; 
            }
        }
        if (swapped == false) {
            break;
        }
    }
}
//=======================================
void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; 
    }
}
//=======================================
void selectSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}
//=======================================
int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = low - 1;
    int j = low;
    int temp;
    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
//=======================================
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
//=======================================
void merge(int arr[], int low, int mid, int high) {
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
}
//=======================================
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);      
        mergeSort(arr, mid + 1, high);        
        merge(arr, low , mid, high);
    }
}
//=======================================
void siftDown(int arr[], int root, int size) {
    int child;
    int temp;
    while(2 * root + 1 < size) {
        child = 2 * root + 1;
        if ((child + 1 < size) && (arr[child + 1] > arr[child])) {
            child = child + 1; 
        }
        if (arr[root] >= arr[child]) {
            break;
        }
        temp = arr[root];
        arr[root] = arr[child];
        arr[child] = temp;
        root = child; 
    }
}
//=======================================
void heapSort(int arr[], int n) {
    int temp;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        siftDown(arr, i, n);
    }

    for (int end = n - 1; end >= 1; end--) {
        temp = arr[0];
        arr[0] = arr[end];
        arr[end] = temp;
        siftDown(arr, 0, end);
    }
}
//=======================================
int main() {
    srand(time(0));

    int size = 10000; //update to test various sized array
    int generated[size];

    for (int i = 0; i < size; i++) {
        generated[i] = rand() % 100000 + 1;
    }

    int bubble1[size];
    int insert1[size];
    int select1[size];
    int quick1[size];
    int merge1[size];
    int heap1[size];

    std::copy(generated, generated + size, bubble1);
    std::copy(generated, generated + size, insert1);
    std::copy(generated, generated + size, select1);
    std::copy(generated, generated + size, quick1);
    std::copy(generated, generated + size, merge1);
    std::copy(generated, generated + size, heap1);

    std::cout << "=== Sorting " << size << " items ===" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(bubble1, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Bubble Sort: " << duration.count() << " ms -> ";
    printArray(bubble1, 10);
    
    start = std::chrono::high_resolution_clock::now();
    insertSort(insert1, size);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Insertion Sort: " << duration.count() << " ms -> ";
    printArray(insert1, 10);
    
    start = std::chrono::high_resolution_clock::now();
    selectSort(select1, size);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Selection Sort: " << duration.count() << " ms -> ";
    printArray(select1, 10);
    
    start = std::chrono::high_resolution_clock::now();
    quickSort(quick1, 0, size - 1);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Quick Sort: " << duration.count() << " ms -> ";
    printArray(quick1, 10);
    
    start = std::chrono::high_resolution_clock::now();
    mergeSort(merge1, 0, size - 1);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Merge Sort: " << duration.count() << " ms -> ";
    printArray(merge1, 10);
    
    start = std::chrono::high_resolution_clock::now();
    heapSort(heap1, size);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Heap Sort: " << duration.count() << " ms -> ";
    printArray(heap1, 10);
}
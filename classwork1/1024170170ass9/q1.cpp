#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int>& arr, int n, int i, bool isMaxHeap) {
    int extreme = i;           
    int left = 2 * i + 1;      
    int right = 2 * i + 2;     
    if (left < n && ((isMaxHeap && arr[left] > arr[extreme]) || (!isMaxHeap && arr[left] < arr[extreme])))
        extreme = left;
    if (right < n && ((isMaxHeap && arr[right] > arr[extreme]) || (!isMaxHeap && arr[right] < arr[extreme])))
        extreme = right;
    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, isMaxHeap);
    }
}
void heapSort(vector<int>& arr, bool increasingOrder = true) {
    int n = arr.size();
    bool isMaxHeap = increasingOrder;  
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0, isMaxHeap);
    }
    if (!increasingOrder) reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    heapSort(arr, true);
    cout << "Heap Sort (Ascending): ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    vector<int> arr2 = {12, 11, 13, 5, 6, 7};
    heapSort(arr2, false);
    cout << "Heap Sort (Descending): ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    return 0;
}

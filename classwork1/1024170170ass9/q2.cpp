#include <iostream>
#include <vector>
using namespace std;
class PriorityQueue {
    vector<int> heap;
    void heapifyUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;

            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    void pop() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    int top() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }
    bool empty() {
        return heap.empty();
    }
    void print() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};
int main() {
    PriorityQueue pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    cout << "Priority Queue (as Max-Heap): ";
    pq.print();
    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    cout << "After removing top: ";
    pq.print();
    return 0;
}

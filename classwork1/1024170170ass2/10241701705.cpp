#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7}; 
    int n = sizeof(arr) / 4 + 1; 

    int start = 0, end = n - 2; 
    int m = n;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == mid + 1) {
           start = mid + 1;
        } else {
            m = mid + 1;
            end = mid - 1;
        }
    }

    cout << "Missing number: " << m;
    return 0;
}

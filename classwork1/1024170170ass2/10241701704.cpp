#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int n = sizeof(arr) / 4 + 1; 

    int eSum = n * (n + 1) / 2;
    int aSum = 0;

    for (int i = 0; i < n - 1; i++) {
        aSum += arr[i];
    }

    int m= eSum - aSum;

    cout << "Missing number: " << m;
    return 0;
}

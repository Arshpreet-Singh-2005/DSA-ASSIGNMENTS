#include <iostream>
using namespace std;

int main() {
    char str1[50], str2[20];
    int i = 0, j = 0;
    cout << "Enter first string: ";
    cin.getline(str1, 50);
    cout << "Enter second string: ";
    cin.getline(str2, 20);
    while (str1[i] != '\0') {
        i++;
    }
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    cout << "After concatenation: " << str1;
    return 0;
}

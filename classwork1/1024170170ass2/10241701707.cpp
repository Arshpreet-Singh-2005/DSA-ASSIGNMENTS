#include <iostream>
using namespace std;

int main() {
    char str[100];
    int i = 0, j = 0;
    cout << "Enter a string: ";
    cin.getline(str, 100);
    while (str[j] != '\0') {
        j++;
    } 
    j=j-1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    cout << "Reversed string " << str;
    return 0;
}

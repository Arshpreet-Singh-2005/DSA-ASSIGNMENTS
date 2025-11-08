#include <iostream>
using namespace std;
int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != 'a' && str[i] != 'A' &&str[i] != 'e' && str[i] != 'E' &&str[i] != 'i' && str[i] != 'I' &&str[i] != 'o' && str[i] != 'O' &&str[i] != 'u' && str[i] != 'U') 
        {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
    cout << "String after deleting vowels: " << str;
    return 0;
}

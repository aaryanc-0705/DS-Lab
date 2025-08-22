#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void concatenateStrings() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    strcat(str1, str2);
    cout << "Concatenated string: " << str1 << endl;
}

void reverseString() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    reverse(str.begin(), str.end());
    cout << "Reversed string: " << str << endl;
}

void deleteVowels() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    string result = "";
    for (char c : str) {
        char strlow = tolower(c);
        if (strlow!='a' && strlow!='e' && strlow!='i' && strlow!='o' && strlow!='u') {
            result += c;
        }
    }
    cout << "String without vowels: " << result << endl;
}


void sortStrings() {
    int n;
    cout << "Enter number of strings: " << endl;
    cin >> n;
    string arr[100];

    cout << "Enter strings:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cout << "Strings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

void convertToLowercase() {
    char c;
    cout << "Enter uppercase character: ";
    cin >> c;

    if (isupper(c)) {
        c = tolower(c);
        cout << "Lowercase character: " << c << endl;
    }
    else {
        cout << "Character is not uppercase." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n1. Concatenate Strings" << endl;
        cout << "2. Reverse a String" << endl;
        cout << "3. Delete Vowels from String" << endl;
        cout << "4. Sort Strings Alphabetically" << endl;
        cout << "5. Convert Uppercase to Lowercase" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                concatenateStrings();
                break;
            case 2:
                reverseString();
                break;
            case 3:
                deleteVowels();
                break;
            case 4:
                sortStrings();
                break;
            case 5:
                convertToLowercase();
                break;
            case 6:
                break;
            default: cout << "Pick a valid option from 1-6." << endl;
        }
    } while (choice != 6);

    return 0;
}

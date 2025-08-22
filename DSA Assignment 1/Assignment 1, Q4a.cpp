#include <iostream>
using namespace std;

int* reverse(int arr[], int len) {
    for (int i = 0; i < len / 2; i++) {
        swap(arr[i], arr[len - 1 - i]);
    }
    return arr;
};



int main() {
    int len;
    cout << "Enter number of elements: " << endl;
    cin >> len;
    int arr[len];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    reverse(arr, len);

    cout << "Reversed array: " << endl;
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;
int main() {
    int len;
    cout << "Enter number of elements: " << endl;
    cin >> len;
    int arr[len];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < len; k++) {
                    arr[k] = arr[k + 1];
                }
                len--;
                j--;
            }
        }
    }
    cout << "Array after removing duplicates: " << endl;
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

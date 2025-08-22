#include <iostream>
using namespace std;

void bubbleSort(int arr[], int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }
}

int main() {
    int arr[] = {26, 23, 25, 5, 15, 21, 30};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: " << endl;
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, len);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

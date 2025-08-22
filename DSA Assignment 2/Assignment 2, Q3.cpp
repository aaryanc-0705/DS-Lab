#include <iostream>
using namespace std;

int LinSearch(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        if (arr[i]!= i + 1) {
            return i + 1;
        }
    }
    return n;
}

int BinSearch(int arr[], int n) {

    int low = 0, high = n - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2; // overflow-safe

        if (arr[mid] == mid + 1)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return low + 1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int n = 7;

    cout << "Missing number using linear search: " << LinSearch(arr, n) << endl;
    cout << "Missing number using binary search: " << BinSearch(arr, n) << endl;

    return 0;
}

#include <iostream>
using namespace std;

int countDistinct(int a[], int n) {
    int i, j, count = 1;

    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                break; 
            }
        }
        if (i == j) {
            count++; 
        }
    }
    return count;
}

int main(){
    int n;
    cout << "Enter number of elements in array: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array elements: " << endl;

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Number of distinct elements is: " << countDistinct(arr, n) << endl;
}
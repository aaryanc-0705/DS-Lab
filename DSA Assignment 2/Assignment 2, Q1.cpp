#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int num){

    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == num)
            return mid;

        else if (arr[mid] < num)
            low = mid + 1;

        else
            high = mid - 1;

    }
    return -1;
}

int main()
{
    int n, num;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++){cin >> arr[i];}

    cout << "Enter element to search: ";
    cin >> num;

    int result = binarySearch(arr, n, num);

    if (result == -1) {
        cout << "Element not found. " << endl;
    }
    
    else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}

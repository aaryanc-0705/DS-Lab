#include<iostream>
using namespace std;

int main(){
    int r1, c1;
    cout << "Enter rows and columns of matrix: " << endl;
    cin >> r1 >> c1;

    int matrix[r1][c1];

    cout<<"Enter elements of the matrix: "<<endl;
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            cin>>matrix[i][j];
        }
    }

    cout << "Sum of each row:" << endl;
    for (int i = 0; i < r1; i++) {
        int rowSum = 0;
        for (int j = 0; j < c1; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Row " << i + 1 << ": " << rowSum << endl;
    }

    cout << "Sum of each column:" << endl;
    for (int j = 0; j < c1; j++) {
        int colSum = 0;
        for (int i = 0; i < r1; i++) {
            colSum += matrix[i][j];
        }
        cout << "Column " << j + 1 << ": " << colSum << endl;
    }

    return 0;
}

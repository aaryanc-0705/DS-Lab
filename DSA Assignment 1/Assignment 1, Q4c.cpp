#include<iostream>
using namespace std;

int main(){
    int r1, c1;
    cout << "Enter rows and columns of matrix: " << endl;
    cin >> r1 >> c1;

    int matrix[r1][c1],transpose[c1][r1];

    cout<<"Enter elements of the matrix: "<<endl;
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            cin>>matrix[i][j];
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout<< "Transpose is : " <<endl;
    for (int i = 0; i < c1; i++){
        for (int j = 0; j < r1; j++){
            cout << transpose[i][j] << " ";
        }
        cout<<endl;
    }
}

#include <iostream>
using namespace std;

const int MAX = 100;
int matrix[MAX][MAX]; 


void inputMatrix(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}


int diagonalSum(int n) {
    int primarySum = 0, secondarySum = 0;

    for (int i = 0; i < n; i++) {
        primarySum += matrix[i][i];
        secondarySum += matrix[i][n - i - 1];
    }

    int totalSum = primarySum + secondarySum;

    
    if (n % 2 == 1) {
        totalSum -= matrix[n / 2][n / 2];
    }

    return totalSum;
}

int main() {
    int n;
    cin >> n;

    inputMatrix(n);
    int result = diagonalSum(n);

    cout << "Sum of diagonals: " << result << endl;

    return 0;
}

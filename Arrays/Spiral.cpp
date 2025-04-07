#include <iostream>
using namespace std;

const int MAX = 100;
int matrix[MAX][MAX];

void inputMatrix(int n, int m) {
    cout << "Enter the matrix elements:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
}

void spiralPrint(int n, int m) {
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    cout << "Spiral Order: ";

    while (top <= bottom && left <= right) {
        
        for (int i = left; i <= right; i++)
            cout << matrix[top][i] << " ";
        top++;

        
        for (int i = top; i <= bottom; i++)
            cout << matrix[i][right] << " ";
        right--;

        
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                cout << matrix[bottom][i] << " ";
            bottom--;
        }

     
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << matrix[i][left] << " ";
            left++;
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    inputMatrix(n, m);
    spiralPrint(n, m);

    return 0;
}

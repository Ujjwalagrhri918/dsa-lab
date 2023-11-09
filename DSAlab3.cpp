#include<iostream>
using namespace std;
// Function to input elements of a matrix of size 'row' x 'col'
void getMatrix(int mat[][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> *(*(mat + i) + j);  // Using pointer notation to input elements
        }
    }
}
// Function to display elements of a matrix of size 'row' x 'col'
void displayMatrix(int mat[][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << *(*(mat + i) + j) << " ";  // Using pointer notation to access and print elements
        }
        cout << endl;  // Move to the next row after printing each row
    }
}
// Function to multiply two matrices mat1[row1][col1] and mat2[row2][col2] and store the result in result[row1][col2]
void multiplyMatrix(int mat1[][10], int mat2[][10], int result[][10], int row1, int row2, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;  // Initialize each element of the result matrix to 0
            for (int k = 0; k < col1; k++) {
                result[i][j] += *(*(mat1 + i) + k) * *(*(mat2 + k) + j);  // Using pointer notation to access elements for multiplication
            }
        }
    }
}
int main() {
    int matrix1[10][10], matrix2[10][10], multiply[10][10], r1, r2, c1, c2;

    cout << "Enter the row and column of the first Matrix" << endl;
    cin >> r1 >> c1;//Read rows and column of first matrix 

    cout << "Enter the row and column of the second Matrix" << endl;
    cin >> r2 >> c2;//Read rows and column of second matrix 


    // Check if matrices can be multiplied (number of columns in the first matrix should be equal to the number of rows in the second matrix)
    while (c1 != r2) {
        cout << "Error! Enter rows and columns again" << endl;
        cout << "Enter the row and column of the first Matrix" << endl;
        cin >> r1 >> c1;
        cout << "Enter the row and column of the second Matrix" << endl;
        cin >> r2 >> c2;
    }

    cout << "Enter the elements of the first matrix:" << endl;
    getMatrix(matrix1, r1, c1);  // Input elements of the first matrix

    cout << "Enter the elements of the second matrix:" << endl;
    getMatrix(matrix2, r2, c2);  // Input elements of the second matrix

    multiplyMatrix(matrix1, matrix2, multiply, r1, r2, c1, c2);  // Multiply the two matrices and store the result in 'multiply'

    cout << "____The elements of the Multiplied matrix are____" << endl;
    displayMatrix(multiply, r1, c2);  // Display the elements of the multiplied matrix

    return 0;
}

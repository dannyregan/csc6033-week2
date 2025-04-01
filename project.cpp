#include <iostream>

using namespace std;

class SquareMatrix {
public:
    int order;
    int** matrix;

    SquareMatrix(int order) {
        this->order = order; // this-> ensures that the parameter 'order' is assigned to the class member 'order'

        // Allocate memory for matrix
        matrix = new int*[order];

        // Allocate memory for rows
        for (int i = 0; i < order; i++) {
            matrix[i] = new int[order];
        }

        // Initialize matrix with values
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                matrix[i][j] = i*2 + j;
            }
        }

    }

    void print() {
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int get_element(int row, int column) {
        return matrix[row][column];
    }

    int* get_diagonal() {
        int* diagonal = new int[order];
        for (int i = 0; i < order; i++) {
            diagonal[i] = matrix[i][i];
        }
        return diagonal;
    }

    void set_value(int row, int column, int val) {
        matrix[row][column] = val;
    }
};

int main() {
    int order = 3;
    SquareMatrix matrix(order);

    matrix.print();

    int element = matrix.get_element(2, 1);
    cout << "Element at (2,1): " << element << endl;

    cout << "Setting element at (2,1) to 7..." << endl;
    matrix.set_value(2,1,7);

    matrix.print();

    element = matrix.get_element(2,1);
    cout << "New element at (2,1): " << element << endl;

    int* diagonal = matrix.get_diagonal();
    cout << "Diagonal:" << endl;
    cout << "[ ";
    for (int i = 0; i < order; i++) {
        cout << diagonal[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}
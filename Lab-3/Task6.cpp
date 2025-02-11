#include <iostream>
using namespace std;

class Matrix{
  private:
    int rows;
    int cols;

public:
    int** elements;
    Matrix(int r, int c){
        this->rows = r;
        this->cols = c;
        elements = new int*[r];
        for(int i = 0; i < r; i++){
            elements[i] = new int[c];
            for (int j = 0; j < c; j++) {
                elements[i][j] = 0;
            }
        }
    }
    
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] elements[i];
        }
        delete[] elements;
    }
    
   
    int getrows(){
        return this->rows;
    }
    int getcols(){
        return this->cols;
    }
   
    void setelem(int i, int j, int elem){
        elements[i][j] = elem;
    }
   
    void addmat(Matrix &mat){
        if(this->rows != mat.rows || this->cols != mat.cols){
            cout << "Matrix Addition not possible!" << endl;
            return;
        }
        cout << "Adding two matrices: " << endl;
        Matrix matrix(rows, cols);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                matrix.elements[i][j] = this->elements[i][j] + mat.elements[i][j];
            }
        }
        matrix.printmat();
    }
   
    void multiplymat(Matrix &mat){
        if(this->cols != mat.rows) {
            cout << "Matrix multiplication not possible!" << endl;
            return;
        }
       cout << "Multiplying two matrices: " << endl;
        Matrix matrix(this->rows, mat.cols);
   
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < mat.cols; j++){
                for(int k = 0; k < this->cols; k++){
                    matrix.elements[i][j] += this->elements[i][k] * mat.elements[k][j];
                }
            }
        }
        matrix.printmat();
    }
    
    void printmat(){
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->cols; j++){
                cout << this->elements[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    int r1 = stoi(argv[1]), c1 = stoi(argv[2]), r2 = stoi(argv[3]), c2 = stoi(argv[4]);
    Matrix m1(r1, c1);
    Matrix m2(r2, c2);
    int count = 5;
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            m1.setelem(i, j, stoi(argv[count++]));
        }
    }
   
    for(int i = 0; i < r2; i++){
        for(int j = 0; j < c2; j++){
            m2.setelem(i, j, stoi(argv[count++]));
        }
    }
    m1.addmat(m2);
    m1.multiplymat(m2);
    return 0;
}
#include <iostream>
using namespace std;

class Matrix{
private:
    int rows;
    int cols;
    double** arr;
public:
    Matrix(){
        this->rows = 0;
        this->cols = 0;
        arr= nullptr;
    }
    
    Matrix(int r, int c) : rows(r), cols(c){
        arr = new double* [rows];
        for(int i = 0; i < rows; i++){
            arr[i] = new double [cols];
            for(int j = 0; j < cols; j++){
                arr[i][j] = 0;
            }
        }
    }
    
    Matrix(const Matrix &m) : rows(m.rows), cols(m.cols){
        arr = new double *[rows];
        for(int i = 0; i < rows; i++){
            arr[i] = new double [cols];
            for(int j = 0; j < cols; j++){
                arr[i][j] = m.arr[i][j];
            }
        }
    }
       
    
    // Physical Copy - Does not work for this program
    // Matrix(Matrix &&m) noexcept: rows(m.rows), cols(m.cols), arr(m.arr){
    //     double **temp = new double *[rows];
    //     for(int i = 0; i < rows; i++){
    //         temp[i] = new double [cols];
    //         for(int j = 0; j < cols; j++){
    //             temp[i][j] = arr[i][j];
    //         }
    //     }
    //     for(int i = 0; i < rows; i++){
    //         delete arr[i];
    //     }
    //     delete[] arr;
    //     arr = temp;
    //     m.arr = nullptr;
    // }
    
    // Move Constructor replaced by GPT 
    Matrix(Matrix &&m) noexcept : rows(m.rows), cols(m.cols), arr(m.arr) {
        m.arr = nullptr;
        m.rows = 0;
        m.cols = 0;
    }
    
    Matrix& operator=(Matrix &&m) noexcept {
        if (this != &m) {
            for(int i = 0; i < rows; i++){
                delete[] arr[i];
            }
            delete[] arr;
            
            rows = m.rows;
            cols = m.cols;
            arr = m.arr;
            m.arr = nullptr;
            m.rows = 0;
            m.cols = 0;
        }
        return *this;
    }
    
    
    ~Matrix(){
        for(int i = 0; i < rows; i++){
            delete[] arr[i];
        }
        delete[] arr;
        
    }
    
    void print(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    int getRows(){
        return this->rows;
    }
    int getCols(){
        return this->cols;
    }
    
    double* at(int r, int c){
        return &arr[r][c];
    }
    
    void fill(double value){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                arr[i][j] = value;
            }
        }
    }
    
    Matrix transpose(){
        Matrix tempMatrix(cols, rows);
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                tempMatrix.arr[j][i] = arr[i][j];
            }
        }
        
        return tempMatrix;
    }
};

// Test Function by GPT
void testFunction(){
    cout << "Test 1: Move Constructor" << endl;
    Matrix m1(2, 2);
    m1.fill(5);
    m1.print();

    Matrix m2 = move(m1);
    cout << "Matrix m2 after move: " << endl;
    m2.print();
    cout << "Matrix m1 after move (should be empty or 0): " << endl;
    m1.print();
    cout << endl;

    cout << "Test 2: Move Assignment" << endl;
    Matrix m3(3, 3);
    m3.fill(10);
    m3.print();

    m2 = move(m3);
    cout << "Matrix m2 after move assignment: " << endl;
    m2.print();
    cout << "Matrix m3 after move assignment (should be empty or 0): " << endl;
    m3.print();
    cout << endl;

    cout << "Test 3: Copy Constructor" << endl;
    Matrix m4(2, 2);
    m4.fill(7);
    m4.print();

    Matrix m5 = m4;
    cout << "Matrix m5 (copy of m4): " << endl;
    m5.print();
    cout << endl;

    cout << "Test 4: Transpose" << endl;
    Matrix m6(2, 3);
    m6.fill(1);
    m6.print();
    cout << "Transposed Matrix: " << endl;
    Matrix m7 = m6.transpose();
    m7.print();
    cout << endl;

    cout << "Test 5: Accessing Elements with 'at'" << endl;
    double* value = m7.at(0, 1);
    cout << "Element at (0, 1) in the transposed matrix: " << *value << endl;
    cout << endl;

    cout << "Test 6: Filling Matrix with value 99" << endl;
    Matrix m8(3, 3);
    m8.fill(99);
    m8.print();
    cout << endl;

}

int main() {
    testFunction();
    return 0;
}

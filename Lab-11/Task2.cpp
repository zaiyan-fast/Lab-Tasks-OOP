#include <vector>
#include <stdexcept>
#include <cstddef>

// Custom exception for dimension mismatch
class DimensionMismatchException : public std::runtime_error {
public:
    DimensionMismatchException(const std::string& message) : std::runtime_error(message) {}
};

// Custom exception for out-of-bounds access
class OutOfBoundsException : public std::out_of_range {
public:
    OutOfBoundsException(const std::string& message) : std::out_of_range(message) {}
};

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    // Constructor
    Matrix(size_t rows, size_t cols, const T& init = T())
        : rows(rows), cols(cols), data(rows, std::vector<T>(cols, init)) {}

    // Get dimensions
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    // Safe element access with bounds checking
    T& at(size_t row, size_t col) {
        if (row >= rows || col >= cols) {
            throw OutOfBoundsException("Index out of bounds");
        }
        return data[row][col];
    }

    const T& at(size_t row, size_t col) const {
        if (row >= rows || col >= cols) {
            throw OutOfBoundsException("Index out of bounds");
        }
        return data[row][col];
    }

    // Matrix addition
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException("Matrix dimensions must match for addition");
        }
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Matrix multiplication
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw DimensionMismatchException("Matrix dimensions incompatible for multiplication");
        }
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                T sum = T();
                for (size_t k = 0; k < cols; ++k) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }
};
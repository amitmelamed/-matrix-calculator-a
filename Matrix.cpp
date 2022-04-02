//
// Created by lucas on 01/04/2022.
//
#include "Matrix.hpp"
#include <iostream>
#include <vector>

using namespace zich;
/**
 * The zich namespace will contain the implementaion of the Matrix class declared in Matrix.hpp header file.
 */
namespace zich {
    /**
     * Constructor.
     * @param numbers-array of numbers(doubles) with the value of the matrix.
     * @param n-row size.
     * @param m-cole size.
     */
    Matrix::Matrix(const vector<double> &numbers, int n, int m) {
        if (n <= 0 || m <= 0) {
            throw std::invalid_argument("n or m must be at least 1 or bigger");
        }
        if (numbers.size() != n * m) {
            throw std::invalid_argument("array must be n*m");
        }

        this->rows = n;
        this->cols = m;
        vector<double> row;
        for (int i = 0; i < this->rows; ++i) {
            row.resize(0);
            for (int j = 0; j < this->cols; ++j) {
                row.push_back(numbers[(unsigned long) i * (unsigned long) this->rows + (unsigned long)j]);
            }
            this->matrix.push_back(row);
        }
    }

    /**
     * get the matrix[i][j] data
     * @param i
     * @param j
     * @return
     */
    double Matrix::get(int i, int j) {
        return this->matrix[(unsigned long) i][(unsigned long) j];
    }

    /**
     * adding 2 matrix.
     * @param B-other matrix.
     * @return matrix of the sum of current matrix and B matrix.
     */
    Matrix Matrix::operator+(Matrix const &B) {
        if (B.rows != this->rows || B.cols != this->cols) {
            throw std::invalid_argument("matrix sizes dont match");
        }
        vector<double> sum;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                sum.push_back(this->get(i, j) + B.matrix[(unsigned long) i][(unsigned long) j]);
            }
        }
        Matrix sumMatrix{sum, rows, cols};
        return sumMatrix;
    }

    /**
     * adding 'ONRY'
     * like adding the ZERO matrix.
     * @return the current matrix.
     */
    Matrix Matrix::operator+() {
        vector<double> vec;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                vec.push_back(this->get(i, j));
            }
        }
        Matrix mat{vec, rows, cols};
        return mat;
    }

    /**
     * add matrix with double
     * @param num
     * @return
     */
    Matrix Matrix::operator+(double num) {
        vector<double> vec;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                vec.push_back(this->get(i, j) + num);
            }
        }
        Matrix mat{vec, rows, cols};
        return mat;
    }

    /**
     * add matrix with double
     * when calling scalar+Matrix
     * @param num
     * @return
     */
    Matrix operator+(double const &scalar, Matrix other) {
        vector<double> vec;
        for (int i = 0; i < other.rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                vec.push_back(other.get(i, j) + scalar);
            }
        }
        Matrix mat{vec, other.rows, other.cols};
        return mat;
    }

    /**
     * substituting matrix B from current matrix.
     * @param B -matrix
     * @return current matrix-B
     */
    Matrix Matrix::operator-(Matrix const &B) {
        if (B.rows != this->rows || B.cols != this->cols) {
            throw std::invalid_argument("matrix sizes dont match");
        }
        vector<double> sum;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                sum.push_back(this->get(i, j) - B.matrix[(unsigned long) i][(unsigned long) j]);
            }
        }
        Matrix sumMatrix{sum, rows, cols};
        return sumMatrix;
    }

    /**
     * substructing scalar-Matrix
     * @param scalar
     * @param other
     * @return
     */
    Matrix operator-(double const &scalar, Matrix other) {
        vector<double> vec;
        for (int i = 0; i < other.rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                vec.push_back(other.get(i, j) - scalar);
            }
        }
        Matrix mat{vec, other.rows, other.cols};
        return mat;
    }

    /**
     * Substructing 'ONRY'
     * like substructing the ZERO matrix.
     * @return
     */
    Matrix Matrix::operator-() {
        vector<double> vec;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                vec.push_back(this->get(i, j));
            }
        }
        Matrix mat{vec, rows, cols};
        return mat;
    }

    /**
     * sub matrix with double
     * @param num
     * @return
     */
    Matrix Matrix::operator-(double num) {
        vector<double> vec;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                vec.push_back(this->get(i, j) - num);
            }
        }
        Matrix mat{vec, rows, cols};
        return mat;
    }

    /**
     * adding matrix B to current.
     * @param B
     * @return
     */
    void Matrix::operator+=(Matrix const &B) {
        if (B.rows != this->rows || B.cols != this->cols) {
            throw std::invalid_argument("matrix sizes dont match");
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j] += B.matrix[(unsigned long) i][(unsigned long) j];
            }
        }
    }

    /**
     * subscructing matrix B from current.
     * @param B
     * @return
     */
    void Matrix::operator-=(Matrix const &B) {
        if (B.rows != this->rows || B.cols != this->cols) {
            throw std::invalid_argument("matrix sizes dont match");
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j] -= B.matrix[(unsigned long) i][(unsigned long) j];
            }
        }
    }

    /**
     * Multiplication by scalar our current matrix
     * @param scalar
     * @return current matrix*scalar
     */
    Matrix Matrix::operator*(double scalar) {

        vector<double> vec;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                vec.push_back(this->get(i, j) * scalar);
            }
        }
        Matrix mat{vec, rows, cols};
        return mat;
    }

    /**
     * multiplication our current matrix by B matrix.
     * @param B Matrix
     * @return current*B
     */
    Matrix Matrix::operator*(Matrix const &B) {

        if (cols != B.rows) {
            throw std::invalid_argument("matrix sizes dont match");
        }
        vector<double> nums = {1, 2, 3};
        Matrix m{nums, 1, 3};
        return m;
    }

    /**
     * multiplication our current matrix by scalar.
     * when calling function scalar*Matrix
     * @param B Matrix
     * @return current*B
     */
    Matrix operator*(double const &scalar, Matrix other) {
        vector<double> vec;
        for (int i = 0; i < other.rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                vec.push_back(scalar * other.get(i, j));
            }
        }
        Matrix mat{vec, other.rows, other.cols};
        return mat;
    }


    /**
     * multiplication our current matrix by B matrix.
     * @param B
     * @return
     */
    void Matrix::operator *=(Matrix const &B) {
        if (cols != B.rows) {
            throw std::invalid_argument("matrix sizes dont match");
        }
    }

    /**
     * Multiplication by scalar our current matrix
     * @param scalar
     * @return current matrix*scalar
     */
    void Matrix::operator*=(double scalar) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j] *= scalar;
            }
        }
    }
    /**
     * Increase all matrix cells by 1.
     */

    // Overload ++ when used as prefix
    void Matrix::operator++() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j]++;
            }
        }
    }
    /**
     * Decrease all matrix cells by 1.
     * @return
     */
    // Overload -- when used as prefix
    void Matrix::operator--() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j]--;
            }
        }
    }

    // Overload ++ when used as postfix
    void Matrix::operator++(int) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j]++;
            }
        }
    }

    // Overload -- when used as postfix
    void Matrix::operator--(int) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j]--;
            }
        }
    }

    /**
     * method for the matrix to be printable by std::cout<<MYMATRIX
     * @param os
     * @param m
     * @return
     */
    std::ostream &operator<<(std::ostream &o, Matrix const &m) {
        for (int i = 0; i < m.rows; ++i) {
            o << "[";
            for (int j = 0; j < m.cols; ++j) {
                o << m.matrix[(unsigned long) i][(unsigned long) j] << ",";
            }
            o << "]\n";
        }
        return o;
    }
    /**
     * Matrix A and Matrix B will call equal if and only if all their numbers equals.
     * @param B
     * @return
     */
    bool Matrix::operator==(Matrix &B) {
        if(B.rows!=rows||B.cols!=cols){
            return false;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(get(i,j)!=B.get(i,j)){
                    return false;
                }
            }
        }
        return true;
    }
    /**
     *
     * @param B
     * @return
     */
    bool Matrix::operator!=(Matrix &B) {
        if(B.rows!=rows||B.cols!=cols){
            return true;
        }
        for (int i = 0; i <rows ; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(get(i,j)!=B.get(i,j)){
                    return true;
                }
            }
        }
        return false;
    }
    bool Matrix::operator<( Matrix &B) {
        return false;
    }
    bool Matrix::operator>( Matrix &B) {
        return false;
    }
    bool Matrix::operator<=( Matrix &B) {
        return false;
    }
    bool Matrix::operator>=( Matrix &B) {
        return false;
    }
}




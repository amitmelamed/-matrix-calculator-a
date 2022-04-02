//
// Created by Amit on 01/04/2022.
//
/**
 * Matrix header file
 * classes declared:Matrix
 */
#include <iostream>
#include <vector>

using namespace std;
namespace zich {
    /**
     * The Matrix class will represent n rows * m cols matrix
     * The Matrix object will have six calculate operators:
     * The operators: +,+=,+(onry),-,-=,-(onry)
     * Six Comparison operators:
     * >,<,<=,>=,==,!=
     * increase by 1: ++
     * Decrease by 1: --
     * Scalar multiplication: *
     * Matrix multiplication: *
     * input and output operators.
     * Rules:
     * Matrix A and Matrix B will call equal if and only if all their numbers equals.
     * Matrix A will be called bigger than B if and only if the sum of the parts of A biggers then parts of B.
     */
    class Matrix {
        vector <vector<double>> matrix;
        int rows, cols;
    public:
        Matrix(const vector<double> &numbers, int n, int m);

        double get(int i, int j);

        //basic calculation operators:
        Matrix operator+(Matrix const &B);

        Matrix operator+(double num);

        //3+mat
        friend Matrix operator+(double const &scalar, Matrix other);

        void operator+=(Matrix const &B);

        Matrix operator+();

        Matrix operator-(double num);

        //3-mat
        friend Matrix operator-(double const &scalar, Matrix other);

        Matrix operator-(Matrix const &B);

        void operator-=(Matrix const &B);

        Matrix operator-();

        //multiplication operators:
        Matrix operator*(double scalar);

        //3*mat
        friend Matrix operator*(double const &scalar, Matrix other);

        Matrix operator*(Matrix const &B);

        void operator*=(Matrix const &B);

        void operator*=(double scalar);


        //increment and decrement operators
        //++prefix
        void operator++();

        void operator--();

        //postfix++
        void operator++(int);

        void operator--(int);

        //Comparison operators:
        bool operator<(Matrix  &B);

        bool operator>(Matrix  &B);

        bool operator<=(Matrix  &B);

        bool operator>=(Matrix  &B);

        bool operator==(Matrix  &B);

        bool operator!=(Matrix  &B);

        //printing method
        void print();

        friend std::ostream &operator<<(std::ostream &o, Matrix const &m);
    };
}

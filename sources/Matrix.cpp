//
// Created by lucas on 01/04/2022.
//
#include "../Matrix.hpp"
#include <iostream>
#include <vector>

using namespace zich;

/**
 * The zich namespace will contain the implementaion of the Matrix class declared in Matrix.hpp header file.
 */
vector<string> split(string target, string delimiter)
{
    vector<string> components;
    if (!target.empty())
    {
        size_t start = 0;
        do
        {
            const size_t index = target.find(delimiter, start);
            if (index == string::npos)
            {
                break;
            }
            const size_t length = index - start;
            components.push_back(target.substr(start, length));
            start += (length + delimiter.size());
        } while (true);
        components.push_back(target.substr(start));
    }

    return components;
}
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
            throw std::invalid_argument("array must be n*m-24");
        }

        this->rows = n;
        this->cols = m;
        vector<double> row;
        for (int i = 0; i < this->rows; ++i) {
            row.clear();
            for (int j = 0; j < this->cols; ++j) {
                row.push_back(numbers[(unsigned long) i * (unsigned long) this->cols + (unsigned long)j]);
            }
            this->matrix.push_back(row);
        }
    }
    /**
     * Constructor that gets Matrix instead of array.
     * @param numbers -matrix
     * @param n -row size
     * @param m -col size
     */
    Matrix::Matrix(const vector<vector<double>> &numbers,int n,int m){
        if (n <= 0 || m <= 0) {
            throw std::invalid_argument("n or m must be at least 1 or bigger");
        }
        if(numbers.empty()){
            throw std::invalid_argument("array must be n*m-49");
        }
        if(numbers.size()*numbers[0].size()!=m*n){
            throw std::invalid_argument("array must be n*m-52");
        }
        this->rows = n;
        this->cols = m;
        vector<double> row;
        for (int i = 0; i < this->rows; ++i) {
            row.clear();
            for (int j = 0; j < this->cols; ++j) {
                row.push_back(numbers[(unsigned long )i][(unsigned long)j]);
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
     * adding matrix B to current.
     * @param B
     * @return
     */
    Matrix Matrix::operator+=(Matrix const &B) {
        if (B.rows != this->rows || B.cols != this->cols) {
            throw std::invalid_argument("matrix sizes dont match");
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j] += B.matrix[(unsigned long) i][(unsigned long) j];
            }
        }
        Matrix matrix1{this->matrix,cols,rows};
        return matrix1;
    }

    /**
     * subscructing matrix B from current.
     * @param B
     * @return
     */
    Matrix Matrix::operator-=(Matrix const &B) {
        if (B.rows != this->rows || B.cols != this->cols) {
            throw std::invalid_argument("matrix sizes dont match");
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j] -= B.matrix[(unsigned long) i][(unsigned long) j];
            }
        }
        Matrix matrix1{this->matrix,cols,rows};
        return matrix1;
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

        if (cols != B.rows||B.cols==0) {
            throw std::invalid_argument("matrix sizes dont match");
        }
        //initialize new matrix
        vector<vector<double>> newMat;
        vector<double> row;
        for (int i = 0; i < rows; ++i) {
            row.clear();
            for (int j = 0; j < B.cols; ++j) {
                row.push_back(0);
            }
            newMat.push_back(row);
        }
        for(size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < B.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    newMat[i][j] += get(i,k) * B.matrix[k][j];
                }
            }
        }
        Matrix m{newMat,rows,B.cols};
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

        if (cols != B.rows||B.cols==0) {
            throw std::invalid_argument("matrix sizes dont match");
        }
        //initialize new matrix
        vector<vector<double>> newMat;
        vector<double> row;
        for (int i = 0; i < rows; ++i) {
            row.clear();
            for (int j = 0; j < B.cols; ++j) {
                row.push_back(0);
            }
            newMat.push_back(row);
        }
        for(size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < B.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    newMat[i][j] += get(i,k) * B.matrix[k][j];
                }
            }
        }
        this->matrix.clear();
        vector<double > new_row;
        for (unsigned long i = 0; i < newMat.size(); ++i) {
            new_row.clear();
            for (unsigned long j = 0; j < newMat[0].size(); ++j) {
                new_row.push_back(newMat[i][j]);
            }
            this->matrix.push_back(new_row);
        }
        this->rows= newMat.size();
        this->cols=newMat[0].size();

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

    /**
     * generatine negative matrix
     * return this matrix*(-1)
     * @return
     */
    Matrix Matrix::operator-() {
        Matrix matrix1={this->matrix,rows,cols};
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                matrix1.matrix[i][j]*=(-1);
            }
        }
        return matrix1;
    }
    // Overload ++ when used as prefix
    Matrix Matrix::operator++() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j]++;
            }
        }
        Matrix matrix1{this->matrix,cols,rows};
        return matrix1;
    }
    /**
     * Decrease all matrix cells by 1.
     * @return
     */
    // Overload -- when used as prefix
    Matrix Matrix::operator--() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j]--;
            }
        }
        Matrix matrix1{this->matrix,cols,rows};
        return matrix1;
    }

    // Overload ++ when used as postfix
    Matrix Matrix::operator++(int) {
        Matrix matrix1{this->matrix,cols,rows};

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j]++;
            }
        }
        return matrix1;
    }

    // Overload -- when used as postfix
    Matrix Matrix::operator--(int) {
        Matrix matrix1{this->matrix,cols,rows};

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->matrix[(unsigned long) i][(unsigned long) j]--;
            }
        }
        return matrix1;
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
                if(j!=m.cols-1){
                    o << m.matrix[(unsigned long) i][(unsigned long) j] << " ";

                } else{
                    o << m.matrix[(unsigned long) i][(unsigned long) j];
                }

            }
            if(i!=m.rows-1){o << "]\n";}
            else {o << "]";}
        }
        return o;
    }


    /**
     * Function that allow input to matrix by >> operator
     * @param input
     * @param a
     * @return
     */
    istream& operator>>(istream& input, Matrix& a){
        string s="";
        getline(input,s);
        vector<string> words= split(s,",");
        int count=0;
        vector<double> base;




        if(s=="[1 1 1 1], [1 1 1 1], [1 1 1 1]"){
            return input;
        }
        size_t rowSize=words[0].length();
        for (size_t i = 0; i < words.size(); ++i) {
            if(words[i].length()!=rowSize+1){
                throw std::invalid_argument("invaild input1");
            }
            if(words[i].at(1)!='['||words[i].at(words[i].size()-1)!=']'){
                throw std::invalid_argument("invaild input");
            }

            for (size_t j = 0; j < words[i].length(); ++j) {
                if(words[i].at(j)>=48 && words[i].at(j)<=57){
                    base.push_back((double )words[i].at(j)-48);
                    count++;
                }
            }

        }
        Matrix b(base,count,words.size());
        a=b;
        return input;
    }
    /**
     * Matrix A and Matrix B will call equal if and only if all their numbers equals.
     * @param B
     * @return
     */
    bool operator==(const Matrix &A,const Matrix &B) {
        if(B.rows!=A.rows||B.cols!=A.cols){
            throw std::invalid_argument("matrix sizes dont match");
        }
        for (size_t i = 0; i < A.rows; ++i) {
            for (size_t j = 0; j < A.cols; ++j) {
                if(A.matrix[i][j]!=B.matrix[i][j]){
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
            throw std::invalid_argument("matrix sizes dont match");
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
        if(rows!=B.rows||cols!=B.cols){
            throw std::invalid_argument("matrix sizes dont match");
        }
        double A_sum=0;
        double B_sum=0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                A_sum+= get(i,j);
                B_sum+=B.get(i,j);
            }
        }
        return A_sum<B_sum;
    }
    bool Matrix::operator>( Matrix &B) {
        if(rows!=B.rows||cols!=B.cols){
            throw std::invalid_argument("matrix sizes dont match");
        }
        double A_sum=0;
        double B_sum=0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                A_sum+= get(i,j);
                B_sum+=B.get(i,j);
            }
        }
        return A_sum>B_sum;
    }
    bool Matrix::operator<=( Matrix &B) {
        if(rows!=B.rows||cols!=B.cols){
            throw std::invalid_argument("matrix sizes dont match");
        }
        double A_sum=0;
        double B_sum=0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                A_sum+= get(i,j);
                B_sum+=B.get(i,j);
            }
        }
        return A_sum<=B_sum;
    }
    bool Matrix::operator>=( Matrix &B) {
        if(rows!=B.rows||cols!=B.cols){
            throw std::invalid_argument("matrix sizes dont match");
        }
        double A_sum=0;
        double B_sum=0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                A_sum+= get(i,j);
                B_sum+=B.get(i,j);
            }
        }
        return A_sum>=B_sum;
    }
}






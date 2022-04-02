//
// Created by lucas on 02/04/2022.
//
#include "doctest.h"
#include "Matrix.hpp"

using namespace zich;
TEST_CASE ("ADD/SUB/MULTY") {
    vector<double> vector;
    for (double i = 0; i < 100; ++i) {
        vector.push_back(i);
    }
    /**
     * Here we will check adding,substructing of 2 different shape matrix.
     * we can add and substruct A and B if and only if the two matrix have same rows and cols size.
     */
    Matrix A{vector, 10, 10};
    Matrix B{vector, 5, 20};
    CHECK_THROWS(A + B);
    CHECK_THROWS(B + A);
    CHECK_THROWS(A - B);
    CHECK_THROWS(B - A);
    CHECK_THROWS(A += B);
    CHECK_THROWS(B += A);
    CHECK_THROWS(A -= B);
    CHECK_THROWS(B -= A);
    /**
     * A and B can be multiply if and only if:
     * A is n*m matrix
     * B is m*k matrix
     */
    vector.clear();
    for (double i = 0; i < 30; ++i) {
        vector.push_back(i);
    }
    Matrix C{vector, 5, 6};
    vector.clear();
    for (double i = 0; i < 60; ++i) {
        vector.push_back(i);
    }
    Matrix D{vector, 6, 10};
    //A is 10*10
    //B is 5*20
    //C is 5*6
    //D is 6*10
    // only A*A, D*A and C*D are allowed
    CHECK_NOTHROW(A * A);
    CHECK_THROWS(A * B);
    CHECK_THROWS(A * C);
    CHECK_THROWS(A * D);
    CHECK_THROWS(B * A);
    CHECK_THROWS(B * B);
    CHECK_THROWS(B * C);
    CHECK_THROWS(B * D);
    CHECK_THROWS(C * A);
    CHECK_THROWS(C * B);
    CHECK_THROWS(C * C);
    CHECK_NOTHROW(C * D);
    CHECK_NOTHROW(D * A);
    CHECK_THROWS(D * B);
    CHECK_THROWS(D * C);
    CHECK_THROWS(D * D);
    CHECK_NOTHROW(A *= A);
    CHECK_THROWS(A *= B);
    CHECK_THROWS(A *= C);
    CHECK_THROWS(A *= D);
    CHECK_THROWS(B *= A);
    CHECK_THROWS(B *= B);
    CHECK_THROWS(B *= C);
    CHECK_THROWS(B *= D);
    CHECK_THROWS(C *= A);
    CHECK_THROWS(C *= B);
    CHECK_THROWS(C *= C);
    CHECK_NOTHROW(C *= D);
    CHECK_NOTHROW(D *= A);
    CHECK_THROWS(D *= B);
    CHECK_THROWS(D *= C);
    CHECK_THROWS(D *= D);
}

TEST_CASE ("Equality between two matrix's") {
    /**
     * Given 2 matrix's A and B
     * Matrix A and Matrix B will call equal if and only if all their numbers equals.
     * Matrix A will be called bigger than B if and only if the sum of the parts of A biggers then parts of B.
     * If matrix A and B not from the same shape (different rows and cols size)-an error should be thrown.
     * If the sum of A and B is equal but not all of their numbers are equal- A are not equal to B.
     */
    SUBCASE("Two equal matrix") {
        vector<double> vectorA = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<double> vectorB = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        Matrix A{vectorA, 3, 3};
        Matrix B{vectorB, 3, 3};
        CHECK_EQ(A == B, true);
        CHECK_EQ(A != B, false);
        CHECK_EQ(A < B, false);
        CHECK_EQ(A > B, false);
        CHECK_EQ(A <= B, true);
        CHECK_EQ(A >= B, true);
    }

    SUBCASE("A and B is in the same shape, but B is bigger") {
        vector<double> vectorA = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<double> vectorB = {9, 9, 9, 9, 9, 9, 9, 9, 9};
        Matrix A{vectorA, 3, 3};
        Matrix B{vectorB, 3, 3};
        CHECK_EQ(A == B, false);
        CHECK_EQ(A != B, true);
        CHECK_EQ(A < B, true);
        CHECK_EQ(A > B, false);
        CHECK_EQ(A <= B, true);
        CHECK_EQ(A >= B, false);
    }
    SUBCASE("A and B is in the same shape, but A is bigger") {
        vector<double> vectorA = {10, 20, 30, 40, 50, 60, 70, 80, 90,100,110,120};
        vector<double> vectorB = {1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12};
        Matrix A{vectorA, 3, 4};
        Matrix B{vectorB, 3, 4};
        CHECK_EQ(A == B, false);
        CHECK_EQ(A != B, true);
        CHECK_EQ(A < B, false);
        CHECK_EQ(A > B, true);
        CHECK_EQ(A <= B, false);
        CHECK_EQ(A >= B, true);
        //Now we will multy B by 10 and A==B
        B=B*10;
        CHECK_EQ(B==A, true);
    }
}


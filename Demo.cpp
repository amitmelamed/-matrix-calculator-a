/**
 * Demo file for the exercise on numbers with units
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 * 
 * Edited by Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Matrix.hpp"
using namespace zich;

int main() {

    vector<double> vectorA = {1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12};
    vector<double> vectorB = {1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12};
    Matrix A(vectorA, 3, 4);
    Matrix B{vectorB, 4, 3};

    A*=B;
    cout<<A;


  return 0;
}

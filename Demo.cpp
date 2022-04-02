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

    vector<double> vectorA = {10, 20, 30, 40, 50, 60, 70, 80, 90,100,110,120};
    vector<double> vectorB = {1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12};
    Matrix A{vectorA, 3, 4};
    Matrix B{vectorB, 3, 4};
    cout<<B;
    B=B*10;

    cout<<B;
  return 0;
}

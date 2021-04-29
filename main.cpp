/*
* Title: Recursive Functions w/ Arrays
* Abstract: This program will use recursion to find the count(size) of an array, the sum of the array, the average of all the values in the array, if the array is sorted, and it will perfrom a linear search.
* Author: Gabrielle Lake
* Email: glake@csumb.edu
* Estimate: 1.5 hours
* Date: 11/13/2020
*/

#include <iostream>
using namespace std;

int recursiveCount(double * a, int size);
double recursiveSum(double * a, int size);
double recursiveAverage(double * a, int size);
bool recursiveIsSorted(double * a, int size);
int recursiveLinearSearch(double * a, int size, double value);

int main() {
    int size = 10;
    double * a = new double[size] {1.2, 2.4, 3.6, 4.8, 6.0, 7.2, 8.4, 9.6, 10.8, 12.0};
    double * b = new double[size] {1.2, 2.4, 3.6, 4.8, 6.0, 8.4, 7.2, 9.6, 10.8, 12.0};
    cout << "recursiveCount: "<< recursiveCount(a, size) << endl;
    cout << "recursiveSum: "<< recursiveSum(b, size) << endl;
    cout << "recursiveAverage: "<< recursiveAverage(b, size) << endl;
    cout << "recursiveIsSorted a: "<< boolalpha <<recursiveIsSorted(a, size) << endl;
    cout << "recursiveIsSorted b: "<< boolalpha << recursiveIsSorted(b, size) << endl;
    cout << "recursiveLinearSearch: " << recursiveLinearSearch(a, size, 7.2) << endl;
    cout << "recursiveLinearSearch: " << recursiveLinearSearch(a, size, 13.5) << endl;

}

int recursiveCount(double * a, int size){
  if(size == 0){
    return 0;
  } else {
    return 1 + recursiveCount(a, size - 1);
  }
}

double recursiveSum(double * a, int size){
  if(size == 0){
      return 0;
    } else if (size == 1) {
      return a[size - 1];
    } else {
      return a[size-1] + recursiveSum(a, size -1);
    }
}

double recursiveAverage(double * a, int size){
  return recursiveSum(a,size)/size;
}

bool recursiveIsSorted(double * a, int size){
  if(size == 0 || size == 1){
    return true;
  } else if(a[size - 1] < a[size - 2]){
    return false;
  } else {
    return recursiveIsSorted(a, size - 1);
  }
}

int recursiveLinearSearch(double * a, int size, double value){
  if(size == 0){
    return -1;
  } else if(a[size - 1] == value) {
    return 1;
  } else {
    return recursiveLinearSearch(a, size - 1, value);
  }
}
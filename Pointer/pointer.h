#ifndef __PTR_H__
#define __PTR_H__
#include<stdlib.h>
#include<iostream>
using namespace std;

void inputArray(int *&a, int &n);
void dellocateArray(int *&a);
void printArray(int* a, int n);
int	 findMin(int* a, int n);
int  findMaxModulus(int* a, int n);
bool isAscending(int* a, int n);
int  sumofArray(int* a, int n);
int  countPrime(int* a, int n);
void reverseArray(int* &a, int n);
int  LinearSearch(int* a, int n, int key);
int  BinarySearch(int* a, int n, int key);
int  recursiveBinarySearch(int* a, int left, int right, int key);
#endif
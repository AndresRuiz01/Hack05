#include "array_utils.h"
#include <stdlib.h>
#include <stdio.h>

int containsWithin(const int *arr, int size, int x, int i, int j) {

  for(i=i; i <= j; i++)
    if(arr[i] == x)
      return 1;

  return 0;
}

int contains(const int *arr, int size, int x) {
  for(int i = 0; i < size; i++)
    if(arr[i] == x)
      return 1;

  return 0;
}

void reverse(int *arr, int size) {
  int store;

  for(int i = 0; i < size / 2; i++) {
    store = arr[i];
    arr[i] = arr[size-(1+i)];
    arr[size-(i+1)] = store;
  }

  for(int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  return;
}

int orderStatistic(int *arr, int size, int i){
  int element = -1;
  int store;
  for(int j = 0; j < size; j++)
    for(int k = j + 1; k < size; k++)
      if (arr[j] > arr[k]) {
        store = arr[j];
        arr[j] = arr[k];
        arr[k] = store;
      }
  element = arr[i-1];

  return element;
}

  // TESTING //
  // TESTING //

int main(){

  int result;
  int numPassed = 0;
  int numFailed = 0;

  int arr[5] = {1,2,3,4,5};
  result = contains(arr, 5, 5);
  if(result != 1) {
    printf("FAILED: Array does contain 5\n");
    numFailed++;
   }
  else {
    printf("PASSED\n");
    numPassed++;
   }

  int arr2[5] = {2,4,6,8,10};
  result = contains(arr2, 5, 5);
  if(result != 0) {
    printf("FAILED: Array does not contain 5\n");
    numFailed++;
   }
  else {
    printf("PASSED\n");
    numPassed++;
   }

  int arr3[10] = {1,2,3,4,5,6,7,8,9,10};
  result = containsWithin(arr3, 10, 7, 3, 8);
  if(result != 1) {
    printf("FAILED: Array range does contain 7\n");
    numFailed++;
    }
   else {
      printf("PASSED\n");
      numPassed++;
    }

    int arr4[10] = {1,2,3,4,5,6,7,8,9,10};
    result = containsWithin(arr4, 10, 8, 1, 5);
    if(result != 0) {
       printf("FAILED: Array range does not contain 8\n");
       numFailed++;
     }
    else {
       printf("PASSED\n");
       numPassed++;
     }

    int arr5[10] = {10,9,8,7,6,5,4,3,2,1};
    result = orderStatistic(arr5, 10, 3);
    if(result != 3) {
      printf("FAILED: Array range does not contain 8\n");
      numFailed++;
    }
    else {
      printf("PASSED\n");
      numPassed++;
    }

    int arr6[10] = {2,4,6,8,10,1,3,5,7,9};
    result = orderStatistic(arr6, 10, 7);
    if(result != 7) {
      printf("FAILED: Array range does not contain 8\n");
      numFailed++;
    }
    else {
      printf("PASSED\n");
      numPassed++;
    }

    int arr7[10] = {1,2,3,4,5,6,7,8,9,10};
    reverse(arr7, 10);



  printf("Number Test Cases Passed: %6d\n", numPassed);
  printf("Number Test Cases Failed: %6d\n", numFailed);
  printf("Percent Passed:           %6.2f\n", 100.0 * numPassed / (numPassed + numFailed));

  return 0;
}

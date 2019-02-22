/*
 * File: array_utils.c
 * Author: Andres Ruiz and Teresa Gramer
 * Date: 2019/02/22
 *
 * A program that creates the functions containsWithin
 * contains, reverse, and orderStatistic
 *
 */

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

int main(){}

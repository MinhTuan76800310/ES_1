/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Embedded Systems from Coursera lab 1 source file>
 *
 *
 * @author <Pham Minh Tuan>
 * @date <11/06/2024>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test, SIZE);
}

/* Add other Implementation File Code Here */
void print_array(unsigned char *data, unsigned int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d", data[i]) ;
    printf("\n");
  }
}

int find_median(unsigned char *data, unsigned int size)
{
  int median;
  if (size % 2 == 0)
  {
    median = (data[size/2] + data[size/2 - 1]) / 2;
  }
  else
  {
    median = data[size/2];
  }
  return median;
}

int find_mean(unsigned char *data, unsigned int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += data[i];
  }
  return sum / size;
}

int find_maximum(unsigned char *data, unsigned int size)
{
  int max = data[0];
  for (int i = 1; i < size; i++)
  {
    if (data[i] > max)
    {
      max = data[i];
    }
  }
  return max;
}

int find_minimum(unsigned char *data, unsigned int size)
{
  int min = data[0];
  for (int i = 1; i < size; i++)
  {
    if (data[i] < min)
    {
      min = data[i];
    }
  }
  return min;
}

void print_statistics(unsigned char *data, unsigned int size)
{
  printf("Array: ");
  print_array(data, size);
  printf("Median: %d\n", find_median(data, size));
  printf("Mean: %d\n", find_mean(data, size));
  printf("Maximum: %d\n", find_maximum(data, size));
  printf("Minimum: %d\n", find_minimum(data, size));
}

void sort_array(unsigned char *data, unsigned int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (data[i] < data[j])
      {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
  }
}


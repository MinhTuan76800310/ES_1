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
 * @file <ES lab 1> 
 * @brief <Embedded Systems from Coursera lab 1  >
 *
 *
 * @author <Pham Minh Tuan>
 * @date <11/06/2024 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Print the statistics of an array including minimun, maximum, mean and median value
 *
 * This function will take an array of unsigned char data items and print statistics of the array.
 *
 * @param data The array of unsigned char.
 * @param size The size of the array
 *
 * @return void Print the statistics of the array
 */
void print_statistics(unsigned char *data, unsigned int size);

/**
 * @brief Print the array to the screen
 * 
 * This function will take an array of unsigned char data and print it to the screen
 * 
 * @param data The array of unsigned char
 * @param size The size of the array
 * 
 * @return void Print the array to the screen
*/
void print_array(unsigned char *data, unsigned int size);

/**
 * @brief Find the median value of the array
 * 
 * @param data The array of unsigned char
 * @param size The size of the array
 * 
 * @return The median value of the array
*/
int find_median(unsigned char *data, unsigned int size);

/**
 * @brief Find the mean value of the array
 * 
 * @param data The array of unsigned char
 * @param size The size of the array
 * 
 * @return The mean value of the array
*/
int find_mean(unsigned char *data, unsigned int size);

/**
 * @brief Find the maximum value of the array
 * 
 * @param data The array of unsigned char
 * @param size The size of the array
 * 
 * @return The maximum value of the array
*/
int find_maximum(unsigned char *data, unsigned int size);

/**
 * @brief Find the minimum value of the array
 * 
 * @param data The array of unsigned char
 * @param size The size of the array
 * 
 * @return The minimum value of the array
*/
int find_minimum(unsigned char *data, unsigned int size);

/**
 * @brief Sort the array from the largest to the smallest
 * 
 * @param data The array of unsigned char
 * @param size The size of the array
 * 
 * @return void Sort the array from the largest to the smallest
*/
void sort_array(unsigned char *data, unsigned int size);

#endif /* __STATS_H__ */

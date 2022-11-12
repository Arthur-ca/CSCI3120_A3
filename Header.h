//
// Created by ch243 on 2022-11-09.
//

#ifndef CSCI3120_A3_HEADER_H
#define CSCI3120_A3_HEADER_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define Max_Len 500
#define NUL '\0'
#define space ' '
#define True 1
#define False 0

//Able to read the file
FILE* input;
FILE* output;

//Global variable used in the program
char Input_str[Max_Len];
enum state { right, left };

/* structure for passing data to threads */
typedef struct {
    int starting_index;
    int ending_index;
} parameters;

/* structure for sorting data */
typedef struct{
    char data[Max_Len];
    struct node* left;
    struct node* right;
    int count;
} node;

#endif //CSCI3120_A3_HEADER_H

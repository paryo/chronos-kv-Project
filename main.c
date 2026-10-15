#include <stdio.h> // For standard Input/Output (printf, fgets)

#include <stdlib.h>  // For Memory Management (malloc, free)

#include <string.h> // // For String Operations (strcpy, strcmp, strlen)

// define fixed, clean limits for our keys and values so we don't accidentally overflow our memory buffer.

#define KEY_SIZE 50

#define VALUE_SIZE 100

// define fixed, clean limits for our keys and values so we don't accidentally overflow our memory buffer.


// 1. Defining the blueprint of a single Data Entry (Node)

struct key_value {

    char key[KEY_SIZE];   // To store the lookup key (e.g., "username")

    char value[VALUE_SIZE]; // To store the actual data (e.g., "rahul123")

    struct key_value* next; // Pointer to link another node in case of collisions


};



int main() {

    printf("---Baseline Setup Complete ---\n");

    return 0;


}
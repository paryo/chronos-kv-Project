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

#define TABLE_SIZE 10

unsigned int hash_function(const char* key) {

    unsigned long int value = 0;

    unsigned int i =0;

    unsigned key_len = strlen(key);


    // Loop through each character of the key

    for (i = 0 ; i <key_len ; i++) {

        value+= key[i];


    }

    // Ensure the index fits inside our table size

    return value % TABLE_SIZE;


}














int main() {

    printf("---Baseline Setup Complete ---\n");

    return 0;


}
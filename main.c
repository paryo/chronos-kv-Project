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

struct key_value* hash_table[TABLE_SIZE];


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

void init_hash_table() {


    for (int k =0 ; k <TABLE_SIZE ; k++) {

        hash_table[k] = NULL;

    }


}

void set(const char* target_key , const char* target_value) {

    unsigned int slot_index = hash_function(target_key);

    struct key_value* new_node = (struct key_value*)malloc(sizeof(struct key_value));


    if (new_node == NULL) {

        printf("[Error] System out of heap memory! Insertion failed.\n");

        return;
    }

    strcpy(new_node->key ,target_key);

    strcpy(new_node->value ,target_value);

    new_node->next = NULL;

    hash_table[slot_index] = new_node;

    printf("[Success] Stored '%s' at array index: %u\n", target_key, slot_index);


}





int main() {

    init_hash_table();


    printf("--- Initiating Live Data Insertion ---\n");


    set("username", "rahul123");

    unsigned int checked_index = hash_function("username");

    if (hash_table[checked_index] != NULL) {
        printf("--- Validation Success ---\n");
        printf("Verified Slot %u holds key: '%s' with payload: '%s'\n",
               checked_index,
               hash_table[checked_index]->key,
               hash_table[checked_index]->value);
    }

    return 0;


}
/* Project:     ArrayStack in C
 * File:        CArrayStack.h
 * Coder:       FunctionGHW
 * Version:     1.1
 * Last Change: 2013-5-9
 * Description: Stack for C implemented using array.
 *              This is the header file of arraystack.
 *              Note: We assume that the user will not modify the stack directly.
 *                    All operations must be done using functions which are declared here.
 */

#ifndef _CARRAYSTACK_E1AFBBBE_7627_4C18_8F56_72348535ED6D
#define _CARRAYSTACK_E1AFBBBE_7627_4C18_8F56_72348535ED6D

#include <stddef.h>

#ifndef TYPEDEF_BYTE
#define TYPEDEF_BYTE
typedef unsigned char BYTE;
#endif

typedef struct
{
    size_t size;
    size_t top;
    size_t elemt_size;
    BYTE* data;
} ArrayStack;

//Create a new array stack that has the specified size;
ArrayStack* new_arystk(size_t size, size_t elemt_size);

//Get the number of elements contained in the stack;
size_t arystk_count(const ArrayStack* stack);

//Get the maximum number of elements that the stack could contain currently;
size_t arystk_size(const ArrayStack* stack);

//Get the size of each element in the stack;
size_t arystk_elemt_size(const ArrayStack* stack);

//Check if the stack is full;
int arystk_is_full(const ArrayStack* stack);

//Check if the stack is empty;
int arystk_is_empty(const ArrayStack* stack);

//Insert an element into the top of the stack;
void arystk_push(ArrayStack* stack, const BYTE* elemt);

//Get the top element of the stack;
BYTE* arystk_peek(const ArrayStack* stack);

//Remove the top element, but don't return it;
void arystk_pop(ArrayStack* stack);

//Get the top element and remove it;
BYTE* arystk_peek_and_pop(ArrayStack* stack);

//Delete all elements of the stack;
void arystk_empty(ArrayStack* stack);

//Disopse the stack;
void arystk_dispose(ArrayStack* stack);

//Double the size of the stack;
void arystk_double_size(ArrayStack* stack);

#endif
// _CARRAYSTACK_E1AFBBBE_7627_4C18_8F56_72348535ED6D

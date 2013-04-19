/* Project:     ArrayStack in C
 * File:        CArrayStack.c
 * Coder:       FunctionGHW
 * Version:     1.0
 * Last Change: 2013-4-19
 * Description: Stack for C implemented using array.
 *              This is an inmplementation of CArrayStack.h.
 *              Note:   In most cases, users must check arguments before them passed,
 *                      we don't do much about handle these mistakes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CArrayStack.h"

/*You can change this size with your value, if it's necessary.*/
#define ARRAY_STACK_MAX_SIZE (((size_t)-1))

//Create a new array stack that has the specified size;
//Note: the size can not great than ARRAY_STACK_MAX_SIZE,
//      or the function will use ARRAY_STACK_MAX_SIZE as the size;
ArrayStack* new_arystk(size_t size, size_t elemt_size)
{
    if(size == 0 || elemt_size == 0)
    {
        return NULL;
    }

    if (size > ARRAY_STACK_MAX_SIZE)
    {
        size = ARRAY_STACK_MAX_SIZE;
    }
    size_t bytes_num = elemt_size * size;
    if ( (bytes_num / elemt_size) != size )
    {   //Arithmetic overflow;
        return NULL;
    }
    ArrayStack* newStack = (ArrayStack*)malloc(sizeof(ArrayStack));
    if (newStack == NULL)
    {
        return NULL;
    }

    newStack->data = (BYTE*)malloc(bytes_num);
    if (newStack->data != NULL)
    {
        newStack->size = size;
        newStack->elemt_size = elemt_size;
        newStack->top = 0;
    }
    else
    {
        free(newStack);
        newStack = NULL;
    }
    return newStack;
}

//Get the number of elements contained in the stack;
inline size_t arystk_count(const ArrayStack* stack)
{
    if (stack != NULL)
    {
        return stack->top;
    }
    else
    {
        return 0;
    }
}

//Get the maximum number of elements that the stack could contain currently;
inline size_t arystk_size(const ArrayStack* stack)
{
    if (stack != NULL)
    {
        return stack->size;
    }
    else
    {
        return 0;
    }
}

//Get the size of each element in the stack;
inline size_t arystk_elemt_size(const ArrayStack* stack)
{
    if (stack != NULL)
    {
        return stack->elemt_size;
    }
    else
    {
        return 0;
    }
}

//Check if the stack is full;
//Note: We assume that a null stack is always full;
inline int arystk_is_full(const ArrayStack* stack)
{
    if ( stack != NULL && stack->top < stack->size )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Check if the stack is empty;
//Note: We assume that a null stack is always empty;
inline int arystk_is_empty(const ArrayStack* stack)
{
    if (stack != NULL && stack->top > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Insert an element into the top of the stack;
void arystk_push(ArrayStack* stack, const BYTE* elemt)
{
    if (arystk_is_full(stack) || elemt == NULL)
    {
        return;
    }

    memcpy( (stack->data) + (stack->top) * stack->elemt_size, elemt, stack->elemt_size);
    stack->top++;
}

//Get the top element of the stack;
BYTE* arystk_peek(const ArrayStack* stack)
{
    if (arystk_is_empty(stack))
    {
        return NULL;
    }
    if (stack->elemt_size == 0)
    {   //Something wrong with your stack;
        return NULL;
    }
    BYTE* pCopy = (BYTE*)malloc(stack->elemt_size);
    if (pCopy != NULL)
    {
        memcpy(pCopy, stack->data + (stack->top - 1) * stack->elemt_size, stack->elemt_size);
    }
    return pCopy;
}

//Remove the top element, but don't return it;
void arystk_pop(ArrayStack* stack)
{
    if (arystk_is_empty(stack))
    {
        return;
    }
    else
    {
        stack->top--;
    }
}

//Get the top element and remove it;
BYTE* arystk_peek_and_pop(ArrayStack* stack)
{
    if (arystk_is_empty(stack))
    {
        return NULL;
    }
    if (stack->elemt_size == 0)
    {   //Something wrong with your stack;
        return NULL;
    }
    BYTE* pCopy = (BYTE*)malloc(stack->elemt_size);
    if (pCopy != NULL)
    {
        memcpy(pCopy, stack->data + (stack->top - 1) * stack->elemt_size, stack->elemt_size);
        stack->top--;
    }
    return pCopy;
}

//Delete all elements of the stack;
//Note: This function will not to decrease the size of stack;
inline void arystk_empty(ArrayStack* stack)
{
    if (stack != NULL)
    {
        stack->top = 0;
    }
}

//Disopse the stack;
//Note: After disposing, you need assign NULL to the stack if necessary;
void arystk_dispose(ArrayStack* stack)
{
    if (stack != NULL)
    {
        if (stack->data != NULL)
        {
            free(stack->data);
            stack->data = NULL;
        }
        free(stack);
    }
}

//Double the size of the stack;
//Note: If the new size is great than ARRAY_STACK_MAX_SIZE,
//      the function will use ARRAY_STACK_MAX_SIZE as new size;
void arystk_double_size(ArrayStack* stack)
{
    if (stack == NULL)
    {
        return;
    }

    size_t new_size = stack->size << 1;
    if (new_size > ARRAY_STACK_MAX_SIZE)
    {
        new_size = ARRAY_STACK_MAX_SIZE;
    }
    size_t old_bytes = stack->elemt_size * stack->size;
    size_t new_bytes = stack->elemt_size * new_size;
    if ( (new_bytes >> 1) != old_bytes )
    {
        return;
    }

    BYTE* tmp = (BYTE*)realloc(stack->data, new_bytes);
    if (tmp != NULL)
    {
        stack->data = tmp;
        stack->size = new_size;
    }
}

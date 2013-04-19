#include <stdio.h>
#include <stdlib.h>


/*
 to test CArrayStack Here;
*/
#include "CArrayStack.h"
void print_arr(int arr[], int len)
{
    int i;
    printf("{");
    for (i = 0; i < len; ++i)
    {
        printf("%d, ", arr[i]);
    }
    printf("}\n");
}

void chk_stack(ArrayStack* stack)
{
    printf("{\n");
    printf("    stack->size:%d\n", arystk_size(stack));
    printf("    stack->elemt_size:%d\n", arystk_elemt_size(stack));
    printf("    stack->top:%d\n", arystk_count(stack));
    printf("    stack->data:%x\n", (int)stack->data);
    printf("}\n");
}

int main()
{
    //printf("%d\n", sizeof(BYTE));
    int* tmp;
    int arr[] = {92, 93, 65, 66, 4, 5, 6, 7, 8, 9};
    ArrayStack* theStack = new_arystk(4, sizeof(arr[0]));
    if (theStack == NULL)
    {
        printf("stack NULL!\n");
        return -1;
    }
    //chk_stack(theStack);

    //print_arr(arr, sizeof(arr) / sizeof(arr[0]));
    arystk_push(theStack, (BYTE*)(arr + 0));
    arystk_push(theStack, (BYTE*)(arr + 1));
    arystk_push(theStack, (BYTE*)(arr + 2));
    arystk_push(theStack, (BYTE*)(arr + 3));
    chk_stack(theStack);
    arystk_push(theStack, (BYTE*)(arr + 4));
    arystk_push(theStack, (BYTE*)(arr + 5));
    chk_stack(theStack);

    while ( !arystk_is_empty(theStack))
    {
        tmp = (int*)arystk_peek_and_pop(theStack);
        printf("stack elemts count:%d, last pop: %d\n", arystk_count(theStack), *tmp);
        free(tmp);
        tmp = NULL;
    }

    arystk_double_size(theStack);
    chk_stack(theStack);
    arystk_push(theStack, (BYTE*)(arr + 4));
    arystk_push(theStack, (BYTE*)(arr + 5));
    arystk_push(theStack, (BYTE*)(arr + 0));
    arystk_push(theStack, (BYTE*)(arr + 1));
    arystk_push(theStack, (BYTE*)(arr + 2));
    arystk_push(theStack, (BYTE*)(arr + 3));
    chk_stack(theStack);

    while ( !arystk_is_empty(theStack))
    {
        tmp = (int*)arystk_peek_and_pop(theStack);
        printf("stack elemts count:%d, last pop: %d\n", arystk_count(theStack), *tmp);
        free(tmp);
        tmp = NULL;
    }

    return 0;
}

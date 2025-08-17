#include "apc.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
    int borrow = 0;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int negative_result = 0; // Flag to track if the result should be negative

    // First, determine which number is larger
    Dlist *larger_head = *head1, *larger_tail = *tail1;
    Dlist *smaller_head = *head2, *smaller_tail = *tail2;

    if (subc(head1, tail1, head2, tail2) == 2) 
    {
        // If `head2` is greater than `head1`, swap them
        larger_head = *head2;
        larger_tail = *tail2;
        smaller_head = *head1;
        smaller_tail = *tail1;
        negative_result = 1; // Result will be negative
    }

    // Reset temp pointers to start subtraction
    temp1 = larger_tail;
    temp2 = smaller_tail;

    while (temp1 != NULL || temp2 != NULL)
    {
        int n1 = (temp1 != NULL) ? temp1->data : 0;
        int n2 = (temp2 != NULL) ? temp2->data : 0;

        n1 -= borrow;

        if (n1 < n2)
        {
            n1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        int res = n1 - n2;

        // Insert the result at the beginning of the result list
        if (insert_at_first(headR, tailR, res) == FAILURE)
            return FAILURE;

        if (temp1 != NULL) temp1 = temp1->prev;
        if (temp2 != NULL) temp2 = temp2->prev;
    }

    // Remove leading zeros
    remove_zeros(headR, tailR);

    // If the result is negative, insert a negative sign
    if (negative_result && *headR != NULL)
    {
        (*headR)->data *= -1;
    }

    return SUCCESS;
 } 
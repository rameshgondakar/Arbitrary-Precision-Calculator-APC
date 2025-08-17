#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "apc.h"
//#include <stddef.h>

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{

	Dlist *temp1 = *tail1, *temp2 = *tail2;
    int sum = 0, data = 0, carry = 0;

    // Determine the signs of the numbers
    int sign1 = (temp1 != NULL && temp1->data < 0) ? -1 : 1;  // Sign of the first number
    int sign2 = (temp2 != NULL && temp2->data < 0) ? -1 : 1;  // Sign of the second number

    // If both numbers are positive (+ +)
    if (sign1 == 1 && sign2 == 1) {
        while (temp1 != NULL || temp2 != NULL) {
            int n1 = (temp1 != NULL) ? temp1->data : 0;
            int n2 = (temp2 != NULL) ? temp2->data : 0;

            sum = n1 + n2 + carry;
            data = sum % 10;

            // Insert at first
            if (insert_at_first(headR, tailR, data) == FAILURE)
                return FAILURE;

            carry = sum / 10;

            if (temp1 != NULL) temp1 = temp1->prev;
            if (temp2 != NULL) temp2 = temp2->prev;
        }
    }
    // If one number is positive and the other is negative (+ - or - +)
    else if (sign1 != sign2) {
        // Swap temp1 and temp2 to always subtract the smaller from the larger
        if (abs(temp1->data) < abs(temp2->data)) {
            Dlist *temp = temp1;
            temp1 = temp2;
            temp2 = temp;
        }

        // Handle addition/subtraction
        while (temp1 != NULL || temp2 != NULL) {
            int n1 = (temp1 != NULL) ? temp1->data : 0;
            int n2 = (temp2 != NULL) ? temp2->data : 0;

            sum = n1 - n2 + carry;
            data = sum % 10;

            // Insert at first
            if (insert_at_first(headR, tailR, data) == FAILURE)
                return FAILURE;

            carry = sum / 10;

            if (temp1 != NULL) temp1 = temp1->prev;
            if (temp2 != NULL) temp2 = temp2->prev;
        }
    }
    // If both numbers are negative (- -)
    else if (sign1 == -1 && sign2 == -1) {
        while (temp1 != NULL || temp2 != NULL) {
            int n1 = (temp1 != NULL) ? temp1->data : 0;
            int n2 = (temp2 != NULL) ? temp2->data : 0;

            sum = n1 + n2 + carry;
            data = sum % 10;

            // Insert at first
            if (insert_at_first(headR, tailR, data) == FAILURE)
                return FAILURE;

            carry = sum / 10;

            if (temp1 != NULL) temp1 = temp1->prev;
            if (temp2 != NULL) temp2 = temp2->prev;
        }
    }

    // If there is a carry left, insert it
    if (carry > 0) {
        if (insert_at_first(headR, tailR, carry) == FAILURE)
            return FAILURE;
    }

    // Remove leading zeros from the result
    remove_zeros(headR, tailR);

    return SUCCESS;

}

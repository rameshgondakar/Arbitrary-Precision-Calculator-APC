/*main.c

This is the entry point of the program. It processes command-line arguments,
converts the operands into doubly linked lists,
and then calls appropriate arithmetic operations based on the operator provided.
apc.c

This file contains shared utility functions such as remove_zeros (to clean up leading zeros) 
and addition (for adding two large numbers). These functions are used by other arithmetic operations.

addition.c

Implements the logic for adding two large numbers,
represented by doubly linked lists. This operation handles carry-over, 
and inserts the result into a new linked list.

subtraction.c

Implements the logic for subtracting one large number from another. 
It takes care of borrow operations and handles cases where the result might be negative.

multiplication.c

Implements the logic for multiplying two large numbers. 
This is done by multiplying each digit of the second number with each digit of the first number,
 adding the results, and managing carry operations.

division.c

Implements the logic for dividing two large numbers. 
It repeatedly subtracts the divisor from the dividend and counts how many times this can happen. 
It also handles edge cases like division by zero.
*/
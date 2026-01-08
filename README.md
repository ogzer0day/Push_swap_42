# This project has been created as part of the 42 curriculum by mzougari.

Description:

push_swap is a sorting algorithm project from the 42 curriculum.
The goal of this project is to sort a stack of integers using a limited set of operations while minimizing the number of moves.

The program takes a list of integers as input, places them into stack A, and sorts them in ascending order using stack B as auxiliary storage. Only specific operations (push, swap, rotate, reverse rotate) are allowed.

In this implementation, the sorting logic is based on a Least Significant Bit (LSB) radix sort strategy, which efficiently sorts numbers by processing their binary representation bit by bit.
____________________________________________________________________________________
# Instructions:

   *Compilation:

To compile the project, run:
	-make => This will generate the push_swap executable.
	
   *Execution:

Run the program by passing a list of integers as arguments, for exemple:
        -./push_swap 3 2 5 1 4 => The program will output a sequence of instructions that when applied will sort the stack.

   *Cleaning:
To remove object files and the executable:
	-make clean => To remove object files.
	-make fclean =>To remove object files and the executable.
_____________________________________________________________________________________________
# Algorithm Overview:

	-The numbers are first indexed to simplify comparisons.
	-The algorithm uses radix sort (LSB-first):
	
	    *It processes each bit starting from the least significant bit.
	    *Depending on the bit value, elements are pushed or rotated between stacks.
		
	-This approach ensures efficient sorting even for large input sizes.

# Resources:

    Technical References:
	
	-https://en.wikipedia.org/wiki/Radix_sort
	-https://www.geeksforgeeks.org/binary-representation-of-a-given-number/
	
    AI Usage Disclosure:
	
	-Clarifying the concept of LSB radix sort.
	-Reviewing explanations for clarity.

# Features:

- Efficient sorting using radix sort (LSB).

- Handles both small and large input sizes.

- Fully compliant with push_swap operation constraints.

- Memory-safe and norm-compliant (42 standards).

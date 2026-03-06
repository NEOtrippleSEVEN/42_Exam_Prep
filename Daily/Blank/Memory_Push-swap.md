
/* Memory Set-up 
size - number of elements

stack_a = allocate memory for (size integers)
stack_b = allocate memory for (size integers)

IF allocation failed 
	exit program 

stack_a --> [ ] [ ] [ ] [ ] [ ] [ ];
stack_b --> [ ] [ ] [ ] [ ] [ ] [ ];
			 0	 1 	 2 	 3 	 4 	 5 ;
*/

/*	 Initialising STACK_A

manually place values into memory using pointer access

*(stack_a + 0) = 5;
*(stack_a + 1) = 10;
*(stack_a + 2) = 4;
*(stack_a + 3) = 25;
*(stack_a + 4) = 50;
*(stack_a + 5) = 21;


Stack Position Tracking

top_a = size - 1 		// Last filled position
top_b = -1				// Empty stack

stack_a: 	[5][10][4][25][50][21]
								^^ Top A
stack_b;	[ ] [ ] [ ] [ ] [ ]
			^^ top b = -1 (empty)


After One push..
stack_a: 	[5][10][4][25][50][21]
								^^ Top A
stack_b;	[21] [ ] [ ] [ ] [ ]
				^^ top b = -1 (empty)

Value is moved instead of memory blocks. 
*/



/* PUSH OPERATION 

>> Take vlaue from top a
place onto top of B
uipdate both tops << 

IF stack_a is not empty
	increase top_b by
	random_value at stack_a[top_a]
		moves to
	stack_b[top_b]

	decrease top_a by 1



Pointer thinking is important here:

Instead of Array thinking:
	stack_b[top_b] = stack_a[top_a]

Implement Pointer thinking:
	*(stack_b + top_b) = *(stack_a + top_a);


Optional Mutiple PUshes 

FOR i from 0 to size -1 
	print *(stack_a + i)
>> Same goes for Stack_b <<
*/


/* When Converting to linked lists 

*(stack_b + top_b) = *(stack_a + top_a)
>> Becomes <<

node = pop from list A
push node into list B

*/

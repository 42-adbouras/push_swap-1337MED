# Introduction

`push_swap` is a sorting algorithm project that entails sorting two stacks using a limited set of instructions to sort the first stack with the fewest moves possible.

You start with two empty stacks, `a` and `b`. And you are given a random list of integers via command line arguments.

These are the allowed moves:

`sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.\
`sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.\
`ss` : sa and sb at the same time.

<p align="center">
<img src="https://github.com/42-adbouras/images/blob/master/push_swap/Screen%20Shot%202024-04-26%20at%204.42.37%20PM.png" style="width:700px"/>
</p>

`pa` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.\
`pb` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

<p align="center">
<img src="https://github.com/42-adbouras/images/blob/master/push_swap/Screen%20Shot%202024-04-26%20at%204.44.35%20PM.png" style="width:700px"/>
</p>

`ra` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.\
`rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.\
`rr` : ra and rb at the same time.

<p align="center">
<img src="https://github.com/42-adbouras/images/blob/master/push_swap/Screen%20Shot%202024-04-26%20at%204.43.18%20PM.png" style="width:700px"/>
</p>

`rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.\
`rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.\
`rrr` : rra and rrb at the same time.

<p align="center">
<img src="https://github.com/42-adbouras/images/blob/master/push_swap/Screen%20Shot%202024-04-26%20at%204.44.04%20PM.png" style="width:700px"/>
</p>

# Mandatory
* Implementation:
  I choosed to work with linked list to help me sort the stack a, this the structure that I went with:

```c
  typedef struct stack_list
  {
	  int					value; // This holds the actual value of an element.
	  int					index; // This is a refrence to where an element is locate on a stack.
	  int					pose;  // This is the final position to where an element true position.
	  struct stack_list	*next;
  }						t_stack;
```


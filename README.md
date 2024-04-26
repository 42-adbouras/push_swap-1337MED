# Introduction

`push_swap` is a sorting algorithm project that entails organizing two stacks using a limited set of instructions to sort a random list of integers with the fewest moves possible.

You start with two empty stacks, `a` and `b`. And you are given a random list of integers via the command line arguments.

These are the allowed moves:

`sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.\
`sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.\
`ss` : `sa` and `sb` at the same time.

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
`rr` : `ra` and `rb` at the same time.

<p align="center">
<img src="https://github.com/42-adbouras/images/blob/master/push_swap/Screen%20Shot%202024-04-26%20at%204.43.18%20PM.png" style="width:700px"/>
</p>

`rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.\
`rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.\
`rrr` : `rra` and `rrb` at the same time.

<p align="center">
<img src="https://github.com/42-adbouras/images/blob/master/push_swap/Screen%20Shot%202024-04-26%20at%204.44.04%20PM.png" style="width:700px"/>
</p>

# Mandatory
* Implementation:\
	I choosed to work with linked list to help me sort the stack a, this the structure that I went with:

	```c
	typedef struct stack_list
	{
		int					value;	// This holds the actual value of an element.
		int					index;	// This is a refrence to where an element is locate on a stack.
		int					pose;	// This is the final position to where an element true position.
		struct stack_list	*next;
	}						t_stack;
	```
 
	Fist I parse the command line arguments using `ft_split()` from `libft`, space being the delimeter. Then I convert the output to integers using slightly modified `ft_atoi()`, after that stack a is inicialized with atoi's output.
	From there I check if the newlly created stack is sorted or not, if it is I return and do nothing, else I check how Im going to sort the stack depending on its size.

* The Algorythems:\
	The algorythem is divided to four main parts to minimize the number of instructions.
	- Part I: If stack size miner than three.
 	- Part II: If stack size miner than five.
 	- Part III: If stack size miner than hundred.
 	- Part IV: If stack size major than hundred.

		* Part I : If stack size miner than three.\
			To sort three number is very easy and trivial, What I do, I check if the head is the bigger element, if so I execute `ft_ra()`, if thats not the case, I check if the second element is the biggest and I execute `ft_rra()`. Securing the bigger element at the tail, from here I 					compaire the first two element if the first element major than the second I execute `ft_sa()`. Now you have a sorted three element under two instruction.

		* Part II: If stack size miner than five.\
  			To sort five element I rely on the algorythem that sorts three element. What I do is look for the smallest two elements on the stack `a` and push them to stack `b`. I execute `ft_ra` or `ft_rra()` depending on the `index`, this last is crucial helping me to execute the least 				amount of instructions, if the element's index at the first half of the list I use `ft_ra()` else `ft_rra`, now that the smallest element at the head I push it to `b` repeating the process twice.\
    		With two element at stack `b` and three at stack `a`, I sort `a` with `ft_sort_three()` and push back the two elements using `ft_pa()`. And this is how I managed to sort five element.
      		
	











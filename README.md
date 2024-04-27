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
To sort three number is very easy and trivial, What I do, I check if the head is the bigger element, if so I execute `ft_ra()`, if thats not the case, I check if the second element is the biggest and I execute `ft_rra()`. Securing the bigger element at the tail, from here I compaire the first two element if the first element major than the second I execute you have a sorted three element under two instruction.

		* Part II: If stack size miner than five.\
To sort five element I rely on the algorythem that sorts three element. What I do is look for the smallest two elements on the stack `a` and push them to stack `b`. I execute `ft_ra` or `ft_rra()` depending on the `index`, this last is crucial helping me to execute the least 				amount of instructions, if the element's index at the first half of the list I use `ft_ra()` else `ft_rra`, now that the smallest element at the head I push it to `b` repeating the process twice.\
With two element at stack `b` and three at stack `a`, I sort `a` with `ft_sort_three()` and push back the two elements using `ft_pa()`. And this is how I managed to sort five element.
      		
		* Part III & IV:
  			I used the same algorythem with a small tweak if number of element is major than a hundred.\
I dont know what this algorythem originality or what it's trully called some say its `Bucket Sort` others say `Hourglass` on our campus they call it `The Range`. I pick it up from my peers and I tryed to optimize it, here how it goes:\
First I create a third stack (array of integers) identical to satack `a` values, and I sort it using insertion, then I set every element on stack `a` its final position. After that I choose a range `0 to 13` for elements less than a hundred, and `0 to 37`
for elements more than a hundred, don't ask me why I choose does numbers 😑. But trully when I was doing benchmarks on the algorythem those where the best average moves.\
Now that you have a range you check if the head of the stack `a` `pose` is between the range `0 <= pose <= 13`, if so you push it to `b` and you incrimant the range by one `1 to 14`, or if the `pose` is minor than the range `pose < 0 < 13`, you push it to `b` and execute `ft_rb`
placing the element at the tail, and don't forget to incrimant the range by one `1 to 14`. If non of those cases you simply rotate `a`, this was the firtst eteration, you repeate this until stack `a` is empty.

Now that stack `a` is empty, we are going to work on stack `b`. If everything went right, the element at stack `b` would be kind of sorted from the biggest to the smallest being at the middle. Now that `Hourglass` make some sence.
All we have to do now is look for the biggest element on stack `b` and rotate it the the head then push it back, same drill using `ft_rb()` or `ft_rrb` depending on the element's index wether it is on the first half or second, we repeat this untill `b` is empty.
And that is all to it you have a sorted stack `a`. 







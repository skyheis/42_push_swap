# PUSH SWAP: sorting algorithm with 2 stacks!

## Description

This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you'll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting. You have two stacks, A and B. Stack A contains a random number of either positive or negative numbers without any duplicates. Stack B is empty. The goal is to sort in ascending order numbers into stack A. To do this you have the following operations at your disposal:

- sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- ss : sa and sb at the same time.
- ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.
- pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

## My approach

I started by studing sort algorithm and the big O notation. After a lot of search I decide to follow an approch that I saw in a video, by reverse engineering the logic. This are the steps of my algorithm:

- Find a referent number in the stack A
- Push in the stack B all the numbers that are smaller than the referent number
- After a push in B, if the number is bigger than the half of the referent number, rotate the stack B
- Repeat the process recursively until there are 5 numbers in the stack B
- When there are 5 numbers in the stack B, order them with the smallest on the top
- The stack B is now divided in small groups of numbers
- Push back in the stack A right numbers until the small group is empty
- While the small group is not empty push in stack A and rotate it all the numbers in ascending order
- When a new right number is pushed in the stack A, check if the last number is the biggest of the stack B, if yes reverse rotate the stack A
- Repeat the process until the stack B is empty and A is sorted

It's a mix and readaptation of the quick sort algorithm and the insertion sort algorithm.

## What I learned

This is the first project where I had to write a complex algorithm. I learned a lot about the big O notation. I learned how to use the linked list data structure and how to use it to create a stack and I how to use the recursion to solve a problem. After all I'm really happy about the result.

## Test and visualization

I wrote my own [tester](git@github.com:skyheis/push_swap_moulinette) to check how many operations my algorithm need to sort a stack of 100 and 500 numbers. I also wrote a python [script](https://github.com/skyheis/push_swap_randomizer) to get a random series of numbers. A great visualization tool is [here](https://github.com/o-reo/push_swap_visualizer).

## Post considerations

When I first finished I was really happy about my work, but looking back after a few month I can see that there are a lot of things that I could have done better. The code is not really readable (for my standard) and the algorithm is not really efficient. I can see my big improvment in few month! I'm planning to refactor the code and improve the algorithm in the future.

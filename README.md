# Push_Swap

**Subject**: [Push_Swap](https://cdn.intra.42.fr/pdf/pdf/20315/en.subject.pdf)

**Member**: :last_quarter_moon_with_face: [Ymanzi](https://github.com/ymanzi) :first_quarter_moon_with_face:

## Challenge
Sort a random list of integers using the smallest number of moves, 2 stacks and a limited set of operations.

<img src="https://github.com/ymanzi/push_swap/blob/main/srcs/push_swap.gif" alt="gif" width=750 height=500>

## Instruction set
For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

Code    | Instruction           | Action
--------|-----------------------|----------------------------------------------
`sa`    | swap a                | swaps the 2 top elements of stack a
`sb`    | swap b                | swaps the 2 top elements of stack b
`ss`    | swap a + swap b       | both `sa` and `sb`
`pa`    | push a                | moves the top element of stack b at the top of stack a
`pb`    | push b                | moves the top element of stack a at the top of stack b
`ra`    | rotate a              | shifts all elements of stack a from bottom to top
`rb`    | rotate b              | shifts all elements of stack b from bottom to top
`rr`    | rotate a + rotate b   | both `ra` and `rb`
`rra`   | reverse rotate a      | shifts all elements of stack a from top to bottom
`rrb`   | reverse rotate b      | shifts all elements of stack b from top to bottom
`rrr`   | reverse rotate a + reverse rotate b   | both `rra` and `rrb`


## The Project
Create two programs: ``checker`` and ``push_swap``.

* **checker** : takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO
* **push_swap** : calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts integer arguments received.

## Algorythme

The simplest approach is to find the biggest number in stack A move it to stack B, and do it again and again until the stack is empty. Push All the stack B back to A and we would have the numbers sorted from biggest to smallest. This way works but it's inneficient.

Let's say i have a **random list** of 100 numbers from 0-99. Instead of sorting a big chunck of 100 numbers, it's better to sort 4 chuncks of 25 numbers.
* **step 1**: divide the big list in 4 chuncks (chunk 1 are numbers from 0-24, chunk 2: 25-49, chunck 3: 51-74, chunck 4: 75-99)
* **step 2**: Look for all the numbers from chunck 1 and move them to Stack B. Repeat until all the chuncks are in stack B.
* **step 3**: Push the maximum of the stack B to A, repeat until all the numbers are back to A.
* **step 4**: It's over. Your stack should be sorted

### Upgrade
* Instead of moving one chunck a time, move the smallest chunck and the biggest one at once

## Usage
Run ```make```.

The **checker** program is used as follows:
```c
  ./checker 5 2 3 1 4
```
```c
  ./checker "-50 -400 -20 -1 -100"
```
```c
  ./checker "-22" "35" "40" "-15" "75"
```

The **push_swap** program is used in the same way
```c
  ./push_swap 5 2 3 1 4
```

You can run the two together using:
```c
  ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
```

Run the visualizer
```c
  python3 pyviz.py `ruby -e "puts (1..99).to_a.shuffle.join(' ')"`
```

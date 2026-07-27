*This project has been created as part of the 42 curriculum by dode-lim, gucoelho*

# Push Swap

## Description
This project is about adapting a variety of sorting algorithms using a pre-defined and limited set of operations on a pair of integer stacks. The stacks will be called $A$ and $B$

#### The operations are:
 - Swap A (`sa`) swaps the first two elements at the top of stack $A$. Do nothing if there is only one or no elements.
 
 - Swap B (`sb`) swaps the first two elements at the top of stack $B$. Do nothing if there is only one or no elements.

 - Swap Both (`ss`) it performs `sa` and `sb` at the same time

 - Push A (`pa`) takes the first element at the top of $B$ and put it at the top of $A$. Do nothing if $B$ is empty

 - Push B (`pb`) takes the first element at the top of $A$ and put it at the top of $B$. Do nothing if $A$ is empty

 - Rotate A (`ra`) shifts up all elements of stack $A$ by one. The first element becomes the last one.

 - Rotate B (`rb`) shifts up all elements of stack $B$ by one. The first element becomes the last one.

 - Rotate Both (`rr`) it performs `ra` and `rb` at  the same time.

 - Reverse Rotate A (`rra`) shifts down all elements of stack $A$ by one. The last element becomes the first one.

 - Reverse Rotate B (`rrb`) shifts down all elements of stack $B$ by one. The last element becomes the first one.

 - Reverse Rotate Both (`rrr`) it performs `rra` and `rrb` at the same time.

The program will receive as input a sequence of integers that represents the stack $A$, being the first element the top of the stack. The program will output on `stdout` the [operations](#the-operations-are) needed in order to sort them in the stack $A$ using stack $B$ as auxiliary.

This project must contain at least one algorithm of each of the following complexity classes: $O(n^2)$, $O(n\sqrt{n})$ and $O(nlogn)$.

Those complexity classes reefer to the amount of [operations](#the-operations-are) needed to perform on the stack.

#### Disorder
In this project disorder is a number between 0 and 1 that tells how far your initial
stack $A$ is from being sorted. To calculate it, you can think of looking at all the possible pairs of numbers in the stack.
Each time a bigger number appears before a smaller one, that pair counts as a mistake.
The more mistakes you have, the closer the disorder is to 1.

In program's default behavior disorder is used to choose the algorithm to sort the stack following the thresholds below:

| Disorder   | Complexity Class |
| --------   | ---------------- |
| [0, 0.2)   | $O(n^2)$         |
| [0.2, 0.5) | $O(n\sqrt{n})$   |
| [0.5, 1]   | $O(nlogn)$       |

## Instructions
To compile the program is necessary to have <a href="https://www.gnu.org/software/make/" target="_blank">GNU Make</a>.
Once it is installed, you need to navigate to the root of the repository and run the command `make`.

This will build the `push_swap` excutable.

Synopsis:

&emsp; &emsp;push_swap [--bench] [--simple] [--medium] [--adpative] [INTEGERS]

Options:

&emsp; &emsp; --bench

&emsp; &emsp;&emsp; &emsp; it displays on `stderr` a report showing the choosen algorithm and associated complexity and a summary of operations

&emsp; &emsp; --simple

&emsp; &emsp;&emsp; &emsp; it forces the program to use an algorithm that has a complexity class of $O(n^2)$

&emsp; &emsp; --medium

&emsp; &emsp;&emsp; &emsp; it forces the program to use an algorithm that has a complexity class of $O(n\sqrt{n})$

&emsp; &emsp; --complex

&emsp; &emsp;&emsp; &emsp; it forces the program to use an algorithm that has a complexity class of $O(nlogn)$

&emsp; &emsp; --adaptive

&emsp; &emsp;&emsp; &emsp; it chooses the algorithm based on integers [disorder](#disorder) (default)

EXTRA:

&emsp; &emsp; --simple, --medium, --complex and --adaptive may be used together and the last option will override the others.

&emsp; &emsp;  [INTEGERS] must be a sequence of unique numbers between `INT_MIN` and `INT_MAX` of a 32 bit integer. Otherwise the program will throw `Error` in the `stderr`.

Example:

    $ ./push_swap --bench 5 4 3 2 1
    pb
    pb
    ra
    sa
    pa
    ra
    pa
    ra
    [bench] disorder:  100.00%
    [bench] strategy:  Adaptive / O(nlogn)
    [bench] total_ops:  8
    [bench] sa:  1  sb:  0  ss:  0  pa:  2  pb:  2
    [bench] ra:  3  rb:  0  rr:  0  rra:  0  rrb:  0  rrr:  0

## Algorithms
The selected algorithms for this project were insertion sort, chunk sort and radix sort.

Before any algorithm is executed, the input integers are normalized to $[0, size - 1]$ where $size$ is the size of stack $A$. For example an input of `13 22 -9` becomes `1 2 0`.

#### Insertion Sort

Insertion sort fits in the $O(n^2)$ complexity class and it is a good choice for this project since it takes good advantage of an almost sorted stack (i.e. a [disorder](#disorder) of 0.1).

The adaptation was made by considering stack $B$ as the already sorted stack and for every element on the top of stack $A$ we need to find its right position for insertion on stack $B$. Once we found that position, put the current element at that position on the top of $B$ by `rb` or `rrb` (any of which gives us the minimum amount of operations), and perform `pb`. By doing it repeatedly we will have a stack $B$ sorted in descending order.

Once we have the stack $B$ in descending order we need to put the greatest element on the and perform `pa` until stack $B$ is empty.

#### Chunk Sort

Chunk Sort fits in the $O(n\sqrt{n})$ complexity class.

The adaptation was made by having $\lceil \sqrt{n} \rceil$ chunks where each chunk has at most $\lfloor\sqrt{n}\rfloor$ elements and for first chunk all elements are between $[0, \lfloor\sqrt{n}\rfloor - 1]$, the second chunk elements are between $[\lfloor\sqrt{n}\rfloor, 2\lfloor\sqrt{n}\rfloor - 1]$, the third chunk elements are between $[2\lfloor\sqrt{n}\rfloor, 3\lfloor\sqrt{n}\rfloor - 1]$ and so on.

For example a stack with 9 elements from $[0, 8]$ will be separated into 3 chunks where the first one has a range of $[0, 2]$, $[3, 5]$, $[6, 8]$.

We will search in the stack $A$ for all elements that are in first chunk's range.

All those elements are going to be pushed to stack $B$.

After that we execute an insertion sort into this chunk.

For all the remaining numbers of stack $A$, new chunks will be created having ranges that respect the above pattern and the steps mentioned are going to be repeatedly executed until we have all the chunks on stack $B$ sorted in descending order.

Once we have stack $B$ sorted on descending order, we just need to perform `pa` until stack $B$ is empty.

#### Radix Sort

Radix Sort fits in the $O(nlogn)$ complexity class and it is a good choice for this project due to its simplicity in adaptation.

For radix sort, we will perform $k$ iterations, where $k$ is the amount of bits of the greatest number. On the $i-th$ iteration we need to make sure that stack $A$ is sorted in ascending order in regards to the $i$ least significant bits. We can achieve that by checking if, on the $i-th$ iteration, the element on the top of stack $A$ has its $i-th$ bit as 0 or 1. If it's 0, we perform `pb`, otherwise `ra`. This will keep all numbers with 1 on the $i-th$ bit in the stack $A$ and numbers with 0 on the $i-th$ bit on stack $B$. After that, performing `pa` until the stack $B$ is empty, will result in a stack $A$ having all integers with 0 in the $i-th$ bit to be above all integers with 1 in the $i-th$ bit.

## Resources

- [Complexity Analysis](https://www.geeksforgeeks.org/dsa/complete-guide-on-complexity-analysis/)
- [Stack data structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Classical quick sort](https://www.youtube.com/watch?v=wx5juM9bbFo&t=731s)
- [Classical radix sort](https://www.youtube.com/watch?v=XiuSW_mEn7g)
- [Standard output (stdout), error (stderr)](https://www.geeksforgeeks.org/linux-unix/shell-scripting-standard-input-output-and-error/)
- [GNU Make](https://www.gnu.org/software/make/)
- [Integer Limits](https://en.cppreference.com/c/types/limits)

AI was used to detect minor bugs while implementing algorithms.
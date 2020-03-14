# CH2 Pr5
In cryptarithmetic puzzles, mathematical equations are written using letters.
Each letter can be a digit from 0 to 9, but no two letters can be the same.
Here is a sample problem:
    `SEND + MORE = MONEY`

A solution to the puzzle is

| Code | Number |
|:----:|:------:|
|  S   |   9    |
|  R   |   8    |
|  O   |   0    |
|  M   |   1    |
|  Y   |   2    |
|  E   |   5    |
|  N   |   6    |
|  D   |   7    |

Write a program that finds solutions to the following cryptarithmetic puzzle:

    TOO + TOO + TOO + TOO = GOOD

The simplest technique is to use a nested loop for each unique letter (in ths case T, O, G, D).
The loops would systematically assign the digits from 0-9 to each letter.
For example, it might first try T = 0, O = 0, G = 0, D = 0, 
then T = 0, O = 0, G = 0, D = 1, etc.
up to T = 9, O = 9, G = 9, D = 9.

|  T  |  O  |  G  |  D  |
|:---:|:---:|:---:|:---:|
|  0  |  0  |  0  |  0  |
|  0  |  0  |  0  |  1  |
|  0  |  0  |  0  |  2  |
| ... |     |     |     |
|  9  |  9  |  9  |  9  |

In the loop body. test that each variable is unique and that the equation is satisfied.
Output the values for the letters that satisfy the equation. 
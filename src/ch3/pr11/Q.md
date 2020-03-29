# Ch3 Pr11
The game of Pig is simple two dice game in which the first player to reach 100 or more points wins.
Players take turns.

On each turn a player rolls a six-sided die:
* If the player rolls a 2-6 then he or she can either
  - **Roll again** <br> or
  - **Hold**.<br>
    At this point the sum of all rolls made this turn is added to the player's total score and it becomes the other player's turn.
* If the player rolls a 1 then the player loses his or her turn. <br>
  The player gets no new points and it becomes the opponent's turn.

If a player reaches 100 or more points after holding then the player wins.

Write a program that plays the game of Pig,
where one player is human and the other is the computer.
Allow the human to input "r" to roll again or "h" to hold.

The computer program should play according to the following rule:
keep rolling on the computer's turn until it has accumulated 20 or more points, then hold.
Of course, if computer wins or rolls a 1 then the turn ends immediately.

Allow the human to roll first.

Write your program using a least two functions:
```cpp=
int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);
```

These functions should perform the necessary logic to handle a single turn for either the computer or the human.
The input parameter is the total score for the human or computer.
The functions should return the turn total to be added to the total score upon completion of the turn.

For example:
If the human rolls a 3 and 5 and then holds, then `humanTurn` should return 9.
However, if the human rolls a 3 and 6 and 1, then th function should return 0.

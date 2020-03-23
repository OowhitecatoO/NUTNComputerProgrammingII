# Ch3 Pr9
In the game of craps, a "Pass Line" bet proceeds as follows.
the first roll of the two, six-sided dice in a craps round is called the "come out roll".
The bet immediately wins when the come out roll is 7 or 11,
and loses when the come out roll is 2, 3, or 12.
If 4, 5, 6, 8, 9, or 10 is rolled on the come out roll, that number becomes "**the point**".
The player keeps rolling the dice until either 7 or "**the point**" is rolled.
If **the point** is rolled first, then the player wins this bet.
If the player rolls a 7 first, then the player loses.

Write a program that plays craps using those rules so that it simulates a game without human input.
Instead of asking for a wager, the program should calculate whether the player would win or lose.
Create a function that simulates rolling the two dice and returns the sum.
Add a loop so that the program plays 10,000 games.
Add counters that count how many times the player wins, and how many times the player loses.
At the end of the 10,000 games, compute the probability of winning,
as `Wins / (Wins + Losses)`, and output this value.
Over the long run, who is go to win more games of craps, you or the house?

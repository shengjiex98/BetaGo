# Gomoku Go

## Description

Gomoku Go is a computer program that plays Gomoku (five-in-a-row). It utilizes an evaluation function to calculate a score for each vacuum space, and it always chooses the space with highest score as its next move. Now it plays at the level of my friends and I (we are only amateurs) and we can only occasionally beat it.

One current issue with the algorithm is that it makes illogical moves near the boundaries of the map. It gets inaccurate scores because the way it assigns a score is by looking for 4 spaces ahead in each direction from the space being evaluated. Hitting the boundaries makes the condition inconsistent in different situations.

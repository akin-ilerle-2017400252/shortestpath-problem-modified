## Problem Description
Ali Baba has become a trader - head of caravan with large amount of camels. Currently he is returning to his hometown Tehran. The way home leads through a land full of thieves. Fortunately the residents of the towns, forced to fight the thieves for centuries, have mastered preparing special coins to persuade the thieves to avoid robbery. They are now capable of avoiding the thieves via coins. Whenever a group of thieves see their favourite coin, they can let Ali Baba pass.
The land of Middle East is quite confusing: there are many towns, and many roads connect them. These roads do not cross outside the towns. Ali Baba has gathered all practical information about the land. He knows what kind of thieves he may come across on each of the roads and how much time he needs to walk it down. He also knows in which towns there are jeweler and what kinds of thieves can be avoided with the coins that they have.
But Ali Baba does not have any special coins to avoid thieves at the moment. He wants to get back to Tehran as soon as possible. As a trader he is quite ashamed that he does not know the best route, and that he has no special coins. Help him find the shortest path to Tehran such that whenever he could meet some group of thieves, previously he would have a chance to get an appropriate coin to avoid the group of thieves. Notice taht he can store unlimited number of special coins.

## Input Format
The first line of the input file holds four integers: n, m, p and k, separated by single spaces.
1. n: the number of towns (1 <= n <= 2,000)
2. m: the number of roads connecting the towns (0 <= m <= 3, 000)
3. p: the number of di↵erent kinds of thief groups (1 <= p <= 13)
4. k: the number of jewelers who have some special coins (0 <= k <= n)
The towns are numbered from 1 to n in such a way that n is Tehran’s number and 1 is the number of the town which Ali Baba starts in. The di↵erent kinds of thief groups are numbered from 1 to p.
In the following k lines, the profiles of successive jewelers are given, one per line. The (i + 1)-st line holds the integers wi, qi, ri,1 < ri,2 < ... < ri,qi , separated by single spaces. Note that a town may have more than one jeweler.
1. wi: the town id in which the jeweler lives (1 <= wi <= n)
2. qi: the number of different kinds of coins that the jeweler can provide
(1 <= qi <= p)
3. ri,1 < ri,2 < ... < ri,qi : the kinds of coins themselves in increasing order
(1 <= ri,j <= p)
The coin id corresponds the thief group id which it is produced for. For
example, Ali Baba needs to have coin type 3 in order to pass by thief group 3.
After that, there are m lines with road descriptions. The (k + i + 1)-th line holds the integers vi, wi, ti, si, ui,1 < ui,2 < ... < ui,si, separated by single spaces. No two roads connect the same pair of towns.
1. vi: thetowninthebeginningoftheroad(1 <= vi <wi <= n)
2. wi: thetownintheendoftheroad(1 <= vi < wi <=n)
3. ti: the time needed to walk down the road (same in both directions) (1 <= ti <= 500)
2
4. si: the number of di↵erent kinds of group of thieves that may appear onthatroad(0 <= si <= p)
5. ui,1 < ui,2 < ... < ui,si: the kinds of thieves groups themselves in increasing order (1 <= ui,j <= p)

## Output Format
Your program should print out the path to the output file. The path is a sequence of town ids in order of travel from starting town (1) to Tehran (n). The optimum path takes the minimum transfer time to reach Tehran.
If reaching Tehran is impossible, the output should be  -1.


## How to compile

In a terminal, call commands:
```
>cmake CMakeLists.txt

>make

OR

>cmake CMakeLists.txt && make

```
Make sure the executable is produced.

Then you can test the project with the command:
```
>./project3 inputFile outputFile
```

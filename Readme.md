Run the program:

./main (Already compiled binary)
or 
run g++ -std=c++11 main.o GameEngine.o solution.o BoardGame.o -o main
then ./main

Program will prompt for number of live cells.
Enter number of living cells

Program will prompt for coordinate of each cell.
Enter co-ordinates for each cell.
(in the form)

For e.g:
If input is 
    1, 1
    1, 2
    1, 3
    2, 2
    2, 3
    2, 4
then execution should something like this:

Enter the number of living cells
6
Enter co-ordinates for each cell
1
1
1
2
1
3
2
2
2
3
2
4

Output:

grid size 4 6
input cells----->
1 1
1 2
1 3
2 2
2 3
2 4
Shifted Grid at time step 0
0 0 0 0 0 0 
0 1 1 1 0 0 
0 0 1 1 1 0 
0 0 0 0 0 0 

Final live cells at next time step:

0, 2
1, 1
1, 4
2, 1
2, 4
3, 3

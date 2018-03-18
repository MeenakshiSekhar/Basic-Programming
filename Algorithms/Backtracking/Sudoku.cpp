/*
* Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits (from 1 to 9) 
* to the empty cells so that every row, column, and subgrid of size 3×3 contains exactly one instance 
* of the digits from 1 to 9.
*/
#include <iostream>
using namespace std;

bool findUnassigned(int grid[9][9], int &row, int &col)
{
    for( row=0; row<9; row++)
    {
        for( col=0; col<9; col++)
        {
            if(grid[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool isUsedRow(int grid[][9], int row, int num)
{
    for(int col=0; col<9; col++)
    {
        if(grid[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool isUsedCol(int grid[][9], int col, int num)
{
    for(int row=0; row<9; row++)
    {
        if(grid[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool isUsedBox(int grid[][9], int rowBeginIndex, int colBeginIndex, int num)
{
    for(int row=0; row<3; row++)
    {
        for(int col=0; col<3; col++)
        {
            if(grid[rowBeginIndex+row][colBeginIndex+col] == num)
            {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[][9], int row, int col, int num)
{
    return !isUsedRow(grid, row, num) &&
            !isUsedCol(grid, col, num) &&
            !isUsedBox(grid, row-row%3, col-col%3, num);
}

bool solveSudoku(int grid[9][9])
{
    int row, col;
    if(!findUnassigned(grid, row, col))
    {
        return true;
    }
    for(int num=1; num<=9; num++)
    {
    
        if(isSafe(grid, row, col,num))
        {
        	grid[row][col] = num;
            if(solveSudoku(grid))
            {
            	return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid(int grid[][9])
{
    for(int grid_i=0; grid_i<9; grid_i++)
    {
        for(int grid_j=0; grid_j<9; grid_j++)
        {
            cout<<grid[grid_i][grid_j]<<" ";
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int grid[9][9];
        for(int grid_i=0; grid_i<9; grid_i++)
        {
            for(int grid_j=0; grid_j<9; grid_j++)
            {
                cin>>grid[grid_i][grid_j];
            }
        }
        if(solveSudoku(grid))
        {
            printGrid(grid);
            cout<<endl;
        }
    }
	return 0;
}

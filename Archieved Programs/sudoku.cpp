#include <stdio.h>
int sudoku[9][9]; //array which stores the sudoku
void sudokusolve(int,int);
int rowcheck(int row,int num)
{//checking whether the number can be placed in the row or not
    int column;
    for(column=0;column<9;column++)
        if(sudoku[row][column]==num)
            return 0; // if number already there, we return 0
    return 1; // number not found anywhere, we return 1
}
//SCB

int columncheck(int column, int num)
{//checking whether the number can be placed in the column or not
    int row;
    for(row=0;row<9;row++)
        if(sudoku[row][column]==num)
            return 0;// if number already there, return 0
    return 1;// number not present, return 1
}
//SCB

int boxcheck(int row,int column,int num)
{// checking whether the number can be placed in the 3x3 box or not
    row = (row/3)*3;
    column = (column/3)*3;//getting the starting row and column for the box
    int r,c;
    for(r=0;r<3;r++)
        for(c=0;c<3;c++)
            if(sudoku[row+c][column+c]==num)
                return 0;//if number already present, return 0
    return 1;// if number can be placed, reeturn 1
}
//SCB

void navigate(int row,int column)
{// function to move to the next cell if we have filled one cell
    if(column<8)
        sudokusolve(row, column+1);
    else 
        sudokusolve(row+1,0);
}
//SCB

void display()
{//function to display the solved sudoku
    int row,column;
    printf("The Solved Sudoku is \n");
    for(row=0;row<9;row++)
    {
        for(column=0;column<9;column++)
            printf("%d",sudoku[row][column]);
        printf("\n");
    }
}
//SCB

void sudokusolve(int row,int column)
{
    if(row>8)// if the row number is greater than 8, we have filled all the blank cells!
        display();
    if(sudoku[row][column]!=0)
        navigate(row,column);//if the number filled in the cell is non zero, then it is filled with some appropriate value and move further
    else
    {
        int counter;//counter to check numbers from 1 to 9 whether the number should be filled or not
        for(counter=1;counter<=9;counter++)
        {// check for validity in row, column and box
            if((rowcheck(row,counter)==1)&&(columncheck(column,counter)==1)&&(boxcheck(row,column,counter)==1))
            {
                sudoku[row][column]=counter;
                navigate(row,column);
            }
        }
        sudoku[row][column]=0;//no valid number found, so we clean up and return to the caller
    }
}
//SCB

int main() {
    int row,column;
    printf("Enter the desired Sudoku with unknown number to be 0 \n");
    for(row=0;row<9;row++)
        for(column=0;column<9;column++)
            scanf("%d",&sudoku[row][column]);
    sudokusolve(0,0);// START SOLVING THE SUDOKU!
    return 0;
}
//SCB
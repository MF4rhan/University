#include<stdio.h>
void update_status(int rows,int columns,int grid[rows][columns]);
void query_status(int rows,int columns,int grid[rows][columns]);
void run_diagnostic(int rows,int columns,int grid[rows][columns]);
int main()
{
    int rows,columns,power_status=0,overload_warning=1,maintainance_required=2,choice;
    printf("Enter the total number of rows for grid\n");
    scanf("%d",&rows);
    printf("Enter the total number of columns for the grid\n");
    scanf("%d",&columns);
    int grid[rows][columns];
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<columns;j++)
        {
            grid[i][j]=0;
        }
    }
    do
    {
        printf("WELCOME TO POWER GRID MONITORING SYSTEM\n");
        printf("Select an option from the following\n");
        printf("1.Update sector status\n2.Query sector status\n3.Run system diagnostic\n4.Exit the system\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            update_status(rows,columns,grid);
            break;
            case 2:
            query_status(rows,columns,grid);
            break;
            case 3:
            run_diagnostic(rows,columns,grid);
            break;
            case 4:
            printf("Exiting the system\n");
            break;
            default:
            printf("invalid inputs\n");
        }
    }while (choice!=4);
}
void update_status(int rows,int columns,int grid[rows][columns])
{
    int row,column,option,kind;
    printf("Enter the row and column of a particular sector (row column)\n");
    scanf("%d %d",&row,&column);
    if (row<0 || row>=rows || column<0 || column>=columns)
    {
        printf("invalid input\n");
    }
    printf("Enter the option which status you want to update\n");
    printf("0 for power status\n1 for overload warning\n2 for maintainance required\n");
    scanf("%d",&option);
    printf("what kind of status you want to update (1 for ON and 0 for OFF)\n");
    scanf("%d",&kind);
    if (kind==1)
    {
        grid[row][column]= grid[row][column]|(1<<option);
    }
    else
    {
        grid[row][column]=grid[row][column]&~(1<<option);
    }
    printf("STATUS UPDATED SUCCESSFULLY\n");
    return;
}
void query_status(int rows,int columns,int grid[rows][columns])
{
    int row,column,power=0,overload=0,maintainance=0;
    printf("enter the row and column of a particular sector(row column)\n");
    scanf("%d %d",&row,&column);
    if (row<0 || row>=rows || column<0 || column>=columns)
    {
        printf("invalid input\n");
    }
    if (grid[row][column]&(1<<0))
    {
        printf("Power=ON\n");
    }
    else
    {
        printf("Power=OFF\n");
    }
    if (grid[row][column]&(1<<1))
    {
        printf("Overload=ON\n");
    }
    else
    {
        printf("Overload=OFF\n");
    }
    if (grid[row][column]&(1<<2))
    {
        printf("Maintainance=ON\n");
    }
    else
    {
        printf("Maintainance=OFF\n");
    }
    printf("QUERY UPDATED SUCCESSFULLY\n");
}
void run_diagnostic(int rows,int columns,int grid[rows][columns])
{
    int Overload=0,Maintainance=0;
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<columns;j++)
        {
            if (grid[i][j]&(1<<1))
            {
                Overload++;
            }
            if (grid[i][j]&(1<<2))
            {
                Maintainance++;
            }
        }
    }
    printf("RUN SYSTEM DIAGNOSTIC\n");
    printf("overload sectors=%d\n",Overload);
    printf("Maintainance needed sectors=%d",Maintainance);
}
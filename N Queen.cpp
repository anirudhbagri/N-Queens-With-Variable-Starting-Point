#define N 8
#include<stdio.h>

void printSolution(int board[N][N])
{
	printf(" ");
	for (int y = 0; y < N; y++)
            printf(" %2d",y);
    printf("\n");
    for (int i = 0; i < N; i++)
    {
    	printf("%d ",i);
        for (int j = 0; j < N; j++)
            board[i][j]?printf(" Q "):printf(" - ");
        printf("\n");
    }
}
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < N; i++)
        if (board[row][i])
            return false;

	for (i = 0; i < N; i++)
        if (board[i][col])
            return false;

    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;
            
    for (i=row, j=col; i>=0 && j<N; i--, j++)
        if (board[i][j])
            return false;

    for (i=row, j=col; j<N && i<N; i++, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col,int stop)
{
    if(col == stop)
    	return true;
    for (int i = 0; i < N; i++)
    {
        if ( isSafe(board, i, col) )
        {
            board[i][col] = 1;

            if ( solveNQUtil(board, (col + 1)%N, stop) )
                return true;
            board[i][col] = 0; 
        }
    }
    return false;
}
bool solveNQ()
{
    int board[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0},
        				        {0, 0, 0, 0, 0, 0, 0, 0},
        				        {0, 0, 0, 0, 0, 0, 0, 0},
        				        {0, 0, 0, 0, 0, 0, 0, 0},
						            {0, 0, 0, 0, 0, 0, 0, 0},
        				        {0, 0, 0, 0, 0, 0, 0, 0},
        				        {0, 0, 0, 0, 0, 0, 0, 0},
        				        {0, 0, 0, 0, 0, 0, 0, 0}
   					          };
	int x1,y1;
	printf("Enter position of 1 Queen: ");
	scanf("%d %d",&x1,&y1);
	board[x1][y1]=1;
	
    if ( solveNQUtil(board, (y1+1)%N, y1) == false )
    {
      printf("Solution does not exist");
      return false;
    }
	
    printSolution(board);
    return true;
}

int main()
{
    solveNQ();
    return 0;
}

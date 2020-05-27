
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		
		if (SolveSudoku(grid) == true)  
            printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}// } Driver Code Ends

void printGrid(int mat[N][N])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cout<<mat[i][j]<<" ";
    }
}
bool isrow(int mat[N][N],int row,int i)
{
    for(int col=0;col<N;col++)
    {
        if(mat[row][col] == i)
            return true;
    }
    return false;
}

bool iscol(int mat[N][N],int col,int i)
{
    for(int row=0;row<N;row++)
    {
        if(mat[row][col]==i)
            return true;
    }
    return false;
}

bool isbox(int mat[N][N],int boxrow,int boxcol,int i)
{
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(mat[row+boxrow][col+boxcol]==i)
                return true;
        }
    }
    return false;
}

bool issafe(int mat[N][N],int row,int col,int i)
{
    return !isrow(mat,row,i) && !iscol(mat,col,i) &&
        !isbox(mat,row-row%3,col-col%3,i) && mat[row][col] == 0;
}

bool findlocation(int mat[N][N],int &row,int &col)
{
    for(row=0;row<N;row++)
    {
        for(col=0;col<N;col++)
        {
            if(mat[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool SolveSudoku(int grid[N][N])  
{ 
    int row,col;
    if(!findlocation(grid,row,col))
        return true;
    
    for(int i=1;i<=9;i++)
    {
        if(issafe(grid,row,col,i))
        {
            grid[row][col]=i;
            if(SolveSudoku(grid))
                return  true;
            
            grid[row][col]=0;
        }
    }
    return false;
}

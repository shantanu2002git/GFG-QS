//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends


class Solution 
{
    public:
    int solved=0;
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        int empty[9][9], i, j, row[9][10], column[9][10], k;
        int square[9][10];
     
        for(i=0; i<9; i++)
        {
            for(j=0; j<10; j++)
            {
                row[i][j]=column[i][j]=square[i][j]=0;
            }
        }
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                if(grid[i][j]==0){
                    empty[i][j]=1;
                }else{
                    row[i][grid[i][j]]++;
                    column[j][grid[i][j]]++;
                    
                    square[calculate_grid(i, j)][grid[i][j]]++;
                    empty[i][j]=0;
                }
            }
        }
        
        fillGrid(grid, empty, 0, 0, row, column, square);
        
        if(solved==1){
            return true;
        }else{
            return false;
        }
    }
    
    void fillGrid(int grid[N][N], int empty[][9], int i, int j, int row[][10], int column[][10], int square[][10])
    {
        if(i==9){
          
            if(checkGrid(row, column, square, grid)==true){
                solved=1;
            }
            return;
        }
        
        if(empty[i][j]==1){
            for(int k=1; k<=9 && solved==0; k++)
            {
                if(row[i][k]==1 || column[j][k]==1 || square[calculate_grid(i, j)][k]==1){
                    continue;
                }
                grid[i][j]=k;
                row[i][k]++;
                column[j][k]++;
                square[calculate_grid(i,j)][k]++;
                
                if(j==8){
                    fillGrid(grid, empty, i+1, 0, row, column, square);
                }else{
                    fillGrid(grid, empty, i, j+1, row, column, square);
                }
                
                row[i][k]--;
                column[j][k]--;
                square[calculate_grid(i, j)][k]--;
            }
        }else{
            if(j==8){
                fillGrid(grid, empty, i+1, 0, row, column, square);
            }else{
                fillGrid(grid, empty, i, j+1, row, column, square);
            }
        }
    }
    
    bool checkGrid(int row[][10], int column[][10], int square [][10], int grid[N][N])
    {
        bool ans=true;
        int i, j, k;
        
        
        for(i=0; i<9; i++)
        {
            for(j=1; j<=9; j++)
            {
                if(row[i][j]!=1){
                    ans=false;
                    break;
                }
            }
        }
        for(i=0; i<9; i++)
        {
            for(j=1; j<=9; j++)
            {
                if(column[i][j]!=1){
                    ans=false;
                    break;
                }
            }
        }
        for(i=0; i<9; i++)
        {
            for(j=1; j<=9; j++)
            {
                if(square[calculate_grid(i, j-1)][j]!=1){
                    ans=false;
                    break;
                }
            }
        }
        return ans;
    }
    
    int calculate_grid(int i, int j)
    {
        if(i<=2 && j<=2){
            return 0;
        }else if(i<=2 && j<=5){
            return 1;
        }else if(i<=2 && j<=8){
            return 2;
        }else if(i<=5 && j<=2){
            return 3;
        }else if(i<=5 && j<=5){
            return 4;
        }else if(i<=5 && j<=8){
            return 5;
        }else if(i<=8 && j<=2){
            return 6;
        }else if(i<=8 && j<=5){
            return 7;
        }else if(i<=8 && j<=8){
            return 8;
        }
    }
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        int i, j;
        
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
    }
    
};



//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
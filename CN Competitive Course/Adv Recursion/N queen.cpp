// https://stackoverflow.com/questions/26670757/difference-between-backtracking-and-recursion

#include<bits/stdc++.h>
using namespace std;


int board[11][11];

bool isPossible(int n,int row,int col){
	//in the same line cases
	for(int i=row-1;i>=0;i--){
		if(board[i][col]==1)
			return false;
	}

	//upper left diagonal line cases
	for(int i=row-1,j=col-1;i>=0 && j>=0;j--,i--){
		if(board[i][j]==1)
			return false;
	}
	//upper right diagonal line cases
	for(int i=row-1,j=col+1;i>=0 && j<n;j++,i--){
		if(board[i][j]==1)
			return false;
	}
	return true;


}

void nQueenHelper(int n, int row){
	if(row==n){
		//we have reached a solution
		//print board matrix
		//return
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
		}
		cout<<endl;
		return;
	}
	//place at all possible positions(1 row me hoga to 1 hi position vese) and move to smaller problem(next row)

	for(int j=0;j<n;j++){
		if(isPossible(n,row,j)){
			board[row][j]=1;
			nQueenHelper(n,row+1);
			board[row][j] = 0;
		}
	}
	return;

}


void placeNQueens(int n){
	memset(board,0,11*11*sizeof(int));
	nQueenHelper(n,0);
}

int main(){



}
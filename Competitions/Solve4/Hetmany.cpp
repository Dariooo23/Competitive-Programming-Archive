//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>>& board,int row,int col,int N){
    for(int i=0;i<N;i++) {
        if(board[row][i]==1 || board[i][col]==1){
            return false;
        }
    }

    int i=row-1;
    int j=col-1;
    while(i>=0 && j>=0) {
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    }

    i = row-1;
    j = col+1;
    while (i>=0 && j<N){
        if (board[i][j]==1){
            return false;
        }
        i--;
        j++;
    }

    return true;
}

int placeQueens(vector<vector<int>>& board, int row, int N){
    if(row==N){
        return 1;
    }

    int count=0;

    for (int col=0;col<N;col++){
        if(isSafe(board,row,col,N)){
            board[row][col]=1;
            count=count+placeQueens(board,row+1,N);
            board[row][col]=0;
        }
    }

    return count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n, 0));
    int numSolutions=placeQueens(board,0,n);
    cout<<numSolutions;
    return 0;
}
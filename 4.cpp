#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n){
        int rowDup = row;
        int colDup = col;
        while(rowDup >=0 && colDup >= 0){
            if(board[rowDup][colDup] == 'Q') return false;
            rowDup--;
            colDup--;
        }

        rowDup = row;
        colDup = col;
        while(colDup >= 0){
            if(board[rowDup][colDup] == 'Q') return false;
            colDup--;
        }

        rowDup = row;
        colDup = col;
        while((rowDup < n)&&(colDup >= 0)){
            if(board[rowDup][colDup] == 'Q') return false;
            rowDup++;
            colDup--;
        }
        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row < n; row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        
        string s(n, '.'); //trying to put a string n in vector board
        
        for(int i = 0;i < n;i++){
            board[i] = s;
        }
        
        solve(0, board, ans, n);
        
        for(int i = 0;i < n;i++){
        	for(int j = 0;j < n;j++){
     			cout<<ans[i][j]<<endl;
        	}
        	cout<<endl;
        }
        return ans;
    }
};


int main() {
	int n = 0;
    Solution s1;
    cout<<"Enter the n : ";
    cin>>n;
    
    s1.solveNQueens(n);
    
    return 0;
}
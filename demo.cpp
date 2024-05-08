#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<string> board, int n){
        int rd = row;
        int cd = col;

        while(rd >= 0 && cd >=0){
            if(board[rd][cd] == 'Q') return false;
            rd--;
            cd--;
        }

        rd = row;
        cd = col;

        while(rd >= 0){
            if(board[rd][cd] == 'Q') return false;
            rd--;
        }

        rd = row;
        cd = col;

        while(rd >= 0 && cd < n){
            if(board[rd][cd] == 'Q') return false;
            rd--;
            cd++;
        }

        return true;
    }

    void solve(int row, vector<string> &board, vector<vector<string>> &ans, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0;col < n;col++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(row+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNqueens(int n){
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n,s);

        solve(0,board,ans,n);

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
    
    s1.solveNqueens(n);
    
    return 0;
}
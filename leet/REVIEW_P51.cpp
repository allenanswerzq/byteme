#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
void printVector(vector<string>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << endl;;
    cout <<"] " << endl;
}

bool isValid(vector<string>& board, int x, int y) {
	int n = board.size();
	// check row
	for (int i=0; i<n; i++) 
		if (i!=y && board[x][i] == 'Q') return false;
	// check cloumn
	for (int i=0; i<n; ++i) 
		if (i!=x && board[i][y] == 'Q') return false;
	// check left branch
	int i=x, j=y;
	while (i+1<n && j-1>=0) {
		if (board[i+1][j-1] == 'Q') return false;
		i++;
		j--;
	}
	i=x, j=y;
	while (i-1>=0 && j+1<n) {
		if (board[i-1][j+1] == 'Q') return false;
		i--;
		j++;
	}
	// check right branch
	i=x, j=y;
	while (i+1<n && j+1<n) {
	    //cout << "XXXXX: " << i+1<< " " << j+1 << " " << board[i+1][j+1] << endl;
		if (board[i+1][j+1] == 'Q') return false;
		i++;
		j++;
	}
	
	i=x, j=y;
	while (i-1>=0 && j-1>=0) {
	    //cout << "XXXXX: " << i-1<< " " << j-1 << " " << board[i-1][j-1] << endl;
		if (board[i-1][j-1] == 'Q') return false;
		i--;
		j--;
	}

	return true;
}

void bt(int x, vector<string>& board, vector<vector<string>>& res) {
  int n = board.size();
	if (x == n) {
		//printVector(board);
		res.push_back(board);
		return ;
	}

  for (int col = 0; col != n; ++col)
	  if (isValid(board, x, col)) {
      board[x][col] = 'Q';
      bt(x+1, board, res);
      board[x][col] = '.';
  	}

}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> res;
	string s;
	for (int i=0; i<n; ++i) s += '.';
	vector<string> board(n, s);
	bt(0, board, res); 
	return res;
}
};

int main(int argc, char** argv) {
    return 0;
}

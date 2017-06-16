#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

void printVector(vector<string>& v) {
    cout << "[ ";
    for (int x:v)
        cout << x << endl;;
    cout <<"] " << endl;
}

// two approachs
// 	1) backtracking
// 	2) dfs
bool isValid(vector<string> board, int x, int y) {

	return true;
}

void bt(int x, vector<string>& board, vector<bool>& visit, vector<vector<string>>& res) {
	if (x == board.size()) {
		printVector(board);
		res.push_back(board);
		for (int i=0; i<x; ++i) 
			visit[i] = false;
		return ;
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if(isValid(b
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> res;
	string s;
	for (int i=0; i<n; ++i) s += '.';
	vector<string> board(n, s);
	vector<bool> visit(n, false);
	bt(1, board, visit, res); 
	return res;
}

int main(int argc, char** argv) {
    return 0;
}

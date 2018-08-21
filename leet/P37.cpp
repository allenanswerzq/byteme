#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
            cout << x << " ";
    cout <<"] " << endl;
}

class Solution {
public:
bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i=0; i<9; ++i) {
        if (board[row][i]!='.' && board[row][i]==c) return false;
        if (board[i][col]!='.' && board[i][col]==c) return false;
        // NOTE: how to access square
        if (board[row/3*3 + i/3][col/3*3 + i%3]!='.' &&
            board[row/3*3 + i/3][col/3*3 + i%3]==c) return false;
    }
    return true;
}

bool bt(vector<vector<char>>& board) {
    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            if (board[i][j] == '.') {
                for (char c='1'; c<='9'; ++c) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if(bt(board))
                            return true;
                    }
                }
                board[i][j] = '.';
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    bt(board);
}


};
int main(int argc, char** argv) {
    return 0;
}

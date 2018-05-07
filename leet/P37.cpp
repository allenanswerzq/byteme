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

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
            cout << x << " ";
    cout <<"] " << endl;
}

bool isValidSudoku(vector<vector<char>>& board) {
    unsigned int rows[9] = {0};
    unsigned int cols[9] = {0};
    unsigned int area[9] = {0};
    for (int i=0; i<board.size(); ++i) {
        for (int j=0; j<board[0].size(); ++j) {
            if (board[i][j] == '.') return false;
            int idx = 1 << (board[i][j]-'0');
            //cout << idx << endl;
            if (rows[i] & idx || cols[j] & idx || area[i/3*3+j/3] & idx) 
                return false;
            rows[i] |= idx;
            cols[j] |= idx;
            area[i/3*3+j/3] |= idx;
            //cout << rows[i] << endl;
            //cout << cols[j] << endl;
            //cout << area[i/3*3+j/3] << endl;
        }
    }
    return true;
}

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i=0; i<9; ++i) {
        if (board[row][j]!='.' && board[row][j]==c) return false;
        if (board[i][col]!='.' && board[i][col]==c) return false;
        // NOTE: how to access square
        if (board[row/3*3 + i/3][col/3*3 + i%3]!='.' &&
            board[row/3*3 + i/3][col/3*3 + i%3]==c) return false;
    }
    return true;
}

bool bt(vector<vector<char>>& board) {
    for (int i=row; i<9; ++i) {
        for (int j=col; j<9; ++j) {
            if (board[i][j] == '.') {
                for (char c='1'; c<='9'; ++c) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if(bt(board))
                            return true;;
                        //else
                        //   board[i][j] = '.';
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

int main(int argc, char** argv) {
    return 0;
}

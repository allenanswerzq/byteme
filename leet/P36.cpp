#include<bits/stdc++.h>

using namespace std;

printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
            cout << x << " ";
    cout <<"] " << endl;
}

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    unsigned int rows[9] = {0};
    unsigned int cols[9] = {0};
    unsigned int area[9] = {0};
    for (int i=0; i<board.size(); ++i) {
      for (int j=0; j<board[0].size(); ++j) {
        if (board[i][j] == '.') continue;
        int idx = board[i][j]-'0';
        //cout << idx << endl;
        int t = 1 << idx;
        if (rows[i] & t || cols[j] & t || area[i/3*3+j/3] & t) 
          return false;
        rows[i] |= t;
        cols[j] |= t;
        area[i/3*3+j/3] |= t;
        //cout << rows[i] << endl;
        //cout << cols[j] << endl;
        //cout << area[i/3*3+j/3] << endl;
      }
    }
    return true;
  }
};

int main(int argc, char** argv) {
    return 0;
}

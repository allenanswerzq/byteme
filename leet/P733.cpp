#include <cstdio>
#include <stdio.h> // for using printf
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int main(int argc, char** argv) {
  return 0;
}

int color;
void dfs(vector<vector<int>>& image, int sr, int sc, int newColor) {
  if (sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || 
    image[sr][sc] != color) return;
  image[sr][sc] = newColor;
  dfs(image, sr-1, sc, newColor);
  dfs(image, sr+1, sc, newColor);
  dfs(image, sr, sc-1, newColor);
  dfs(image, sr, sc+1, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
  color = image[sr][sc];  
  if (color == newColor) return image;
  dfs(image, sr, sc, newColor);
  return image;
}
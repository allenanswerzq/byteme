#include<bits/stdc++.h>
using namespace std;

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

vector<vector<int>> floodFill(vvi& image, int sr, int sc, int newColor) {
  color = image[sr][sc];
  if (color == newColor) return image;
  dfs(image, sr, sc, newColor);
  return image;
}

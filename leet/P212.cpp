#include<bits/stdc++.h>
using namespace std;

// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]

// Use map TLE
void bt(vector<vector<char>>& board, map<string,int>& mp, map<string,int>& res,int x, int y, string path, 
	vector<vector<int>>& visit, int max_width)  {
	if (path.size() > max_width) return;
	if(mp.find(path) != mp.end()) {
		if (res.find(path) == res.end())
			res[path] = 1;
		// return;   Note: no return here. case aba abaa if aba is the word we are looking for. if returned maybe 
		// 									we cant find abaa in later travel.
	}
	vector<vector<int>> dirs = {{0,1},{0,-1},{1, 0}, {-1, 0}};
	visit[x][y] = 1;
	for (int i=0; i<4; ++i) {
		int next_x = x + dirs[i][0];
		int next_y = y + dirs[i][1];
		if (next_x>=0 && next_x<board.size() && next_y>=0 && next_y<board[0].size() && visit[next_x][next_y]==0) {
			path += board[next_x][next_y];
			bt(board, mp, res, next_x, next_y, path, visit, max_width);
			path.pop_back();
		}
	}	
	visit[x][y] = 0;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	if (words.size() <= 0) return {};
	map<string, int> mp;
	int max_width = 0;
	for (auto w: words) {
		mp[w] = 1;
		max_width = max((int)w.size(), max_width);
	} 

  map<string, int> res;
  string path="";
  vector<vector<int>> visit(board.size(), vector<int>(board[0].size(), 0));
  for (int i=0; i<board.size(); ++i) 
  	for (int j=0; j<board[0].size(); ++j) {
			bt(board, mp, res, i, j, path+board[i][j], visit, max_width);
		}

	vector<string> ret;
	for (auto m : res)
		ret.push_back(m.first);

	return ret;
}


class trieNode {
public:
  // if child[i] not null means its child node contains char 'a'+i
  trieNode *child[26]; 
  // if current is a leaf node, following the path from root to leaf we can get whole word
  bool isLeaf;  
  trieNode() {
  isLeaf = false;
  for (int i=0; i<26; ++i)
  child[i] = nullptr;
  } 
};


// Use Trie Accepted 
class Trie {
private:
  // root node of the trie
  trieNode *root;   
  trieNode *find(string key) {
  trieNode *node = root;
  for (int i=0; i<key.size() && node; ++i)
  node = node->child[key[i] - 'a'];
  return node;
  }

public:
  /** Initialize your data structure here. */
  Trie() {
  root = new trieNode();
  }
  
  /** Inserts a word into the trie. */
  void insert(string s) {
  trieNode *node = root;
  for (int i=0; i<s.size(); ++i) {
  if (node->child[s[i] - 'a'] == nullptr)
    node->child[s[i] - 'a'] = new trieNode();
  node = node->child[s[i] - 'a'];
  }
  node->isLeaf = true;
  }
  
  /** Returns if the word is in the trie. */
  bool search(string word) {
  trieNode *p = find(word);
  return p && p->isLeaf;
  }
  
  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
   trieNode *p = find(prefix); 
   return p != nullptr;
  }
};

#define sz(x) (int)(x).size()
#define vvc vector<vector<char>> 
#define vvi vector<vector<int>>

void bt(vvc& board, Trie root, map<string, int>& res,int x, int y, string path, vvi& visit, int max_width)  {
	if (path.size() > max_width) return;
	if (!root.startsWith(path)) return;

	if(root.search(path)) {
		res[path] = 1;
	}

	vector<vector<int>> dirs = {{0,1},{0,-1},{1, 0}, {-1, 0}};
	visit[x][y] = 1;
	for (int i=0; i<4; ++i) {
		int nx = x + dirs[i][0];
		int ny = y + dirs[i][1];
		if (0<=nx && nx<board.size() && 0<=ny && ny<board[0].size() && visit[nx][ny]==0) {
			path += board[nx][ny];
			bt(board, mp, res, nx, ny, path, visit, max_width);
			path.pop_back();
		}
	}	
	visit[x][y] = 0;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	if (words.size() <= 0) return {};
	Trie root = Trie();
	int max_width = 0;
	for (auto w: words) {
		root.insert(w);
		max_width = max((int)w.size(), max_width);
	} 

  map<string, int> res;
  string path="";
  vector<vector<int>> visit(board.size(), vector<int>(board[0].size(), 0));
  for (int i=0; i<board.size(); ++i) 
  	for (int j=0; j<board[0].size(); ++j) {
			bt(board, root, res, i, j, path+board[i][j], visit, max_width);
		}

	vector<string> ret;
	for (auto m : res)
		ret.push_back(m.first);

	return ret;
}
int main(int argc, char** argv) {
  return 0;
}

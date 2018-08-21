#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
    	cout << x << " ";
    cout <<"] " << endl;
}

bool dfs(string A, string B, int ai, int bi) {
	cout << "DFS: " << ai << " " << bi << endl;
	int p = A.size(), q = B.size();
	if (ai == p && q == bi) return true;
	// A: aa 
	// B: aaa
	if (ai == p && B[bi]!='*') return false;
	// A: aaa
	// B: aa
	if (bi == q)  return false;
	if(B[bi] == '*') {
		while (bi+1<q && B[bi+1]=='*')
			bi++;
		for (int i=ai; i<=p; ++i)
			if(dfs(A, B, i, bi+1)) return true;
	}
	if(A[ai]==B[bi] || B[bi]=='?')
		return dfs(A, B, ai+1, bi+1);
	return false;
}

bool isMatch(string A, string B) {
	return dfs(A, B, 0, 0);
}

int main(int argc, char** argv) {
	cout << " " << "?: " << isMatch("", "?") << endl;
	cout << " " << "*: " << isMatch("", "*") << endl;
	cout << isMatch("abbbbb", "a**********b") << endl;
	cout << "abefcdgiescdfimde " << "ab*cd?i*de: " << 
	   isMatch("abefcdgiescdfimde", "ab*cd?i*de") << endl; 	
    return 0;
}

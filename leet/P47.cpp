#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
      cout << x << " ";
    cout <<"] " << endl;
}

void bt(vector<int>& A, vector<int>& ans, vector<vector<int>>& res, vector<bool>& visit) {
	int n = A.size();
	if (ans.size() == n) {
		// printVector(ans);
		res.push_back(ans);
		return;
	}	

	for(int i=0; i<n; ++i) {
		if (visit[i]) continue;
		if (i>0 && A[i]==A[i-1] && visit[i-1]) continue;
		// cout << i << " " << A[i] << endl;
		visit[i] = true;
		ans.push_back(A[i]);
		bt(A, ans, res, visit); 
		ans.pop_back();
		visit[i] = false;
	}
}

vector<vector<int>> permute(vector<int>& A) {
	vector<vector<int>> res;
	vector<int> ans;
	vector<bool> visit(A.size(), 0);
	sort(A.begin(), A.end());
	bt(A, ans, res, visit);
	return res;
}

int main(int argc, char** argv) {
	int n[] = {1, 1, 2};
	vector<int> v(n, n+3);
	vector<vector<int>> res = permute(v);
	for (auto &a: res)
		printVector(a);
  return 0;
}


#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
            cout << x << " ";
    cout <<"] " << endl;
}

void bt(vector<int>& A, vector<int>& ans, vector<vector<int>>& res) {
	int n = A.size();
	if (ans.size() == n) {
		printVector(ans);
		res.push_back(ans);
		return;
	}	
	for(int i=0; i<n; ++i) {
		if (find(ans.begin(), ans.end(), A[i]) != ans.end()) 
			continue;
		ans.push_back(A[i]);
		bt(A, ans, res); 
		ans.pop_back();
	}
}

vector<vector<int>> permute(vector<int>& A) {
	vector<vector<int>> res;
	vector<int> ans;
	bt(A, ans, res);
	return res;
}

// permute num[begin..end]
// invariant: num[0..begin-1] have been fixed/permuted
void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
	if (begin >= num.size()) {
		// one permutation instance
		printVector(num);
		result.push_back(num);
		return;
	}
	
	for (int i = begin; i < num.size(); i++) {
		swap(num[begin], num[i]);
		permuteRecursive(num, begin + 1, result);
		// reset
		swap(num[begin], num[i]);
	}
}

vector<vector<int> > permute1(vector<int> &num) {
  vector<vector<int> > result;
  permuteRecursive(num, 0, result);
  return result;
}
    

int main(int argc, char** argv) {
	int n[] = {1, 1, 2};
	vector<int> v(n, n+3);
	permute(v);
    return 0;
}

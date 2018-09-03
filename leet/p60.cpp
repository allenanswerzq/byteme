#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	// naive approach
	// it accepted but cost is larger 129ms
	// i saw a algorithm can achive 3ms. big cost
	// need review sometime
	string getPermutation(int n, int k) {
		if (k<=0) return "";
		string s="";
		for (int i=1; i<=n; ++i)
			s += ('0' + i);
			
		while (--k > 0) {
			next_permutation(s.begin(), s.end());
		}
		
		return s;	
	}

	void bt(int k, int n, string ans, string& res) {
		if (ans.size() == n) {
			res = ans;
			return ;
		} else {
			for (int i=1; i<=n; ++i) {
				if (find(ans.begin(), ans.end(), '0'+i) != ans.end()) continue;
				ans.push_back('0'+i);
				bt(); 
				ans.pop_back();
			}
		}
	}

	// backtracking approach
	// not completed
	string getPermutation(int n, int k) {
		string res = "";
		bt(0, k, n, res);
		return res;
	}
};

int main(int argc, char** argv) {
  return 0;
}

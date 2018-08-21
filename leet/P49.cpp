#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Perfect!!!
// Accepted
// NOt that good but ok i think
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>> m;
	for (auto x:strs) {
	    string y = x;
	    sort(y.begin(), y.end());
		m[y].push_back(x);
	}	
	vector<vector<string>> ret;
	for (auto it=m.begin(); it != m.end(); ++it) {
		ret.push_back(it->second);
	}
	return ret;
}

int main(int argc, char** argv) {
    return 0;
}

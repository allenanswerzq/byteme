#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

string addBoldTag(string s, vector<string>& dict) {
	vector<pair<int, int>> tag;
	for (auto d:dict) {
		int x = 0;
		if ((x=s.find(d)) != string:npos) {
			cout << "X: " <<  x << endl;	
			if (tag.size() > 1) {
			}else {
				tag.push_back(make_pair(x, x+d.size()));
			}
		}
	}	
}

int main(int argc, char** argv) {
  return 0;
}

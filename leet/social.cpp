#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  for (auto x:v)
    printf("%d ", x); 
  printf("\n");
}

// Accepted 
// Airbnb interview problem 
// You can find problem description in current directory

int main(int argc, char** argv) {
		int n = 0;
		scanf("%d", &n);

		vector<int> counts(n, 0);
		for (int i=0; i<n; ++i)
			scanf("%d", &counts[i]);

		map<int, vector<int>> mp;
		for (int i=0; i<n; ++i)
			mp[counts[i]].push_back(i);

		set<vector<int>> s;

		for (auto m : mp) {
			int nums = m.first;
			vector<int> v = m.second;
			vector<int> g;
			int k = 0; 
			for (int i=0; i<v.size(); ++i) {
				g.push_back(v[i]);
				k++;
				if (k == nums) {
					s.insert(g);
					g.clear();
					k = 0;
				}
			}
		}
		
		for (auto v : s) {
			printVector(v);	
		}
  return 0;
}

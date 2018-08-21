#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

bool isgood(int x) {
	for (int i=0; i<INT_MAX; ++i) {
		if (i<x/2 && pow(4, i) == x) 
			return true;
		else if (i > x/2)
			return false;
	}
	return false;	
}

int main(int argc, char** argv) {
		int N, K;
		scanf("%d %d", &N, &K);
		
		queue<int> notes;
		map<int, int> mp;
		vector<int> res;

		for (int i=0; i<N; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);

			if (a == 1 ) {
				if (notes.size() < K) {
					notes.push(b);
					mp[b] = 1;	
				} else {
					int t = notes.front();
					notes.pop();
					mp[t] = 4;

					notes.push(b);
					mp[b] = 1;
				}
			}
			if (a == 2) {
				if (isgood(b)) { 
					res.push_back(0);
					continue;
				}
				if(notes.size() > 0) {
					if (mp.find(b)!=mp.end() && mp[b]==1)
						res.push_back(1);
					else
						res.push_back(0);
				}else
					res.push_back(0);
			}
		}

		printVector(res);
    return 0;
}

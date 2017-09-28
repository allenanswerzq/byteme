#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <queue>
#include <deque>
#include <stack>

using namespace std;


void eat(vector<int>& val, vector<int>& dt, int k) {
	int eat = -120;
	int idx = -1;

	for (int i=0; i<val.size(); ++i) {
		if (val[i] == eat && val[i]!=-120) {
			eat = dt[i] > dt[idx] ? val[i]: val[idx];
			idx = dt[i] > dt[idx] ? i: idx;
		} else {
			if (val[i] > eat) {
				eat = val[i];
				idx = i;
			} 
		}
	}
	val[idx] = -120;	
}

int check(vector<int>& val, vector<int>& dt) {
	int cnt = 0;	
	for (int i=0; i<val.size(); ++i) {
		if (val[i] != -120) {
			val[i] -= dt[i];
			if(val[i] > 0) cnt++; 
		}
	}
	return cnt;
}

int ff(vector<int>&val, vector<int>& dt, int m) {
	eat(val, dt, m);
	int t = check(val, dt);
	if (t < m ) return t;
	eat(val, dt, m);		
	return check(val, dt);

}

int main(int argc, char** argv) {
	int n=0, m=0;

	scanf("%d %d", &n, &m);

	vector<int> dt(n, 0);	
	vector<int> val(n, 0);

	for (int i=0; i<n; ++i) {
		scanf("%d %d", &val[i], &dt[i]);
	}	

	for (int i=0; i<INT_MAX; ++i) {
		int t;
		if ((t = ff(val, dt, m)) < m)  {
			for (int i=0; i<val.size(); ++i) {
				if (val[i] == -120) printf("-1\n");
				else if(val[i]<0 && val[i]!=-120) printf("0\n");
				else printf("%d\n", val[i]);
			}	
			break;	
		}
	}
	
	for () {
	}
  return 0;
}

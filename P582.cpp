#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector> 
#include <unordered_map>

using namespace std;

vector<int> helper(int kill, unordered_map<int, vector<int>> m) {
	vector<int> ret;
	if (m.find(kill) != m.end() ) {
		vector<int> v;
		v = m[kill];
		for (auto k : v) {
			vector<int> r =	helper(k, m);
			for (auto val : r)
				ret.push_back(val);
		}
		for (auto val: v) {
			ret.push_back(val);
		}
		return ret;
	} else {
	   return ret;
	}	   
}

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
	vector<int> ret;
	if (kill == 0) {pid.insert(pid.begin(), 0); return pid;}	
	unordered_map <int, vector<int>> m;
	for (int i=0; i<ppid.size(); ++i) {
		m[ppid[i]].push_back(pid[i]);
	}

	/* Time limited
	ret = helper(kill, m);
	ret.insert(ret.begin(), kill);
	*/
	// BFS
	/*ret.push_back(kill);
	for (int i=0; i<ret.size(); ++i) {
		int x = ret[i];
		for (int j : m[x]) ret.push_back(j);
	}*/
	// BFS queue 
	ret.push_back(kill);
	int queue[pid.size() + 1];
	int k = 0;
	queue[k++] = kill; // In queue
	while (k != 0) {  // isEmpty
		int x = queue[--k]; // out queue
		for (int v : m[x]) {
			queue[k++] = v;
			ret.push_back(v);
		}
	}
	return ret;
}

void printVector(vector<int> v) {
	cout << "[ " ;
	for (auto i: v) {
		cout << i << " ";
	}
	cout << "]" << endl;
}

int main(int argc, char **argv) {
	int n = 5;
	if (argc > 1)
		n = atoi(argv[1]);

	vector<int> pid({1,3,10,12,5});
	vector<int> ppid({3,0,5,5,3});
	printVector( killProcess(pid, ppid, n) );

	vector<int> pid01({6,1,3,9,5,8,7,4,10});
	vector<int> ppid01({5,8,4,5,10,5,3,8,0});
	printVector( killProcess(pid01, ppid01, n) );
	return 0;
}

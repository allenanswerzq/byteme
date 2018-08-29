#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& aa, int val) {
		int k = 0;
		for (int i = 0; i < aa.size(); ++i) {
			if (aa[i] != val) 
				aa[k++] = aa[i];
		}	
		return k;
	}
};

int main(){
	return 0;
}

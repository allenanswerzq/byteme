#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string countAndSay(int kk) {
		string ss = "1";
		while (--kk > 0){
			string res = "";
			for (int i = 0; i < ss.size(); ++i) {
				int k = 1;
				while (i < ss.size() - 1 && ss[i] == ss[i + 1]) {
					k++; i++;
				} 
				res += (char)(k + '0');
				res += ss[i];
			}
			ss = res;
		}
		return ss;
	}
};

void test(int kk) {
	Solution go;
	string ret = go.countAndSay(kk);
	cout << ret << endl;
}

int main(int argc, char** argv) {
	test(3);
	test(4);
	test(5);
	test(6);
	return 0;
}


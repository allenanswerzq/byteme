#include<bits/stdc++.h>

using namespace std;

string countAndSay(int n) {
	string s = "1";
	while (--n > 0){
		string ans = "";
		for (int i=0; i<s.size(); ++i) {
			int k = 1;
			while (i<s.size()-1 && s[i] == s[i+1]) {
				k++;
				i++;
			} 
			ans += (char)(k+'0');
			ans += s[i];
		}
		s = ans;
		cout << "S: " << s << endl;
	}
	return s;
}

int main(int argc, char** argv) {
	int n = 5;
	if( argc > 1) 
		n = atoi(argv[1]);
	cout << "RET: " << countAndSay(n) << endl;
	return 0;
}


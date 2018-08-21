#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
            cout << x << " ";
    cout <<"] " << endl;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else 
		return gcd(b, a%b);
}

int lcm(int a, int b) {
	return a*b / gcd(a, b);
}

// really awesome approach
// use istringstream so we dont need to parse nums
string fractionAddition(string expression) {
    istringstream in(expression);
    int A = 0, B = 1, a, b;
    char _;
    while (in >> a >> _ >> b) {
        A = A * b + a * B;
        B *= b;
        int g = abs(__gcd(A, B));
        A /= g;
        B /= g;
    }
    return to_string(A) + '/' + to_string(B);
}

// Wrong Approach 
// case parse nums not correctly
string fractionAddition(string s) {
    int A = 0, B = 1;
    s += 'x';
	while(s.size() > 0) {
          int idx = s.find('/');
          string t = s.substr(0, idx);
          int a = atoi(t.c_str());
          int kk = idx+1;
          int cnt = 0;
          while (s[kk]!='+' && s[kk]!='-' && s[kk]!='x'){
                  cnt++;
                  kk++;
          }
          string tt = s.substr(idx+1, cnt);
          int b = atoi(tt.c_str());
          A = A*b + B*a;
          B = B*b;
          int g = abs(__gcd(A, B));
          A /= g;
          B /= g; 

          if (s[kk] == 'x') break;
          s = s.substr(kk+1);
	}
    return to_string(A) + "/" + to_string(B);
}

// naive method
string fractionAddition1(string s) {
	vector<int> a;
	vector<int> b;
	vector<int> ops;
	int op = 0;
	s += '+';
	while(s.size() > 0) {
		int idx = s.find('/');
		string t = s.substr(0, idx);
		//cout << "A: " << t << endl;
		a.push_back(atoi(t.c_str()));
		int kk = idx+1;
		int cnt = 0;
		while (s[kk]!='+' && s[kk]!='-'){
			cnt++;
			kk++;
		}
		string tt = s.substr(idx+1, cnt);
		//cout << "B: " << tt << endl;
		b.push_back(atoi(tt.c_str()));
		ops.push_back(s[kk]=='+' ? 1:0);
		s = s.substr(kk+1);
		//cout << "REST: " << s << endl;
	}
	/*
	cout << "A: ";
	printVector(a);	
	cout << "B: ";
	printVector(b);	
	cout << "OPS: ";
	printVector(ops);	
*/	
	int cm = b[0];
	for (auto x: b) {
		cm = lcm(cm, x);	
	}
	int sum = cm / b[0] * a[0];
	int k = 0;
	for (int i=1; i<a.size(); ++i) {
		if (ops[k++] == 1) {
			sum += cm / b[i] * a[i];
		}else{
			sum -= cm / b[i] * a[i];
		}
	}
	int cd = gcd(sum, cm);
	sum /= cd;
	cm /= cd;
	cout << "SUM: " << sum << endl;
	cout << "LCM: " << cm << endl;
	string ret = "";
	if ((sum < 0) ^ (cm < 0)) {	
		ret += "-";
	}
	sum = sum<0 ? -sum : sum;
	ret += to_string(sum);
	ret += "/";
	cm = cm <0 ? -cm : cm;
	ret += to_string(cm);
	cout << "RET: " << ret << endl;
	return ret;
}

int main(int argc, char** argv) {
	cout << fractionAddition("-1/2+1/2") << endl;
	cout << endl;
	cout << fractionAddition("-1/2+1/2+1/3") << endl;
	cout << endl;
	cout << fractionAddition("1/3-1/2") << endl;
	cout << endl;
	cout << fractionAddition("1/3-1/2+1/2") << endl;
	cout << endl;
    return 0;
}

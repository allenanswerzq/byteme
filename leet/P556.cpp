#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	int nextGreaterElement(int n) {
		vector<int> buf(0);
		int i = 0;
		int minIndex = 0;
		for (int x=n; x; x=x/10) {
			buf.push_back(x%10);
			// buf[i++] = x%10;   not allowed
		}
		for (vector<int>::iterator it=buf.begin(); it != buf.end(); it++)
				cout << *it << " ";
		for (i=0; i<buf.size(); i++)
				cout << buf[i] << " ";

		reverse(buf.begin(), buf.end());
		for (i= buf.size()-2; i>=0; i--) {
			if (buf[i] < buf[i+1]) {
				minIndex = i+1;
				for (int k=i+1; k<buf.size(); k++)
						if (buf[k] > buf[i] && buf[k] < buf[minIndex])
								minIndex = k;
				swap(buf[i], buf[minIndex]);
				sort(buf.begin()+i+1, buf.end());
				
				long long result = 0; // need to be initialized
				for (i=0; i<buf.size(); i++)
					result = result*10 + buf[i];
				if (result <= INT_MAX)
					return result;		
				else
					return -1;
				
			}
		}

		return -1;
	}
};


int main() 
{
	Solution s;
	cout <<  s.nextGreaterElement(12);
	
	return 0;
}

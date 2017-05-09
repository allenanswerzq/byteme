// Sum of Middle Elements of two sorted arrays
// URL: http://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays/0
#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> a, vector<int> b) {
	int na = a.size();
 	int nb = b.size(); 
	vector<int> m(na+nb);
	int i = 0, j = 0;
	int k = 0;
	while (i < na && j < nb) {
		if (a[i] <= b[j])
			m[k++] = a[i++];
		else
			m[k++] = b[j++];
	}
	while (i < na)
		m[k++] = a[i++];
	while (j < nb)
		m[k++] = b[j++];

   return (m[(na+nb)/2] + m[(na+na)/2-1]);	
}
int main() {
    int testCnt = 0;
    cin >> testCnt;
 	cout << "Test: " << testCnt << endl;
    for (int i=0; i<testCnt; ++i)
    {
        int N = 0;
        cin >> N;
		cout << "Test: " << N << endl;
        vector<int> a, b;
		int t;
        for (int i=0; i<N; ++i) {
			cin >> t;
            a.push_back(t);
		}
		cout << "Input: ";
		for (auto i : a)
			cout << " " << i;
		cout << endl;
        for (int i=0; i<N; ++i) {
			cin >> t;
            b.push_back(t);
		}
		cout << "Input: ";
		for (auto i : b)
			cout << " " << i;
		cout << endl;

		cout << "Sum: " << merge(a, b) << endl;
    }
	//code
	return 0;
}

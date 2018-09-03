#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

void add(vector<int>& data, int lo, int hi) {
	for (int i=lo; i<=hi; ++i)
		data[50+i]++;
}

int main(int argc, char** argv) {
	int n=0, k=0;
	vector<int> data(102, 0);

	scanf("%d %d", &n, &k);
	
	for (int i=0; i<n; ++i) {
		int lo, hi;		
		scanf("%d %d", &lo, &hi);
		add(data, lo, hi);
	}	
	
	int i;
	for (i=0; i<102 && data[i]<k; ++i) {}
	int a = i - 50;
	for (i=100; i>=0 && data[i]<k; --i) {}
	int b = i - 50;
	if (a>50 || b<-50)
		printf("error\n");  
	else
		printf("%d %d\n", a, b);

  return 0;
}

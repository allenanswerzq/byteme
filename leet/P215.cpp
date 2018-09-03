#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define sz(x) (int)(x).size()
#define fori(i, a, b) for(int i=(a); i<(b); ++i)
#define pvi(x) for(auto &e : x) cout << e << " "; cout << endl

// Min heap
int findKthLargest(vector<int>& aa, int k) {
	priority_queue<int, vector<int>, greater<int>> pq;
  int n = sz(aa);
  fori (i, 0, n) {
  pq.push(aa[i]);
  if (sz(pq) >= k)
  pq.pop();
  }
  return pq.top();
}

// #define all(x) (x).begin(), (x).end()
// // MultiSet
// int findKthLargest(vector<int>& aa, int k) {
// 	multiset<int> mset(all(aa));
// 	int i=1;
// 	for (auto it=mset.rbegin(); it!=mset.rend(); ++it) {
// 		if (i++ >= k)
// 			return *it;
// 	}
// 	return 0;
// }

// Divide and conquer
int partition(vector<int>& aa, int left, int right) {
  int pivot = aa[left];
  int lo = left + 1, hi = right;
  while (lo < hi) {
  cout << lo << " " << hi << endl;
  pvi(aa);
  if (aa[lo] <= pivot && aa[hi] > pivot) {
  swap(aa[lo++], aa[hi--]);
  }
  if (aa[lo] >= pivot) ++lo;
  if (aa[hi] <= pivot) --hi;
  } 
  swap(aa[left], aa[hi]);
  return hi;
}

int findKthLargest(vector<int>& aa, int k) {
  int n = sz(aa);
  int lo = 0, hi = n - 1;
  while (1) {
  int pos = partition(aa, lo, hi);
  if (pos == k - 1) return aa[pos];
  else if (pos > k - 1) hi = pos - 1;
  else lo = pos + 1; 
  }
  return 0;
}

int main(int argc, char** argv) {
  vi aa = {3,2,3,1,2,4,5,5,6};
  int kk = 4;
  int r = findKthLargest(aa, kk);  
  cout << r << endl;
  return 0;
}

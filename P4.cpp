#include <iostream>
#include <vector>

using namespace std;
// Method 1: merge sort
// Method 2: median compare
// Method 3: count 
// Divide & conquer
// Below my code is not correct 
double find(vector<int>& a, vector<int>& b, int aStart, int aEnd, int bStart, int bEnd) {
	int na = aEnd - aStart + 1;
	int nb = bEnd - bStart + 1;
	if (na < 2 || nb < 2) {
		if (na == 1 && nb == 1) return (a[aStart] + b[bStart]) / 2.0;
		else if (na == 0 && nb == 1) return b[bStart];	
		else return a[aStart];
	}

	int aMid = na % 2 ? a[na/2] : (a[na/2] + a[na/2-1]) / 2;
	int bMid = nb % 2 ? b[nb/2] : (b[nb/2] + b[nb/2-1]) / 2;
	int aIdx = na % 2 ? na/2 - 1 : na/2;
	int bIdx = nb % 2 ? nb/2 - 1 : nb/2;
	if (aMid == bMid) return aMid;
	if (aMid > bMid) return find(a, b, aStart, aIdx, bIdx, bEnd);     
	else return find(a, b, aIdx, aEnd, bStart, bIdx);
}

double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
	int m = a.size();
	int n = b.size();
	return find(a, b, 0, m-1, 0, n-1);		
}
// count
// time complexity O(n+m)
double findMedianSortedArrays2(vector<int>& a, vector<int>& b) {
	int na = a.size();
	int nb = b.size();	
	int total = na + nb;
	int i = 0, j = 0, k = 0;
	int ans = 0;
	int tmp = 0;

	while (i < na || j < nb) {
		if ( i < na && j < nb) { 
			if (a[i] <= b[j]) tmp = a[i++];
			else tmp = b[j++];
		} else if (i < na) tmp=a[i++];
		else tmp = b[j++];
		if (k == total / 2) ans += tmp;
		if (total % 2 == 0 && k == total/2 -1 ) ans += tmp;
		k++;
	}
	if (total % 2 == 0) return ans / 2.0;
	else return ans;
}
// Merge sort
// time complexity O(m+n)
double findMedianSortedArrays1(vector<int>& a, vector<int>& b) {
	int na = a.size();
	int nb = b.size();	
	vector<int> v(na+nb);
	int i = 0, j = 0, k = 0;
	while (i < na && j < nb) {
		if (a[i] <= b[j]) {
			v[k++] = a[i++];
		} else {
			v[k++] = b[j++];
		}
	}
	while (i < na) {
		v[k++] = a[i++];
	}
	while (j < nb) {
		v[k++] = b[j++];
	}

	int total = na + nb;
	if (total % 2 == 0){
		cout << total << v[total/2] << v[total/2-1] << endl;
		return ( v[total/2] + v[total/2-1] ) / 2.0;
	}
	else
		return (v[total/2]);
}

int main()
{
	int a[] = {1, 3};
	int b[] = {2};
	vector<int> nums1(a, a+2);
	vector<int> nums2(b, b+1);

	cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl;
	int c[] = {1, 2};
	int d[] = {3, 4};
	vector<int> nums3(c, c+2);
	vector<int> nums4(d, d+2);
	cout << "Median: " << findMedianSortedArrays(nums3, nums4) << endl;


	return 0;
}

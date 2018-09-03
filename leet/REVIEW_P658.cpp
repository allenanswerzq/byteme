#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

int binary_search(vector<int> &arr, int tar) {
  int lo=0, hi=arr.size()-1;
  while (lo <= hi) {
    int mid = lo+(hi-lo)/2;
    if (arr[mid] == tar)
      return mid;
    else if (arr[mid] > tar) 
      hi = mid-1;
    else lo = mid+1;
  }
  return lo;
}

// Some wrong here
// but there have python better approch
// python sorted or lambda custom list sort
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  vector<int> res;
  int idx = binary_search(arr, x);
  int l = idx-1;
  int r = arr[idx] == x ? idx+1: idx;
  int c = arr[idx] == x ? 1: 0;
  if (arr[idx] == x) res.push_back(arr[idx]);
  while (c < k) {
    if (l>=0 && c<k) {
      res.insert(res.begin(), arr[l--]);
      c++;
    }
    if (r<arr.size() && c<k) {
        res.push_back(arr[r++]);
        c++;
    }
  }
  return res;
}

int main(int argc, char** argv) {
  return 0;
}

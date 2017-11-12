#include <cstdio>
#include <stdio.h> // for using printf
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
	// not conside overflow
  return (x && !(x & (x-1)));
}

int countOne (int n){
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

// 
vector<string> summaryRanges(vector<int>& nums) {
	vector<string> range;
	for (int i=0, start=0; i<nums.size(); ++i) {
		if (i==nums.size()-1 || nums[i+1]>nums[i]+1) {
			// current i is the end of previous range
			range.push_back(to_string(nums[start]));
			if (i > start) range.back() += "->" + to_string(nums[i]);
			// new range start
			start = i+1;
		}
	}        
	return range;
}

//
vector<string> summaryRanges(vector<int>& nums) {
	vector<string> range;
	int start = 0;	// range start pos
	for (int i=0; i<nums.size(); ++i) {
		while (i+1<nums.size() && nums[i]+1==nums[i+1]) 
			++i;			// sliding through range
		// current i is the end of this range
		range.push_back(to_string(nums[start]));
		if (i>start) range.back() += "->" + to_string(nums[i]);
		start = i+1;
	}
	return range;
}

int main(int argc, char** argv) {
  return 0;
}

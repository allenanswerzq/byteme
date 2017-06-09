#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
            cout << x << " ";
    cout <<"] " << endl;
}

int trap1(vector<int>& height)
{
    int ans = 0;
    int size = height.size();
    for (int i = 1; i < size - 1; i++) {
        int max_left = 0, max_right = 0;
        for (int j = i; j >= 0; j--) { //Search the left part for max bar size
            max_left = max(max_left, height[j]);
        }
        for (int j = i; j < size; j++) { //Search the right part for max bar size
            max_right = max(max_right, height[j]);
        }
		cout << max_left << " " << max_right << endl;
        ans += min(max_left, max_right) - height[i];
    }
    return ans;
}

int trap2(vector<int>& height)
{
    int ans = 0, current = 0;
    int st[height.size()];
	int k = 0;
    while (current < height.size()) {
        while (k && height[current] > height[st[k-1]]) {
            int top = st[k-1]; // index
           	k--; 
            if (!k)
                break;
            int distance = current - st[k-1] - 1;
			cout << k << " " << current << " " << st[k-1] << " " << top << endl;
            int bounded_height = min(height[current], height[st[k-1]]) - height[top];
            ans += distance * bounded_height;
        }
        st[k++] = current++;
		cout << "ST: ";
		for (int i=0; i<k; ++i) 
			cout << st[i] << " ";
		cout << endl;
    }
    return ans;

}

int trap(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] <= height[r] ? l++ : r--];
        level = max(level, lower);
        water += level - lower;
		cout << lower << " " << level << " " << water << endl;
    }
    return water;
}

int main(int argc, char** argv) {
	int n[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> v(n, n+sizeof(n)/sizeof(int));
	cout << trap(v) << endl;
	int m[] = {4,2,3};
	vector<int> vv(m, m+sizeof(m)/sizeof(int));
	cout << trap(vv) << endl;
    return 0;
}

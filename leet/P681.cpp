#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

void bt(vector<int>& nums, string& path, string& res, int& min_dist) {
  if (path.size() == 4) {
    int curr = 0, t=0;
    int a=nums[0], b=nums[1], c=nums[2], d=nums[3];
    curr = (a*10+b)*60 +  (c*10+d);
  a = path[0]-'0', b=path[1]-'0', c=path[2]-'0', d=path[3]-'0';
  if (a*10 + b > 23) return;
  if (c*10 + d > 59) return;
    t = (a*10+b)*60 +  (c*10+d);
    int e = t > curr ? t-curr: 24*60-(curr-t);
    if (e < min_dist) {
      min_dist = e;
      res = path;
    }
    return ;
  } 
  
  for (int i=0; i<4; ++i) {
    path += to_string(nums[i]);
    bt(nums, path, res, min_dist);
    path.pop_back();
  }

}

string nextClosestTime(string time) {
  vector<int> nums;
  for (auto t: time) {
    if  (t != ':')
      nums.push_back(t-'0');
  }
  //printVector(nums);
  string res = "";
  string path = "";
  int min_dist = INT_MAX;
  bt(nums, path, res, min_dist);
  res.insert(res.begin()+2, ':');
  return res; 
}

int main(int argc, char** argv) {
  return 0;
}

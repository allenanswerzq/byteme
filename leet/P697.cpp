#include<bits/stdc++.h>

int findShortestSubArray(vector<int>& nums) {
      map<int, vector<int>> mp;
      for (int i=0; i<nums.size(); ++i) {
          if (mp.find(nums[i]) == mp.end()) {
              mp[nums[i]] = {i, i, 1};
          } else {
              mp[nums[i]][1] = i;
              mp[nums[i]][2]++;
          }
      }

      int max_degree = -1;
      int shortest_path = INT_MAX;
      for (auto it=mp.begin(); it!=mp.end(); it++) {
          vector<int> v = it->second;
          if (v[2] > max_degree) {
              max_degree = v[2];
              shortest_path = v[1]-v[0]+1;
          } else if (v[2] == max_degree) {
              shortest_path = min(shortest_path, v[1]-v[0]+1);
          }
      }
      return shortest_path;
    }

#include <bits/stdc++.h>
using namespace std;

vector<int> pourWater(vector<int>& heights, int V, int K) {
  while (V--) {
    auto low = make_pair(K, heights[K]);        
    for (int i=K; i>=0; i--)
      // Note case when height equals low.second
      if (heights[i] < low.second)
        low = make_pair(i, heights[i]);   
      else if(heights[i] > low.second)
        break;
    // Does not find a lower place on the left side 
    // So we check on the right side
    if (low.first == K) {
      for (int i=K+1; i<heights.size(); ++i)
        if (heights[i] < low.second)
          low = make_pair(i, heights[i]);
        else if (heights[i] > low.second)
          break;
    }
    heights[low.first]++;
  }
  return heights;
}

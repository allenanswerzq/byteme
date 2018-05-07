
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
  set<int> window;
  for (int i=0; i<nums.size(); ++i) {
    if (i > k) window.earse(nums[i-k-1]);
    # |nums[i] - x | <= t
    # -t <= num[i]-x <= t
    # x <= num[i] + t  and x >= num[i]-t
    auto pos = window.lower_bound(nums[i] - t); # x >= nums[i]-t
    if (pos!=window.end() && *pos <= nums[i]+t)
      return true;
    window.insert(nums[i]);
  }
  return false;
}

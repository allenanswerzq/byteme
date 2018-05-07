
// Bit manipulation
// Idea: x ^ x = 0
int missingNumber(vector<int>& nums) {
    int ret = 0; 
    for (auto x: nums)
        ret ^= x;
    for (int i=0; i<nums.size()+1; ++i)
        ret ^=i;
    return ret;
}
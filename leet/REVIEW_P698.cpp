// ref: http://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/
// ref: https://www.hackerearth.com/practice/notes/bit-manipulation/

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

bool dfs(vector<int>& nums, vector<vector<int>>& path, vector<int>& subSetSum, vector<int>& taken, int sum, int idx, int k, int lastIdx) {
  if (subSetSum[idx] == sum) {
    if (idx == k-1)
      return true;
    return dfs(nums, path, subSetSum, taken, sum, idx+1, k, nums.size()-1);
  }

  // lastIdx from where elements should be taken
  // Use this to avoid repeat already tested elements
  for (int i=lastIdx; i>=0; --i) {
    if (taken[i]) continue;
    int tmp = subSetSum[idx] + nums[i];
    if (tmp <= sum) {
        taken[i] = 1;
        subSetSum[idx] += nums[i];
        path[idx].push_back(nums[i]);
        bool next = dfs(nums, path, subSetSum, taken, sum, idx, k, i-1);

        // After taken nums[i] we can partition then just return
        if (next)
          return true;

        // if cannt, remove already taken nums[i] and find a new one
        taken[i] = 0;
        subSetSum[idx] -= nums[i];
        path[idx].pop_back();

    }
  }

  return false;
}

// Every element exactly in one partition namely cannt use elements mulit times
bool canPartitionKSubsets(vector<int>& nums, int k) {
  int N = nums.size();
  if (k == 1) return true;
  if (k > N) return false;

  int sum = 0;
  for (auto n: nums)
    sum += n;
  // if sum cant divide by k then we cant partition k subsets that have euqal sum
  if (sum % k != 0)
   return false;

  sum /= k;
  vector<int> subSetSum(k, 0);
  vector<int> taken(N, 0);
  vector<vector<int>> path(k); // save the partition result

  subSetSum[0] = nums[N-1];
  taken[N-1] = 1;
  path[0].push_back(1);

  bool ret = dfs(nums, path, subSetSum, taken, sum, 0, k, N-1);
  //printMatrix(path);
  //printVector(subSetSum);
  //printVector(taken);
  return ret;
}

// bit manipulation approach
/* Assume there are four elements in array
   for every subsets use 1 and 0 to decide which elements included in sujbsets
   i.e. [5 4 7 8] k=2
   from 1111 to 0000 there are 2^4 = 16 different choices
   subset 1: [5, 7]  bits representation: 1010
   subset 2: [4, 8]  bits representation: 0101
   decrese from 15 to 0 we can get all bits representations
*/

vector<int> a;
int dfs(int bit, int sum) {
  if (bit==0) return 1; // no elements can be taken
  for (int i=(1<<a.size())-1;i>=0;i--) {
    i&=bit;             // get all available elements

    int tot=0;
    for (int j=0;j<a.size();j++)
      if (((1<<j) & i))
        tot+=a[j];

    if (tot==sum) {
      tmp=dfs(bit^i,sum);
      if (tmp)
        return true;
    }
  }
  return false;
}

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
      int i,sum;
      sum=0;
      for (i=0;i<nums.size();i++)
        sum+=nums[i];
      if (sum%k!=0) return false;
      sum/=k;
      a=nums;
      return dfs((1<<a.size())-1,sum);
    }
};

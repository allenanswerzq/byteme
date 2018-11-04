#include<bits/stdc++.h>
using namespace std;

int recu(str inp, int lo, int hi) {
  if (lo == hi) return 1;
  if (inp[lo] == inp[hi] && hi == lo + 1) return 2;
  if (inp[lo] == inp[hi]) return recu(inp, lo + 1, hi - 1) + 2;
  int a = recu(inp, lo, hi - 1);
  int b = recu(inp, lo + 1, hi);
  return max(a, b);
}

const int N = 1004;
// dp[i][j] denotes the longest palindrome in the
// range of [i...j].
int dp[N][N];
int longestPalindromeSubseqDP(string& inp) {
  int n = sz(inp);
  mst(dp, 0);
  fori (r, 1, n + 1) {
  fori (i, 0, n - r + 1) {
    int j = i + r - 1;
    if (r == 1)
    dp[i][j] = 1;
    else if (inp[i] == inp[j] && j == i+ 1)
    dp[i][j] = 2;
    else if (inp[i] == inp[j])
    dp[i][j] = dp[i+1][j-1] + 2;
    else
    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
  }
  }
  return dp[0][n-1];
}

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    // return recu(s, 0, sz(s)-1);
    return longestPalindromeSubseqDP(s);
  }
};

void test(string inp) {
  Solution go;
  int r = go.longestPalindromeSubseq(inp);
  output(r);
}

int main() {
  test("bbbab");
  test("gphyvqruxjmwhonjjrgumxjhfyupajxbjgthzdvrdqmdouuukeaxhjumkmmhdglqrrohydrmbvtuwstgkobyzjjtdtjroqpyusfsbjlusekghtfbdctvgmqzeybnwzlhdnhwzptgkzmujfldoiejmvxnorvbiubfflygrkedyirienybosqzrkbpcfidvkkafftgzwrcitqizelhfsruwmtrgaocjcyxdkovtdennrkmxwpdsxpxuarhgusizmwakrmhdwcgvfljhzcskclgrvvbrkesojyhofwqiwhiupujmkcvlywjtmbncurxxmpdskupyvvweuhbsnanzfioirecfxvmgcpwrpmbhmkdtckhvbxnsbcifhqwjjczfokovpqyjmbywtpaqcfjowxnmtirdsfeujyogbzjnjcmqyzciwjqxxgrxblvqbutqittroqadqlsdzihngpfpjovbkpeveidjpfjktavvwurqrgqdomiibfgqxwybcyovysydxyyymmiuwovnevzsjisdwgkcbsookbarezbhnwyqthcvzyodbcwjptvigcphawzxouixhbpezzirbhvomqhxkfdbokblqmrhhioyqubpyqhjrnwhjxsrodtblqxkhezubprqftrqcyrzwywqrgockioqdmzuqjkpmsyohtlcnesbgzqhkalwixfcgyeqdzhnnlzawrdgskurcxfbekbspupbduxqxjeczpmdvssikbivjhinaopbabrmvscthvoqqbkgekcgyrelxkwoawpbrcbszelnxlyikbulgmlwyffurimlfxurjsbzgddxbgqpcdsuutfiivjbyqzhprdqhahpgenjkbiukurvdwapuewrbehczrtswubthodv");
  return 0;
}

#include <cstdio>  
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
#include <sstream>  // std:istringstream
#include <queue>
#include <deque>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

int main(int argc, char** argv) {

  // c way more efficient if std::ios_base::sync_with_stdio is open 
  // int N = 0;
  // scanf("%d", &N); 
  // printf("%d\n", N);
  // 
  // vector<int> v;
  // int t = 0;
  // int k = 0;
  // while ((scanf("%d", &k) != EOF))
  //   v.push_back(k);
  // printf("t val is %d\n", t);
  // printVector(v);
  // 
  // int K = 0;
  // scanf("%d", &K); 
  // printf("%d\n", K);

  // c++ way to read a sequence
  // int length; cin >> length;
  // vector<int> sequence(length, 0);
  // copy_n(istream_iterator<int>(cin), length, back_inserter(sequence));   
  // cout << "len: " << length << endl;
  // printVector(sequence);

  // // c++ way to read a matrix
  // int rows, cols; cin >> rows >> cols; 
  // vector<vector<int>> matrix; matrix.resize(rows); 
  // for (auto& row : matrix)
  // {    
  //    row.reserve(cols); 
  //    copy_n(istream_iterator<int>(cin), cols, back_inserter(row)); 
  // }


  int N; string line; 
  cin >> N; getline(cin, line);
  // Note here you got nothing
  cout << "got string is: "  << '\n';
  // for correcting get line 
  cin >> N >> std::ws; getline(cin, line);

  return 0;
}

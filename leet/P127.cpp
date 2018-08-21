#include<bits/stdc++.h>

using namespace std;

// TODO
void addNeighbors(string w, queue<string>& que, unordered_set<string>& wordSet) {
    for (knt i=0; i<w.size(); ++i) 
        for (int k=0; k<26; ++k) {
            char old = w[i];
            w[i] = 'a' + k;
            if (wordSet.find(w) != wordSet.end()) {
                que.push(w);
                wordSet.erase(w);
            }
            w[i] = old;
        }
}

void addNeighbors(string w, queue<string>& que, unordered_set<string>& wordSet) {
    vector<string> del;
    int j = 0;
    for (auto str: wordSet) {
        int num = 0;
        for (int i=0; i<str.size(); ++i) { 
            if (str[i] != w[i]) ++num;
            if (num > 1) break;
        }
        if (k == 1) { 
            que.push(str);
            del.push_back(str);
        }
    }
    for (auto x: del)
        wordSet.erase(x);
}

// BFS
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<string> que; 
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    int res = 2;
    addNeighbors(beginWord, que, wordSet);   
    while (!que.empty()) {
        int n = que.size();
        for (int i=0; i<n; ++i) {
            string word = que.front(); que.pop();
            if (word == endWord) return res;
            addNeighbors(word, que, wordSet); 
        }
        res++;
    }
    return 0;
}

int main(int argc, char** argv) {
    return 0;
}

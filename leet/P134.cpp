#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int idx;    
    int n = gas.size();
    for (int i=0; i<gas.size(); ++i) {
        idx = i;
        int total = gas[i];
        if (total < cost[i]) continue;
        // Note: gas station along a circular route
        int j = (i+1) % n;
        int prev = idx;
        for (; j!=i; j=(j+1)%n) {
            total = total-cost[prev] + gas[j];
            prev = j;
            if (total < cost[j]) break;
        }
        if (j == i)
            return idx;
    }
    return -1;
}

int main(int argc, char** argv) {
    return 0;
}

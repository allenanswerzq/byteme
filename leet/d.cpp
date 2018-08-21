#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x);
    printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
    printf("{ \n");
    for (auto x:v)
    	printVector(x);
    printf("} \n");
}

int main(int argc, char** argv) {
    return 0;
}

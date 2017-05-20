#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//void bt(const vector<vector<char>>& table, vector<string>& res, string& ans, int idx, const string& d) {
//	if(idx==d.size()) {
//		res.push_back(ans);
//		cout << ans << endl;;
//	}
//	else
//		for(int i=0;i<table[d[idx]-'0'].size();i++) {
//			ans.push_back(table[d[idx]-'0'][i]);
//			cout << "curr idx: " << idx << endl;
//			bt(table, res, ans, idx+1, d);
//			ans.pop_back();
//		}
//}
void bt(string d, int idx, vector<vector<char>> &table) {
	if (idx == d.size()) {
		//cout << "CURR IDX: " << idx << endl; 
		return;
	}
	else {
		for(int i=0;i<table[d[idx]-'0'].size();i++) {
			//cout << "curr idx: " << idx << endl;
			cout << table[d[idx]-'0'][i] << endl;
			bt(d, idx+1, table);
			//bt(d, ++idx, table);  NOTE: ++idx is not correct
		}
	}
}

vector<string> letterCombinations(string d) 
{
	vector<string> res;
	if(d.size()==0) return res;
	string ans;
	vector<vector<char>> table(2,vector<char>());
	table.push_back(vector<char>{'a','b','c'}); // idx 2
	table.push_back(vector<char>{'d','e','f'}); // 3
	table.push_back(vector<char>{'g','h','i'});
	table.push_back(vector<char>{'j','k','l'}); // 5
	table.push_back(vector<char>{'m','n','o'});
	table.push_back(vector<char>{'p','q','r','s'}); // 7
	table.push_back(vector<char>{'t','u','v'});
	table.push_back(vector<char>{'w','x','y','z'}); // 9
	
	bt(d, 0, table);
	return res;
}

void printVector(vector<string>& ss){
    cout << "{ ";
    for(int i=0; i<ss.size(); i++){
        if (i>0) cout << ", "; 
        cout << ss[i];
    }
    cout << " }" << endl;
}
int main() {
	
	vector<string> res;
	res = letterCombinations("23");
	printVector(res);
	return 0;
}

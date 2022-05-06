/* created   : 2020-09-23 08:40:07
 * accepted  : 2022-05-05 00:30:15
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
    vector<vector<string>> findLadders(string B, string E, vector<string>& W) {
    int n = W.size();
    int start = -1;
    int end = -1;
    for (int i = 0; i < n; i++) {
      if (W[i] == B) start = i;
      if (W[i] == E) end = i;
    }
    if (end == -1) return {};
    if (start == -1) {
      W.push_back(B);
      start = n++;
    }
    cout << start << " " << end << endl;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
      mp[W[i]] = i;
    }
    vector<vector<int>> g(n);
    for (auto & w : W) {
      int u = mp[w];
      for (int j = 0; j < w.size(); j++) {
        char b = w[j];
        for (char c = 'a'; c <= 'z'; c++) {
          w[j] = c;
          if (mp.count(w)) {
            int v = mp[w];
            if (u == v) continue;
            g[u].push_back(v); // NOTE: only one direction should be added here
          }
        }
        w[j] = b;
      }
    }
    const int INF = 1e9 + 7;
    vector<int> dist(n, INF);
    vector<int> vis(n);
    dist[start] = 1;
    vis[start] = 1;
    vector<int> qu;
    qu.push_back(start);
    for (int i = 0; i < qu.size(); i++) {
      int u = qu[i];
      for (int v : g[u]) {
        if (vis[v]) continue;
        dist[v] = min(dist[v], dist[u] + 1);
        qu.push_back(v);
        vis[v] = 1;
      }
    }
    if (dist[end] == INF) return {};
    vector<vector<string>> ans;
    std::function<void(int, int, vector<string>&)> dfs = [&](int u, int d, vector<string>& path) {
      path.push_back(W[u]);
      if (u == start) {
        // reverse(path.begin(), path.end()); // NOTE: this is wrong, will affect the pop order
        ans.push_back(path);
        reverse(ans.back().begin(), ans.back().end()); // this is right
        path.pop_back();
        return;
      }
      for (int v : g[u]) {
        if (dist[v] == d - 1) {
          dfs(v, d - 1, path);
        }
      }
      path.pop_back();
    };
    vector<string> path;
    dfs(end, dist[end], path);
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void test(const string& B, const string& E, vector<string> W) {
  Solution sol;
  auto ans = sol.findLadders(B, E, W);
  trace(ans);
}

void solve() {
  test("hit", "cog", vector<string>({"hot", "dot", "dog", "lot", "log", "cog"}));

  // test("cet", "ism", vector<string>({"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"}));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}

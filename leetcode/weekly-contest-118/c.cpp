#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if (v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if (v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
    cout << fixed << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
    const char* split = strchr(names + 1, ',');
    cout.write(names, split - names) << ": " << arg << " |";
    _f(split, args...);
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

vector<int> concat(vector<int> a, const vector<int> &b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

// [start ... end - 1]
vector<int> subvector(const vector<int> &v, int start, int end) {
    return vector<int>(v.begin() + start, v.begin() + end);
}

int tree_size(TreeNode *root) {
    if (!root) {
        return 0;
    }

    int left = tree_size(root->left);
    int right = tree_size(root->right);

    return (left + 1 + right);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const vector<int> BAD = {-1};
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int> voyage) {
        if (root == nullptr || sz(voyage) == 0) {
            return {};
        }

        if (root->val != voyage[0]) {
            return BAD;
        }

        vector<int> ret;

        if (root->left && root->right && root->right->val == voyage[1]) {
            ret = {root->val};
            swap(root->left, root->right);
        }

        vector<int> lefts = flipMatchVoyage(
                root->left,
                subvector(voyage, 1, 1 + tree_size(root->left)));

        if (lefts == BAD) {
            return BAD;
        }

        vector<int> rights = flipMatchVoyage(
                root->right,
                subvector(voyage, 1 + tree_size(root->left), voyage.size()));

        if (rights == BAD){
            return BAD;
        }

        return concat(ret, concat(lefts, rights));
    }
};

// Misunderstanding: swap all child under one node instead of swapping
// only left chlild'value and right child's value.

const int maxn = 120;
int parent[maxn];
int lefts[maxn];
int rights[maxn];
int pre[maxn];
int cnt;

void pre_order(TreeNode *root, int par = -1) {
    if (!root) return;
    int cur = root->val;
    pre[cnt++] = cur;
    parent[cur] = par;
    lefts[cur] = root->left ? root->left->val : -1;
    rights[cur] = root->right ? root->right->val : -1;

    pre_order(root->left, cur);
    pre_order(root->right, cur);

}

bool flip(int &cur, int n) {
    int par = parent[cur];
    int left = lefts[par], right = rights[par];

    int ia = -1, ib = -1;
    fori (i, 0, n) {
        if (pre[i] == left) {
            ia = i;
        }
        if (pre[i] == right) {
            ib = i;
        }
    }

    if (ia == -1 || ib == -1) {
        return 0;
    }
    swap(pre[ia], pre[ib]);
    return 1;
}

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {

        vi ret;
        if (!root) {
            return ret;
        }

        if (sz(voyage) == 0) {
            return {-1};
        }

        cnt = 0;
        pre_order(root);
        // trace(cnt);
        // par(pre, cnt, 1);

        if (cnt != sz(voyage)) {
            return {-1};
        }

        fori (i, 0, sz(voyage)) {
            if (pre[i] != voyage[i]) {
                if (i == 0) {
                    return {-1};
                } else {
                    bool ok = flip(pre[i], sz(voyage));
                    if (pre[i] != voyage[i] || !ok) {
                        return {-1};
                    } else {
                        ret.pb(parent[pre[i]]);
                    }
                }
            }
        }

        return ret;
    }
};

void test(TreeNode* root, vi voyage) {
    Solution go;
    vi ret = go.flipMatchVoyage(root, voyage);
    pvi(ret, 1);
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    test(root, {1, 3, 2});
    return 0;
}

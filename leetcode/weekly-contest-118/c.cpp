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

double tick() {
    static clock_t old;
    clock_t now = clock();
    double diff = 1.0 * (now - old);
    diff /= CLOCKS_PER_SEC;
    old = now;
    return diff;
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

const vector<int> BAD = {-1};

vector<int> concat(vector<int> a, const vector<int> &b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

vector<int> subvector(const vector<int> &v, int start, int end) {
    return vector<int>(v.begin() + start, v.begin() + end);
}

int subtree_size(TreeNode *root) {
    return root == nullptr ? 0 : 1 + subtree_size(root->left)
                                   + subtree_size(root->right);
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
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int> voyage) {
        if (root == nullptr)
            return {};

        if (root->val != voyage.front())
            return BAD;

        vector<int> answer;

        if (root->left != nullptr && root->right != nullptr &&
            root->right->val == voyage[1]) {
            answer = {root->val};
            swap(root->left, root->right);
        }

        vector<int> left_answer
            = flipMatchVoyage(root->left, subvector(voyage, 1, 1 + subtree_size(root->left)));

        if (left_answer == BAD)
            return BAD;

        vector<int> right_answer =
            flipMatchVoyage(root->right, subvector(voyage, 1 + subtree_size(root->left), voyage.size()));

        if (right_answer == BAD)
            return BAD;

        return concat(answer, concat(left_answer, right_answer));
    }
};

// Misunderstading: swap all child under one node instead of swapping
// only left chlild and right child.
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

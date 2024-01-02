#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

struct node {
    node* left;
    node* right;
    int val;
    node(int val) {
        this -> val = val;
    }
};
typedef node* nodeptr;

void solve() {
    int n; cin >> n;

    vi nums(n), index(n + 1), heights(n + 1);
    for (int i = 0; i < n; i++)
        cin >> nums[i], index[nums[i]] = i;
    
    function<nodeptr(int, int, int)> build = [&](int l, int r, int height) -> nodeptr {
        if (l >= r)
            return 0;
        int max = -1;
        for (int i = l; i < r; i++)
            max = std::max(max, nums[i]);
        nodeptr x = new node(max);
        heights[max] = height;
        x -> left = build(l, index[max], height + 1);
        x -> right = build(index[max] + 1, r, height + 1);
        return x;
    };

    nodeptr root = new node(n);
    heights[n] = 0;
    root -> left = build(0, index[n], 1);
    root -> right = build(index[n] + 1, n, 1);

    for (int i = 0; i < n; i++) 
        cout << heights[nums[i]] << " ";
    cout nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
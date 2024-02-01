#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n; cin >> n;

    vi nums(n), cnt(n + 1);
    for (int& a : nums) {
        cin >> a;
        cnt[a]++;
    }
    
    int mex = 0;
    for (int i = 0; i <= n; i++)
        if (cnt[i] == 0) {
            mex = i;
            break;
        }
    
    if (mex == 0) {
        cout << n << nl;
        for (int i = 0; i < n; i++)
            cout << "0 ";
        cout << nl;
        return;
    }
    
    vi b;
    int i = 0;
    while (1) {
        int next = mex;
        unordered_set<int, custom_hash> set;
        for (; i < n; i++) {
            if (set.size() == mex) break;
            cnt[nums[i]]--;
            if (cnt[nums[i]] == 0) next = min(next, nums[i]);
            if (nums[i] < mex) set.insert(nums[i]);
        }
        b.pb(mex);
        mex = next;
        if (mex == 0) {
            for (; i < n; i++)
                b.pb(0);
            break;
        }
    }
    cout << b.size() << nl;
    for (int& a : b)
        cout << a << " ";
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
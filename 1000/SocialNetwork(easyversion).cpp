#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

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

int32_t main() {
    fast;

    int n, k; cin >> n >> k;

    unordered_set<int, custom_hash> set;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (set.find(a) != set.end())
            continue;

        if (set.size() < k) {
            set.insert(a);
            dq.push_front(a);
            continue;
        }

        set.erase(dq.back());
        dq.pop_back();
        set.insert(a);
        dq.push_front(a);
    }

    cout << dq.size() nl;
    while (not dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }

    return 0;
}
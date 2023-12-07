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

int32_t main() {
    fast;

    int n; cin >> n;

    set<int> left, right;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        left.find(a) == left.end()? 
            left.insert(a) : right.insert(a);
    }
    
    int y = 1;
    for (auto i : right)
        y = lcm(y, i);
    
    int x = y;
    for (auto it = left.rbegin(); it != left.rend(); it++) {
        int val = lcm(x, *it);
        if (val == x or val == *it)
            x = lcm(x, *it);
        else
            y = lcm(y, *it);
    }
    cout << x << " " << y;

    return 0;
}
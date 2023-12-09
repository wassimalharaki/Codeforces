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

    vi left, mid, right;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a < 0) {
            if (left.empty())
                left.pb(a);
            else
                right.pb(a);
        }
        else if (a > 0) {
            if (mid.empty())
                mid.pb(a);
            else
                right.pb(a);
        }
        else
            right.pb(a);
    }

    cout << 1 << " " << left[0] nl;
    int count = 0;
    if (mid.empty()) {
        cout << 2 << " ";
        for (int i = 0; i < right.size() and count < 2; i++)
            if (right[i] < 0)
                cout << right[i] << " ", count++;
        cout nl;
    }
    else
        cout << 1 << " " << mid[0] nl;
    cout << right.size() - count << " ";
    for (int i = 0; i < right.size(); i++)
        if (right[i] < 0 and count)
            count--;
        else
            cout << right[i] << " ";

    return 0;
}
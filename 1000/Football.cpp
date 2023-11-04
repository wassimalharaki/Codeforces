#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int n; cin >> n;

    string ft, st; cin >> ft;
    int t1 = 1, t2 = 0;

    for (int i = 1; i < n; i++) {
        string s; cin >> s;
        if (s == ft)    
            t1++;
        else {
            if (st.empty()) st = s;
            t2++;
        }
    }
    cout << (t1 > t2 ? ft : st);

    return 0;
}
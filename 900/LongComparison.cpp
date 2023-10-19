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

    int T; cin >> T;
    
    while (T--) {
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;

        string s1 = to_string(x1), s2 = to_string(x2);
        while (s1.size() < s2.size() && p1 > 0)
            s1 += '0', x1 *= 10, p1--;
        while (s2.size() < s1.size() && p2 > 0)
            s2 += '0', x2 *= 10, p2--;
        int n1 = s1.size(), n2 = s2.size();

        if (n1 + p1 > n2 + p2)
            cout << '>' nl;
        else if (n1 + p1 < n2 + p2)
            cout << '<' nl;
        else if (x1 > x2)
            cout << '>' nl;
        else if (x1 < x2)
            cout << '<' nl;
        else
            cout << '=' nl;
    }

    return 0;
}
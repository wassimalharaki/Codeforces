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

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    string find = "a";
    for (int i = 0; i < 5000; i++) {
        if (s.find(find) == -1) {
            cout << find nl;
            return;
        }
        if (find == "z")
            find = "aa";
        else if (find == "zz")
            find = "aaa";
        else {
            int last = find.size() - 1;
            if (find[last] != 'z')
                find[last]++;
            else {
                if (find[last - 1] != 'z')
                    find[last - 1]++;
                else
                    find[last - 2]++, find[last - 1] = 'a';
                find[last] = 'a';
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
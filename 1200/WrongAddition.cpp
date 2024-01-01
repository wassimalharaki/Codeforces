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
    string a, s; cin >> a >> s;
    reverse(all(a)); reverse(all(s));

    //s - a
    string answ;
    int i = 0, j = 0;
    while (i < s.size() and j < a.size()) {
        if (s[i] >= a[j])
            answ += '0' + s[i] - a[j];
        else {
            if (i == s.size() - 1) {
                cout << -1 nl;
                return;
            }
            if (s[i + 1] != '1') {
                cout << -1 nl;
                return;
            }
            answ += '0' + s[i] + 10 - a[j];
            i++;
        }
        i++, j++;
    }
    while (i < s.size())
        answ += s[i++];
    reverse(all(answ));
    cout << (j == a.size() ? stoll(answ) : -1) nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
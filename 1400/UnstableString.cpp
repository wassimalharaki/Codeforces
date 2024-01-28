#include <bits/stdc++.h>

using namespace std;

void dbg_out() { cerr << '\n'; }
template<typename T> void dbg_out(vector<T>& a) { for (auto& b : a) cerr << ' ' << b; cerr << '\n'; }
template<typename H, typename... T> void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#ifdef WASSIM
#define dbg(...) cerr << '[' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
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

void solve() {
    string s; cin >> s;

    int ans = 0, curr = 1, cqm = 0, pqm = 0;
    char prev = s[0];
    for (int i = 1; i < s.size(); i++)
        if (s[i] == '?') {
            cqm++;
            curr++;
            if (prev == '1')
                prev = '0';
            else if (prev == '0')
                prev = '1';
        }
        else if (s[i] == '1') {
            if (prev == '1') {
                curr += pqm;
                ans += curr * (curr + 1) / 2 - pqm * (pqm + 1) / 2;
                pqm = cqm;
                cqm = 0;
                curr = 1;
            }
            else {
                curr++;
                cqm = 0;
                prev = '1';
            }
        }
        else {
            if (prev == '0') {
                curr += pqm;
                ans += curr * (curr + 1) / 2 - pqm * (pqm + 1) / 2;
                pqm = cqm;
                cqm = 0;
                curr = 1;
            }
            else {
                curr++;
                cqm = 0;
                prev = '0';
            }
        }
    curr += pqm;
    ans += curr * (curr + 1) / 2 - pqm * (pqm + 1) / 2;
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
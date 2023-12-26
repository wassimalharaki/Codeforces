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

void solve() {
    string s; cin >> s;
    int n = s.size();

    if (s.find('1') == -1
            or s.find('2') == -1
            or s.find('3') == -1) {
        cout << 0 nl;
        return;
    }

    int lo = 1, hi = n, answ;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        vi check(3);
        for (int i = 0; i < mid; i++)
            check[s[i] - '1']++;
        bool works = (*min_element(all(check)) >= 1);

        for (int i = mid; i < n and not works; i++) {
            check[s[i - mid] - '1']--;
            check[s[i] - '1']++;
            works = (*min_element(all(check)) >= 1);
        }

        if (works)
            answ = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << answ nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
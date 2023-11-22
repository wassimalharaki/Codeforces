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

    string s; cin >> s;
    int k; cin >> k;

    vi letters(26);
    int max = 0;
    for (int i = 0; i < 26; i++) {
        cin >> letters[i];
        max = std::max(max, letters[i]);
    }

    int tot = 0;
    for (int i = 0; i < s.size(); i++)
        tot += letters[s[i] - 'a'] * (i + 1);
    for (int i = 0; i < k; i++)
        tot += max * (s.size() + i + 1);

    cout << tot nl;

    return 0;
}
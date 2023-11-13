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

    int k; cin >> k;
    string s; cin >> s;

    vi letters (26);
    for (int i = 0; i < s.size(); i++) 
        letters[s[i] - 'a']++;
    
    string rep;
    for (int i = 0; i < 26; i++) {
        if (letters[i] % k) {
            cout << -1;
            return 0;
        }
        for (int j = 0; j < letters[i] / k; j++)
            rep += 'a' + i;
    }

    for (int i = 0; i < k; i++)
        cout << rep;

    return 0;
}
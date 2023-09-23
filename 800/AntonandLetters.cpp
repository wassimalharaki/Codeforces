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

    string s; getline(cin, s);
    vi letters(26);
    int counter = 0;

    if (s.size() == 2) {
        cout << counter;
        return 0;
    }
    
    for (int i = 1; i < s.size();  i += 3)
        if (not letters[s[i] - 'a']) {
            letters[s[i] - 'a'] = 1;
            counter++;
        }

    cout << counter;

    return 0;
}
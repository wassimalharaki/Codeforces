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
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    map<char, int> letters;
    for (int i = 0; i < s1.size(); i++)
        if (s1[i] != ' ')
            letters[s1[i]]++;
    
    string answ = "YES";
    for (int i = 0; i < s2.size(); i++)
        if (s2[i] == ' ')
            continue;
        else if (letters.find(s2[i]) == letters.end()) {
            answ = "NO";
            break;
        }
        else {
            letters[s2[i]]--;
            if (letters[s2[i]] == 0)
                letters.erase(s2[i]);
        }
    cout << answ nl;
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;

    while (T--)
        solve();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast

    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;
        
        map<string, vi> words;
        vi players(3, 0);

        for (int i = 0; i < 3 * n; i++) {
            string s; cin >> s;
            words[s].push_back(i / n);
        }

        for (auto it = words.begin(); it != words.end(); it++)
            if (it -> second.size() == 2) {
                players[it -> second[0]]++;
                players[it -> second[1]]++;
            }
            else if (it -> second.size() == 1)
                players[it ->second[0]] += 3;

        for (int i = 0; i < 3; i++)
            cout << players[i] << " ";
        cout nl;
    }

    return 0;
}
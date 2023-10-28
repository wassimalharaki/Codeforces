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
        string s, answ = "NO"; cin >> s;
        
        for (int i = 1; i <= 6; i++) {
            int a = i & 4, b = i & 2, c = i & 1;
            int ones = 0, zeroes = 0;
            
            for (int i = 0; i < s.size() and zeroes <= ones; i++)
                if (s[i] == 'A')
                    a ? ones++ : zeroes++;
                else if (s[i] == 'B')
                    b ? ones++ : zeroes++;
                else
                    c ? ones++ : zeroes++;

            if (ones == zeroes) {
                answ = "YES";
                break;
            }
        }
        cout << answ nl;
    }

    return 0;
}
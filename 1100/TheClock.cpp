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

const int mod = 1440;

int32_t main() {
    fast;

    int T; cin >> T;
    set<int> palindromes{
        0, 70, 140, 210, 280, 350, 601, 671, 741,
        811, 881, 951, 1202, 1272, 1342, 1412
    };
    
    function is_palindrome = [&](int x) -> bool {
        return (palindromes.find(x) != palindromes.end());
    };

    
    while (T--) {
        string s; cin >> s;
        int x; cin >> x;
        
        int hr = (s[0] - '0') * 10 + (s[1] - '0');
        int mn = (s[3] - '0') * 10 + (s[4] - '0');

        int start = hr * 60 + mn;
        int time = start;

        int answ = is_palindrome(time);
        time = (time + x) % mod;
        while (time != start) {
            answ += is_palindrome(time);
            time = (time + x) % mod;
        }
        cout << answ nl;
    }

    return 0;
}
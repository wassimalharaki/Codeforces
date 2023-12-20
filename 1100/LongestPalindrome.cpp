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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

bool equal(string& s1, string& s2) {
    int n = s1.size();
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[n - i - 1])
            return 0;
    return 1;
}

bool is_palindrome(string& s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            return 0;
    return 1;
}

int32_t main() {
    fast;

    int n, m; cin >> n >> m;

    unordered_set<int, custom_hash> map;
    v<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (is_palindrome(s[i]))
            map.insert(i);
    }
    
    vpii pairs;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (equal(s[i], s[j])) {
                pairs.pb(mp(i, j)); 
                map.erase(i);
                map.erase(j);
            }
    
    string answ = "";
    for (int i = 0; i < pairs.size(); i++)
        answ += s[pairs[i].F];
    string longest = "";
    for (int i : map)
        if (longest.size() < s[i].size())
            longest = s[i];
    answ += longest;
    for (int i = pairs.size() - 1; i >= 0; i--)
        answ += s[pairs[i].S];
    cout << answ.size() nl << answ;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

vector<int> divisors(int n) {
    vector<int> divs;

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            divs.push_back(i);

    for (int i = divs.size() - 1; i >= 0; i--)
        if (n / divs[i] != divs[i])
            divs.push_back(n / divs[i]);

    return divs;
}
 
void solve() {
    int n; cin >> n;
 
    v<int> nums(n);
    for (int& a : nums) cin >> a;
 
    int answ = 0;
    v<int> divs = divisors(n);
    for (int i = 0; i < divs.size(); i++) {
        int a = n / divs[i];
        int b = divs[i];
        v<v<int>> splits(a, v<int>(b));
        for (int j = 0; j < n; j++)
            splits[j / b][j % b] = nums[j];
        
        int g = 0;
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < a - 1; k++)
                g = __gcd(g, abs(splits[k + 1][j] - splits[k][j]));
        }
        if (g != 1) answ++;
    }
    cout << answ << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

vi divisors(int n) {
    vi divs;

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            divs.push_back(i);

    for (int i = divs.size() - 1; i >= 0; i--)
        if (n / divs[i] != divs[i])
            divs.push_back(n / divs[i]);

    return divs;
}

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;

        vi nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        
        int answ = 0;
        vi divs = divisors(n);
        for (int i = 0; i < divs.size(); i++) {
            int mn = INF, mx = 0;
            for (int j = 0; j < n / divs[i]; j++) {
                int sum = 0;
                for (int k = 0; k < divs[i]; k++)
                    sum += nums[j * divs[i] + k];
                mn = min(mn, sum);
                mx = max(mx, sum);
            }
            answ = max(answ, mx - mn);
        }
        cout << answ nl;
    }

    return 0;
}
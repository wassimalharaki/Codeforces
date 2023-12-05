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

int sum(int i) {
    int sum = 0;
    string s = to_string(i);
    for (int i = 0; i < s.size(); i++)
        sum += s[i] - '0';
    return sum;
}

int kth(int k) {
    int count = 0;
    for (int i = 19; 1; i += 9) {
        if (sum(i) == 10)
            count++;
        if (count == k)
            return i;
    }
}

int32_t main() {
    fast;

    int k; cin >> k;
    cout << kth(k);

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>

bool isPrime(int n) {
    if (n <= 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i <= sqrt(n); i+= 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int32_t main() {
    fast

    int n, m;

    cin >> n >> m;

    for (int i = n + 1; i < m; i++) {
        if (isPrime(i)) {
            cout << "NO";
            return 0;
        }
    }

    cout << ((isPrime(m))? "YES": "NO");

    return 0;
}
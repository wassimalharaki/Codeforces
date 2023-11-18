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

int computeXOR(int n) {
  if (n % 4 == 0) 
    return n;

  if (n % 4 == 1) 
    return 1;
    
  if (n % 4 == 2) 
    return n + 1;

  return 0; 
} 

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int a, b; cin >> a >> b;
        int x = computeXOR(a - 1);
        cout << a + (x == b ? 0 : (b ^ x) == a ? 2 : 1) nl;
    }

    return 0;
}
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

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;

        deque<int> left, right;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += (s[i] == 'R' ? s.size() - (i + 1) : i);
            if (i < s.size() / 2 and s[i] == 'L')
                left.push_back(i);
            else if (i > (s.size() - 1) / 2 and s[i] == 'R')
                right.push_front(i);
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (left.empty() and right.empty()) {
                cout << sum << " ";
                continue;
            }
            
            if (left.empty()) {
                sum -= s.size() - (right.front() + 1);
                sum += right.front();
                right.pop_front();
                cout << sum << " ";
                continue;
            }

            if (right.empty()) {
                sum -= left.front();
                sum += s.size() - (left.front() + 1);
                left.pop_front();
                cout << sum << " ";
                continue;
            }
            
            int remleft = - left.front() + s.size() - (left.front() + 1);
            int remright = - s.size() + (right.front() + 1) + right.front();
            if (remleft > remright)
                sum += remleft, left.pop_front();
            else
                sum += remright, right.pop_front();
            cout << sum << " ";
        }
        cout nl;
    }

    return 0;
}
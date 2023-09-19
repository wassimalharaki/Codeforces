#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>

int32_t main() {
    fast

    int t;
    
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vi nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 != nums[i] % 2) {
                bool found = false;
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] % 2 == i % 2 && nums[j] % 2 != j % 2) {
                        int temp = nums[j];
                        nums[j] = nums[i];
                        nums[i] = temp;
                        swaps++;
                        found = true;
                        break;
                    }
                }
                if (not found) {
                    swaps = -1;
                    break;
                }
            }
        }
        cout << swaps nl;
        
    }

    return 0;
}
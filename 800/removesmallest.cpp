#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    
    cin >> t;

    for (int i = 0; i < t; i++) {

        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j++)
            cin >> arr[j];

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size() - 1; i++)
            if (abs(arr[i] - arr[i + 1]) <= 1)
                n--;

        if (n == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
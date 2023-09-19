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
        
        int prev;
        int current;
        int next;
        bool found = false;
        cin >> prev >> current >> next;

        if (prev == current && prev != next) {
            found = true;
            cout << 3 << endl;
        }
        else if (prev == next && prev != current) {
            found = true;
            cout << 2 << endl;
        }
        else if (current == next && current != prev) {
            found = true;
            cout << 1 << endl;
        }

        for (int j = 4; j <= n; j++) {
            cin >> current;
            if (current != prev && not found)
                cout << j << endl;
        }
    }

    return 0;
}
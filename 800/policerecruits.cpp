#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, police = 0, crimes = 0, event;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> event;
        if (event != -1)
            police += event;
        else {
            if (police == 0)
                crimes++;
            else
                police--;
        }
    }

    cout << crimes;

    return 0;
}
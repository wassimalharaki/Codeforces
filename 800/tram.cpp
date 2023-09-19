#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int stops;
    int current = 0;
    int max = 0;
    cin >> stops;

    loop(i, 0, stops) {
        int exit, enter;
        cin >> exit;
        cin >> enter;
        current -= exit;
        current += enter;
        if (current > max)
            max = current;
    }

    cout << max;

    return 0;
}
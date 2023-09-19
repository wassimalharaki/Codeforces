#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> home(n, 0);
    vector<int> guest(n, 0);

    for (int i = 0; i < n; i++)
        cin >> home[i] >> guest[i];

    int counter = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (home[i] == guest[j])
                counter++;

    cout << counter;

    return 0;
}
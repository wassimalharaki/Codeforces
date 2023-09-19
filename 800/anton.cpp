#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int games;
    string winner;
    cin >> games >> winner;

    int a = 0;
    int d = 0;

    loop(i, 0, games)
        if (winner[i] == 'A')
            ++a;
        else
            ++d;

    if (a == d)
        cout << "Friendship";
    else if (a > d)
        cout << "Anton";
    else
        cout << "Danik";

    return 0;
}
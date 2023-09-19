#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> cards(n);

    for (int i = 0; i < n; i++)
        cin >> cards[i];

    int sereja = 0, dima = 0;

    for (int start = 0, end = n - 1; start <= end;) {
        if (cards[start] > cards[end]) {
            sereja += cards[start];
            start++;
        }
        else {
            sereja += cards[end];
            end--;
        }
        if (start > end)
            break;
        if (cards[start] > cards[end]) {
            dima += cards[start];
            start++;
        }
        else {
            dima += cards[end];
            end--;
        }
    }

    cout << sereja << " " << dima;

    return 0;
}
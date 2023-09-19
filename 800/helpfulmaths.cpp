#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string in;
    cin >> in;
    vector<int> list;

    loop(i, 0, in.length()) {
        if (in[i] == '1'
                || in[i] == '2'
                || in[i] == '3')
            list.push_back(in[i] - '0');
    }

    sort(list.begin(), list.end());

    if (!list.empty()) {
        cout << list[0];
        loop(i, 1, list.size())
            cout << "+" << list[i];
    }
    return 0;
}
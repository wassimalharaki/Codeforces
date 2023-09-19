#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int year;
    cin >> year;
    int nums[4];

    bool found = false;
    while (!found) {
        found = true;
        year++;
        loop(i, 0, 4)
            nums[i] = (year / (int) pow(10, 3 - i)) % 10;
        int c[4];
        copy(nums, nums + 4, c);
        sort(c, c + 4);
        loop(i, 0, 4 - 1)
            if (c[i] == c[i + 1]) {
                found = false;
                break;
            }
    }

    loop(i, 0, 4)
        cout << nums[i];

    return 0;
}
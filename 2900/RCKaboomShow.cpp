#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int n; cin >> n;
    
    vi x(n), y(n), dx(n), dy(n), speed(n);
    v<double> a(n), b(n);

    function intersection = [&](int i, int j) -> pair<double, double> {
        double xx = (b[j] - b[i]) / (a[i] - a[j]);
        return mp(xx, a[i] * xx + b[i]);
    };

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> speed[i];
        a[i] = (double) dy[i] / dx[i];
        b[i] = y[i] - a[i] * x[i];
    }
    
    double shortest = INF;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                if (abs(b[i] - b[j]) >= 1e-10)
                    continue;
                if (x[i] < x[j] and dx[j] > 0 and dx[i] < 0)
                    continue;
                if (x[i] >= x[j] and dx[i] > 0 and dx[j] < 0)
                    continue;

                double ratio = sqrt(dx[i] * dx[i] + dy[i] * dy[i]) / abs(dx[i]);
                double speedxi = (double) speed[i] / ratio;
                speedxi = abs(speedxi);

                ratio = sqrt(dx[j] * dx[j] + dy[j] * dy[j]) / abs(dx[j]);
                double speedxj = (double) speed[j] / ratio;
                speedxj = abs(speedxj);


                if (dx[i] * dx[j] < 0) {
                    double time = abs(x[j] - x[i]) / (speedxi + speedxj);
                    shortest = min(shortest, time);
                    continue;
                }
                
                double time;
                if (dx[i] < 0 and dx[j] < 0)
                    if (x[i] > x[j])
                        time = abs(x[j] - x[i]) / speedxi;
                    else
                        time = abs(x[j] - x[i]) / speedxj;
                else
                    if (x[i] > x[j])
                        time = abs(x[i] - x[j]) / speedxj;
                    else
                        time = abs(x[i] - x[j]) / speedxi;
                shortest = min(shortest, time);
                continue;
            }

            pair<double, double> inter = intersection(i, j);
            if ((inter.F - x[i]) * dx[i] < 0)
                continue;
            if ((inter.F - x[j]) * dx[j] < 0)
                continue;
            
            double idist = sqrt(pow(x[i] - inter.F, 2) + pow(y[i] - inter.S, 2));
            double itime = idist / speed[i];

            double jdist = sqrt(pow(x[j] - inter.F, 2) + pow(y[j] - inter.S, 2));
            double jtime = jdist / speed[j];

            shortest = min(shortest, max(jtime, itime));
        }

    if (shortest == INF)
        cout << "No show :(";
    else
        cout << fixed << setprecision(10) << shortest;

    return 0;
}
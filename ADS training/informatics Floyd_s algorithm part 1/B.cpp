#include <bits/stdc++.h>
using namespace std;

const int mx = 5e7+5;

void solve () {
    int n;
    cin >> n;
    vector <vector <int>> a (n + 1, vector <int> (n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) {
                a[i][j] = mx;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = min (a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max (ans, a[i][j]);
        }
    }
    cout << ans;
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve ();
    return 0;
}
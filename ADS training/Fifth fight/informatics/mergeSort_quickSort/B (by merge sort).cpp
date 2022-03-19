#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

void merge (int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (i = 0; i < n1; ++i) left[i] = a[l+i];
    for (i = 0; i < n2; ++i) right[i] = a[m+1+i];
    i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) a[k++] = left[i++];
        else a[k++] = right[j++];
    }
    while (i < n1) a[k++] = left[i++];
    while (j < n2) a[k++] = right[j++];
}

void mergeSort (int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort (a, l, m);
        mergeSort (a, m + 1, r);
        merge (a, l, m, r);
    } else return;
}

signed main() {
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    mergeSort (a, 0, n - 1);
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            cnt++;
        }
    }
    cout << n - cnt;
    
    return 0;
}
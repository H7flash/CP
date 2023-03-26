#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

struct DSU {
    int sz[N], par[N];

    DSU(int n) {
        for (int i = 0; i <= n; i++) {
            sz[i] = 1;
            par[i] = i;
        }
    }

    void join(int i, int j) {
        i = get(i);
        j = get(j);

        if (i == j) return;
        if (sz[i] < sz[j]) swap(i, j);

        sz[i] += sz[j];
        par[j] = i; 
    }

    int get(int i) {
        if (par[i] == i) return i;
        return par[i] = get(par[i]);
    }
};

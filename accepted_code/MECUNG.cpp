#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
int n;
int d[N];
int h[N];
vector<ii> v[N];
int main() {
    int m;
    cin >> n >> m;
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        v[x].push_back(ii(y, w));
        v[y].push_back(ii(x, w));
    }
    queue<int> q;
    q.push(n);
    d[n] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for(auto i : v[x]) {
            int y = i.first;
            if (d[y] != 0) continue;
            d[y] = d[x] + 1;
            q.push(y);
        }
    }

    cout << d[1] - 1 << '\n';
    
    queue<int> tmpq;
    q.push(1);
    h[1] = 1;
    for(int turn = 1; turn < d[1]; turn++) {
        int best = INF;
        while (!q.empty()) {
            int x = q.front();
            q.pop(); tmpq.push(x);
            for(auto i : v[x]) {
                int y = i.first;
                if (d[y] == d[x] - 1) 
                    best = min(best, i.second);
            }
        }
        cout << best << " ";
        while (!tmpq.empty()) {
            int x = tmpq.front();
            tmpq.pop(); 
            for(auto i : v[x]) {
                int y = i.first;
                if (d[y] == d[x] - 1 && i.second == best && !h[y]) {
                    h[y] = 1;
                    q.push(y);
                }
            }
        }
    }
}

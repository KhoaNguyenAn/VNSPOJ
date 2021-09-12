#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 10; 
const int inf = 1e9 + 10;


int n, k;
int pa[N];


vector<int> adj[N]; 
vector<vector<int>> sf[N], tf[N];

int w[N];


bool maximize(int &x, int v) {
    if (x < v) x = v; else return 0;
    return 1;
}

void DFS(int u) {

    int deg = adj[u].size();
    for(int i = 0; i < deg; i++) {
        int v = adj[u][i]; 

        ///for easier trace procedure later
        if (v == pa[u]) {
            swap(adj[u][i--], adj[u][--deg]);
            adj[u].pop_back();
            continue;
        }
        pa[v] = u;
        DFS(v);
    }

    
    sf[u].assign(deg + 1, vector<int>());
    tf[u].assign(deg + 1, vector<int>());
    sf[u][0] = {-inf, w[u]};
    tf[u][0] = {0, 0};
    


    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];

        int news = sf[u][i].size() + sf[v].back().size() - 1;
        sf[u][i + 1].assign(news, -inf);
        tf[u][i + 1].assign(news, 0);
        
        ///notice how useU and useV only loop through possible value
        ///this way the entire DFS procedure and the memory sf, tf consume will be O(n ^ 2) instead of O(n ^ 3)

        for(int useU = 0; useU < sf[u][i].size(); useU++) 
            for(int useV = 0; useV < sf[v].back().size(); useV++)
                if (maximize(sf[u][i + 1][useU + useV], sf[u][i][useU] + sf[v].back()[useV])) {
                    tf[u][i + 1][useU + useV] = useV;
                }
    }

    sf[u].back()[0] = 0;
}
void trace(int root, int use) {
    if (use == 0) return;
    cout << root << " "; 

    for(int i = adj[root].size() - 1; i >= 0; i--) {
        int v = adj[root][i];
        int useV = tf[root][i + 1][use];
        trace(v, useV);
        use -= useV;
    }
}
void prepare() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

}
int main() {
    prepare();

    DFS(1);
    int root = 1; /// because sf[1].back().size() == n + 1
    for(int i = 1; i <= n; i++) if (sf[i].back().size() > k)  {
        if (sf[i].back()[k] > sf[root].back()[k]) {
            root = i;
        }
    }
    trace(root, k);
}

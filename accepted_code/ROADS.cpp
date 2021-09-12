#include <bits/stdc++.h>
#define MAX 105
#define INF 1e9

using namespace std;

struct node{
    int id, length, cost;
};

struct option{
    bool operator()(node a, node b){
        return a.length > b.length;
    }
};

vector<node> graph[MAX];
vector<int> dist(MAX, INF);
int k, n, m, s, d, l, c;

void Dijkstra(int s){
    priority_queue<node, vector<node>, option> pq;
    pq.push({s, 0, 0});
    while(!pq.empty()){
        node u = pq.top();
        pq.pop();
        dist[u.id] = min(dist[u.id], u.length);
        if(u.id == n){
            break;
        }
        for(node v : graph[u.id]){
            if(u.cost + v.cost <= k){
                pq.push({v.id, u.length + v.length, u.cost + v.cost});
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> k >> n >> m;
        for(int i = 1; i <= n; i++){
            graph[i].clear();
            dist[i] = INF;
        }
        for(int i = 0; i < m; i++){
            cin >> s >> d >> l >> c;
            graph[s].push_back({d, l, c});
        }
        Dijkstra(1);
        if(dist[n] == INF){
            cout << -1 << endl;
        }
        else{
            cout << dist[n] << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;



void distanceFromNode(int root, int cur, vector<vector<int>> &ADJ, vector<int> &dist, vector<int> &vis){
        
        vis[root] = 1;
        dist[root] = cur;
        for(auto x : ADJ[root]){
                if(!vis[x]){
                        distanceFromNode(x, cur+1, ADJ, dist, vis);
                }
        }
}

void createAdj(vector<vector<int>> graph, int V, int N, vector<vector<int>> &ADJ){
    vector<vector<int>> adj(V);
    for(int i=0; i<N; i++){
        adj[graph[i][0]].push_back(graph[i][1]);
        adj[graph[i][1]].push_back(graph[i][0]);
    }
    for(int i = 0; i<V; i++){
        cout<<i<<"->";
        for(auto x : adj[i]){
            cout<<x<<",";
        }
        cout<<endl;
    }
    ADJ = adj;
}

int main()
{
    int V, N;
    cin>>V>>N;
    
    vector<vector<int>> graph(V);
    for(int i = 0; i<N; i++){
        int u, v;
        cin>>u>>v;
        graph[i]={u,v};

    }
    vector<vector<int>> ADJ;
    createAdj(graph, V, N, ADJ);
    // vector<vector<int>> ADJ;
    int edges;
    edges = V;
    vector<int> dist(edges, -1);
    vector<int> vis(edges);
    distanceFromNode(0, 0, ADJ, dist, vis);
    cout<<endl;
    
    for(int i = 0; i<V; i++){
            cout<<i<< " "<< dist[i] <<endl;
    }
    
    
    
    return 0;
}



Input :
7 6
0 1
0 3
2 3
3 6
3 4
4 5

OutPut:

0->1,3,
1->0,
2->3,
3->0,2,6,4,
4->3,5,
5->4,
6->3,

0 0
1 1
2 2
3 1
4 2
5 3
6 2


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> adj, int start, int n){
    vector<int> vis(n,0);

    queue<int> q;
    q.push(start);

    vis[start] = 1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        cout<< front << " -> ";

        int n = adj[front].size();
        
        for(int i = 0;i < n;i++){
            int temp = adj[front][i];

            if(vis[temp] == 0){
                q.push(temp);
                vis[temp] = 1;
            }

        }
    }
}


void dfs(vector<vector<int>> adj, int node, vector<int> & vis){
    if(vis[node] == 1) return;

    vis[node] = 1;

    int n = adj[node].size();

    cout<<node<< " -> ";

    for(int i = 0;i < n;i++){
        int temp = adj[node][i];
        if(vis[temp] == 0){
            dfs(adj,temp,vis);
        }
    }

    return;
}

void addEdge(vector<vector<int> >& adjList, int u, int v)
{
    adjList[u].push_back(v);
}
 

int main(){
    int vertices = 3;
 
    // Adjacency list representation of the graph
    vector<vector<int> > adjList(vertices);
 
    // Add edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 0);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 0);
    addEdge(adjList, 2, 1);


    bfs(adjList,0,vertices);

    cout<<endl;
    
    vector<int> vis(vertices,0);

    dfs(adjList,0,vis);

    return 0;
}
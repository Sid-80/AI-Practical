#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        vector<int> vis(V,0);
        
        pq.push({0,0}); //wt,node
        int sum = 0;
        
        while(!pq.empty()){
            auto front = pq.top();
            int wt = front.first;
            int node = front.second;
            pq.pop();
            
            if(vis[node] == 1) continue;
            
            vis[node] = 1;
            
            sum += wt;
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgWt = it[1];
                
                if(!vis[adjNode]){
                    pq.push({edgWt,adjNode});
                }
            }
        }
        
        return sum;
    }
};

int main() {
    int V = 0; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj[V];

    int E; // Number of edges
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges in the format (source, destination, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // Assuming undirected graph
    }

    Solution obj;
    int minSpanningTreeWeight = obj.spanningTree(V, adj);
    cout << "Sum of weights of edges of the Minimum Spanning Tree: " << minSpanningTreeWeight << endl;

    return 0;
}

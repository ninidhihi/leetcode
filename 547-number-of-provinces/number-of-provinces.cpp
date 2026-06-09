class Solution {
public:
    // DFS function to traverse a connected component
    void dfs(int node, vector<vector<int>>& adjls, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adjls[node]) {
            if (!vis[it]) {
                dfs(it, adjls, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        // Correctly declare the adjacency list as a vector of vectors
        vector<vector<int>> adjls(V);

        // Build the adjacency list from the adjacency matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                    // Since the matrix is symmetric, we only need to add one way
                    // but adding both is also correct and ensures the graph is fully represented.
                }
            }
        }

        // Initialize a visited array and a counter for provinces
        vector<int> vis(V, 0);
        int count = 0;

        // Iterate through all nodes to find unvisited ones (new provinces)
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adjls, vis);
            }
        }
        return count;
    }
};
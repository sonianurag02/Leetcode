// ------------------------------------------ Approach - 1 (DFS) --------------------------------

class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& edges, int n){
        vector<vector<int>> adj(n + 1);
        vector<int> order;

        // 0: not visited, 1: visiting, 2: visited
        vector<int> visited(n + 1, 0);
        bool hasCycle = false;

        // Build adjacency list
        for(auto& x: edges){
            adj[x[0]].push_back(x[1]);
        }

        // Perform DFS for each node
        for(int i = 1; i <= n; i++){
            if(visited[i] == 0){
                dfs(i, adj, visited, order, hasCycle);
                // Return emoty if cycle detected
                if(hasCycle) return {};
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& order, bool& hasCycle){
        visited[node] = 1;
        for(int ngbr: adj[node]){
            if(visited[ngbr] == 0){
                dfs(ngbr, adj, visited, order, hasCycle);
                // Early exit if cycle is detected
                if(hasCycle) return;
            }
            else if(visited[ngbr] == 1){
                hasCycle = true;
                return;
            }
        }

        visited[node] = 2;
        order.push_back(node);
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Store the topologically sorted sequences
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        // If no topological sort exists, return empty array
        if(orderRows.empty() || orderColumns.empty()) return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));

        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(orderRows[i] == orderColumns[j]){
                    matrix[i][j] = orderRows[i];
                }
            }
        }

        return matrix;
    }
};

// ------------------------------------------ Approach - 2 (BFS) --------------------------------

class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& edges, int n){
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n+1, 0);

        for(vector<int>& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> que;
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(inDegree[i] == 0){
                que.push(i);
                count++;
            }
        }

        vector<int> topoOrder;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            topoOrder.push_back(u);

            for(int &v: adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    que.push(v);
                    count++;
                }
            }
        }

        if(count != n){
            return {};
        }

        return topoOrder;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        // Store the topologically sorted sequences
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        // If no topological sort exists, return empty array
        if(orderRows.empty() || orderColumns.empty()) return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));

        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(orderRows[i] == orderColumns[j]){
                    matrix[i][j] = orderRows[i];
                }
            }
        }

        return matrix;
    }
};
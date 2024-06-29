// -------------------------------- Approach - 1 (DFS) --------------------------------

class Solution {
public:
    void DFS(int ancestor, unordered_map<int, vector<int>>& adj, int currNode, vector<vector<int>>& result){
        for(int& ngbr: adj[currNode]){
            if(result[ngbr].empty() || result[ngbr].back() != ancestor){
                result[ngbr].push_back(ancestor);
                DFS(ancestor, adj, ngbr, result);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj;

        for(vector<int>& vec: edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
        }

        for(int i = 0; i < n; i++){
            int ancestor = i;
            DFS(ancestor, adj, i, result);
        }

        return result;
    }
};

// ---------------------------------- Approach - 2 -----------------------------------

class Solution {
public:
    void DFS(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited){
        visited[u] = true;

        for(int& v: adj[u]){
            if(visited[v] != true){
                DFS(v, adj, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> adj;

        for(vector<int>& vec: edges){
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
        }

        for(int u = 0; u < n; u++){
            vector<int> ancestors;
            vector<bool> visited(n, false);
            DFS(u, adj, visited);

            for(int i = 0; i < n; i++){
                if(i == u) continue;

                if(visited[i] == true){
                    ancestors.push_back(i);
                }
            }

            result.push_back(ancestors);
        }

        return result;
    }
};

// ---------------------------- Approach - 3 (TopoLogical Sort) ------------------------------

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj;

        vector<int> Indegree(n, 0);

        for(vector<int>& vec: edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);

            Indegree[v]++;
        }

        queue<int> que;
        for(int i = 0; i < n; i++){
            if(Indegree[i] == 0){
                que.push(i);
            }
        }

        vector<int> topoOrder;
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            topoOrder.push_back(curr);

            for(int& v: adj[curr]){
                Indegree[v]--;
                if(Indegree[v] == 0){
                    que.push(v);
                }
            }
        }

        vector<unordered_set<int>> vec(n);
        for(int& node: topoOrder){
            for(int& v: adj[node]){
                vec[v].insert(node);
                vec[v].insert(vec[node].begin(), vec[node].end());
            }
        }

        for(int i = 0; i < n; i++){
            result[i] = vector<int>(vec[i].begin(), vec[i].end());

            sort(result[i].begin(), result[i].end());
        }

        return result;
    }
};
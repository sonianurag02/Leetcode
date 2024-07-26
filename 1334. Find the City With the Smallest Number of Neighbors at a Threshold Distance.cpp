// ------------------------------ Approach - 1 --------------------------------------------
// Using Dijkstra's algorithm

class Solution {
public:
    #define P pair<int, int>

    void dijkstra(int n, unordered_map<int, vector<P>>& adj, vector<int>& result, int source)
    {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, source});

        fill(result.begin(), result.end(), INT_MAX);

        result[source] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto& vec: adj[node]){
                int adjNode = vec.first;
                int dist = vec.second;

                if(d + dist < result[adjNode]){
                    result[adjNode] = d+dist;
                    pq.push({d+dist, adjNode});
                } 
            }
        }    
    }

    int findResultCity(int n, vector<vector<int>>& SPM, int D){
        int resultCity = -1;
        int leastReachCount = INT_MAX;

        for(int i = 0; i < n; i++){
            int countReach = 0;
            for(int j = 0; j < n; j++){
                if(i != j && SPM[i][j] <= D){
                    countReach++;
                }
            }
            if(countReach <= leastReachCount){
                leastReachCount = countReach;
                resultCity = i;
            }
        }

        return resultCity;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++){
            SPM[i][i] = 0;
        }

        unordered_map<int, vector<P>> adj;

        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        for(int i = 0; i < n; i++){
            dijkstra(n, adj, SPM[i], i);
        }

        // Find the city by iterating over SPM
        return findResultCity(n, SPM, distanceThreshold);
    }
};

// ------------------------------ Approach - 2 --------------------------------------------
// Using Bellman Ford algorithm

class Solution {
public:
    #define P pair<int, int>

    void bellman_ford(int n, vector<vector<int>>& edges, vector<int>& result, int source)
    {
        fill(result.begin(), result.end(), INT_MAX);
        result[source] = 0;

        for(int count = 1; count < n; count++){
            for(auto& edge: edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if(result[u] != INT_MAX && result[u] + w < result[v]){
                    result[v] = result[u] + w;
                }

                if(result[v] != INT_MAX && result[v] + w < result[u]){
                    result[u] = result[v] + w;
                }
            }
        }
    }

    int findResultCity(int n, vector<vector<int>>& SPM, int D){
        int resultCity = -1;
        int leastReachCount = INT_MAX;

        for(int i = 0; i < n; i++){
            int countReach = 0;
            for(int j = 0; j < n; j++){
                if(i != j && SPM[i][j] <= D){
                    countReach++;
                }
            }
            if(countReach <= leastReachCount){
                leastReachCount = countReach;
                resultCity = i;
            }
        }

        return resultCity;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++){
            SPM[i][i] = 0;
        }

        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            SPM[u][v] = wt;
            SPM[v][u] = wt;
        }

        for(int i = 0; i < n; i++){
            bellman_ford(n, edges, SPM[i], i);
        }

        // Find the city by iterating over SPM
        return findResultCity(n, SPM, distanceThreshold);
    }
};

// ------------------------------ Approach - 3 --------------------------------------------
// Using Floyd Warshall algorithm

class Solution {
public:
    #define P pair<int, int>

    void floydWarshall(int n, vector<vector<int>>& SPM)
    {
        for(int via = 0; via < n; via++) {
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                   SPM[i][j] = min(SPM[i][j], SPM[i][via] + SPM[via][j]);
                }
            }
        }
    }

    int findResultCity(int n, vector<vector<int>>& SPM, int D){
        int resultCity = -1;
        int leastReachCount = INT_MAX;

        for(int i = 0; i < n; i++){
            int countReach = 0;
            for(int j = 0; j < n; j++){
                if(i != j && SPM[i][j] <= D){
                    countReach++;
                }
            }
            if(countReach <= leastReachCount){
                leastReachCount = countReach;
                resultCity = i;
            }
        }

        return resultCity;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n, vector<int>(n, 1e9+7));

        for(int i = 0; i < n; i++){
            SPM[i][i] = 0;
        }

        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            SPM[u][v] = wt;
            SPM[v][u] = wt;
        }

        floydWarshall(n, SPM);

        // Find the city by iterating over SPM
        return findResultCity(n, SPM, distanceThreshold);
    }
};
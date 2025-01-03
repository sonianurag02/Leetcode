// -------------------------- Approach - 1 --------------------------------
// Using Dijkstras Algo

class Solution {
public:
    typedef long long ll;
    const int LARGE_VAL = 2e9;
    typedef pair<long, long> P;

    ll DijkstraAlgo(vector<vector<int>>& edges, int n, int src, int dest){
        unordered_map<ll, vector<pair<ll, ll>>> adj; // u -> {v, wt}

        for(vector<int>& edge: edges){
            if(edge[2] != -1){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq; // min-heap
        vector<ll> result(n, LONG_MAX);
        vector<bool> visited(n, false);

        result[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            ll currDist = pq.top().first;
            ll currNode = pq.top().second;
            pq.pop();

            if(visited[currNode] == true){
                continue;
            }
            visited[currNode] = true;

            for(auto& [ngbr, wt]: adj[currNode]){
                if(result[ngbr] > currDist + wt){
                    result[ngbr] = currDist + wt;
                    pq.push({result[ngbr], ngbr});
                }
            }
        }

        return result[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int nodeCount, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currShortestDistance = DijkstraAlgo(edges, nodeCount, source, destination);

        if(currShortestDistance < target){
            return {};
        } 
        
        bool matchedTarget = (currShortestDistance == target);

        // if(matchedTarget == true){
        //     for(vector<int>& edge: edges){
        //         if(edge[2] == -1){
        //             edge[2] = LARGE_VAL;
        //         }
        //     }

        //     return edges;
        // }

        for(vector<int>& edge: edges){
            if(edge[2] == -1){
                edge[2] = (matchedTarget == true) ? LARGE_VAL : 1;

                if(matchedTarget != true){
                    ll newShortestDist = DijkstraAlgo(edges, nodeCount, source, destination);

                    if(newShortestDist <= target){
                        matchedTarget = true;
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }

        if(matchedTarget == false){
            return {};
        }

        return edges;
    }
};
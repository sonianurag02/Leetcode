// -------------------------------- Approach - 1 -------------------------------------
// Using Dijkstra's Algorithm

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);

        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist1(n+1, INT_MAX), dist2(n+1, INT_MAX), freq(n+1, 0);

        pq.push({0, 1});

        while(!pq.empty()){
            auto [timeTaken, node] = pq.top();
            pq.pop();

            freq[node]++;

            if(freq[node] == 2 && node == n) return timeTaken;

            if((timeTaken/change) % 2){
                timeTaken = change * (timeTaken / change + 1) + time;
            }
            else{
                timeTaken += time;
            }

            for(auto ngbr: adj[node]){
                if(dist1[ngbr] > timeTaken){
                    dist2[ngbr] = dist1[ngbr];
                    dist1[ngbr] = timeTaken;
                    pq.push({timeTaken, ngbr});
                } else if(dist2[ngbr] > timeTaken && dist1[ngbr] != timeTaken){
                    dist2[ngbr] = timeTaken;
                    pq.push({timeTaken, ngbr});
                }
            }
        }
        return 0;
    }
};
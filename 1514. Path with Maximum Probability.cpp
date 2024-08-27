#include <bits/stdc++.h>
using namespace std;

// ---------------------------------- Approach - 1 ----------------------------------

class Solution {
public:
    typedef pair<double, int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;

        int j = 0;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            double prob = succProb[j];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
            j++;
        }

        vector<double> result(n, 0);

        priority_queue<P> pq;

        result[start] = 1; // Probability to reach start from start is 100% = probability of 1
        pq.push({1.0, start});

        while(!pq.empty()){
            double currProb = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto& temp: adj[currNode]){
                int adjNode = temp.first;
                double adjProb = temp.second;

                if(result[adjNode] < currProb * adjProb){
                    result[adjNode] = currProb * adjProb;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }

        return result[end];
    }
};
// ---------------------- Approach - 1 ----------------------------
// Using BFS | Kahn's Algo

class Solution {
public:
    vector<int> topologicalSort(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree){
        queue<int> que;

        vector<int> result;
        int count = 0;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                result.push_back(i);
                count++;
                que.push(i);
            }
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int &v: adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    result.push_back(v);
                    count++;
                    que.push(v);
                }
            }
        }

        if(count == n){
            return result;
        }

        // we had a cycle and we couldn't complete aa the courses (visit all nodes)
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        vector<int> indegree(numCourses, 0); // Kahn's Algo

        for(auto& vec: prerequisites){
            int a = vec[0];
            int b = vec[1];

            // {a, b}
            // b -> a
            adj[b].push_back(a);

            // arrow -> 'a' me jaa rha hai
            indegree[a]++;
        }

        return topologicalSort(adj, numCourses, indegree);
    }
};

// ---------------------- Approach - 2 ----------------------------
// Using DFS | Topological Sort

class Solution {
public:
    bool hasCycle;

    void DFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st,  vector<bool>& inRecursion){
        visited[u] = true;
        inRecursion[u] = true;

        // Pehle mere (u ke node ke) bacchon ko daalo stack(st) me
        for(int& v: adj[u]){
            if(inRecursion[v] == true){
                hasCycle = true;
                return;
            }

            if(!visited[v]){
                DFS(adj, v, visited, st, inRecursion);
            }
        }

        // Ab mujhe daalo stack(st) me
        st.push(u);
        inRecursion[u] = false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        vector<bool> inRecursion(numCourses, false);
        vector<bool> visited(numCourses, false);
        hasCycle = false;

        for(auto& vec: prerequisites){
            int a = vec[0];
            int b = vec[1];

            // {a, b}
            // b -> a
            adj[b].push_back(a);
        }

        stack<int> st;

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                DFS(adj, i, visited, st, inRecursion);
            }
        }

        if(hasCycle == true){
            return {};
        }

        vector<int> result;

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};
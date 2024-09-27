// ----------------------- Approach - 1 -------------------------
// Using BFS

class Solution {
public:
    bool topologicalSortCheck(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree){
        queue<int> que;

        int count = 0;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                count++;
                que.push(i);
            }
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int& v: adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    count++;
                    que.push(v);
                }
            }
        }

        if(count == n){ // I was able to visit all nodes (courses)
            return true; // i.e., I was able to finish all the courses
        }

        return false; // means there was a cycle and i was not able to complete all the courses
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0); // Kahn's Algo

        for(vector<int>& vec: prerequisites){
            int a = vec[0];
            int b = vec[1];

            // b --> a
            adj[b].push_back(a);

            // arrow is going to 'a'
            indegree[a]++;
        }

        return topologicalSortCheck(adj, numCourses, indegree);
    }
};

// ----------------------- Approach - 2 -------------------------
// Using DFS

class Solution {
public:
    bool isCycleDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion){
        visited[u] = true;
        inRecursion[u] = true;

        for(int& v: adj[u]){
            // If not visited, then hit DFS on v
            if(!visited[v] && isCycleDFS(adj, v, visited, inRecursion)){
                return true; // cycle to hai
            }
            else if (inRecursion[v] == true){
                return true;
            }
        }

        inRecursion[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        vector<bool> visited(numCourses, false); 
        vector<bool> inRecursion(numCourses, false); 

        for(auto& vec: prerequisites){
            int a = vec[0];
            int b = vec[1];

            // b --> a
            adj[b].push_back(a);
        }

        for(int i = 0; i < numCourses; i++){
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion)){
                return false; // Course complete nahi kar sakte
            }
        }

        return true; // Kar sakte hai saare course complete
    }
};
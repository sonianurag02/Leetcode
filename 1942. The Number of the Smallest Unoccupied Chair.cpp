// -------------------------- Approach - 1 --------------------------------------
// Brute Force

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<int> chairs(n, -1);

        int targetFriendArrivalTime = times[targetFriend][0];

        sort(begin(times), end(times));

        for(vector<int>& time: times){
            int arrival = time[0];
            int depart = time[1];

            for(int i = 0; i < n; i++){
                if(chairs[i] <= arrival){
                    chairs[i] = depart;

                    if(arrival == targetFriendArrivalTime){
                        return i;
                    }
                    break;
                }
            }
        }

        return -1;
    }
};

// -------------------------- Approach - 2 --------------------------------------
// Optimal 

class Solution {
public:
    typedef pair<int, int> P;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        // {depart, chair} pair<int, int>
        // {freeChair}

        priority_queue<P, vector<P>, greater<P>> occupied; // {departTime, ChairNum}
        priority_queue<int, vector<int>, greater<int>> free; // min indexed chair number

        int targetFriendArrivalTime = times[targetFriend][0];

        int chairNo = 0;
        sort(begin(times), end(times)); // based on arrival time

        for(int i = 0; i < n; i++){
            int arrival = times[i][0];
            int depart = times[i][1];

            while(!occupied.empty() && occupied.top().first <= arrival){
                free.push(occupied.top().second);
                occupied.pop();
            }

            if(free.empty()){ // No free chairs aailable
                occupied.push({depart, chairNo});
                if(arrival == targetFriendArrivalTime){
                    return chairNo;
                }
                chairNo++;
            } else {
                int leastChairAvailable = free.top();
                free.pop();
                if(arrival == targetFriendArrivalTime){
                    return leastChairAvailable;
                }
                occupied.push({depart, leastChairAvailable});
            }
        }

        return -1;
    }
};
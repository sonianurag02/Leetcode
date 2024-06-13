// -------------------------------- Approach - 1 (Sorting (Greedy)) ------------------------------

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int minMoves = 0;

        for(int i = 0; i < seats.size(); i++){
            minMoves += abs(seats[i] - students[i]);
        }

        return minMoves;
    }
};

// -------------------------------- Approach - 2 (Counting sort) ------------------------------

class Solution {
public:
    int findMax(const vector<int>& arr){
        int maxi = 0;
        for(int num: arr){
            if(num > maxi){
                maxi = num;
            }
        }
        return maxi;
    }

    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int maxPos = max(findMax(seats), findMax(students));

        vector<int> differences(maxPos, 0);

        for(int pos: seats){
            differences[pos - 1]++;
        }

        for(int pos: students){
            differences[pos - 1]--;
        }

        int moves = 0;
        int unmatched = 0;

        for(int diff: differences){
            moves += abs(unmatched);
            unmatched += diff;
        }

        return moves;
    }
};
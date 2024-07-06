// ------------------------------ Approach - 1 (Simulation) ------------------------------------

class Solution {
public:
    int passThePillow(int n, int time) {
        int idx = 1;
        int dir = 1;

        while(time > 0){
            if(idx + dir >= 1 && idx + dir <= n){
                idx += dir;
                time--;
            }
            else{
                dir *= -1;
            }
        }

        return idx;
    }
};

// ------------------------------ Approach - 2 (Math) ------------------------------------

class Solution {
public:
    int passThePillow(int n, int time) {
        int fullRound = time / (n-1);
        int timeLeft = time % (n-1);

        if(fullRound % 2 == 0){
            return timeLeft+1;
        }
        else{
            return n - timeLeft;
        }
    }
};
// ------------------------------------------ Approach - 1 ---------------------------------------------

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int i = 0, j = 0, cur_d = 0,
        direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res(m, vector<int>(n, -1));

        for (; head != nullptr; head = head->next) {
            res[i][j] = head->val;
            int newi = i + direction[cur_d][0];
            int newj = j + direction[cur_d][1];

            // If we bump into an edge or an already filled cell, change the
            // direction.
            if (min(newi, newj) < 0 || newi >= m || newj >= n || res[newi][newj] != -1)
                cur_d = (cur_d + 1) % 4;
            i += direction[cur_d][0];
            j += direction[cur_d][1];
        }

        return res;
    }
};

// -------------------------------------------- Approach - 2 --------------------------------------------

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int id    = 0; //0, 1, 2, 3
        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;

        while(top <= down && left <= right) {
            if(id == 0) { //left to right
                for(int i = left; head != NULL && i <= right; i++) {
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }

            if(id == 1) { //top to down
                for(int i = top; head != NULL && i <= down; i++) {
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }

            if(id == 2) { //right to left
                for(int i = right; head != NULL && i >= left; i--) {
                    matrix[down][i] = head->val;
                    head = head->next;
                }
                down--;
            }

            if(id == 3) { //down to top
                for(int i = down; head != NULL && i >= top; i--) {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }

            id = (id+1)%4; //0, 1, 2, 3
        }

        return matrix;
    }
};
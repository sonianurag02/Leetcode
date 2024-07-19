// --------------------------- Approach - 1 ---------------------------------

class Solution {
public:
    bool validBox(vector<vector<char>>& board, int sr, int er, int sc, int ec){
        unordered_set<char> st;
        
        for(int row = sr; row <= er; row++){
            for(int col = sc; col <= ec; col++){
                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end()){
                    return false;
                }

                st.insert(board[row][col]);
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // validate rows
        for(int row = 0; row < 9; row++){
            unordered_set<char> st;
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end()){
                    return false;
                }

                st.insert(board[row][col]);
            }
        }

        // validate columns
        for(int col = 0; col < 9; col++){
            unordered_set<char> st;
            for(int row = 0; row < 9; row++){
                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end()){
                    return false;
                }

                st.insert(board[row][col]);
            }
        }

        // validate 3*3 boxes
        for(int sr = 0; sr < 9; sr+=3){
            int er = sr + 2;
            for(int sc = 0; sc < 9; sc+=3){
                int ec = sc + 2;

                // sr, er, sc, ec
                if(!validBox(board, sr, er, sc, ec)){
                    return false;
                }
            }
        }

        return true;
    }
};

// --------------------------- Approach - 2 ---------------------------------

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;

                string row = string(1, board[i][j]) + "_ROW_" + to_string(i);
                string col = string(1, board[i][j]) + "_COL_" + to_string(j);
                string box = string(1, board[i][j]) + "_BOX_" + to_string(i/3) + "_" + to_string(j/3);

                if(st.find(row) != st.end() || st.find(col) != st.end() || st.find(box) != st.end()){
                    return false;
                }

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }

        return true;
    }
};
529. Minesweeper

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        else if (board[click[0]][click[1]] == 'E') {
            dfs (board,click);
        }
        return board;
    }
    
    void dfs (vector<vector<char>>& board, vector<int> position) {
        stack<vector<int>> st;
        int num = 0;
        // N
        if (position[0]+1<board.size()) {
            if (board[position[0]+1][position[1]] == 'M')
                num++;
        }
        // S
        if (position[0]-1>=0) {
            if (board[position[0]-1][position[1]] == 'M')
                num++;
        }
        // NE
        if (position[0]-1<board.size() && position[1]+1<board[0].size()) {
            if (board[position[0]-1][position[1]+1] == 'M')
                num++;
        }
        // E
        if (position[1]+1<board[0].size()) {
            if (board[position[0]][position[1]+1] == 'M')
                num++;
        }
        // W
        if (position[1]-1>=0) {
            if (board[position[0]][position[1]-1] == 'M')
                num++;
        }
        // SW
        if (position[0]+1<board.size() && position[1]-1>=0) {
            if (board[position[0]+1][position[1]-1] == 'M')
                num++;
        }
        // SE
        if (position[0]+1<board.size() && position[1]+1<board[0].size()) {
            if (board[position[0]+1][position[1]+1] == 'M')
                num++;
        }
        // NW
        if (position[1]-1>=0 && position[0]-1>=0) {
            if (board[position[0]-1][position[1]-1] == 'M')
                num++;
        }
        if (num != 0) {
            stringstream ss;
            char s;
            ss << num;
            ss >> s;
            board[position[0]][position[1]] = s;
        }
        else {
            board[position[0]][position[1]] = 'B';
        }
        
        if (board[position[0]][position[1]] == 'B') {
            if (position[0]-1>=0 && board[position[0]-1][position[1]] == 'E') {
                position[0]--;
                dfs (board,position);
                position[0]++;
            }
            if (position[0]+1<board.size() && board[position[0]+1][position[1]] == 'E') {
                position[0]++;
                dfs (board,position);
                position[0]--;
            }
            if (position[1]+1<board[0].size() && board[position[0]][position[1]+1] == 'E') {
                position[1]++;
                dfs (board,position);
                position[1]--;
            }
            if (position[1]-1>=0 && board[position[0]][position[1]-1] == 'E') {
                position[1]--;
                dfs (board,position);
                position[1]++;
            }
            // SW
            if (position[0]+1<board.size() && position[1]-1>=0) {
                if (board[position[0]+1][position[1]-1] == 'E') {
                    position[1]--;
                    position[0]++;
                    dfs (board,position);
                    position[1]++;
                    position[0]--;
                } 
            }
            // SE
            if (position[0]+1<board.size() && position[1]+1<board[0].size()) {
                if (board[position[0]+1][position[1]+1] == 'E'){
                    position[1]++;
                    position[0]++;
                    dfs (board,position);
                    position[1]--;
                    position[0]--;
                }
            }
            // NW
            if (position[1]-1>=0 && position[0]-1>=0) {
                if (board[position[0]-1][position[1]-1] == 'E') {
                    position[1]--;
                    position[0]--;
                    dfs (board,position);
                    position[1]++;
                    position[0]++;
                }
            }
            // NE
            if (position[0]-1<board.size() && position[1]+1<board[0].size()) {
                if (board[position[0]-1][position[1]+1] == 'E') {
                    position[1]++;
                    position[0]--;
                    dfs (board,position);
                    position[1]--;
                    position[0]++;
                }
            }
        }
        
        
        return;
    }
};

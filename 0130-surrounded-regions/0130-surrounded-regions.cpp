class Solution {
public:
    int flag = 1;
    set <pair<int,int>> st;

    void solve(vector<vector<char>>& board) {
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 'O')
                {
                    flag = 1;
                    dfs(board, i, j);
                    
                    
                    if(flag)
                        for(auto it : st)
                            board[it.first][it.second] = 'X';
                       
                    st.clear();
                }
                
            }
        }
    }


    void dfs(vector<vector<char>>& board, int i, int j)
    {
       
        if(i < 0 || i >= board.size() 
        || j < 0 || j >= board[0].size()
        || st.contains({i, j}) || board[i][j] == 'X') return;

        
        st.insert({i, j});
       
      
        if(i == 0 || i == board.size() - 1
        || j == 0 || j == board[0].size() - 1) flag = 0;

        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};
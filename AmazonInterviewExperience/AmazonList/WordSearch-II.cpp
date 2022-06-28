// Problem Link: https://leetcode.com/problems/word-search-ii/

class Solution {
public:

    struct Trie{
        map<char,Trie*> m;
        string st;

        Trie(){};
    };

    vector<string> result;

    void callDFS(int i, int j, int r, int c, vector<vector<char>>&b,Trie* head){

       const char temp = b[i][j];

        if(i<0 || j<0 || i>=r || j>=c || b[i][j]=='*') return;

        if(head->m.find(temp)==head->m.end()) return;
        Trie* cur = new Trie();
        cur = head->m[temp];

        if(!cur->st.empty()){
            result.push_back(cur->st);
            cur->st.clear();
            return;
        }

        b[i][j] = '*';

        callDFS(i+1,j,r,c,b,cur);
        callDFS(i,j-1,r,c,b,cur);
        callDFS(i-1,j,r,c,b,cur);
        callDFS(i,j+1,r,c,b,cur);

        b[i][j] = temp;

    }

    void insertTrie(string s, Trie* r){
        Trie* temp = new Trie();
        temp = r;

        for(char c:s){
            if(temp->m.find(c)==temp->m.end()){
                temp->m[c] = new Trie();
            }

            temp = temp->m[c];
        }

        temp->st = s;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        int r = board.size();
        int c = board[0].size();

        Trie* head = new Trie();
        // building up the Trie
        for(string s:words){
            insertTrie(s,head);
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                callDFS(i,j,r,c,board,head);
            }
        }

        return result;
    }
};

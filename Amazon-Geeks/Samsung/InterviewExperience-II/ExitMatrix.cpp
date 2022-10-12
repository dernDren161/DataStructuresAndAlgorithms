// Problem Link: 

class Solution {
public:
    vector<int> ans;
    int mode = 0;
    //0,1,2,3
    int row[4] = {0,1,0,-1};
    int col[4] = {1,0,-1,0};

    void callDFS(int cr, int cc, int pr, int pc, vector<vector<int>>& mat){

        if(cr<0 || cr>= mat.size() || cc<0 || cc>=mat[0].size()){
            ans.push_back(pr);
            ans.push_back(pc);
            return;
        }
        if(mat[cr][cc]==1){
            mat[cr][cc] = 0;
            if(mode==0) mode=1;
            else if(mode==1) mode=2;
            else if(mode==2) mode=3;
            else if(mode==3) mode=0;
        }

        callDFS(cr+row[mode],cc+col[mode],cr,cc,mat);
    }
    vector<int> FindExitPoint(vector<vector<int>>&matrix){
		// Code here
		callDFS(0,0,0,0,matrix);
		return ans;

    }
};

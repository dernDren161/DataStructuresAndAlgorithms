// Problem Link: https://github.com/twowaits/SDE-Interview-Questions/tree/master/Samsung

#include<bits/stdc++.h>
using namespace std;

int count_number(int **arr,int r,int c,int pos_r,int pos_c,int length){
    if(length <= 1) return length;

    int up[] = {0,1,1,0,1,0,0,1};
    int down[] = {0,1,1,0,0,1,1,0};
    int left[] = {0,1,0,1,0,0,1,1};
    int right[] = {0,1,0,1,1,1,0,0};


    bool **visited = new bool*[r];
    for(int i=0;i<r;i++){
        visited[i] = new bool[c];
        for(int j=0;j<c;j++) visited[i][j] = false;
    }
    int level = 1;
    int count = 0;
    queue<pair<int,int>> q1;
    q1.push(make_pair(pos_r,pos_c));
    visited[pos_r][pos_c] = true;
    q1.push(make_pair(INT_MIN,INT_MIN));

    while(!q1.empty()){
        if(level > length) break;
        pair<int,int> temp = q1.front();
        q1.pop();
        if(temp.first == INT_MIN && temp.second == INT_MIN){
            if(q1.empty()) break;
            level++;
            q1.push(make_pair(INT_MIN,INT_MIN));
        }else{
            count ++;
            int val = arr[temp.first][temp.second];
            int row = temp.first,col = temp.second;

            //cout<<row<<","<<col<<endl;
            //For up
            if(up[val] == 1 && row-1>=0 && arr[row-1][col] != 0 && !visited[row-1][col] && down[arr[row-1][col]]){
                q1.push(make_pair(row-1,col));
                visited[row-1][col] = true;
            }
            //For down
            if(down[val] == 1 && row+1<r && arr[row+1][col] != 0 && !visited[row+1][col] && up[arr[row+1][col]]){
                q1.push(make_pair(row+1,col));
                visited[row+1][col] = true;
            }
            //For left
            if(left[val] == 1 && col-1>=0 && arr[row][col-1] != 0 && !visited[row][col-1] && right[arr[row][col-1]]){
                q1.push(make_pair(row,col-1));
                visited[row][col-1] = true;
            }
            //For right
            if(right[val] == 1 && col+1<c && arr[row][col+1] != 0 && !visited[row][col+1] && left[arr[row][col+1]]){
                q1.push(make_pair(row,col+1));
                visited[row][col+1] = true;
            }
        }
    }
    return count;
}

int main() {
    int test = 0;
    cin>>test;
    for(int i=0;i<test;i++){
        int r = 0, c = 0, pos_r=0,pos_c= 0,length = 0;
        cin>>r>>c>>pos_r>>pos_c>>length;
        int **arr = new int*[r];
        for(int j=0;j<r;j++){
            arr[j] = new int[c];
        }
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                cin>>arr[j][k];
            }
        }
        cout<<count_number(arr,r,c,pos_r,pos_c,length)<<endl;
    }
}

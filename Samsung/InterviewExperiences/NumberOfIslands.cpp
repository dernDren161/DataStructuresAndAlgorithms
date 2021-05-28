// Use simple DFS approach

// Time Complexity: O(Row X Col)

int rowM = {0,1,1,1,0,-1,-1,-1};
int colM = {1,1,0,-1,-1,-1,0,1};

int Row,Col;

bool safe(int r, int c){
  return (r<Row && col<Col && r>=0 && c>=0);
}

void callDFS(int M[][col],bool visited[][col],int row, int col){

  visited[row][col] = true;

  for(int i=0;i<8;i++){
    if(safe(row+rowM[i],col+colM[i]) && !visited[row+rowM[i]][col+colM[i]] && M[row+rowM[i]][col+colM[i]]==1){
      callDFS(M,visited,row+rowM[i],col+colM[i]);
    }
  }

}
int countIslands(int M[][col]){

  bool visited[Row][Col];

  memset(visited,false,sizeof(visited));

  int c = 0;

  for(int i=0;i<Row;i++){
    for(int j=0;j<Col;j++){
      if(!visited[i][j] && M[i][j]==1){
        callDFS(M,visited,Row,Col);
        c++;
      }
    }
  }
  return c;
}

#include<bits/stdc++.h>
using namespace std;
int w;
map<int,string> messMap;

int optimisedMenu(int satisfaction[], int expense[], int messBudget, int days){

    int mat[days+1][messBudget+1];

    for(int i=0;i<messBudget+1;i++) mat[0][i] = 0;

    for(int i=1;i<days+1;i++) mat[i][0] = 0;

    for(int i=1;i<days+1;i++){
      for(int j=1;j<messBudget+1;j++){

        if(j<expense[i-1]){
          mat[i][j] = mat[i-1][j];
        }else{
          mat[i][j] = max(satisfaction[i-1]+mat[i-1][j-expense[i-1]],mat[i-1][j]);
        }
      }
    }



    int res = mat[days][messBudget];

    w = messBudget;

    for (int i = days; i > 0 && res > 0; i--) {
       if (res == mat[i - 1][w])
          continue;
       else {
          auto p = messMap.find(expense[i-1]);
          cout << "The Vegetable is--- " << p -> second << " of price--- " << expense[i-1] << endl;
          res = res - satisfaction[i - 1];
          w = w - expense[i - 1];
       }
    }

    return mat[days][messBudget];
}

int main(){
  int messBudget = 500;
  int satisfaction[7] = {50,80,20,30,40,20,30};
  int expense[7] = {101,121,70,122,102,110,90};
  string vegetables[7] = {"Cabbage","Cauliflower","Nutrela","Beans","Matar Paneer","Palak Paneer","Spinach"};

  for(int i=0;i<7;i++){
    messMap[expense[i]] = vegetables[i];
  }

  int ans = optimisedMenu(satisfaction,expense,messBudget,7);
  cout << "The maximum satisfaction that can be achieved with the given mess budget is: " << ans << endl;
  return 0;
}

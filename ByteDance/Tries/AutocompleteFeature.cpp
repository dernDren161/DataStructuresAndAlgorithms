// Autocomplete feature;
#include<bits/stdc++.h>
using namespace std;

struct Trie{
  unordered_map<int,Trie*>myMap;
  bool isFlag;

  Trie(){
    for(int i=0;i<26;i++){
      myMap[i] = NULL;
    }
    isFlag = false;
  }
};

bool checkAfterNode(Trie* head){

    for(int i=0;i<26;i++){
      head = head->myMap[i];
      if(head!=NULL) return true;
    }

    return false;
}

vector<string> callToSearch(Trie* head, string s, vector<string>&res){

    if(head==NULL) return res;
    if(head->isFlag==true){
      res.push_back(s);
      return res;
    }

    for(int i=0;i<26;i++){
      if(head->myMap.find(i)!=head->myMap.end()){
        callToSearch(head->myMap[i],s+'a',res);
      }
    }
}

vector<string> callToRecommend(Trie* head, string s){

  Trie* temp = new Trie();
  temp = head;

  vector<string>res;

  for(char x:s){
    temp = temp->myMap[x-'a'];
    if(temp == NULL) return {};
  }

  if(!checkAfterNode(temp)){
    return {s};
  }

  return callToSearch(temp,s,res);

}

void callToInsert(Trie* head, string s){
  Trie* temp = new Trie();
  temp = head;

  for(char x:s){
    if(temp->myMap.find(x-'a')==temp->myMap.end()){
      temp->myMap[x-'a'] = new Trie();
    }
    temp = temp->myMap[x-'a'];
  }

  temp->isFlag = true;
}
int main(){

  string str[4] = {"Prastik","Pratik","Pratyush","Pram"};

  Trie* head = new Trie();

  for(int i=0;i<4;i++){
    callToInsert(head,str[i]);
  }

  vector<string>ans = callToRecommend(head,"Pra");
  for(string s:ans)cout << s.c_str() << endl;

}

/*
  T.C: For insertion(of all words), O(N*M), where N is the no. of words and M is the length of the longest string
       For searching, O(M)
  S.C: For insertion(of all) O(N*M)
     : For searching, O(1)
  */

#include<bits/stdc++.h>
using namespace std;

struct Trie{

  bool isLeaf;
  unordered_map<char,Trie*> m;
    Trie(){
      isLeaf = false;
    }
};

void insertInto(string s, Trie* head){

    Trie* temp = new Trie();
    temp = head;

    for(char ch:s){
      if(temp->m.find(ch)==temp->m.end()){
        temp->m[ch] = new Trie();
      }
      temp = temp->m[ch];
    }

    temp->isLeaf = true;
}

bool searchTrie(Trie* head, string s){

  if(head==NULL) return false;

  Trie* temp = new Trie();
  temp = head;

  for(char ch : s){
    temp = temp->m[ch];

    if(temp==NULL) return false;
  }

  return temp->isLeaf;
}

int main(){

  string arr[] = {"prastik","gyawali","kathmandu","nepal"};

  Trie* head = new Trie();

  for(int i=0;i<4;i++){
      insertInto(arr[i],head);
  }

  if(searchTrie(head,"gyawali")){
    cout << "Your word was found inside the Trie" << endl;
  }else{
    cout << "Sorry Your word was not found inside the Trie" << endl;
  }

  return 0;

}

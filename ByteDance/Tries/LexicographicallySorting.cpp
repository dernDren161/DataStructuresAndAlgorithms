#include<bits/stdc++.h>
using namespace std;

struct Trie{

  string myStringValue;
  bool isFlag;
  map<int,Trie*> myMap;

  Trie(){
    isFlag = false;
    for(int i=0;i<26;i++){
      myMap[i]=NULL;
    }
  }
};

// inserted the values into the Trie.
void insertVals(Trie* head,string& str){
  Trie* temp = new Trie();
  temp = head;

  for(char c: str){
    if(temp->myMap.find(c-'a') == temp->myMap.end()){ // if not found, then
      temp->myMap[c-'a'] = new Trie();
    }
    temp = temp->myMap[c-'a'];
  }
  temp->isFlag = true;
  temp->myStringValue = str;

}

void callPreorder(Trie* cur){
  if(cur == NULL) return;

  for(int i=0;i<26;i++){
    if(cur->myMap[i] != NULL){
      if(cur->isFlag){
        cout << cur->myStringValue << endl;
      }
      callPreorder(cur->myMap[i]);
    }
  }
}
int main(){

  Trie* head = new Trie();

  string dict[] =
  {
      "lexicographic", "sorting", "of", "a", "set", "of", "keys", "can",
      "be", "accomplished", "with", "a", "simple", "trie", "based",
      "algorithm", "we", "insert", "all", "keys", "in", "a", "trie",
      "output", "all", "keys", "in", "the", "trie", "by", "means", "of",
      "preorder", "traversal", "which", "results", "in", "output", "that",
      "is", "in", "lexicographically", "increasing", "order", "preorder",
      "traversal", "is", "a", "kind", "of", "depth", "first", "traversal"
  };
  int n = sizeof(dict)/sizeof(dict[0]);

  for(int i=0;i<n;i++){
    insertVals(head,dict[i]);
  }

  callPreorder(head);
  return 0;

}

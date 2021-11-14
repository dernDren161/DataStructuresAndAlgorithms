// Problem Link: https://www.geeksforgeeks.org/find-all-shortest-unique-prefixes-to-represent-each-word-in-a-given-list/
// Main Link:    https://www.techiedelight.com/shortest-unique-prefix/

// T.C: O(m*n), where 'n' is the total number of words in the given list and 'm' is the maxumum length of the word in the list

#include<bits/stdc++.h>
using namespace std;

struct Trie{

  unordered_map<char,Trie*> m;
  int frequency;

    Trie(){
      frequency = 0;
    }
};

void callToInsert(Trie* root, string s){

  Trie* temp = new Trie();
  temp = root;

  for(char ch:s){
    if(temp->m.find(ch)==temp->m.end()){ // if not found
      temp->m[ch] = new Trie();
    }

      temp->m[ch]->frequency++; // NOTE: Important, might forget
      temp = temp->m[ch];
  }
}

// NOTE: Here we pass 's' with call by value as we backtrack, be careful here !!
void callForPreorder(Trie* root, string s){

  if(root==NULL) return;

  if(root->frequency == 1){
    cout << s << endl;
    return;
  }

  for(auto& x:root->m){
    callForPreorder(x.second,s+x.first);
  }
}
void findShortestPrefix(vector<string> words){

  Trie* head = new Trie();

  for(int i=0;i<words.size();i++){
    callToInsert(head,words[i]);
  }

  callForPreorder(head,"");

}
int main(){

  vector<string> words = {"AND","BOOL","BONFIRE","CATCH","CASE","CHAR"};

  findShortestPrefix(words);

  return 0;
}

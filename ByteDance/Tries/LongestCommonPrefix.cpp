#include<bits/stdc++.h>
using namespace std;

// If N elements are there with maximum of M length, then
// Worst case time complexity is:  O(N*M)
// Worst case space complexity is: O(N*M)

// creating a Trie
struct Trie{
  bool isLeaf;
  map<char,Trie*> myMap;

  Trie(){
    isLeaf = false; // means is not a leaf
  }
};

void insertInto(string& str,Trie* head){

  Trie* temp = new Trie();
  temp = head;

  for(char c:str){
    if(temp->myMap.find(c)==temp->myMap.end()){ // not found
      temp->myMap[c] = new Trie();
    }

    temp = temp->myMap[c];
  }
  temp->isLeaf = true;
}

string call(string dict[], int n){
  Trie* head = new Trie(); // creating the emtpy head/root node

  for(int i=0;i<n;i++){
    insertInto(dict[i],head);
  }

  // actual computation
  string res ="";
  Trie* ans = new Trie();
  ans = head;

  while(ans && (!ans->isLeaf) && (ans->myMap.size()==1)){
    auto p = ans->myMap.begin();

    res += p->first;
    ans = p->second;
  }

  return res;
}
int main(){

  string dict[] =
  {
      "code", "coder", "coding", "codable", "codec", "codecs", "coded",
      "codeless", "codependence", "codependency", "codependent",
      "codependents", "codes", "codesign", "codesigned", "codeveloped",
      "codeveloper", "codex", "codify", "codiscovered", "codrive"
  };

  int n = sizeof(dict)/sizeof(dict[0]);

  cout << "The longest common prefix here is: " << endl;
  cout << call(dict,n) << endl;

  return 0;
}

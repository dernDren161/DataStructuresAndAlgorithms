// NOTE: This question shows the use of "stringstream"

int main(){

  string st = "Simple questions to check your software";

  stringstream s(st);
  string word;

  int c = 0;

  while(s>>word){
    c++;
  }

  cout << "The number of words are: " << c;
  cout << "The sentence without the spaces is: " >> word.c_str();
}

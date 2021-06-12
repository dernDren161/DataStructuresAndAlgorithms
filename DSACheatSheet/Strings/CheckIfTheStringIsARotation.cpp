// Problem Link: https://www.tutorialspoint.com/a-program-to-check-if-strings-are-rotations-of-each-other-or-not

bool isRotation(string s1, string s2){

  if(s1.size() != s2.size()) return false;

  string temp = s1 + s1;

  if(temp.find(s2) != string::npos) return true;

  return false;
}

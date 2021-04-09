// Problem Link: https://practice.geeksforgeeks.org/problems/anagram-of-string/1/?track=amazon-strings&batchId=192

// similar question in above array sub section.

int remAnagram(string str1, string str2)
{

     map<char,int> m1;
     map<char,int> m2;
     int count1 = 0;
     int count2 = 0;


     for(auto&& c : str1){
         m1[c]++;
     }
     for(auto&& c : str2){
         m2[c]++;
     }

     for(auto&& c : str1){

         auto btr = m2.find(c);
         auto ptr = m1.find(c);

         if(btr != m2.end()){
             btr -> second--;
             ptr -> second--;
             if(btr -> second == 0) m2.erase(btr);
             if(ptr -> second == 0) m1.erase(ptr);
         }
    }



    for(auto j : m1){
       count1 += j.second;
    }

    for(auto j : m2){
        count2 += j.second;
    }

    m1.clear();
    m2.clear();
    return count1+count2;

}

#include<iostream>
using namespace std;

void show(char array[], int n) {
   for(int i = 0; i<n; i++)
      cout << array[i] << " ";
}

//  partition(nuts, low, high, bolts[high])
int partition(char array[], int low, int high, char pivot) {    //find location of pivot for quick sort
   int i = low;
   for(int j = low; j<high; j++) {
      if(array[j] <pivot) {    //when jth element less than pivot, swap ith and jth element
         swap(array[i], array[j]);
         i++;
      }else if(array[j] == pivot) {    //when jth element is same as pivot, swap jth and last element
         swap(array[j], array[high]);
         j--;
      }
   }
   swap(array[i], array[high]);
   return i;    //the location of pivot element
}

void nutAndBoltMatch(char nuts[], char bolts[], int low, int high) {
   if(low < high) {
      int pivotLoc = partition(nuts, low, high, bolts[high]);   //choose item from bolt to nut partitioning
      partition(bolts, low, high, nuts[pivotLoc]);    //place previous pivot location in bolt also
      nutAndBoltMatch(nuts, bolts, low, pivotLoc - 1);
      nutAndBoltMatch(nuts, bolts, pivotLoc+1, high);
   }
}

int main() {
   char nuts[] = {')','@','*','^','(','%','!','$','&','#'};
   char bolts[] = {'!','(','#','%',')','^','&','*','$','@'};
   int n = 10;
   nutAndBoltMatch(nuts, bolts, 0, n-1);
   cout << "After matching nuts and bolts:"<< endl;
   cout << "Nuts:  "; show(nuts, n); cout << endl;
   cout << "Bolts: "; show(bolts, n); cout << endl;
}

// This was observed in one of Joma Tech's videos
// Using simple sorting to find duplication in the adjacent nodes it takes more Time
// Again solving the question using Hash Maps, it takes more space.
// Thus using this efficient approach to solve this question using the 'Floyd Tortoise and Hare Algorithm'
// This question is similar to finding the loop in a Linked List.


int call(int arr[]){

  int slow = 0;
  int fast = 0;
  int point = 0;

  // break is when the first one of the two duplication is arrived
  while(1){
    slow = arr[slow];
    fast = arr[arr[fast]];

    if(slow == fast) break;
  }

  // this is finding the second duplication one in the array

  // if desired to return the index values of the position of the numbers
  // we can avail from these two while loops.

  while(1){
    slow = arr[slow];
    point = arr[point];

    if(slow == point) return slow;
  }
}

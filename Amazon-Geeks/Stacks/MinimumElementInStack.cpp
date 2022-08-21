// Problem Link: https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1#

// We can do this same problem using two stacks but then the Auzillary complexity become: O(n)
// This solution decreases the space complexity to O(1) space.

int _stack :: getMin()
{

   if(s.empty()) return -1;

   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{

   if(s.empty()) return -1;
   else{
       if(s.top() >= minEle){
           int temp = s.top();
           s.pop();
           return temp;
       }
       else if(s.top() < minEle){ // decrypt the value, restore the value of minEle before popping the top element


            int x = s.top();
           int kk = minEle;
           s.pop();
           minEle = minEle*2 - x;
           return kk;  // Here I return the original minEle as that was the exact element of the then encrypted pushed value.
       }
   }
}

/*push element x into the stack*/
void _stack::push(int x)
{

   if(s.empty()){
      s.push(x);
      minEle = x;
   }else{
       if(x >= minEle){
           s.push(x);
       }else if(x < minEle){ // x-minEle gives negative value, so 2*x-minEle gives value lesser than x
           s.push(2*x-minEle);
          minEle = x;  //  NOTE: this means though the pushed value is encrypted, it's original value is stored inside 'minEle'
       }
   }
}

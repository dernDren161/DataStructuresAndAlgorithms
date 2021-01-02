// { Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class Driverclass
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        //Reading total number of testcases
        int t= sc.nextInt();

        while(t-- >0)
        {
            //reading the string
            String st = sc.next();

            //calling ispar method of Paranthesis class
            //and printing "balanced" if it returns true
            //else printing "not balanced"
            if(Parenthesis.ispar(st) == true)
                System.out.println("balanced");
            else
                System.out.println("not balanced");

        }
    }
}// } Driver Code Ends


class Parenthesis
{
    // Function to return if the paranthesis are balanced or not
    static boolean ispar(String x)
    {
        Stack<Character> st = new Stack<Character>();

        for(char c : x.toCharArray()){

            if(c == '(' || c=='{' || c == '[') st.push(c);
            else if(c==')' && !st.isEmpty() && st.peek()=='(') st.pop();
            else if(c=='}' && !st.isEmpty() && st.peek()=='{') st.pop();
            else if(c==']' && !st.isEmpty() && st.peek()=='[') st.pop();
            else return false;
        }

        if(st.isEmpty()) return true;

        return false;
    }
}

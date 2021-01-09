import java.util.*;
import java.io.*;
import java.lang.*;

public class SingleNumber{
  public static void main(String[] args) {

    Scanner s = new Scanner(System.in);

    int inn = s.nextInt();

    // 7
    // 1,0,0,1,5,1,0
    int[] arr = new int[inn];

    for(int i=0;i<inn;i++){
      arr[i] = s.nextInt();
    }

    System.out.print(Passed.call(arr));

  }
}

class Passed{

  static int call(int arr[]){

    HashMap<Integer,Integer> m = new HashMap<Integer,Integer>();

    for(int x : arr){
      m.put(x,m.getOrDefault(x,0)+1);
    }

    for(int k : m.keySet()){
      if(m.get(k) == 1) return k;
    }

    return -1;
  }
}

import java.util.*;
import java.io.*;
import java.lang.*;

class SingletonLazy{

  private static SingletonLazy singletonTwo;

  private SingletonLazy(){};

  private static SingletonLazy callLazy(){
    if(singletonTwo == null){
      synchronized(SingletonLazy.class){ // 'synchronized' is not that necessary, here we cover
                                         // all the test cases so as to prevent the 'race around condition'

        if(singletonTwo == null){
          singletonTwo = new SingletonLazy();
        }
      }
    }

    return singletonTwo;
  }

  public static void main(String[] args) {

    for(int i=0;i<5;i++){
      SingletonLazy s = new SingletonLazy();
      System.out.println("Return: " + s);
    }
  }
}

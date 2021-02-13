import java.util.*;
import java.io.*;
import java.lang.*;


// This is early singleton instantiation
// That is the instance is already instantiated for us before the hitting of the methods start.

class SingletonEarly{

    private static SingletonEarly singletonOne = new SingletonEarly();

    private SingletonEarly(){}

    public SingletonEarly callSingleton(){
      return singletonOne;
    }

  public static void main(String[] args) {

    // gives the same single instance again and again
    for(int i=0;i<5;i++){
      SingletonEarly s = new SingletonEarly();
      System.out.println("Result: " + s.callSingleton());
    }
  }
}

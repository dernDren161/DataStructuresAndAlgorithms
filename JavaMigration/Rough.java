import java.util.*;
import java.io.*;
import java.lang.*;

 class Employee{

  private String name;

  public String getName(){
    return name;
  }

  public void setName(String name){
    this.name = name;
  }
}

class Test{
 public static void main(String[] args) {

   Employee e = new Employee();

   e.setName("Prastik Gyawali");

   System.out.println("The name is: " + e.getName());
 }
}

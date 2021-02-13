import java.util.*;
import java.io.*;
import java.lang.*;

class EmployeeEntity{

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

    EmployeeEntity e = new EmployeeEntity();
    e.setName("Prastik Gyawali");

    System.out.println("The author's name is " + e.getName());
  }
}

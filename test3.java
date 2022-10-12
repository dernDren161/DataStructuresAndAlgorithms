// Design a Parking ParkingLot

class ParkingLot{

    List<ParkingFloors> parkingFloors;
    String name;
    List<Entrance> entrances;
    List<Exit> exits;

    bool isSpaceAvailable(Vehicle v){}
}

public class Gate{
  ParkingAssistant pA;
  int gateId;
}

public Entrance extends Gate{

}

public Exit extends Gate{

}

class ParkingFloors{
  List<ParkingSpace> parkingSpaces;
  int parkingId;

}

class ParkingSpace{

  private VideoFootage videoFootage;
  int uniqueId;
  ParkingDisplayUnit parkingDisplayUnit;
  Vehicle vehicle;
  double fareUnit;

  int theVacancyHere(int id){

  }

  VideoFootage getVideoFootage(String username, String password){
    bool u = customerDAO.findUsername(usernae);
    bool p = customerDAO.findPassword(username,password);

    if(p) return videoFootage;
  }

  void setVideoFootage(VideoFootage videoFootage){
    this->videoFootage = videoFootage;
  }
}

public enum VehicleType{
  CAR,BIKE,CYCLE;
}

public class Account{
  public String name;
  public String password;
  public String email;
  Public Address address;
}

public User extends Account{

}

public Assistant extends Account{

}

public class ParkingTicket{

  Vehicle vehicle;
  Date inTime;
  Date outTime;

  double vehicleFare(ParkingSpace pS){
    return;
  }
}

public class Payment{

  public PaymentInfo makepayment(ParkingTicket pT, PaymentType payType){
    return PayMentStatus;
  }
}

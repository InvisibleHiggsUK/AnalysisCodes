#ifndef PARTONS_H
#define PARTONS_H

#include <iostream>
#include <string>

class Partons{
 
 public:

  static float quarks(int i){
    if(i == 1){ return 1; }
    else if(i == 2){ return 2; }
    else if(i == 3){ return 3; }
    else if(i == 4){ return 4; }
    else if(i == 5){ return 5; }
    else if(i == 6){ return 6; }
    else if(i == 21){ return 21; }
    else{ return false; }
  }

  static bool findPartons(int p, int s){
    checkStatus(s);
    checkPartons(p);
    if( (s == 1) && (p == 1 || p == 2 || p == 3 || p == 4 || p == 5 || p == 6 || p == 21))
      {
	return true;
      }
    else { return false; }
  }
      

  //  float dquarks() const { return dquark; }
  static float dquarks();
  float uquarks() const { return uquark; }
  float squarks() const { return squark; }
  float cquarks() const { return cquark; }
  float bquarks() const { return bquark; }
  float tquarks() const { return tquark; }
  float gluons()  const { return gluon; }



 private:

  float dquark;  // 1
  float uquark;  // 2
  float squark;  // 3 
  float cquark;  // 4
  float bquark;  // 5
  float tquark;  // 6
  float gluon;   // 21

  static void checkStatus(int s);
  static void checkPartons(int p);

};

float Partons::dquarks(){
  return 1;
}

void Partons::checkStatus(int s){
  if(s != -1 && s != 1){
    std::cerr << "\nERROR invalid status" << s << std::endl;
      }
}

void Partons::checkPartons(int p){
  if(p != 1 && p != 2 && p != 3 && p != 4 && p != 5 && p != 6 && p != 21 && p!= 25) {
    std::cerr << "\nERROR invalid pdgCode" << p << std::endl;
  }
}


#endif

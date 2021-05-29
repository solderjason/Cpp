//Dice Roller

#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include <chrono>
using namespace std;


int main(){
  srand(time(NULL));

int faces=0;
int rolls=0;
int result=0;

std::cout<<"Enter the number of faces:"
std::cin>> faces
std::cout<<"Enter the number of rolls:"

std::cin>> rolls



for (int i = 0; i <rolls; i++) {
  result=rand() %number +1 //+1 so its from 1-n
  std::cout<<"You rolled "+'result'<<std::endl

  auto timenow =
     chrono::system_clock::to_time_t(chrono::system_clock::now());

   cout << ctime(&timenow) << endl;
  return 0;
}

  system("PAUSE")'
  return 0;
}

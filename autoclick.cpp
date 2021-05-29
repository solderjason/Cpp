#include <windows.h>
#include <iostream>
#include <random>
using namespace std;
bool clicker;
int rand;
bool random;

//void location(int x, int y){

//}
void options()
{
std::cout<< "Press '/' to enable left click, 'r' to enable randomized left_click and '\' to turn off autoclick ";
}

void left_click(){

  while(1){
    if(GetAsyncKeyState('/')){
      clicker=true;
    }

  else  if(GetAsyncKeyState('\') ){
      clicker=false;
    }
    else  if(GetAsyncKeyState('r') ){
        clicker=true;
        random=true;
      }
if(clicker==true){
  mouse_event( MOUSEEVENTF_LEFTDOWN, 0, 0, 0 );

  Sleep( 50 );
  mouse_event( MOUSEEVENTF_LEFTUP, 0, 0, 0 );
}
if (clicker==true && random==true){
  mouse_event( MOUSEEVENTF_LEFTDOWN, 0, 0, 0 );

  Sleep( rand() %50 );
  mouse_event( MOUSEEVENTF_LEFTUP, 0, 0, 0 );
}
}
}
/*
void right_click(){
  mouse_event( MOUSEEVENTF_RIGHTDOWN, 0, 0, 0 );

  Sleep( 50 );
  mouse_event( MOUSEEVENTF_RIGHTP, 0, 0, 0 );
}
*/
int main(){
options();
left_click();
return 0;
}

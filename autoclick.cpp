#include <windows.h>
#include <iostream>
#include <random>
bool clicker;
int rand;
bool random;

void location(int x, int y){

}
void options()
{

}

void left_click(){

  while(1){
    if(GetAsyncKeyState('/')){
      clicker=true;
    }

    if(GetAsyncKeyState('\') ){
      clicker=false;
    }
if(clicker==true){
  mouse_event( MOUSEEVENTF_LEFTDOWN, 0, 0, 0 );

  Sleep( 50 );
  mouse_event( MOUSEEVENTF_LEFTUP, 0, 0, 0 );
}
if (clicker==true && random==true)
}
}

void right_click(){
  mouse_event( MOUSEEVENTF_RIGHTDOWN, 0, 0, 0 );

  Sleep( 50 );
  mouse_event( MOUSEEVENTF_RIGHTP, 0, 0, 0 );
}

int main(){

}

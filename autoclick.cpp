#include <windows.h>
#include <iostream>
#include <random>
#ifdef _WIN32

#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
using namespace std;

//void location(int x, int y){

//}
void options()
{
std::cout<< "Press 'E' to enable left click, 'D' to enable randomized left_click and 'R' to turn off autoclick "<<std::endl;
}

void left_click(){
  bool clicker=false;
  bool random=false;
std::cout<<"ON1 "<<std::endl;



  while(true) {
    if (GetAsyncKeyState('E'))
    {
      clicker = true;
      std::cout<<"ON "<<std::endl;
    }

 else if (GetAsyncKeyState('D'))
  {
      clicker = false;
        std::cout<<"OFF "<<std::endl;
    }
    else if (GetAsyncKeyState('R'))    {
        clicker = true;
        random = true;
          std::cout<<"Random "<<std::endl;
      }
if(clicker==true){
  mouse_event( MOUSEEVENTF_LEFTDOWN, 0, 0, 0 ,0);


  mouse_event( MOUSEEVENTF_LEFTUP, 0, 0, 0 ,0);
    Sleep( 10 );
}
 else if (clicker==true && random==true){
  mouse_event( MOUSEEVENTF_LEFTDOWN, 0, 0, 0 ,0);

  Sleep( rand() %10 );
  mouse_event( MOUSEEVENTF_LEFTUP, 0, 0, 0,0 );
}
  }
    }




int main()
{
options();
  std::cout<<"ON "<<std::endl;
left_click();


return 0;

}

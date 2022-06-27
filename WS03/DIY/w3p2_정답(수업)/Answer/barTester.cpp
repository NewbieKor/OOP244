/*----------------------------------------------------
Workshop 3:
Version: 1.0
Author: Fardad Soleimanloo
Description:
This file tests the Bar class of your DIY workshop
----------------------------------------------------*/
#include "Bar.h"
using namespace sdds;
int main() {
    Bar b; //생성과 동시에 초기화(생성자)
    /*Bar b1(b);
    b1 = b;*/
   for (int i = 1; i <= 5; i++) {
      b.set("the bar", '=', i*20);
      b.draw();
   }
   b.set("Bad Bar", '=', -200);
   b.draw();
   b.set("Bad Bar", '=', 200);
   b.draw();
   return 0;
}
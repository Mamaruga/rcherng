#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main()
{
   char drop;
   float win;
   int pick;
   int trials;
   float setTrial;
   char picked_marble;
   int num1;
   int game;
   string bag;	
   srand ( time(NULL));

   game =10;
   setTrial =1000000;
   
   while (!(game<=0))  //count number of game
   {
      bag ="bbwww";
      trials =setTrial;
      win =0;
      while (!(trials<=0))  //count number of trial
	        {
         num1 = rand() % bag.length(); //generate random number between 1-5 (length of bag) 
         if (bag[num1]=='b')
         {
            bag ="bwww";    //create a new bag after drop
            drop ='b';
         }
         else
         {
            bag ="bbww";   
            drop ='w';
         }
         pick =rand() % bag.length(); //generate random number between 1-4(length of the current bag)
         picked_marble =bag[pick];
         if (picked_marble=='b' && drop=='b')  //check if it drop black and pick up black marbles
         {
            win =win+1;
         }
         else
         {
         }
         trials -= 1;
      }
      cout << win/setTrial << endl;  //output the probability
   
		win =0;
      game =game-1;
   }

   return 0;
}

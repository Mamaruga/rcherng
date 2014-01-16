#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
    srand (time(NULL));
   int run;
   double temp;
   int neg;
   double pos;
   //int i;
  // int index;
   double Array[50];

   //setprecision(2);
   run =0;
   for(int i = 0;i < 50; i++)//while (!(run>49))
   {
      pos = double(rand()) / double(RAND_MAX);
      if (pos>0.5)
      {
         neg =1;
      }
      else
      {
         neg =-1;
      }
      Array[i] = neg*(double(rand()) / double(RAND_MAX)*5000);//neg*(rand()*5);
      //run += 1;
   }
   cout << "UN-Sorted Array:" << endl;
//      i =1;
   for(int i = 0; i < 50 ; i ++)//while (!(i>49))
   {
      cout << setw(8) << Array[i];
      cout << '\t';
      if (((i+1) % 5)==0)
      {

         cout << endl;
        }
      //i +=1;
   }
  // i =sizeof(Array);
   for(int i = 0; i < 50; i++)//while (!(i<1))
   {
     // index =1;
      for(int index = 0; index < 49; index++)//while (!(index>(i-1)))
      {
         if (Array[index]<Array[index+1])
         {
            temp =Array[index];
            temp =Array[index];
            Array[index] = Array[index+1];
            Array[index+1] = temp;
         }
         //index =index+1;
      }
      //i =i-1;
   }
   cout << "Sorted ARRAY:" << endl;
   //i =1;
   for(int i =0; i<50; i++)//while (!(i>49))
   {
      cout<<setw(8) << Array[i];
      cout << ((char) 9);
      if (((i+1) % 5)==0)
      {
         cout << "" << endl;      }
   //   i =i+1;
   }
   //int pause;
    //cin>>pause;
    system("pause");
   return 0;
}

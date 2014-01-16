#include <iostream>
#include <string>


using namespace std;
int main()
{
   string raptor_prompt_variable_zzyz;
   int i;
   string FacOut;
   int num;
   string pout;
   int factCount;
   int HiLimit;
   int SumCount;
   int SumInt;
   int LoLimit;
   int FacInt;
   int Count;
   string sumout;

   raptor_prompt_variable_zzyz ="LoLimit";
   cout << raptor_prompt_variable_zzyz << endl;
   cin >> LoLimit;
   raptor_prompt_variable_zzyz ="HiLimit";
   cout << raptor_prompt_variable_zzyz << endl;
   cin >> HiLimit;
   i =LoLimit;

   while (!(i>HiLimit))
   {
      cout << "FACTORIAL: "<< i << " = ";
      FacOut ="";
      FacInt =1;
      factCount =i;
      while (!(factCount<1))
      {
         FacInt =FacInt*factCount;
        cout<<factCount;// FacOut += factCount;
         factCount =factCount-1;
         if (!(factCount<1))
         {
            cout<<"*";//FacOut =FacOut+"*";
         }
      }
      cout <<" = " <<FacInt << endl;
      cout << "SUM OF POSITIVE INTEGER: ";
        //SumOut ="";
      SumInt =0;
      SumCount =i;
      while (!(SumCount<1))
      {
         SumInt =SumInt+SumCount;
        cout<<SumCount; // SumOut =SumOut+SumCount;
         SumCount =SumCount-1;
         if (!(SumCount<1))
         {
            cout<<"+";//SumOut =SumOut+"+";
         }
      }
      cout <<" = "<<SumInt << endl;
      cout << "PRIME FACTORS: "<<i<<" = ";
        //Pout ="";
      num =i;
      Count =2;
      while (!(num==1))
      {
         if ((num % Count)==0)
         {
            num =num/Count;
            cout<<Count;//Pout =Pout+count;
            if (!(num==1))
            {
               cout<<"*";//Pout =Pout+"*";
            }
         }
         else
         {
            Count += 1;
         }
      }
      cout << endl;
        cout << endl;
              i =i+1;
   }
   int pause;
	cin>>pause;//cin.get();//System("pause");
   return 0;
}

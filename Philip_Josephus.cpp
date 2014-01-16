#include<iostream>
#include <cstdlib> //allow us to use system("pause")

using namespace std;

const int NUMBER_SOLDIER = 41;
int remain = NUMBER_SOLDIER;
int soldier[NUMBER_SOLDIER];
int murder = 3;
int order = 1;

int main()
{
    for(int i=0; i< NUMBER_SOLDIER; i++)
    {
        soldier[i]=i+1;
    }
    while(remain > 1) //while solder > 1 it will keep running
    {
        for(int i=0; i < NUMBER_SOLDIER; i++)
        {
            if(soldier[i]!=0)
            {
                if(order%3 == 0) // kill every murder
                {
                    soldier[i] = 0;  //solder = 0 when they die
                    remain -= 1;
                }
                order++;
            }
        }
        for(int i=0; i < NUMBER_SOLDIER; i++)
        {
            if(soldier[i] != 0)
                cout<<soldier[i]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}

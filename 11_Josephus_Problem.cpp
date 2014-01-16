/*
Pongsathorn Cherngchaosil
November 18 2013
Assignment 11, Josephus Problem
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

const int NUMBER_SOLDIER = 41 ;
const int COUNT_TO_KILL = 3;
vector<int> soldier (NUMBER_SOLDIER);
int c = 1; //keep track of counting when finish one circle
void kill(int k)
{
    vector<int> temp;             // temporary array
    for(int i = 0 ; i < soldier.size(); i ++)
    {
         if(!( ((c)%k) == 0)) // put soldier that didn't get kill in temporary array
             temp.push_back(soldier[i]);
         c++;
    }swap(soldier,temp);  // update soldier
    temp.clear();
}
int main()
{
    for(int i=0; i < NUMBER_SOLDIER; i ++)  //initialize elements of the array;
        soldier[i] = i+1;
    while(soldier.size() > 2)   // keep repeating while the size of the array "soldier" is greater than 1
    {
        kill(COUNT_TO_KILL); // call the function kill()
        for(int i=0; i < soldier.size(); i++)
            cout<<soldier[i]<<" ";  //outputing soldier
        cout<<endl<<endl;
    }
    cout<<"The last soldier: "<<soldier[1]<<'\n';
    cout<<"The Second to last Soldier: " <<soldier[0]  <<endl;
    system("pause"); //pause the console
    return 0;
}

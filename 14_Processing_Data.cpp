#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

float digit[10] ;
int upRun = 0;
int downRun = 0;

string getTxt()
{
    string txt,line = "";
    fstream myfile("pi.txt"); // open text file
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,line); // read line out of file
            for(int i=0; i<line.size(); i++)
            {
                if((line[i]>='0') && (line[i]<= '9')) //check for digit
                    txt += line[i];
            }
        }
        myfile.close();
    }
    else cout<< "\nUnable to open file";
    return txt;
}

float getAve(string pi)
{
    float num = 0;
    for(int i=0; i<pi.size(); i++)
    {
        num += pi[i] -48;
    }
    return num/pi.size();
}

void frequency(string pi)
{
    for(int i=0; i<pi.size(); i++)
    {
        digit[pi[i]-48] += 1;
    }
}

int Consecutive(string pi)
{
    for(int i=0; i < pi.size()-2; i++)
    {
        if(pi[i+2] - pi[i+1] == 1)
        {
            if(pi[i+1] - pi[i] == 1)
                upRun ++;
        }
        else
        {
            if(pi[i]-pi[i+1] == 1)
            {
                if(pi[i+1] - pi[i+2] == 1)
                    downRun++;
            }
        }
    }
}

int main()
{
    string piString = getTxt(); //get pi digit from file
    float avePi = getAve(piString);   //calculate average from the file.
    frequency(piString);
    Consecutive(piString);
    cout<<"Digits of PI found in pi.txt = " <<piString.size()<<"\n\n";
    for(int i=0; i < 1000; i++)
    {
        cout<<piString[i];
        if((i+1)%100 == 0)
            cout<<endl;

    }
    cout<<"\n\nAverage of 100000 digits of PI is " << avePi<<"\n\n";

    for(int i=0; i < 10; i++)
            cout<<"Frequency of "<<i<<"'s is "<< digit[i]/piString.size() * 100<<"%\n";

    cout<<"\nUp-Run: "<< upRun<<" times\n";
    cout<<"\nDown-Run: "<< downRun<<" times\n";
    system("pause");
    return 0;
}

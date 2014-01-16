#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

void makeTxt()
{
    ofstream myFile ("assign13_random.txt");
    for(int i=0; i<2000; i++)
    {
        int r = (rand()%(127-33))+ 33;
        myFile <<char(r);//<<endl;
    }
    myFile.close();
}

string readtxt()
{
    string temp;
    string re = "";
    ifstream myFile("assign13_random.txt");
    if(myFile.is_open())
    {
        while(!myFile.eof())
        {
            getline (myFile,temp);
            re += temp;
        }
    }
    else cout<<"Unable to open file"<<endl;

    myFile.close();

    return re;
}

string sorttxt(string txt)
{
        string text = txt;
    for(int i = 0; i < text.length()-1; i ++)
    {
        for(int a=0; a < text.length()-(1+i); a++)
        {
           // string temp = text [a];
            if(text[a] > text [a+1])
            {
                char temp = text[a];
                text[a] = text[a+1];
                text[a+1] = temp;
            }
        }
    }
    ofstream myFile("assign13_sorted.txt");
    myFile<<text;
    myFile.close();
    return text;
}

void Count(string txt)
{
    int upperCase = 0;
    int lowerCase = 0;
    int digit = 0;
    for(int i = 0; i < txt.length(); i ++)
    {
        if(txt[i]>47 && txt[i]<58)
            digit++;
        else{
            if(txt[i]>96 && txt[i]<123)
                lowerCase++;
            else{
                if(txt[i]>64 && txt[i]<91)
                    upperCase++;
            }
        }
    }
    cout<<"Upper case letters: "<<upperCase<<"\nLower case letters: "<<lowerCase<<"\nDigit: "<< digit<<endl;
}

int main()
{
    string line;
    srand(time(NULL));
    makeTxt();
    line = readtxt();
    line = sorttxt(line);
    Count(line);
  //  cout<<line<<end;
    system("pause");
    return 0;
}

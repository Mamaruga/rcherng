#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string randomize ( string array)
{
    int r;
    char temp;
    int k;
    int length = array.size()-1;

    k =1;
    while(!(k > length))
    {
        r= rand()%length +1;
        temp = array[k];
        array[k] = array[r];
        array[r] = temp;
        k = k+1;
    }
    return(array);
}

string sort(string array)
{
    char temp;
    int k;
    int j;
    int length = array.size()-1;

    j = 1;
    while (!(j>length-1))
    {
        k = j+1;
        while(!(k>length))
        {
            if(array[j] > array[k])
            {
                temp = array[k];
                array[k] = array[j];
                array[j] = temp;
            }
            else
            {

            }
            k = k +1;
        }
        j = j +1;
    }
    return (array);
}

int main()
{
    string str;
    int i;

    i =0;
    str = "#123456789";
    cout << "String " <<i<<" ="
         <<str << endl;
    i = i+1;
    while(!(i>10))
    {
        str = randomize(str);
        cout<< "Randomized string"
            <<i<<" = "<< str <<endl;
        str = sort(str);
        cout<< "    Sorted string"
            << i << " = " << str << endl;
        cout<<endl;
        i = i+1;
    }
    system("pause");
    return 0;
}

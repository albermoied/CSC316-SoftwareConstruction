#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    ifstream myfile;
    myfile.open("input.txt");
    ofstream output;
    output.open("output.txt");
    string token;
    while(!myfile.eof())
    {
        myfile>>token;
        if(token=="/*")
        {
            while(token!="*/")
            {
                myfile>>token;
            }
            myfile>>token;
        }
        if(token!="*/")
        {
            output<<token<<endl;
            cout<<token<<endl;
        }

    }
    output.close();
    getch();
    return 0;
}

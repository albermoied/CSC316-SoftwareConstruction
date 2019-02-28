#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

int main()
{
    string line;
    ifstream input;
    input.open("input.txt");
    getline(input,line);
    ofstream myfile("output.txt");
    for(int i=0; line[i]!=NULL; i++)
    {
        myfile<<line[i];
        cout<<line[i];
        if(line[i]==' ')
        {
            myfile<<endl;
            cout<<endl;
        }
    }
    myfile.close();
    getch();
    return 0;
}

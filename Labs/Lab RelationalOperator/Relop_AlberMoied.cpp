#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<string>

using namespace std;

class Tokenizer
{
    private:
            char* buffer;
            int track;
    public:
        Tokenizer()
        {
            buffer= new char[100];
            track =0;
        }
        int readInputFile(string fileName)
            {
                ifstream input(fileName.c_str());
                    int i=0;
                    if(input.is_open())
                        {
                            while(!input.eof())
                            {
                                input.read(&buffer[i],1);
                                i++;
                            }
                        }
                        buffer[i-1] = '\0';
                        input.close();
                        return 0;

            }

        void getNextToken(char* token)
            {
                int i = 0;
                while(buffer[track] == '\n' || buffer[track] == '\t' || buffer[track] == ' ')
                    {
                        track++;
                    }
                    while(buffer[track]!='\0')
                        {
                            if(buffer[track] != '\n' && buffer[track] != '\t' && buffer[track] != ' ')
                            {
                                token[i] = buffer[track];
                            }

                            else
                            {
                                token[i] = '\0';
                            return;
                            }
                            i++;
                            buffer++;
                        }
                    token[i]='\0';
                    return;

            }
            void getNextOp(char* token)
            {
                int c=0;
                ofstream file("Output.txt");
                while(buffer[track]!='\0')
                    {
                        switch(c)
                        {
                            case 0:
                                if(buffer[track]=='<')
                                {c=1;}
                                else if(buffer[track]=='=')
                                {c=2;}
                                else if(buffer[track]=='>')
                                {c=3;}
                                break;
                                case 1:
                                    if(buffer[track]=='=')
                                        {
                                            file.write("<= relop LE\n" , 12);
                                        }
                                    else if(buffer[track]=='>')
                                        {
                                            file.write("<> relop NE\n" , 12);
                                        }
                                    else
                                        {
                                            file.write("< relop LT\n" , 11);
                                            buffer--;
                                        }
                                    c=0;
                                    break;
                                case 2:
                                    file.write("= relop EQ\n" , 11);
                                    buffer--;
                                    c=0;
                                    break;
                                case 3:
                                    if(buffer[track]=='=')
                                        {
                                            file.write(">= relop GE\n" , 12);
                                        }
                                    else
                                        {
                                            file.write("> relop GT\n" , 11);
                                            buffer--;
                                        }
                                    c=0;
                                    break;
                        }
                        buffer++;
                    }
            }
};
int main()
{
    ofstream myfile("output.txt");
    char* token;
    token = new char[20];
    Tokenizer myTokenizer;
    myTokenizer.readInputFile("input.txt");
    myTokenizer.getNextOp(token);
    myfile.close();
    getch();
    return 0;
}


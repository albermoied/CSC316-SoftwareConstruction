#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;
class Token
{
	public:
		Token(void);
		//~Token(void);
		string lexeme;
		string token;
		string attribute;
		Token(string lexeme, string token, string attribute);
};
Token::Token(void)
{
}
/*Token::~Token(void)
{
}*/
Token::Token(string my_lexeme, string my_token, string my_attribute)
{
	lexeme = my_lexeme;
	token = my_token;
	attribute = my_attribute;
}
class Tokenizer
{
	public:
		//Tokenizer(void);
		//~Tokenizer(void);
		int initialize(string infile);
		Token getNextToken(void);
	private:
		char* buffer;
		int start_lex;
		int end_lex;
		int current_state;
		char getNextChar(void);
		int line_no;

		string extractLexeme(void);
		void retract(void);
		void adjustStartLex(void);
		void fail(void);
};
int Tokenizer::initialize(string infile)
{
	//initialize lexeme pointers
	start_lex = 0;
	end_lex = 0;
	current_state = 0;
	//assuming that the buffer is large enough to hold the entire input
	buffer = new char[200];
	int bytes_read;
	ifstream input(infile.c_str());
	input.read(buffer, 200);
	bytes_read = input.gcount();
	buffer[bytes_read] = '\0';
	line_no = 1;
	return 0;
}
char Tokenizer::getNextChar(void)

{
	//return and advance trackingpointer
	return buffer[end_lex++];
}
Token Tokenizer::getNextToken(void)
{
	//[2-7][b-d][b-d]*[2-7]*
	char c;
	Token *token;
	while (buffer[start_lex] != '\0')
	{
		switch(current_state)
		{
		case 0:
			c = getNextChar();
			if(c >= '2' && c <= '7')
			current_state = 1;
			else
			{
				current_state = 0;
				adjustStartLex();
			}
			break;
		case 1:
	 		c = getNextChar();
			if(c >= 'b' && c <= 'd')
			current_state = 2;
			else
			{
				retract();
				current_state = 0;
				adjustStartLex();
			}
			break;
		case 2:
			c = getNextChar();
			if(c >= 'b' && c <= 'd')
			current_state = 2;
			else if (c >= '2' && c <= '7')
			current_state = 3;
			else
			{
				//return lexeme and retract
				retract();
				token = new Token(extractLexeme(), "","");
			return *token;
			}
			break;
		case 3:
			c = getNextChar();
			if(c >= '2' && c <= '7')
			current_state = 3;
			else
			{
				//return lexeme and retract
				retract();
				token = new Token(extractLexeme(), "", "");
				return *token;
			}
			break;
			}
		}
			token = new Token("","","");
			return *token;
}
string Tokenizer::extractLexeme(void)
{
	string my_token = "";
	for(int i = start_lex; i<end_lex;i++)
	{
		if(buffer[i] != '\0')
			my_token += buffer[i];
	}
	start_lex = end_lex;
	current_state = 0;
	return my_token;
}
void Tokenizer::retract(void)
{
	end_lex--;
}
void Tokenizer::adjustStartLex(void)
{
	start_lex = end_lex;
}
int main()
{
     ofstream myfile("output.txt");
     char* token;
     token = new char[20];
     Tokenizer myTokenizer;
     //myTokenizer.readInputFile("Input.txt");
     myTokenizer.initialize("Input.txt");
     myTokenizer.getNextToken();
     myTokenizer.getNextToken(token);
     while(token[0]!=0)
     {
               myfile.write((char*)token, strlen(token));
               if(!myfile)
               cout<<"Write failed"<<endl;
               myfile.write("\n",1);
               if(!myfile)
               cout<<"Write failed"<<endl;
               myTokenizer.getNextToken(token);
                   }*/
                   myfile.close();
                   getch();
                   return 0;
}

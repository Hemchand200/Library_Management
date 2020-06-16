#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
#include<conio.h>
#include <cstdlib>
using namespace std;
#define el "\n"
#define sp " "

int res_book(int,int);
/*Class of books*/
class book
{
	protected:
	int bno,quant;						//book no 
	char bname[50]; 				//book name
	char aname[50]; 				//book author's name
	char pname[50];  				//publication name
	public:
		void createb();
		void showb();
		void showlist();
		void assignbno(int x)       //bno assigned on the basis of no
		{						    //no. of objects in file
			bno=10001;
			bno+=x-1;
			start1:
				bno+=1;
				if(res_book(bno,0))
				goto start1;
		}
		void set_q()
		{
			quant-=1;
		}
		int quantity()
		{
			return quant;
		}
		void reset_q()
		{
			quant+=1;
		}
		int retbno()
		{
			return bno;
		} 
};
/*End of class book*/

/*Class of Students*/
class student
{
	protected:
		char name[25];					//Student name
		int bno;						//Book no. of book issued
		int token;						//To veirfy book issued or not
	public:
		void creates();
		void shows();
		void showlist();
		void settoken(int x)			//To set token and assign bno a book no
		{
			bno=x;
			token=1;
		}
		void resettoken()				//To reset token
		{
			bno=0;
			token=0;
		}
		int retbno()
		{
			return bno;
		}
		int admno;						//Admission No
};
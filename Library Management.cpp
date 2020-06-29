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
/*End of class Students*/

bool res_student(int);					//To check whether the admission no. already exist or not
void student::creates()                //To enter values to all data members of class student
{
	int i;
	plane:
	system("CLS");
	cout<<"\n\t\tEnter the details:-\n";
	cout<<"\n\t\tEnter student's Admission no: ";
	cin>>admno;
	if(res_student(admno))
	{
		cout<<"\n\t\tRecord already exist with this admission no.";
		cout<<"\n\t\tEnter a different admission no.\n";
		system("PAUSE");
		goto plane;
	}
	cout<<"\n\t\tEnter student's Name: ";
	char n[50];
	cin.getline(n,50);
	cin.getline(name,25);
	for(i=0;name[i]!='\0';i++)
	{
		if(name[i]>='a'&&name[i]<='z')
		name[i]-=32;
	}
	bno=0;
	token=0;
}


void student::shows()                                     //Show details of Students
{
	cout<<"\n\t\tStudent's Admission No.: "<<admno<<el;
	cout<<"\n\t\tStudent's Name: "<<name<<el;
	if(token==1)
	{
		cout<<"\n\t\tBook Issued (Book no): "<<bno;
	}
}


void student::showlist()                                  // To display Student details in list form
{
	cout<<"\n\t"<<admno<<"\t\t"<<name<<"\t\t"<<bno;
}


/*To Write object of class book in file*/
void write_book()
{
	book bk;
	ofstream outf("book1.bin",ios::app|ios::binary);
	outf.seekp(0,ios::end);
	int x=outf.tellp()/sizeof(book);
	bk.assignbno(x);
	bk.createb();
	bk.showb();
	outf.write(reinterpret_cast<char *>(&bk),sizeof(book));
	cout<<"\n\t\tRecord added successfully";
	outf.close();
}


/*To Write object of class student in file*/
void write_student()
{
	student st;
	ofstream outf("student.bin",ios::app|ios::binary);
	outf.seekp(0,ios::end);
	st.creates();
	st.shows();
	outf.write(reinterpret_cast<char *>(&st),sizeof(student));
	cout<<"\n\t\tRecord added successfully";
	outf.close();
}

/*To display Student records in list form*/
void list_student()
{
	system("CLS");
	student st;
	ifstream intf("student.bin",ios::in|ios::binary);
	intf.seekg(0,ios::beg);
	if(!intf)
	cout<<"\n\t\tFile not found";
	else
	{
		cout<<"\n\t*****Students Details*****\n\n";
		cout<<"\n\tAdmission No:\tName: \tBook Issued:";
		while(intf.read(reinterpret_cast<char *>(&st),sizeof(student)))
		st.showlist();
	}
	intf.close();
}



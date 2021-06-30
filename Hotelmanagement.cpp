/*
HOTEL MANAGEMENT system
Name of Hotel : Oive Cliff Resorts
*/

//NOTE: THIS RUNS ON LINUX
//FOR RUNNING ON WINDOWS TYPE "cls" INSTEAD OF "clear" IN system("clear")
// Created by Ayush kumar

#include<iostream>

#include<fstream>

#include<vector>

#include<string.h>

using namespace std;

void SetCursorPos(int XPos, int YPos)
{
 printf("\033[%d;%dH", YPos+1, XPos+1);
}

class employee
{int empid;
char name[20],post[20];
float basic;
public :

employee() {
	empid=-1;
	basic=0;
}

void getdata()
{cout<<"Enter the name of employee"<<'\n';
cin>>name;
cout<<"Enter employee id"<<'\n';
cin>>empid;
cout<<"Enter the post"<<'\n';
cin>>post;
cout<<"Enter the salary"<<'\n';
cin>>basic;
}

void showdata()
{
cout<<"ID:"<<empid<<'\n';
cout<<"Name:"<<name<<'\n';
cout<<"Post:"<<post<<'\n';
cout<<"Salary:"<<basic<<'\n';
}

void changebasic()
{
cout<<"Enter the new salary"<<'\n';
cin>>basic;
}
int get_id()  {return empid;}
};

void input()
{
ofstream mf ("employee.dat",ios::binary);
if (!mf)
	{cout<<"Error";
	 
	 exit(0);
		}
char cont;
employee emp;
do     {emp.getdata();
mf.write((char*)&emp,sizeof(emp));
cout<<"Continue writing into file?"<<'\n';
cin>>cont; }  while (cont=='y' || cont=='Y');
mf.close();
}

void showallemp()
{
ifstream mf ("employee.dat",ios::binary);
if (!mf)
	{cout<<"Error";
	 
	 exit(0);
		}
employee emp;
mf.read((char*)&emp,sizeof(emp));
while (mf)
	{emp.showdata();
	 mf.read((char*)&emp,sizeof(emp));
		}
mf.close();
}


void searchemp()
{
int n,f=0;
ifstream mf ("employee.dat",ios::binary);
if (!mf)
	{cout<<"Error"<<'\n';
	 
	 exit(0);
		}
cout<<"Enter the employee id"<<'\n';
cin>>n;
employee emp;
mf.read((char*)&emp,sizeof(emp));
while (mf && f==0)
	{if (n==emp.get_id())
		{f=1;
		 emp.showdata();
			}
	 mf.read((char*)&emp,sizeof(emp));
		}
if (f==0) cout<<"Record not found"<<'\n';
mf.close();
}


void deleteemp()
{
ifstream mf("employee.dat",ios::binary);
ofstream nf("temp.dat",ios::binary);
if (!(mf||nf))
	{cout<<"Error"<<'\n';
	 
	 exit(0);


		}
employee emp;
int num;
cout<<"Enter the employee id to be deleted"<<'\n';
cin>>num;
int f=0;
mf.read((char*)&emp,sizeof(emp));
while (mf && f==0)
	{if (emp.get_id()!=num)
		{nf.write((char*)&emp,sizeof(emp));
		 f=1;}
	mf.read((char*)&emp,sizeof(emp));
		}
if (f==0) cout<<"NOT FOUND";
else cout<<"Deleted successfully"<<'\n';
mf.close();
nf.close();
remove("employee.dat");
rename("temp.dat","employee.dat");
}


void modifyemp()     //Modifies salary of employee
{
fstream mf;
mf.open("employee.dat",ios::binary | ios::in | ios::out);
if (!mf)
	{cout<<"Error"<<'\n';
	 
	 exit(0);
		}
int num,f=0;
employee emp;
cout<<"Enter the id of the employee"<<'\n';
cin>>num;
while (mf && f==0)
	{if (emp.get_id()==num)
		{f=1;
		 emp.changebasic();
		 long pos=mf.tellg();
		 pos-=sizeof(emp);
		 mf.seekg(pos,ios::beg);
		 mf.write((char*)&emp,sizeof(emp));
			}
	 mf.read((char*)&emp,sizeof(emp));
		}
if (f==0) cout<<"Record not found"<<'\n';
mf.close();
}


struct date
{int d,m,y;};
void showdate(date dt)
	{cout<<dt.d<<'/'<<dt.m<<'/'<<dt.y<<'\n';}


class customer
{int roomno;
date doin,doout;
char name[20],id[10],phno[13],from[20];
public:

void input(int x)
	{roomno=x;
	 cout<<"Enter Name"<<'\n';
	 cin>>name;
	 cout<<"Date of check-in"<<'\n';
	 cin>>doin.d>>doin.m>>doin.y;
	 cout<<"Date of check-out"<<'\n';
	 cin>>doout.d>>doout.m>>doout.y;
	 cout<<"Enter ID"<<'\n';
	 cin>>id;
	 cout<<"Enter phone number"<<'\n';
	 cin>>phno;
	 cout<<"Where have you come from?"<<'\n';
	 cin>>from;
		}

void showdetails()
	{cout<<"Name:"<<name<<'\n';
	 cout<<"Check-in:";showdate(doin);cout<<'\n';
	 cout<<"Check-out:";showdate(doout);cout<<'\n';
	 cout<<"Phone number:"<<phno<<'\n';
	 cout<<"From:"<<from<<'\n';
		}

int R_rno()  {return roomno;}
date outdate() {return doout;}
};


class room
{
int status,days,meals,people;
char description[100],type;
float rate,gt,mealrate;

void calc()
	{if (type=='A') rate=20000;
	 else if (type=='B') rate=15000;
	 else if (type=='C') rate=10000;
	 else if (type=='D') rate=5000;
	 else rate=0;
		}

void grandtotal()
	{gt=rate*days;
	 gt+=mealrate*days*people;		}

protected:
	int rno;

public :

room ()
	{rno=0;
	status=0;
	days=0;
	strcpy(description," ");
	type='Z';
	rate=0;
	gt=0; }

void newroom()
	{room();
	 cout<<"Enter room number "<<'\n';
	 cin>>rno;
	 cout<<"Enter the room desription "<<'\n';
	 cin>>description;
	 cout<<"Enter the room type "<<'\n';
	 cin>>type;
	 calc();
		}

void getdata()
{if (status==0)
	 {status=1;   int op;
	 cout<<"Enter the number of days of stay"<<'\n';
	 cin>>days;
	 cout<<"Enter the number of people"<<'\n';
	 cin>>people;
	 cout<<"Choose :-"<<'\n';
	 cout<<"0...No meals included"<<'\n';
	 cout<<"1...Breakfast, Lunch, Dinner"<<'\n';
	 cout<<"2...Breakfast and Dinner"<<'\n';
	 cout<<"3...Only a single meal"<<'\n';
	 cin>>op;
	       switch(op)
		{case 0:mealrate=0; break;
		 case 1:mealrate=1500;break;
		 case 2:mealrate=1000;break;
		 case 3:mealrate=500;break;
		 default : cout<<"Inappropriate choice"<<'\n';
			}
	 grandtotal();
	 }
else cout<<"Room is already booked"<<'\n';
}

void showdata()
	{cout<<"Your room details :-"<<'\n';
	 cout<<"Room no:"<<rno<<'\n';
	 cout<<"Room type:"<<type<<'\n';
	 cout<<"Room description:"<<description<<'\n';
	 if (status==1) cout<<"Status :BOOKED"<<'\n';
	 else cout<<"Status : VACANT"<<'\n';

		}

void checkout()
	{system("clear");
	 SetCursorPos(36,1);
	 cout<<"BILL";
	 SetCursorPos(36,2);
	 cout<<"****";
	 SetCursorPos(18,5);
	 cout<<"Room no:            :"<<rno;
	 SetCursorPos(18,7);
	 cout<<"No. of people       :"<<people;
	 SetCursorPos(18,9);
	 cout<<"No. of days of stay :"<<days;
	 SetCursorPos(18,11);
	 cout<<"Cost of stay per day:"<<rate;
	 SetCursorPos(18,13);
	 cout<<"Subtotal            :"<<rate*days;
	 SetCursorPos(18,15);
	 cout<<"Cost of meal per day:"<<mealrate;
	 SetCursorPos(18,17);
	 cout<<"Sub total           :"<<mealrate*days;
	 SetCursorPos(1,19);
	 for (int line=1;line<=80;line++)
	 cout<<'_';
	 SetCursorPos(1,21);
	 cout<<"Your total amount to be paid"<<gt<<'\n';
	 cout<<"Thank you for visiting !!!!!"<<'\n';
	 cout<<"Hope you enjoyed your stay with us";
	 char ch=2;      //Prints smile emoticon
	 cout<<ch<<ch<<ch<<'\n';
	 status=0;
	 days=0;
	 gt=0;

		}

void changedesc()
{
cout<<"Enter the new description"<<'\n';
cin>>description;
}
int get_rno() {return rno;}
float get_meal() {return mealrate;}
int get_status() {return status;}
float get_total() {return gt;}
};

class food {
int ID;
char name[20];
float price; 
public:
	food() {
		ID=-1;
	}
	void getdata() {
		cout<<"Enter the unique ID \n";
		cin>>ID;
		cout<<"Enter name of the dish \n";
		cin>>name;
		cout<<"Enter the price of dish \n";
		cin>>price;
	}
	void showdata() {
		cout<<name<<"     :     "<<price<<endl;
	}
	void get_name() {
		cout<<name;
	}
	float getPrice() {
		return price;
	}
	int get_id() {
		return ID;
	}
};


void initialise()
	{ofstream mf;
	 mf.open("rooms.dat",ios::binary);
	 if (!mf)
		{cout<<"Due to an unknown error, the program has terminated";
		 
		 exit(0);}
	 room r;
	 char cont;
	 do {r.newroom();
	     mf.write((char*)&r,sizeof(r));
	     cout<<"Continue?"<<'\n';
	     cin>>cont;
		} while (cont=='y' || cont=='Y');
	 mf.close();
		  }

void addroom()
	{ofstream mf;
	 mf.open("rooms.dat",ios::binary|ios::app);
	 if (!mf)
		{cout<<"Due to an unknown error, the program has terminated";
		 
		 exit(0);}
	 room r;
	 r.newroom();
	     mf.write((char*)&r,sizeof(r));
	 mf.close();
		  }


void showallrooms()
{
ifstream mf("rooms.dat",ios::binary);
if (!mf)
	{cout<<"Due to an unknown error, the program has terminated";
	 
	 exit(0);}
room r;
mf.read((char*)&r,sizeof(r));
while (mf)
	{r.showdata();
	
	mf.read((char*)&r,sizeof(r));
		}
mf.close();
				}


int searchroom(int num)    //shows details of a given room no.
{                          //Returns 0 if booked
ifstream mf;
mf.open("rooms.dat",ios::binary);
if (!mf)
	{cout<<"Error!";
	 
	 exit(0);
		}
int stat=-1;  //to store status
room r;
int f=0;
mf.read((char*)&r,sizeof(r));
while (mf && f==0)
	{if (r.get_rno()==num)
		{r.showdata();
		 stat=r.get_status();
		 f=1;
		     }
	     mf.read((char*)&r,sizeof(r));
		}
mf.close();
if (f==0) cout<<"Room not found"<<'\n';
return stat;
}


void searchbyrno(int num)
{
ifstream mf;
mf.open("customer.dat",ios::binary);
if (!mf)
	{cout<<"Error!";
	
	exit(0);
		}
customer c;
int f=0;
mf.read((char*)&c,sizeof(c));
while (mf && f==0)
	{if (num==c.R_rno())
		{c.showdetails();
		 f=1;
			}
	 mf.read((char*)&c,sizeof(c));
		}
if (f==0) cout<<"Record does not exist"<<'\n';
mf.close();
}


void checkin()
{
fstream mf;
ofstream nf;
int num,stat;
char ans;
mf.open("rooms.dat",ios::binary|ios::in|ios::out);
nf.open("customer.dat",ios::binary|ios::app);
if (!(mf||nf)) 	{cout<<"Error!";
		 
		 exit(0);
			}
cout<<"Enter the room number to be booked"<<'\n';
cin>>num;
stat=searchroom(num);
if (stat==0)
{cout<<"Are you sure you want to book this room?"<<'\n';
cin>>ans;
if (ans=='y'||ans=='Y')
	{room r;
	 customer c;
	 int f=0;
	 mf.read((char*)&r,sizeof(r));
	 while (mf && f==0)
		{if (r.get_rno()==num)
			{r.getdata();
			 c.input(num);
			 long pos=mf.tellg();
			 pos-=sizeof(r);
			 mf.seekg(pos,ios::beg);
			 mf.write((char*)&r,sizeof(r));
			 nf.write((char*)&c,sizeof(c));
			 cout<<"Room booked successfully"<<'\n';
			 char emoji=2;
			 cout<<emoji<<emoji<<emoji<<'\n';
			 cout<<"Estimated total :"<<r.get_total();
			 f=1;
				}
		 mf.read((char*)&r,sizeof(r));
				}

		}
	}
else if (stat==1) {cout<<"Room already booked"<<'\n';}
else cout<<"Room not found"<<'\n';
nf.close();
mf.close();
}


void checkout() //Modifies rooms.dat
{               //Deletes customer record
fstream mf("rooms.dat",ios::binary|ios::in|ios::out);
ifstream nf("customer.dat",ios::binary);
ofstream temp("temp.dat",ios::binary);
int num;
cout<<"Enter your room number"<<'\n';
customer c;
room r;
int f=0;
cin>>num;
mf.read((char*)&r,sizeof(r));
while (mf && f==0)
	{if (r.get_rno()==num)
	    { if (r.get_status()==1)	{r.checkout();
					 f=1;
					 long pos=mf.tellg();
					 pos-=sizeof(r);
					 mf.seekg(pos,ios::beg);
					 mf.write((char*)&r,sizeof(r));
						}
	      else cout<<"Room not yet booked!!!"<<'\n';  }
	  mf.read((char*)&r,sizeof(r));
				}
nf.read((char*)&c,sizeof(c));
while (nf)
	{if (c.R_rno()!=num)
		temp.write((char*)&c,sizeof(c));
	 nf.read((char*)&c,sizeof(c));
		}
mf.close();
nf.close();
temp.close();
remove("customer.dat");
rename("temp.dat","customer.dat");
}


void checkouttoday()
{
date today;
cout<<"Enter today's date"<<'\n';
cin>>today.d>>today.m>>today.y;
ifstream mf;
mf.open("customer.dat",ios::binary);
if (!mf)
	{cout<<"ERROR"<<'\n';
	
	exit(0);}
customer r;
mf.read((char*)&r,sizeof(r));
date ch_out;
ch_out=r.outdate();
cout<<"The guests which need to check out today"<<'\n';
while (mf)
	{if (ch_out.d==today.d && ch_out.m==today.m && ch_out.y==today.y)
	       {r.showdetails();
		   }
	 mf.read((char*)&r,sizeof(r));
	 ch_out=r.outdate();
				}
mf.close();
}


void modify()     //Modifies description of a room
{
fstream mf;
mf.open("rooms.dat",ios::binary | ios::in | ios::out);
if (!mf)
	{cout<<"Error";
	
	exit (0);}
int rno,f=0;
cout<<"Enter the room number "<<'\n';
cin>>rno;
room r;
mf.read((char*)&r,sizeof(r));
while (mf && f==0)
	{if (rno==r.get_rno())
		{f=1;
		 r.changedesc();
		 long pos=mf.tellg();
		 pos-=sizeof(r);
		 mf.seekg(pos,ios::beg);
		 mf.write((char*)&r,sizeof(r));
			}
	 mf.read((char*)&r,sizeof(r));
		}
if (f==0) cout<<"Room not found"<<'\n';
else cout<<"Updated successfully"<<'\n';
mf.close();
}

void CreateMenu() {
	ofstream mf;
	mf.open("menu.dat", ios::binary|ios::app);
	if (!mf)
		{cout<<"Due to an unknown error, the program has terminated";
		 
		 exit(0);}
	char cont;
	food f;
	do {
		f.getdata();
		mf.write((char*)&f, sizeof(f));
		cout<<"Add more food items? \n";
		cin>>cont;
	} while(cont=='Y' || cont=='y');
	mf.close();
}

void PrintMenu() {
	ifstream mf;
	mf.open("menu.dat", ios::binary);
	if (!mf) {
		cout<<"Unknown Error";
		exit(0);
	}
	food f;
	cout<<"         MENU        "<<endl<<endl<<endl;
	while (mf) {
		mf.read((char*)&f, sizeof(f));
		f.showdata();
		cout<<endl;
	}
	mf.close();
}

void RemoveDish() {
	ifstream mf;
	ofstream nf;
	mf.open("menu.dat", ios::binary);
	nf.open("temp.dat", ios::binary);
	if (!(mf&&nf)) {
		cout<<"Unknow error";
		exit(0);
	}
	food f;
	int num;
	cout<<"Enter the ID of the dish to be removed \n";
	cin>>num;
	while (mf) {
		mf.read((char*)&f, sizeof(f));
		if (f.get_id()!=num) {
			nf.write((char*)&f,sizeof(f));
		}
	}
	mf.close();
	nf.close();
	remove("menu.dat");
	rename("temp.dat", "menu.dat");
}

food get_price_of_dish() {
	ifstream mf;
	mf.open("menu.dat", ios::binary);
	if (!mf) {
		cout<<"Error";
		exit(0);
	}
	food f;
	int num;
	cout<<"Enter the dish ID you want to order \n";
	cin>>num;

	int flag=0;

	while (mf && flag==0) {
		mf.read((char*)&f, sizeof(f));
		if (f.get_id()==num) {
			return f;
		}
	}
	if (flag==0) {
		return f; //Default ID in constructor is -1
	}
	mf.close();
}

float get_meal_rate(int num) {
	ifstream mf;
mf.open("rooms.dat",ios::binary);
if (!mf)
	{cout<<"Error!";
	 
	 exit(0);
		}
int m_rate=-1; 
room r;
int f=0;
mf.read((char*)&r,sizeof(r));
while (mf && f==0)
	{if (r.get_rno()==num)
		{
		 m_rate=r.get_meal();
		 f=1;
		     }
	     mf.read((char*)&r,sizeof(r));
		}
mf.close();
if (f==0) cout<<"Room not found"<<'\n';
return m_rate;
}

class order: private room {

pair<food,int> p[10]; //Pair of food items with their quantity
int n; //Size of array of dishes

public:
	order() {
		n=0;
	}

	void getdata () {
		char cont;
		int qty;
		cout<<"Enter your room number please \n";
		cin>>rno;
		do {
			food f=get_price_of_dish();
			if(f.get_id()!=-1) {
				cout<<"Enter quantity \n";
				cin>>qty;
				if (n<=9) {
					p[n]=make_pair(f,qty);
					n++;
				}
				else {
					cout<<"Maximum order limit reached";
					return;
				}
			}
			else {
				cout<<"Dish not found \n";
			}
			cout<<"Eat more? \n";
			cin>>cont;
		}while(cont=='y' || cont=='Y');		
	}

	float showbill() {
		float gt=0;
		if (n==0) {
			cout<<"No order placed \n";
			return 0;
		}
		cout<<"ROOM NUMBER : "<<rno<<endl;
		float mr=get_meal_rate(rno);
		int x= (int)mr;
		switch (x) {
			case -1: cout<<"\n Invalid room number \n"; break;

			case 0: cout<<"No meals include in your package \n";

						break;
			
			case 500: cout<<"Your meal package : Only breakfast \n";
						
						break;

			case 1000: cout<<"Your meal package : Breakfast and Dinner \n";
						
						break;

			case 1500: cout<<"Your meal package : Breakfast, Lunch and Dinner \n";

						break;

			default : cout<<"ERROR!!! ROOM NOT OCCUPIED \n";
		}
		cout<<"FOOD        COST        QTY        AMOUNT"<<endl;
		for (int i=0;i<=n-1;i++) {
			float amt=p[i].first.getPrice()* p[i].second;
			gt+=amt;
			p[i].first.get_name();
			cout<<"    "<<p[i].first.getPrice()<<"        "<<p[i].second<<"       "<<amt<<endl;
		}
		return gt;
	}

};


void TakeOrder(vector<order> &v) {
	order o;
	system("clear");
	cout<<"        WELCOME  \n";
	o.getdata();
	v.insert(v.begin(),o);
}

void Ready(vector<order> &v) {
	order o;
	system("clear");
	o=v.back();
	float bill=o.showbill();
	cout<<"Amount payable : Rs."<<bill<<endl;
	cout<<"Enjoy your meal ! \n";
	v.pop_back();
}

void managermode()
{int op;
char cont;
do  {system("clear");
SetCursorPos(1,5);
for (int dec=1; dec<=80; dec++)
cout<<'_';
SetCursorPos(36,6);
cout<<"Employees :-"<<'\n';
SetCursorPos(24,7);
cout<<"1...Enter the list of employees"<<'\n';
SetCursorPos(24,8);
cout<<"2...Show details of all employees"<<'\n';
SetCursorPos(24,9);
cout<<"3...Search for a given employee"<<'\n';
SetCursorPos(24,10);
cout<<"4...Delete a particular record"<<'\n';
SetCursorPos(24,11);
cout<<"5...Modify basic of an employee"<<'\n';
SetCursorPos(1,12);
for (int dec=1; dec<=80; dec++)
cout<<'_';
SetCursorPos(36,13);
cout<<"New Rooms:-"<<'\n';
SetCursorPos(24,14);
cout<<"6...Make a new list of rooms"<<'\n';
SetCursorPos(24,15);
cout<<"7...Add a new room to the hotel"<<'\n';
cin>>op;
switch (op)
{
case 1:input();  break;
case 2:showallemp();break;
case 3:searchemp();break;
case 4:deleteemp();break;
case 5:modifyemp();break;
case 6:initialise(); break;
case 7:addroom(); break;
default:cout<<"Wrong choice"<<'\n';
}
cout<<"Continue?"<<'\n';
cin>>cont; }  while (cont=='y' || cont=='Y');

}


void receptionmode()
{int op;
char cont;
do {  system("clear");
SetCursorPos(1,5);
for (int dec=1; dec<=80; dec++)
cout<<'_';
SetCursorPos(36,6);
cout<<"RECEPTION :-";
SetCursorPos(36,7);
cout<<"************";
SetCursorPos(24,8);
cout<<"1...See details of all rooms";
SetCursorPos(24,9);
cout<<"2...Check in ";
SetCursorPos(24,10);
cout<<"3...Check out";
SetCursorPos(24,11);
cout<<"4...See details of a particular room";
SetCursorPos(24,12);
cout<<"5...Search a guest";
SetCursorPos(24,13);
cout<<"6...Print details of guests who have to check out today";
SetCursorPos(24,14);
cout<<"7...Modify the description of a room";
SetCursorPos(1,15);
for (int dec=1; dec<=80; dec++)
cout<<'_';
cin>>op;
switch(op)
{
case 1:showallrooms(); break;
case 2:checkin(); break;
case 3:checkout(); break;
case 4:int rno,temp;
cout<<"Enter the room number to be searched"<<'\n';
cin>>rno;
temp=searchroom(rno); break;
case 5:int r;
cout<<"Enter the room number of the guest"<<'\n';
cin>>r;
searchbyrno(r); break;
case 6: checkouttoday();   break;
case 7: modify();    break;
default :cout<<"Wrong choice"<<'\n';
}
cout<<"Continue?"<<'\n';
cin>>cont; } while (cont=='y' || cont=='Y');

}


void foodcourt()
{
vector<order> q;
int op;
char cont;
do  {system("clear");
SetCursorPos(1,5);
for (int dec=1; dec<=80; dec++)
cout<<'_';
SetCursorPos(36,6);
cout<<"Food Court :-"<<'\n';
SetCursorPos(24,7);
cout<<"1...Add dish to menu"<<'\n';
SetCursorPos(24,8);
cout<<"2...Show the menu"<<'\n';
SetCursorPos(24,9);
cout<<"3...Take order"<<'\n';
SetCursorPos(24,10);
cout<<"4...Order Ready"<<'\n';
SetCursorPos(24,11);
cout<<"5...Remove dish from menu"<<'\n';
cin>>op;
switch (op)
{
case 1:CreateMenu();  break;
case 2:PrintMenu();break;
case 3:TakeOrder(q);break;
case 4:Ready(q);break;
case 5:RemoveDish();break;
default:cout<<"Wrong choice"<<'\n';
}
cout<<"Continue?"<<'\n';
cin>>cont; }  while (cont=='y' || cont=='Y');

}


int main()
{
char tl=201, tr=187, bl=200,br=188,v=186,h=205;
system("clear");
 char e=17,f=16;
SetCursorPos(28,10) ;
cout<<e<<e<<e<<"  OLIVE CLIFF RESORT  "<<f<<f<<f<<'\n';

char cont;
int op;
do{

system("clear");
SetCursorPos(36,7);
cout<<"MAIN MENU";
SetCursorPos(28,8);
cout<<tl<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<tr;
SetCursorPos(28,9);
cout<<v<<"1...Reception Desk "<<v;
SetCursorPos(28,10);
cout<<v<<"2...Manager        "<<v;
SetCursorPos(28,11);
cout<<v<<"3...Food Court     "<<v;
SetCursorPos(28,12);
cout<<bl<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<br;
cout<<'\n';
cin>>op;

switch (op)
{
case 1:receptionmode(); break;
case 2: char pass[20];
cout<<"Enter the password (Case Sensitive)"<<'\n';
cin>>pass;
if (strcmp(pass,"imthemanager")==0) managermode();
else cout<<"Wrong Password"<<'\n';
break;
case 3: foodcourt(); break;
default : cout<<"wrong choice"<<'\n';
}
cout<<"Go back to homescreen?"<<'\n';
cin>>cont; } while (cont=='y' || cont=='Y');
}
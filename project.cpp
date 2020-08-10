#include<fstream>
#include<iostream>
#include<process.h>
#include<stdio.h>
#include<ctime>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
using namespace std;


class user
{
	char name[20],email[50],from[20],to[20];
	int studconc,ttype;
	int bid;

    float ttckt;
    char trno[5];
	    public:
    int bnumber();
	void search_bid();
	void searchtrainno();
    int deletetrainticket(char*);
    int bookticket(char *,char *,char *,int ,int ,int);
    void cancel_ticket();
    void checkmystatus();
    char mob[10];
}s;

void validation_int(int&);
char* validation_character2(char*);
int check(char a[],char b[]);
void design();
char* validation_character1(char*);

char* validation_character1(char*m)
{
	int i,flag,l;
	char mno[10],dummy[10];
		strcpy(mno,m);
	do{
		flag=0;

		l=strlen(mno);
		for(i=0;i<l;i++)
		{
			if(isalpha(mno[i]))
			{
				flag=1;
				break;
			}

		}

		if(flag==1)
		{
			cout<<"\n Data must have only digits ";
            cout<<"\n Enter again";
		gets(mno);
		}
		else
		strcpy(m,mno);
	}while(flag);
	return m;
}


char* validation_character2(char*a)
{
int flag;
char str[20],dummy[29];
strcpy(str,a);
do
{
flag=0;

int l=strlen(str);
for(int i=0;i<l;i++)
{
if(isdigit(str[i]))
{
flag=1;
break;
}


}
if(flag==1)
{
cout<<"\n Data must have no digits\n";
cout<<"\n Enter again";
gets(str);
}
else
strcpy(a,str);
}while(flag);
return a;
}

void validation_int(int& a)
{
int error;
do
{
error=0;
cin>>a;
if(cin.fail())
{
cout<<"\n PLEASE ENTER A VALID INTEGER:";
error=1;
cin.clear();
cin.ignore(80,'\n');
}
}while(error==1);
}

int admin_password()
{
char pwd[50],def[]="admin";
int i=0,mycheck,a=0;
cout<<"\n ENTER ADMIN PASSWORD :  ";
for(i=0;;i++)
{
pwd[i]=getch();
a=pwd[i];
if(a==13)
{
pwd[i]='\0';
break;
}
else if(a==8)
{
if(i>0)
{
cout<<"\b"<<" "<<"\b";
i-=2;
}
else if(i==0)
{
cout<<"\b";
i--;
}
}
else if(a==0||a==224)
{
getch();
continue;
}
else
putch('*');
}
cout<<endl;
mycheck=check(pwd,def);
return mycheck;
}

int check(char a[5],char b[5])
{
	 int i;
	 for(i=0;i<5;i++)
	 {
		  if(a[i]!=b[i])
		  {
		  break;
		  }
	 }
	 if(i==5)
	 return 1;
	 else
	 return 0;
}

void design()
{  int i;
 for( i=0;i<120;i++)
  cout<<"=";
 cout<<"\n\n";


 time_t currentTime;
  struct tm *localTime;

  time( &currentTime );
  localTime = localtime( &currentTime );

  int Day    = localTime->tm_mday;
  int Month  = localTime->tm_mon + 1;
  int Year   = localTime->tm_year + 1900;
  int Hour   = localTime->tm_hour;
  int Min    = localTime->tm_min;
  int Sec    = localTime->tm_sec;

  cout << std::endl;
  cout << std::endl;



 cout<< "Time: " << Hour << ":" << Min << ":" << Sec <<"                                       OOPS  PROJECT ";
 cout<<"\n";

 cout<< "Date: " << Day << "/" << Month << "/" << Year <<"                              RAILWAY RESERVATION SYSTEM";
 cout<<endl<<endl;
 for( i=0;i<120;i++)
  cout<<"=";
  cout<<"\n\n\n";
}

struct TRAIN
{
		char stno[5],sfcity[20],stcity[20];
	int stime,steco,stbus,sseco,ssbus;
	int sefare,sbfare,sday;
	struct TRAIN *next;
};


class train
{
    public:
	char tno[5],fcity[20],tcity[20];
	int time,teco,tbus,seco,sbus;
	int efare,bfare,day;
	public :
	void createhash();
	void deletetrain();
    void modify_train();
    void traincheckmystatus(char*);
	void newtrain();
	TRAIN* createNode();
	void searchbook();
	void viewall();
	int traincancel_ticket(int ,char*);
	void searchtrainno();
}f;

struct hash
 {

 struct TRAIN *head;
        int count;
  };

TRAIN* train:: createNode()
	{
         TRAIN *nnode= new TRAIN;

    	cout<<"Enter details : \n";
    	cout<<"Enter train number : \n";
    	cin>>nnode->stno;
    	cout<<"Enter day of travel ( 1 being Monday and 7 being Sunday ) : \n";
    	cin>>nnode->sday;
    	cout<<"Enter time of travel : \n";
    	cin>>nnode->stime;
    	cout<<"Enter from city : \n";
    	cin>>nnode->sfcity;
    	cout<<"Enter to city : \n";
    	cin>>nnode->stcity;
    	cout<<"Enter fare for Non AC category: \n";
    	cin>>nnode->sefare;
    	cout<<"Enter fare for AC category : \n";
    	cin>>nnode->sbfare;
    	nnode->steco=100;
    	nnode->stbus=20;
    	nnode->sseco=0;
    	nnode->ssbus=0;
    	nnode->next=NULL;
    	return nnode;
    }

void train::createhash()
    	{
    		char ch;
    		ofstream f3,f4;
f3.open("train.dat",ios::binary|ios::trunc);
f4.open("cust.dat",ios::binary|ios::trunc);
if(f3.fail())
{
cerr<<"\n CANNOT OPEN FILE";
exit(1);
}
struct hash *hashTable = NULL;
 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
         do
        {
        cout<<"\n Details for the train : \n";
        struct TRAIN *newnode =  createNode();


        int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                goto j;
        }

        newnode->next = (hashTable[hashIndex].head);
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
       j:
	    cout<<"\n  Press Y if you want to enter details of another train .. Otherwise press N \n";
        cin>>ch;
    }while(ch=='y'||ch=='Y');

     TRAIN *mynode;
     int i;
        for (i = 0; i < 7; i++)
		 {
                if (hashTable[i].count == 0)
                        continue;
                mynode = hashTable[i].head;
                if (!mynode)
                        continue;


                while (mynode != NULL) {

                	strcpy(tno,mynode->stno);
                	strcpy(fcity,mynode->sfcity);
                	strcpy(tcity,mynode->stcity);
                	time=mynode->stime;
                	teco=mynode->steco;
                	seco=mynode->sseco;
                	tbus=mynode->stbus;
                	sbus=mynode->ssbus;
                	efare=mynode->sefare;
                	bfare=mynode->sbfare;
                	day=mynode->sday;
                	f3.write((char*)&f,sizeof(f));

                        mynode = mynode->next;
                }
        }

        f3.close();
        f4.close();
        }

void train::deletetrain()
	{
	char temptrno[5];
	int counter=0;
		struct hash *hashTable = NULL;
 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
	fstream f2,t2;
    f2.open("train.dat",ios::binary|ios::in);
    t2.open("temp2.dat",ios::binary|ios::out);

		while(f2.read((char*)&f,sizeof(f)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
              continue;
			          }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}



		int key,hindex,flag=0;

		 TRAIN *temp,*mynode;
		 cout<<"\n Enter the train no of the train to be deleted :";
		 cin>>temptrno;
		 cout<<"\n Enter the day of the train :";
		 cin>>key;
		 hindex=key % 7;
		 mynode=hashTable[hindex].head;
		 if(!mynode){
		 	cout<<"\n Invalid train no";
		 	 printf("\n Given data is not present!!!\n");
        f2.close();
        t2.close();

		return;
		 }
		 temp=mynode;
		 while(mynode!=NULL)
		 {
		 	if(strcmp(mynode->stno,temptrno)==0)
		 	{
		 	flag = 1;
                        if (mynode == hashTable[hindex].head)
                                 hashTable[hindex].head = mynode->next;
                        else
                                temp->next = mynode->next;

                        hashTable[hindex].count--;
                        free(mynode);
                        break;
		 	}
		 	temp=mynode;
            mynode = mynode->next;
		 }



		 if (flag)
		 {

            TRAIN *mnode;
     int i;
        for (i = 0; i < 7; i++)
		 {
                if (hashTable[i].count == 0)
                        continue;
                mnode = hashTable[i].head;
                if (!mnode)
                        continue;

                while (mnode != NULL) {
                	strcpy(tno,mnode->stno);
                	strcpy(fcity,mnode->sfcity);
                	strcpy(tcity,mnode->stcity);
                	time=mnode->stime;
                	teco=mnode->steco;
                	seco=mnode->sseco;
                	tbus=mnode->stbus;
                	sbus=mnode->ssbus;
                	efare=mnode->sefare;
                	bfare=mnode->sbfare;
                	day=mnode->sday;
                	t2.write((char*)&f,sizeof(f));

                        mnode = mnode->next;
                }
        }
                f2.close();
        t2.close();
         remove("train.dat");
         rename("temp2.dat","train.dat");
		 counter=s.deletetrainticket(temptrno);
          if(counter)
		  printf("Data deleted successfully from Hash Table\n");
         }
        else
        {
        printf("Given data is not present in hash Table!!!!\n");
        f2.close();
        t2.close();
	    }
		return;
	}

    void train::modify_train()
    {
    	struct hash *hashTable = NULL;
 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
	fstream f2,t2;
    f2.open("train.dat",ios::binary|ios::in);
    t2.open("temp2.dat",ios::binary|ios::out);

		while(f2.read((char*)&f,sizeof(f)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                continue;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}


		int key,hindex,flag=0;
		char temptrno[5];
		 TRAIN *temp,*mynode;
		 cout<<"\n Enter the train no of the train whose details have to be modified :";
		 cin>>temptrno;
		 cout<<"\n Enter the day of the train :";
		 cin>>key;
		 hindex=key % 7;
		 mynode=hashTable[hindex].head;
		 if(!mynode){
		 	cout<<"\n invalid train no";

        printf("Given data is not present!!!!\n");
        f2.close();
        t2.close();

		return;
		 }

		 while(mynode!=NULL)
		 {
		 	if(strcmp(mynode->stno,temptrno)==0)
		 	{
		 	flag = 1;
		 	cout<<"\n enter new details";
		 	cout<<"Enter time of travel : \n";
        	cin>>mynode->stime;
    	    cout<<"Enter from city : \n";
    	    cin>>mynode->sfcity;
    	    cout<<"Enter to city : \n";
    	    cin>>mynode->stcity;
    	    cout<<"Enter fare for Non AC category : \n";
    	    cin>>mynode->sefare;
    	    cout<<"Enter fare for AC category : \n";
    	    cin>>mynode->sbfare;
             break;
		 	}

            mynode = mynode->next;
		 }



		 if (flag)
		 {

            TRAIN *mnode;
     int i;
        for (i = 0; i < 7; i++)
		 {
                if (hashTable[i].count == 0)
                        continue;
                mnode = hashTable[i].head;
                if (!mnode)
                        continue;

                while (mnode != NULL) {

                	strcpy(tno,mnode->stno);
                	strcpy(fcity,mnode->sfcity);
                	strcpy(tcity,mnode->stcity);
                	time=mnode->stime;
                	teco=mnode->steco;
                	seco=mnode->sseco;
                	tbus=mnode->stbus;
                	sbus=mnode->ssbus;
                	efare=mnode->sefare;
                	bfare=mnode->sbfare;
                	day=mnode->sday;
                	t2.write((char*)&f,sizeof(f));

                        mnode = mnode->next;
                }
        }
                f2.close();
        t2.close();
         remove("train.dat");
         rename("temp2.dat","train.dat");
          printf("Data has been successfully modified\n");
         }
        else
        {
        printf("Given data is not present!!!!\n");
        f2.close();
        t2.close();
	    }
		return;
	}

void train::newtrain()
    {
    	char ch;int flag=0;
	struct hash *hashTable = NULL;
 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
	fstream f2,t2;
    f2.open("train.dat",ios::binary|ios::in);
    t2.open("temp2.dat",ios::binary|ios::out);

		while(f2.read((char*)&f,sizeof(f)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                continue;
        }

        newnode->next = (hashTable[hashIndex].head);
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}


		do
		{
			cout<<"\nEnter details for new train"<<endl;
			struct TRAIN *newnode =  createNode();
            flag=1;

        int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                goto l;
        }

        newnode->next = (hashTable[hashIndex].head);
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
        l:
        cout<<"\n  Press Y if u wanna enter details of another train .. Otherwise press N ";
        cin>>ch;
        }while(ch=='y'||ch=='Y');



		 if (flag)
		 {

            TRAIN *mnode;
     int i;
        for (i = 0; i < 7; i++)
		 {
                if (hashTable[i].count == 0)
                        continue;
                mnode = hashTable[i].head;
                if (!mnode)
                        continue;

                while (mnode != NULL) {
                	strcpy(tno,mnode->stno);
                	strcpy(fcity,mnode->sfcity);
                	strcpy(tcity,mnode->stcity);
                	time=mnode->stime;
                	teco=mnode->steco;
                	seco=mnode->sseco;
                	tbus=mnode->stbus;
                	sbus=mnode->ssbus;
                	efare=mnode->sefare;
                	bfare=mnode->sbfare;
                	day=mnode->sday;
                	t2.write((char*)&f,sizeof(f));

                        mnode = mnode->next;
                }
        }
                f2.close();
               t2.close();
         remove("train.dat");
         rename("temp2.dat","train.dat");

	}

}

void train::viewall()
{
	struct hash *hashTable = NULL;
	 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
	fstream f2,t2;
    f2.open("train.dat",ios::binary|ios::in);


		while(f2.read((char*)&f,sizeof(f)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
            continue;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}


		 struct TRAIN *mynode;
        int i;
        for (i = 0; i < 7; i++) {
                if (hashTable[i].count == 0)
                        continue;
                mynode = hashTable[i].head;
                if (!mynode)
                        continue;
                cout<<"\n Trains on day"<<i<<" of the week: ";

                while (mynode != NULL)
				 {
				 	cout<<"\nTrain number :"<<mynode->stno;
                    cout<<"\nFrom city : "<<mynode->sfcity;
					cout<<"\nTO city : "<<mynode->stcity;
			cout<<"\nTime of departure : "<<mynode->stime/100<<":"<<mynode->stime%100;
			cout<<"\nTotal number of seats in Non AC category:"<<mynode->steco;
			cout<<"\nNumber of seats booked in Non AC category : "<<mynode->sseco;
		    cout<<"\nTotal number of seats in AC category : "<<mynode->stbus;
			cout<<"\nNumber of seats booked in AC Category : "<<mynode->ssbus;
			cout<<"\nFare of Non AC category tickets : "<<mynode->sefare;
			cout<<"\nFare of AC category tickets : "<<mynode->sbfare;
	        cout<<"\n\n\n";
            mynode = mynode->next;
                }
        }
        f2.close();

        return;
}

void train::searchtrainno()
{
	struct hash *hashTable = NULL;
	 hashTable = (struct hash *)calloc(7, sizeof (struct hash));

	fstream f2,t2;
    f2.open("train.dat",ios::binary|ios::in);
    t2.open("temp2.dat",ios::binary|ios::out);

		while(f2.read((char*)&f,sizeof(f)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                continue;
        }

        newnode->next = (hashTable[hashIndex].head);
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}

			int key,hindex,flag=0;
		char temptrno[5];
		 TRAIN *temp,*mynode;
		 cout<<"\n Enter the train number of the train whose details have to be searched :";
		 cin>>temptrno;
		 cout<<"\n Enter the day of the train :";
		 cin>>key;
		 hindex=key % 7;
		 mynode=hashTable[hindex].head;
		 if(!mynode){
		 	cout<<"\n Invalid train no";
		 	f2.close();
               t2.close();
               return;
		 }
		 temp=mynode;
		 while(mynode!=NULL)
		 {
		 	if((mynode->stno,temptrno)==0)
		 	{
		 	flag = 1;
		 	cout<<"\nTrain number :"<<mynode->stno;
                    cout<<"\nFrom city : "<<mynode->sfcity;
					cout<<"\nTO city : "<<mynode->stcity;
			cout<<"\nTime of departure : "<<mynode->stime/100<<":"<<mynode->stime%100;
			cout<<"\nTotal number of seats in Non AC category:"<<mynode->steco;
			cout<<"\nNumber of seats booked in Non AC category: "<<mynode->sseco;
		    cout<<"\nTotal number of seats in AC category : "<<mynode->stbus;
			cout<<"\nNumber of seats booked in AC category : "<<mynode->ssbus;
			cout<<"\nFare of Non AC category tickets : "<<mynode->sefare;
			cout<<"\nFare of AC category tickets : "<<mynode->sbfare;
			cout<<"\nDay of travel : "<<mynode->sday;
			cout<<"\n\n";
			}
		 	temp = mynode;
            mynode = mynode->next;
		 }
f2.close();
               t2.close();
}

int user::bnumber()
{
int i,randnum;
unsigned int s;
time_t t;
s=(unsigned)time(&t);
srand(s);
return rand();
}

void user::search_bid()
{
 int sno;
 cout<<"\n Enter the BOOKING ID  of the passenger to be searched for:";
 validation_int(sno);
 ifstream f;
 f.open("cust.dat",ios::binary);
 int flag=0;
cout<<"\n\t\t\t\t SEARCH USING BOOKING ID";
 while(f.read((char*)&s,sizeof(s)))
{
 if(sno==bid)
  {
  flag=1;
  cout<<"\n PASSENGER DETAILS";
  cout<<"\n BOOKING ID:"<<bid;
  cout<<"\n NAME:"<<name;
  cout<<"\n E-MAIL ID:"<<email;
  cout<<"\n MOBILE NUMBER:"<<mob;
  cout<<"\n TRAIN NO:"<<trno;
  cout<<"\n TRAVELLING FROM:"<<from;
  cout<<"\n TRAVELLING TO:"<<to;


cout<<"\n student concession:";
if(studconc==1)
cout<<"yes";
else cout<<"no";
cout<<"\n category of travel:";
if(ttype==1)
cout<<" AC category";
else if(ttype==2)
cout<<" Non AC category";
 cout<<"\n TOTAL AMOUNT TO BE PAID:"<<ttckt;

  cout<<"\n";
  }
}
if(flag==0)
cout<<"\n RECORD NOT FOUND!!!";
cout<<"\n PRESS ANY KEY TO GO BACK TO MAINMENU:";
f.close();
}

void user::searchtrainno()
{
char tempfl[5];
	ifstream f3;
f3.open("cust.dat",ios::binary);

int flag=0;
if(f3.fail())
{
cerr<<"\n CANNOT OPEN FILE";
exit(1);
}

cout<<"\n ENTER THE TRAIN NO FOR WHICH THE PASSENGER LIST HAS TO BE DISPLAYED\n:";
cin>>tempfl;
while(f3.read((char*)&s,sizeof(s)))
{
 if(strcmp(tempfl,trno)==0)
 {
  flag=1;

    cout<<"\n PASSENGER DETAILS";
  cout<<"\n BOOKING ID:"<<bid;
  cout<<"\n NAME:"<<name;
  cout<<"\n E-MAIL ID:"<<email;

  cout<<"\n MOBILE NUMBER:"<<mob;

  cout<<"\n TRAVELLING FROM:"<<from;
  cout<<"\n TRAVELLING TO:"<<to;
   cout<<"\n TRAIN NO:"<<trno;
cout<<"\n student concession:"; if(studconc==1)cout<<"yes";else cout<<"no";
cout<<"\n category of travel: ";
if(ttype==1)
cout<<" AC category";
else if(ttype==2)
cout<<" Non AC category";
 cout<<"\n TOTAL AMOUNT TO BE PAID:"<<ttckt;

  cout<<"\n";
 }
}
if(flag==0)
cout<<"\n NO RECORD FOUND!!!";
cout<<"\n PRESS ANY KEY TO GO BACK TO MAINMENU:";
f3.close();
}

void train::searchbook()
{
	int ch;
	char temptrno[5];
char choice;
 int flag=0,flag1=0,flag2=0;
    ifstream f3,f4;
    f4.open("train.dat",ios::binary);

    f3.open("train.dat",ios::binary);
    ofstream temp2file;
    temp2file.open("temp2.dat",ios::binary);
    char tempfrom[20],tocity[20];
	cout<<"\nEnter from city : ";
	cin>>tempfrom;
	cout<<"\nEnter to city : ";
	cin>>tocity;
	if(f3.fail()||!temp2file||!f4)
  {
  cerr<<"\n CANNOT OPEN FILE";
  exit(1);
  }

  while(f3.read((char*)&f,sizeof(f)))
{
	if(strcmpi(tempfrom,fcity)==0&&strcmpi(tocity,tcity)==0)
	{   flag=1;
		cout<<"\ntrain number :"<<tno;
        cout<<"\nFrom city : "<<fcity;
	    cout<<"\nTO city : "<<tcity;
	    cout<<"\nDay of travel : "<<day;
		cout<<"\nTime of departure : "<<time/100<<":"<<time%100;
		cout<<"\nNumber of seats available in Non AC category : "<<teco-seco;
	    cout<<"\nFare of Non AC category tickets : "<<efare;
		cout<<"\nNumber of seats available in AC category : "<<tbus-sbus;
		cout<<"\nFare of AC category tickets : "<<bfare;
		cout<<"\n";

	}
}
if(flag==0)
{
	cout<<"\n Sorry .. There are no trains available that meet your requirements";
}
else if(flag==1)
{



   cout<<"\n DO YOU WANT TO BOOK A TICKET.(y/Y)";
   cin>>choice;

   if(choice=='y'||choice=='Y')
   {

   cout<<"\n CHECK THE AVAILABILITY AND THEN ENTER THE EXACT TRAIN NUMBER : ";
    cin>>temptrno;

    cout<<"\n DO YOU WANT TO TRAVEL BY AC category OR Non AC CATEGORY ( 1/2 ) ";

    cin>>ch;

    while(f4.read((char*)&f,sizeof(f)))
{
	if(strcmp(temptrno,tno)==0)
	{  flag1=1;

			if(ch==1)
		{
		strcpy(tno,tno);
		strcpy(fcity,fcity);
		strcpy(tcity,tcity);

	 time=time;
	 teco=teco,
	 tbus=tbus;
	 seco=seco;
	 efare=efare;
	 bfare=bfare;
	 day=day;

		sbus++;
		temp2file.write((char*)&f,sizeof(f));
        }

      	else if(ch==2)
		{

			strcpy(tno,tno);
		strcpy(fcity,fcity);
		strcpy(tcity,tcity);

	 time=time;
	 teco=teco,
	 tbus=tbus;
	 sbus=sbus;
	 efare=efare;
	 bfare=bfare;
	 day=day;
		seco++;
		temp2file.write((char*)&f,sizeof(f));
        }
       flag2=s.bookticket(tno,fcity,tcity,efare,bfare,ch);
	}

	else
	temp2file.write((char*)&f,sizeof(f));
}
if(flag1&&flag2)
{
f4.close();
f3.close();
temp2file.close();
remove("train.dat");
rename("temp2.dat","train.dat");
}
}
else
{  f4.close();
	f3.close();
temp2file.close();
	return;
}

}
f3.close();
f4.close();
temp2file.close();
}

int user::bookticket(char *trainno,char *frm,char *dest,int ecost,int bcost,int type)
{
int flag2=0;
cout<<"\n"<<trainno;
  char nam[20],mobi[10],q[10];
  int a1,a2,a3,a4,a5,a6;
  float charge=0;
  ifstream f1("cust.dat",ios::binary);
  ofstream f("cust.dat",ios::binary|ios::app);
  if(f.fail())
  {
  cerr<<"\n CANNOT OPEN FILE";
  exit(1);
  }
    strcpy(trno,trainno);

  cout<<"\n\t\t\t\t INPUT DETAILS \n";
  cout<<"\n WELCOME TO OOPS PROJECT \n";
  cout<<"\n ENTER YOUR DETAILS\n";
  gets(q);
  cout<<"\n ENTER YOUR NAME:";
  gets(nam);
  strcpy(name,validation_character2(nam));

  cout<<"\n ENTER YOUR E-MAIL ID:";
  gets(email);
  cout<<"\n ENTER MOBILE NUMBER";
  gets(mobi);
  strcpy(mob,validation_character1(mobi));
  strcpy(trno,trainno);
  bid=s.bnumber();


  strcpy(from,frm);
  strcpy(to,dest);
 ttype=type;
  if(ttype==1)
  {
  charge+=bcost;
  cout<<"\n YOUR AC CATEGORY SEAT HAS BEEN BOOKED";
  }
  else if(ttype==2)
  {
  charge+=ecost;
  cout<<"\n YOUR Non AC CATEGORY SEAT HAS BEEN BOOKED";
}




cout<<"\n DO YOU WANT TO AVAIL STUDENT CONCESSION (offer of 5% your total booking cost):(1.YES/2.NO)\n";
 cin>>a5;
 if(a5==1)
{ studconc=1;
 charge=charge-(charge*0.05);
 cout<<"\n YOU HAVE AVAILED STUDENT CONCESSION \n PLEASE CARRY YOUR ID CARD DURING YOUR TRAIN TO AVOID ANY INCONVINIENCE";
}
else
studconc=0;

ttckt=charge;
 cout<<"mycheck : "<<mob<<"\t"<<trno;
  cout<<"\n THE TOTAL AMOUNT TO BE PAID IS:"<<ttckt;
  cout<<"\n YOUR BOOKING HAS BEEN COMPLETED SUCCESFULLLY\n";
  cout<<"\n YOUR BOOKING ID IS:"<<bid;
  f.write((char*)&s,sizeof(s));
  flag2=1;



  cout<<"\n THANK YOU \n";
  cout<<"\n !!!!!!HAVE A COMFORTABLE JOURNEY!\n";
  cout<<"\n PRESS ANY KEY TO GO BACK TO MAINMENU:";
  f.close();
  return flag2;
}

int user::deletetrainticket(char *tempfl)
{
	int flag=0;
	ifstream subfile;
	ofstream tempfile;
	subfile.open("cust.dat",ios::binary|ios::in);
tempfile.open("temp.dat",ios::binary|ios::out);
if(!tempfile||!subfile)
{
cerr<<"\n CANNOT OPEN FILE";
exit(1);
}

while(subfile.read((char*)&s,sizeof(s)))
{
if((strcmp(trno,tempfl)==0))
{

flag=1;

}
else
tempfile.write((char*)&s,sizeof(s));
}
if(flag)
{
	subfile.close();
tempfile.close();
remove("cust.dat");
rename("temp.dat","cust.dat");
}
else
subfile.close();
tempfile.close();

return flag;
}

void user::cancel_ticket()
{
fstream subfile,tempfile;
char tempmob[10];
int tempbid;
int type;
char temptr[5];
int flag1=0,flag=0;

char ans;
subfile.open("cust.dat",ios::binary|ios::in);
tempfile.open("temp.dat",ios::binary|ios::out);
if(!tempfile||!subfile)
{
cerr<<"\n CANNOT OPEN FILE";
exit(1);
}

cout<<"\n ENTER YOUR BOOKING ID:";
cin>>tempbid;
cout<<"\n ENTER THE MOBILE NUMBER USED WHILE BOOKING:";
cin>>tempmob;
cout<<"\n ARE YOU SURE YOU WANT TO CANCEL YOUR TICKET?(Y/y)";
cin>>ans;
if(ans=='y'||ans=='Y')
{

while(subfile.read((char*)&s,sizeof(s)))
{
if((tempbid==bid)&&(strcmp(mob,tempmob)==0))
{
strcpy(temptr,trno);
type=ttype;
flag=1;

}
else
tempfile.write((char*)&s,sizeof(s));
}

if(flag==1)
flag1=f.traincancel_ticket(type,temptr);
}
else
{
subfile.close();
tempfile.close();


cout<<"\n YOUR TICKET IS SAFE!!!";
}
if((flag==1)&&(flag1==1))
{
cout<<"\n YOUR TICKET HAS BEEN CANCELLED";

cout<<"\n THANK YOU";
subfile.close();
tempfile.close();



remove("cust.dat");
rename("temp.dat","cust.dat");


}
cout<<"\n PRESS ANY KEY TO GO BACK TO MAINMENU:";
}

int train::traincancel_ticket(int type,char temptr[5])
{
int flag1=0;
	fstream trainfile,temp2file;
trainfile.open("train.dat",ios::binary|ios::in);
temp2file.open("temp2.dat",ios::binary|ios::out);
if(!temp2file||!trainfile)
{
cerr<<"\n CANNOT OPEN FILE";
exit(1);
}
while(trainfile.read((char*)&f,sizeof(f)))
{
	if(strcmp(temptr,tno)==0)
	{
		if(type==1)
		{
		strcpy(tno,tno);
		strcpy(fcity,fcity);
		strcpy(tcity,tcity);

	 time=time;
	 teco=teco,
	 tbus=tbus;
	 seco=seco;
	 efare=efare;
	 bfare=bfare;
	 day=day;

		sbus++;
		temp2file.write((char*)&f,sizeof(f));
        flag1=1;
        }

      	if(type==2)
		{
			strcpy(tno,tno);
		strcpy(fcity,fcity);
		strcpy(tcity,tcity);

	 time=time;
	 teco=teco,
	 tbus=tbus;
	 sbus=sbus;
	 efare=efare;
	 bfare=bfare;
	 day=day;
		seco++;
		temp2file.write((char*)&f,sizeof(f));
        flag1=1;
		}
	}

	else
	temp2file.write((char*)&f,sizeof(f));
}
if(flag1==1)
{
	temp2file.close();
	trainfile.close();
	remove("train.dat");
rename("temp2.dat","train.dat");

}
else
temp2file.close();
trainfile.close();
return flag1;
}


void user::checkmystatus()
{

ifstream s2;
int flag=0;
s2.open("cust.dat",ios::binary);

int bkngid;
if(!s2)
  {
  cerr<<"\n CANNOT OPEN FILE";
  exit(1);
  }
 cout<<"\n Enter booking id: ";
cin>>bkngid;
 char temptr[5];
 s2.seekg(0);
  while(s2.read((char*)&s,sizeof(s)))
{
	if(bkngid==bid)
	{   flag=1;
		 cout<<"\n BOOKING ID:"<<bid;
  cout<<"\n NAME:"<<name;
  cout<<"\n E-MAIL ID:"<<email;
  cout<<"\n MOBILE NUMBER:"<<mob;
  cout<<"\n TRAIN NO:"<<trno;
  cout<<"\n TRAVELLING FROM:"<<from;
  cout<<"\n TRAVELLING TO:"<<to;
cout<<"\n student concession:"; if(studconc==1)cout<<"yes";else cout<<"no";
cout<<"\n category of travel:";
if(ttype==1)
cout<<" AC category";
else if(ttype==2)
cout<<" Non AC category";
 cout<<"\n TOTAL AMOUNT TO BE PAID:"<<ttckt;
  strcpy(temptr,trno);
  cout<<"\n";
	}
}

if(flag==1)
{
f.traincheckmystatus(temptr);
}
else if(flag==0)
{

	cout<<"\n Invalid booking ID!  ";


}

s2.close();

}

void train::traincheckmystatus(char temptr[5])
{
	ifstream f2;
	if(!f2)
  {
  cerr<<"\n CANNOT OPEN FILE";
  exit(1);
  }
f2.open("train.dat",ios::binary);
	while(f2.read((char*)&f,sizeof(f)))
{
	if(strcmp(temptr,tno)==0)
	{
		cout<<"\nFrom city : "<<fcity;
	    cout<<"\nTO city : "<<tcity;
	    cout<<"\nDay of travel : "<<day;
		cout<<"\nTime of departure : "<<time/100<<":"<<time%100;
	}
}
f2.close();

}
class localtrain: public train
{

    char tno[5],fcity[20],tcity[20];
	int time,teco,tbus,seco,sbus;
	int efare,bfare,day;
	public :
	void createhash();
	void deletetrain();
    void modify_train();
    void traincheckmystatus(char*);
	void newtrain();
	TRAIN* createNode();
	void searchbook();
	void viewall();
	int traincancel_ticket(int ,char*);
	void searchtrainno();
}fff1;
class expresstrain: public train
{

	    char tno[5],fcity[20],tcity[20];
	int time,teco,tbus,seco,sbus;
	int efare,bfare,day;
	public :
	void createhash();
	void deletetrain();
    void modify_train();
    void traincheckmystatus(char*);
	void newtrain();
	TRAIN* createNode();
	void searchbook();
	void viewall();
	int traincancel_ticket(int ,char*);
	void searchtrainno();
}fff2;
void localtrain::createhash()
    	{
    		char ch;
    		ofstream f3,f4;
f3.open("localtrain.dat",ios::binary|ios::trunc);
f4.open("cust.dat",ios::binary|ios::trunc);
if(f3.fail())
{
cerr<<"\n CANNOT OPEN FILE";
exit(1);
}
struct hash *hashTable = NULL;
 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
         do
        {
        cout<<"\n Details for the train : \n";
        struct TRAIN *newnode =  createNode();


        int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                goto j;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
       j:
	    cout<<"\n  Press Y if you want to enter details of another train .. Otherwise press N \n";
        cin>>ch;
    }while(ch=='y'||ch=='Y');

     TRAIN *mynode;
     int i;
        for (i = 0; i < 7; i++)
		 {
                if (hashTable[i].count == 0)
                        continue;
                mynode = hashTable[i].head;
                if (!mynode)
                        continue;


                while (mynode != NULL) {

                	strcpy(tno,mynode->stno);
                	strcpy(fcity,mynode->sfcity);
                	strcpy(tcity,mynode->stcity);
                	time=mynode->stime;
                	teco=mynode->steco;
                	seco=mynode->sseco;
                	tbus=mynode->stbus;
                	sbus=mynode->ssbus;
                	efare=mynode->sefare;
                	bfare=mynode->sbfare;
                	day=mynode->sday;
                	f3.write((char*)&fff1,sizeof(fff1));

                        mynode = mynode->next;
                }
        }

        f3.close();
        f4.close();
        }

void localtrain::deletetrain()
	{
	char temptrno[5];
	int counter=0;
		struct hash *hashTable = NULL;
 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
	fstream f2,t2;
    f2.open("localtrain.dat",ios::binary|ios::in);
    t2.open("temp2.dat",ios::binary|ios::out);

		while(f2.read((char*)&fff1,sizeof(fff1)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
              continue;
			          }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}



		int key,hindex,flag=0;

		 TRAIN *temp,*mynode;
		 cout<<"\n Enter the local train no of the train to be deleted :";
		 cin>>temptrno;
		 cout<<"\n Enter the day of the local train :";
		 cin>>key;
		 hindex=key % 7;
		 mynode=hashTable[hindex].head;
		 if(!mynode){
		 	cout<<"\n Invalid train no";
		 	 printf("\n Given data is not present!!!\n");
        f2.close();
        t2.close();

		return;
		 }
		 temp=mynode;
		 while(mynode!=NULL)
		 {
		 	if(strcmp(mynode->stno,temptrno)==0)
		 	{
		 	flag = 1;
                        if (mynode == hashTable[hindex].head)
                                 hashTable[hindex].head = mynode->next;
                        else
                                temp->next = mynode->next;

                        hashTable[hindex].count--;
                        free(mynode);
                        break;
		 	}
		 	temp=mynode;
            mynode = mynode->next;
		 }



		 if (flag)
		 {

            TRAIN *mnode;
     int i;
        for (i = 0; i < 7; i++)
		 {
                if (hashTable[i].count == 0)
                        continue;
                mnode = hashTable[i].head;
                if (!mnode)
                        continue;

                while (mnode != NULL) {
                	strcpy(tno,mnode->stno);
                	strcpy(fcity,mnode->sfcity);
                	strcpy(tcity,mnode->stcity);
                	time=mnode->stime;
                	teco=mnode->steco;
                	seco=mnode->sseco;
                	tbus=mnode->stbus;
                	sbus=mnode->ssbus;
                	efare=mnode->sefare;
                	bfare=mnode->sbfare;
                	day=mnode->sday;
                	t2.write((char*)&fff1,sizeof(fff1));

                        mnode = mnode->next;
                }
        }
                f2.close();
        t2.close();
         remove("localtrain.dat");
         rename("temp2.dat","localtrain.dat");
		 counter=s.deletetrainticket(temptrno);
          if(counter)
		  printf("Data deleted successfully from Hash Table\n");
         }
        else
        {
        printf("Given data is not present in hash Table!!!!\n");
        f2.close();
        t2.close();
	    }
		return;
	}

    void localtrain::modify_train()
    {
    	struct hash *hashTable = NULL;
 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
	fstream f2,t2;
    f2.open("localtrain.dat",ios::binary|ios::in);
    t2.open("temp2.dat",ios::binary|ios::out);

		while(f2.read((char*)&fff1,sizeof(fff1)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                continue;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}


		int key,hindex,flag=0;
		char temptrno[5];
		 TRAIN *temp,*mynode;
		 cout<<"\n Enter the local train no of the train whose details have to be modified :";
		 cin>>temptrno;
		 cout<<"\n Enter the day of the local train :";
		 cin>>key;
		 hindex=key % 7;
		 mynode=hashTable[hindex].head;
		 if(!mynode){
		 	cout<<"\n invalid train no";

        printf("Given data is not present!!!!\n");
        f2.close();
        t2.close();

		return;
		 }

		 while(mynode!=NULL)
		 {
		 	if(strcmp(mynode->stno,temptrno)==0)
		 	{
		 	flag = 1;
		 	cout<<"\n enter new details";
		 	cout<<"Enter time of travel : \n";
        	cin>>mynode->stime;
    	    cout<<"Enter from city : \n";
    	    cin>>mynode->sfcity;
    	    cout<<"Enter to city : \n";
    	    cin>>mynode->stcity;
    	    cout<<"Enter fare for Non AC category : \n";
    	    cin>>mynode->sefare;
    	    cout<<"Enter fare for AC category : \n";
    	    cin>>mynode->sbfare;
             break;
		 	}

            mynode = mynode->next;
		 }



		 if (flag)
		 {

            TRAIN *mnode;
     int i;
        for (i = 0; i < 7; i++)
		 {
                if (hashTable[i].count == 0)
                        continue;
                mnode = hashTable[i].head;
                if (!mnode)
                        continue;

                while (mnode != NULL) {

                	strcpy(tno,mnode->stno);
                	strcpy(fcity,mnode->sfcity);
                	strcpy(tcity,mnode->stcity);
                	time=mnode->stime;
                	teco=mnode->steco;
                	seco=mnode->sseco;
                	tbus=mnode->stbus;
                	sbus=mnode->ssbus;
                	efare=mnode->sefare;
                	bfare=mnode->sbfare;
                	day=mnode->sday;
                	t2.write((char*)&fff1,sizeof(fff1));

                        mnode = mnode->next;
                }
        }
                f2.close();
        t2.close();
         remove("localtrain.dat");
         rename("temp2.dat","localtrain.dat");
          printf("Data has been successfully modified\n");
         }
        else
        {
        printf("Given data is not present!!!!\n");
        f2.close();
        t2.close();
	    }
		return;
	}

void localtrain::newtrain()
    {
    	char ch;int flag=0;
	struct hash *hashTable = NULL;
 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
	fstream f2,t2;
    f2.open("localtrain.dat",ios::binary|ios::in);
    t2.open("temp4.dat",ios::binary|ios::out);

		while(f2.read((char*)&fff1,sizeof(fff1)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                continue;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}


		do
		{
			cout<<"\nEnter details for new local train"<<endl;
			struct TRAIN *newnode =  createNode();
            flag=1;

        int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                goto l;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
        l:
        cout<<"\n  Press Y if u wanna enter details of another train .. Otherwise press N ";
        cin>>ch;
        }while(ch=='y'||ch=='Y');



		 if (flag)
		 {

            TRAIN *mnode;
     int i;
        for (i = 0; i < 7; i++)
		 {
                if (hashTable[i].count == 0)
                        continue;
                mnode = hashTable[i].head;
                if (!mnode)
                        continue;

                while (mnode != NULL) {
                	strcpy(tno,mnode->stno);
                	strcpy(fcity,mnode->sfcity);
                	strcpy(tcity,mnode->stcity);
                	time=mnode->stime;
                	teco=mnode->steco;
                	seco=mnode->sseco;
                	tbus=mnode->stbus;
                	sbus=mnode->ssbus;
                	efare=mnode->sefare;
                	bfare=mnode->sbfare;
                	day=mnode->sday;
                	t2.write((char*)&fff1,sizeof(fff1));

                        mnode = mnode->next;
                }
        }
                f2.close();
               t2.close();
         remove("localtrain.dat");
         rename("temp4.dat","localtrain.dat");

	}

}

void localtrain::viewall()
{
	struct hash *hashTable = NULL;
	 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
	fstream f2,t2;
    f2.open("localtrain.dat",ios::binary|ios::in);


		while(f2.read((char*)&fff1,sizeof(fff1)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
            continue;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}


		 struct TRAIN *mynode;
        int i;
        for (i = 0; i < 7; i++) {
                if (hashTable[i].count == 0)
                        continue;
                mynode = hashTable[i].head;
                if (!mynode)
                        continue;
                cout<<"\nLocal Trains on day"<<i<<" of the week: ";

                while (mynode != NULL)
				 {
				 	cout<<"\nTrain number :"<<mynode->stno;
                    cout<<"\nFrom city : "<<mynode->sfcity;
					cout<<"\nTO city : "<<mynode->stcity;
			cout<<"\nTime of departure : "<<mynode->stime/100<<":"<<mynode->stime%100;
			cout<<"\nTotal number of seats in Non AC category:"<<mynode->steco;
			cout<<"\nNumber of seats booked in Non AC category : "<<mynode->sseco;
		    cout<<"\nTotal number of seats in AC category : "<<mynode->stbus;
			cout<<"\nNumber of seats booked in AC Category : "<<mynode->ssbus;
			cout<<"\nFare of Non AC category tickets : "<<mynode->sefare;
			cout<<"\nFare of AC category tickets : "<<mynode->sbfare;
	        cout<<"\n\n\n";
            mynode = mynode->next;
                }
        }
        f2.close();

        return;
}

void localtrain::searchtrainno()
{
	struct hash *hashTable = NULL;
	 hashTable = (struct hash *)calloc(7, sizeof (struct hash));

	fstream f2,t2;
    f2.open("localtrain.dat",ios::binary|ios::in);
    t2.open("temp4.dat",ios::binary|ios::out);

		while(f2.read((char*)&fff1,sizeof(fff1)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                continue;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}

			int key,hindex,flag=0;
		char temptrno[5];
		 TRAIN *temp,*mynode;
		 cout<<"\n Enter the Local train number of the train whose details have to be searched :";
		 cin>>temptrno;
		 cout<<"\n Enter the day of the local  train :";
		 cin>>key;
		 hindex=key % 7;
		 mynode=hashTable[hindex].head;
		 if(!mynode){
		 	cout<<"\n Invalid train no";
		 	f2.close();
               t2.close();
               return;
		 }
		 temp=mynode;
		 while(mynode!=NULL)
		 {
		 	if((mynode->stno,temptrno)==0)
		 	{
		 	flag = 1;
		 	cout<<"\nTrain number :"<<mynode->stno;
                    cout<<"\nFrom city : "<<mynode->sfcity;
					cout<<"\nTO city : "<<mynode->stcity;
			cout<<"\nTime of departure : "<<mynode->stime/100<<":"<<mynode->stime%100;
			cout<<"\nTotal number of seats in Non AC category:"<<mynode->steco;
			cout<<"\nNumber of seats booked in Non AC category: "<<mynode->sseco;
		    cout<<"\nTotal number of seats in AC category : "<<mynode->stbus;
			cout<<"\nNumber of seats booked in AC category : "<<mynode->ssbus;
			cout<<"\nFare of Non AC category tickets : "<<mynode->sefare;
			cout<<"\nFare of AC category tickets : "<<mynode->sbfare;
			cout<<"\nDay of travel : "<<mynode->sday;
			cout<<"\n\n";
			}
		 	temp = mynode;
            mynode = mynode->next;
		 }
f2.close();
               t2.close();
}
void expresstrain::createhash()
    	{
    		char ch;
    		ofstream f3,f4;
f3.open("expresstrain.dat",ios::binary|ios::trunc);
f4.open("cust.dat",ios::binary|ios::trunc);
if(f3.fail())
{
cerr<<"\n CANNOT OPEN FILE";
exit(1);
}
struct hash *hashTable = NULL;
 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
         do
        {
        cout<<"\n Details for the train : \n";
        struct TRAIN *newnode =  createNode();


        int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                goto j;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
       j:
	    cout<<"\n  Press Y if you want to enter details of another train .. Otherwise press N \n";
        cin>>ch;
    }while(ch=='y'||ch=='Y');

     TRAIN *mynode;
     int i;
        for (i = 0; i < 7; i++)
		 {
                if (hashTable[i].count == 0)
                        continue;
                mynode = hashTable[i].head;
                if (!mynode)
                        continue;


                while (mynode != NULL) {

                	strcpy(tno,mynode->stno);
                	strcpy(fcity,mynode->sfcity);
                	strcpy(tcity,mynode->stcity);
                	time=mynode->stime;
                	teco=mynode->steco;
                	seco=mynode->sseco;
                	tbus=mynode->stbus;
                	sbus=mynode->ssbus;
                	efare=mynode->sefare;
                	bfare=mynode->sbfare;
                	day=mynode->sday;
                	f3.write((char*)&fff2,sizeof(fff2));

                        mynode = mynode->next;
                }
        }

        f3.close();
        f4.close();
        }

void expresstrain::deletetrain()
	{
	char temptrno[5];
	int counter=0;
		struct hash *hashTable = NULL;
 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
	fstream f2,t2;
    f2.open("expresstrain.dat",ios::binary|ios::in);
    t2.open("temp2.dat",ios::binary|ios::out);

		while(f2.read((char*)&fff2,sizeof(fff2)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
              continue;
			          }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}



		int key,hindex,flag=0;

		 TRAIN *temp,*mynode;
		 cout<<"\n Enter the train no of the train to be deleted :";
		 cin>>temptrno;
		 cout<<"\n Enter the day of the train :";
		 cin>>key;
		 hindex=key % 7;
		 mynode=hashTable[hindex].head;
		 if(!mynode){
		 	cout<<"\n Invalid train no";
		 	 printf("\n Given data is not present!!!\n");
        f2.close();
        t2.close();

		return;
		 }
		 temp=mynode;
		 while(mynode!=NULL)
		 {
		 	if(strcmp(mynode->stno,temptrno)==0)
		 	{
		 	flag = 1;
                        if (mynode == hashTable[hindex].head)
                                 hashTable[hindex].head = mynode->next;
                        else
                                temp->next = mynode->next;

                        hashTable[hindex].count--;
                        free(mynode);
                        break;
		 	}
		 	temp=mynode;
            mynode = mynode->next;
		 }



		 if (flag)
		 {

            TRAIN *mnode;
     int i;
        for (i = 0; i < 7; i++)
		 {
                if (hashTable[i].count == 0)
                        continue;
                mnode = hashTable[i].head;
                if (!mnode)
                        continue;

                while (mnode != NULL) {
                	strcpy(tno,mnode->stno);
                	strcpy(fcity,mnode->sfcity);
                	strcpy(tcity,mnode->stcity);
                	time=mnode->stime;
                	teco=mnode->steco;
                	seco=mnode->sseco;
                	tbus=mnode->stbus;
                	sbus=mnode->ssbus;
                	efare=mnode->sefare;
                	bfare=mnode->sbfare;
                	day=mnode->sday;
                	t2.write((char*)&fff2,sizeof(fff2));

                        mnode = mnode->next;
                }
        }
                f2.close();
        t2.close();
         remove("expresstrain.dat");
         rename("temp2.dat","expresstrain.dat");
		 counter=s.deletetrainticket(temptrno);
          if(counter)
		  printf("Data deleted successfully from Hash Table\n");
         }
        else
        {
        printf("Given data is not present in hash Table!!!!\n");
        f2.close();
        t2.close();
	    }
		return;
	}

    void expresstrain::modify_train()
    {
    	struct hash *hashTable = NULL;
 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
	fstream f2,t2;
    f2.open("expresstrain.dat",ios::binary|ios::in);
    t2.open("temp2.dat",ios::binary|ios::out);

		while(f2.read((char*)&fff2,sizeof(fff2)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                continue;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}


		int key,hindex,flag=0;
		char temptrno[5];
		 TRAIN *temp,*mynode;
		 cout<<"\n Enter the train no of the train whose details have to be modified :";
		 cin>>temptrno;
		 cout<<"\n Enter the day of the train :";
		 cin>>key;
		 hindex=key % 7;
		 mynode=hashTable[hindex].head;
		 if(!mynode){
		 	cout<<"\n invalid train no";

        printf("Given data is not present!!!!\n");
        f2.close();
        t2.close();

		return;
		 }

		 while(mynode!=NULL)
		 {
		 	if(strcmp(mynode->stno,temptrno)==0)
		 	{
		 	flag = 1;
		 	cout<<"\n enter new details";
		 	cout<<"Enter time of travel : \n";
        	cin>>mynode->stime;
    	    cout<<"Enter from city : \n";
    	    cin>>mynode->sfcity;
    	    cout<<"Enter to city : \n";
    	    cin>>mynode->stcity;
    	    cout<<"Enter fare for Non AC category : \n";
    	    cin>>mynode->sefare;
    	    cout<<"Enter fare for AC category : \n";
    	    cin>>mynode->sbfare;
             break;
		 	}

            mynode = mynode->next;
		 }



		 if (flag)
		 {

            TRAIN *mnode;
     int i;
        for (i = 0; i < 7; i++)
		 {
                if (hashTable[i].count == 0)
                        continue;
                mnode = hashTable[i].head;
                if (!mnode)
                        continue;

                while (mnode != NULL) {

                	strcpy(tno,mnode->stno);
                	strcpy(fcity,mnode->sfcity);
                	strcpy(tcity,mnode->stcity);
                	time=mnode->stime;
                	teco=mnode->steco;
                	seco=mnode->sseco;
                	tbus=mnode->stbus;
                	sbus=mnode->ssbus;
                	efare=mnode->sefare;
                	bfare=mnode->sbfare;
                	day=mnode->sday;
                	t2.write((char*)&fff2,sizeof(fff2));

                        mnode = mnode->next;
                }
        }
                f2.close();
        t2.close();
         remove("expresstrain.dat");
         rename("temp2.dat","expresstrain.dat");
          printf("Data has been successfully modified\n");
         }
        else
        {
        printf("Given data is not present!!!!\n");
        f2.close();
        t2.close();
	    }
		return;
	}

void expresstrain::newtrain()
    {
    	char ch;int flag=0;
	struct hash *hashTable = NULL;
 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
	fstream f2,t2;
    f2.open("expresstrain.dat",ios::binary|ios::in);
    t2.open("temp3.dat",ios::binary|ios::out);

		while(f2.read((char*)&fff2,sizeof(fff2)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                continue;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}


		do
		{
			cout<<"\nEnter details for new train"<<endl;
			struct TRAIN *newnode =  createNode();
            flag=1;

        int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                goto l;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
        l:
        cout<<"\n  Press Y if u wanna enter details of another train .. Otherwise press N ";
        cin>>ch;
        }while(ch=='y'||ch=='Y');



		 if (flag)
		 {

            TRAIN *mnode;
     int i;
        for (i = 0; i < 7; i++)
		 {
                if (hashTable[i].count == 0)
                        continue;
                mnode = hashTable[i].head;
                if (!mnode)
                        continue;

                while (mnode != NULL) {
                	strcpy(tno,mnode->stno);
                	strcpy(fcity,mnode->sfcity);
                	strcpy(tcity,mnode->stcity);
                	time=mnode->stime;
                	teco=mnode->steco;
                	seco=mnode->sseco;
                	tbus=mnode->stbus;
                	sbus=mnode->ssbus;
                	efare=mnode->sefare;
                	bfare=mnode->sbfare;
                	day=mnode->sday;
                	t2.write((char*)&fff2,sizeof(fff2));

                        mnode = mnode->next;
                }
        }
                f2.close();
               t2.close();
         remove("expresstrain.dat");
         rename("temp3.dat","expresstrain.dat");

	}

}

void expresstrain::viewall()
{
	struct hash *hashTable = NULL;
	 hashTable = (struct hash *)calloc(7, sizeof (struct hash));
	fstream f2,t2;
    f2.open("expresstrain.dat",ios::binary|ios::in);


		while(f2.read((char*)&fff2,sizeof(fff2)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
            continue;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}


		 struct TRAIN *mynode;
        int i;
        for (i = 0; i < 7; i++) {
                if (hashTable[i].count == 0)
                        continue;
                mynode = hashTable[i].head;
                if (!mynode)
                        continue;
                cout<<"\n Trains on day"<<i<<" of the week: ";

                while (mynode != NULL)
				 {
				 	cout<<"\nTrain number :"<<mynode->stno;
                    cout<<"\nFrom city : "<<mynode->sfcity;
					cout<<"\nTO city : "<<mynode->stcity;
			cout<<"\nTime of departure : "<<mynode->stime/100<<":"<<mynode->stime%100;
			cout<<"\nTotal number of seats in Non AC category:"<<mynode->steco;
			cout<<"\nNumber of seats booked in Non AC category : "<<mynode->sseco;
		    cout<<"\nTotal number of seats in AC category : "<<mynode->stbus;
			cout<<"\nNumber of seats booked in AC Category : "<<mynode->ssbus;
			cout<<"\nFare of Non AC category tickets : "<<mynode->sefare;
			cout<<"\nFare of AC category tickets : "<<mynode->sbfare;
	        cout<<"\n\n\n";
            mynode = mynode->next;
                }
        }
        f2.close();

        return;
}

void expresstrain::searchtrainno()
{
	struct hash *hashTable = NULL;
	 hashTable = (struct hash *)calloc(7, sizeof (struct hash));

	fstream f2,t2;
    f2.open("expresstrain.dat",ios::binary|ios::in);
    t2.open("temp3.dat",ios::binary|ios::out);

		while(f2.read((char*)&fff2,sizeof(fff2)))
		{   TRAIN *newnode=new TRAIN;
			strcpy(newnode->sfcity,fcity);
			strcpy(newnode->stno,tno);
			strcpy(newnode->stcity,tcity);
			newnode->stime=time;
			newnode->steco=teco;
			newnode->sseco=seco;
			newnode->stbus=tbus;
			newnode->ssbus=sbus;
			newnode->sefare=efare;
			newnode->sbfare=bfare;
			newnode->sday=day;
			newnode->next=NULL;

			int hashIndex = newnode->sday % 7;
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                continue;
        }

        newnode->next = (hashTable[hashIndex].head);

        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
		}

			int key,hindex,flag=0;
		char temptrno[5];
		 TRAIN *temp,*mynode;
		 cout<<"\n Enter the train number of the train whose details have to be searched :";
		 cin>>temptrno;
		 cout<<"\n Enter the day of the train :";
		 cin>>key;
		 hindex=key % 7;
		 mynode=hashTable[hindex].head;
		 if(!mynode){
		 	cout<<"\n Invalid train no";
		 	f2.close();
               t2.close();
               return;
		 }
		 temp=mynode;
		 while(mynode!=NULL)
		 {
		 	if((mynode->stno,temptrno)==0)
		 	{
		 	flag = 1;
		 	cout<<"\nTrain number :"<<mynode->stno;
                    cout<<"\nFrom city : "<<mynode->sfcity;
					cout<<"\nTO city : "<<mynode->stcity;
			cout<<"\nTime of departure : "<<mynode->stime/100<<":"<<mynode->stime%100;
			cout<<"\nTotal number of seats in Non AC category:"<<mynode->steco;
			cout<<"\nNumber of seats booked in Non AC category: "<<mynode->sseco;
		    cout<<"\nTotal number of seats in AC category : "<<mynode->stbus;
			cout<<"\nNumber of seats booked in AC category : "<<mynode->ssbus;
			cout<<"\nFare of Non AC category tickets : "<<mynode->sefare;
			cout<<"\nFare of AC category tickets : "<<mynode->sbfare;
			cout<<"\nDay of travel : "<<mynode->sday;
			cout<<"\n\n";
			}
		 	temp = mynode;
            mynode = mynode->next;
		 }
f2.close();
               t2.close();
}
TRAIN* localtrain:: createNode()
	{
         TRAIN *nnode= new TRAIN;

    	cout<<"Enter details : \n";
    	cout<<"Enter train number : \n";
    	cin>>nnode->stno;
    	cout<<"Enter day of travel ( 1 being Monday and 7 being Sunday ) : \n";
    	cin>>nnode->sday;
    	cout<<"Enter time of travel : \n";
    	cin>>nnode->stime;
    	cout<<"Enter from city : \n";
    	cin>>nnode->sfcity;
    	cout<<"Enter to city : \n";
    	cin>>nnode->stcity;
    	cout<<"Enter fare for Non AC category: \n";
    	cin>>nnode->sefare;
    	cout<<"Enter fare for AC category : \n";
    	cin>>nnode->sbfare;
    	nnode->steco=100;
    	nnode->stbus=20;
    	nnode->sseco=0;
    	nnode->ssbus=0;
    	nnode->next=NULL;
    	return nnode;
    }
TRAIN* expresstrain:: createNode()
	{
         TRAIN *nnode= new TRAIN;

    	cout<<"Enter details : \n";
    	cout<<"Enter train number : \n";
    	cin>>nnode->stno;
    	cout<<"Enter day of travel ( 1 being Monday and 7 being Sunday ) : \n";
    	cin>>nnode->sday;
    	cout<<"Enter time of travel : \n";
    	cin>>nnode->stime;
    	cout<<"Enter from city : \n";
    	cin>>nnode->sfcity;
    	cout<<"Enter to city : \n";
    	cin>>nnode->stcity;
    	cout<<"Enter fare for Non AC category: \n";
    	cin>>nnode->sefare;
    	cout<<"Enter fare for AC category : \n";
    	cin>>nnode->sbfare;
    	nnode->steco=100;
    	nnode->stbus=20;
    	nnode->sseco=0;
    	nnode->ssbus=0;
    	nnode->next=NULL;
    	return nnode;
    }

    void localtrain::searchbook()
{
	int ch;
	char temptrno[5];
char choice;
 int flag=0,flag1=0,flag2=0;
    ifstream f3,f4;
    f4.open("localtrain.dat",ios::binary);

    f3.open("localtrain.dat",ios::binary);
    ofstream temp2file;
    temp2file.open("temp2.dat",ios::binary);
    char tempfrom[20],tocity[20];
	cout<<"\nEnter from city : ";
	cin>>tempfrom;
	cout<<"\nEnter to city : ";
	cin>>tocity;
	if(f3.fail()||!temp2file||!f4)
  {
  cerr<<"\n CANNOT OPEN FILE";
  exit(1);
  }

  while(f3.read((char*)&fff1,sizeof(fff1)))
{
	if(strcmpi(tempfrom,fcity)==0&&strcmpi(tocity,tcity)==0)
	{   flag=1;
		cout<<"\ntrain number :"<<tno;
        cout<<"\nFrom city : "<<fcity;
	    cout<<"\nTO city : "<<tcity;
	    cout<<"\nDay of travel : "<<day;
		cout<<"\nTime of departure : "<<time/100<<":"<<time%100;
		cout<<"\nNumber of seats available in Non AC category : "<<teco-seco;
	    cout<<"\nFare of Non AC category tickets : "<<efare;
		cout<<"\nNumber of seats available in AC category : "<<tbus-sbus;
		cout<<"\nFare of AC category tickets : "<<bfare;
		cout<<"\n";

	}
}
if(flag==0)
{
	cout<<"\n Sorry .. There are no trains available that meet your requirements";
}
else if(flag==1)
{



   cout<<"\n DO YOU WANT TO BOOK A TICKET.(y/Y)";
   cin>>choice;

   if(choice=='y'||choice=='Y')
   {

   cout<<"\n CHECK THE AVAILABILITY AND THEN ENTER THE EXACT TRAIN NUMBER : ";
    cin>>temptrno;

    cout<<"\n DO YOU WANT TO TRAVEL BY AC category OR Non AC CATEGORY ( 1/2 ) ";

    cin>>ch;

    while(f4.read((char*)&fff1,sizeof(fff1)))
{
	if(strcmp(temptrno,tno)==0)
	{  flag1=1;

			if(ch==1)
		{
		strcpy(tno,tno);
		strcpy(fcity,fcity);
		strcpy(tcity,tcity);

	 time=time;
	 teco=teco,
	 tbus=tbus;
	 seco=seco;
	 efare=efare;
	 bfare=bfare;
	 day=day;

		sbus++;
		temp2file.write((char*)&fff1,sizeof(fff1));
        }

      	else if(ch==2)
		{

			strcpy(tno,tno);
		strcpy(fcity,fcity);
		strcpy(tcity,tcity);

	 time=time;
	 teco=teco,
	 tbus=tbus;
	 sbus=sbus;
	 efare=efare;
	 bfare=bfare;
	 day=day;
		seco++;
		temp2file.write((char*)&fff1,sizeof(fff1));
        }
       flag2=s.bookticket(tno,fcity,tcity,efare,bfare,ch);
	}

	else
	temp2file.write((char*)&fff1,sizeof(fff1));
}
if(flag1&&flag2)
{
f4.close();
f3.close();
temp2file.close();
remove("localtrain.dat");
rename("temp2.dat","localtrain.dat");
}
}
else
{  f4.close();
	f3.close();
temp2file.close();
	return;
}

}
f3.close();
f4.close();
temp2file.close();
}
void expresstrain::searchbook()
{
	int ch;
	char temptrno[5];
char choice;
 int flag=0,flag1=0,flag2=0;
    ifstream f3,f4;
    f4.open("expresstrain.dat",ios::binary);

    f3.open("expresstrain.dat",ios::binary);
    ofstream temp2file;
    temp2file.open("temp2.dat",ios::binary);
    char tempfrom[20],tocity[20];
	cout<<"\nEnter from city : ";
	cin>>tempfrom;
	cout<<"\nEnter to city : ";
	cin>>tocity;
	if(f3.fail()||!temp2file||!f4)
  {
  cerr<<"\n CANNOT OPEN FILE";
  exit(1);
  }

  while(f3.read((char*)&fff2,sizeof(fff2)))
{
	if(strcmpi(tempfrom,fcity)==0&&strcmpi(tocity,tcity)==0)
	{   flag=1;
		cout<<"\ntrain number :"<<tno;
        cout<<"\nFrom city : "<<fcity;
	    cout<<"\nTO city : "<<tcity;
	    cout<<"\nDay of travel : "<<day;
		cout<<"\nTime of departure : "<<time/100<<":"<<time%100;
		cout<<"\nNumber of seats available in Non AC category : "<<teco-seco;
	    cout<<"\nFare of Non AC category tickets : "<<efare;
		cout<<"\nNumber of seats available in AC category : "<<tbus-sbus;
		cout<<"\nFare of AC category tickets : "<<bfare;
		cout<<"\n";

	}
}
if(flag==0)
{
	cout<<"\n Sorry .. There are no trains available that meet your requirements";
}
else if(flag==1)
{



   cout<<"\n DO YOU WANT TO BOOK A TICKET.(y/Y)";
   cin>>choice;

   if(choice=='y'||choice=='Y')
   {

   cout<<"\n CHECK THE AVAILABILITY AND THEN ENTER THE EXACT TRAIN NUMBER : ";
    cin>>temptrno;

    cout<<"\n DO YOU WANT TO TRAVEL BY AC category OR Non AC CATEGORY ( 1/2 ) ";

    cin>>ch;

    while(f4.read((char*)&fff2,sizeof(fff2)))
{
	if(strcmp(temptrno,tno)==0)
	{  flag1=1;

			if(ch==1)
		{
		strcpy(tno,tno);
		strcpy(fcity,fcity);
		strcpy(tcity,tcity);

	 time=time;
	 teco=teco,
	 tbus=tbus;
	 seco=seco;
	 efare=efare;
	 bfare=bfare;
	 day=day;

		sbus++;
		temp2file.write((char*)&fff2,sizeof(fff2));
        }

      	else if(ch==2)
		{

			strcpy(tno,tno);
		strcpy(fcity,fcity);
		strcpy(tcity,tcity);

	 time=time;
	 teco=teco,
	 tbus=tbus;
	 sbus=sbus;
	 efare=efare;
	 bfare=bfare;
	 day=day;
		seco++;
		temp2file.write((char*)&fff2,sizeof(fff2));
        }
       flag2=s.bookticket(tno,fcity,tcity,efare,bfare,ch);
	}

	else
	temp2file.write((char*)&fff2,sizeof(fff2));
}
if(flag1&&flag2)
{
f4.close();
f3.close();
temp2file.close();
remove("expresstrain.dat");
rename("temp2.dat","expresstrain.dat");
}
}
else
{  f4.close();
	f3.close();
temp2file.close();
	return;
}

}
f3.close();
f4.close();
temp2file.close();
}

 main()
{
int ch,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch15;
int a=0,b=0,h=0,q;
system("cls");
design();
ab:
cout<<"\n\t\t\t\tMAIN MENU";
cout<<"\n 1.ADMIN LOGIN\n";
cout<<"\n 2.TICKETS\n";
cout<<"\n 3.STATUS ENQUIRY\n";
cout<<"\n 4.EXIT\n";
cout<<"\n ENTER YOUR CHOICE(1/2/3):";
w:
validation_int(ch);
switch(ch)
{
case 1:
{
system("cls");
design();
p:a=admin_password();
if(!a)
{
cout<<"\n WRONG PASSWORD.";
goto p;
}
else
{
system("cls");
design();
cout<<"\n\t\t\t\tWELCOME ADMINISTRATOR";
l:
cout<<"\n 1.VIEW ALL PASSENGERS IN A TRAIN\n";
cout<<"\n 2.SEARCH FOR A PASSENGER\n";
cout<<"\n 3.VIEW ALL LCAL TRAINS\n ";
cout<<"\n 4.ADD NEW LOCAL TRAIN\n";
cout<<"\n 5.DELETE A LOCAL TRAIN\n";
cout<<"\n 6.MODIFY A LOCAL TRAIN\n";
cout<<"\n 7.VIEW ALL EXPRESS TRAINS\n ";
cout<<"\n 8.ADD NEW EXPRESS TRAIN\n";
cout<<"\n 9.DELETE A EXPRESS TRAIN\n";
cout<<"\n 10.MODIFY A EXPRESS TRAIN\n";
cout<<"\n 11.CREATE NEW LOCAL TRAIN DATABASE\n";
cout<<"\n 12.CREATE NEW EXPRESS TRAIN DATABASE\n";
cout<<"\n 13.LOG OUT\n";
cout<<"\n ENTER YOUR CHOICE(1-12):";
k:
cin>>ch1;
switch(ch1)
{
case 1:
{
system("cls");
design();
s.searchtrainno();
getch();
system("cls");
design();
goto l;
break;
}
case 2:
{
system("cls");
design();
e:
cout<<"\n SEARCH BY BOOKING ID\n";
s.search_bid();
getch();
system("cls");
design();
goto l;
break;
}
case 3:
{
system("cls");
design();
fff1.viewall();
getch();
system("cls");
design();
goto l;
break;
}
case 4:
{
system("cls");
design();
fff1.newtrain();
getch();
system("cls");
design();
goto l;
break;
}
case 5:
{
system("cls");
design();
fff1.deletetrain();
getch();
system("cls");
design();
goto l;
break;
}
case 6:
{
system("cls");
design();
fff1.modify_train();
getch();
system("cls");
design();
goto l;
break;
}
case 7:
{
system("cls");
design();
fff2.viewall();
getch();
system("cls");
design();
goto l;
break;
}
case 8:
{
system("cls");
design();
fff2.newtrain();
getch();
system("cls");
design();
goto l;
break;
}
case 9:
{
system("cls");
design();
fff2.deletetrain();
getch();
system("cls");
design();
goto l;
break;
}
case 10:
{
system("cls");
design();
fff2.modify_train();
getch();
system("cls");
design();
goto l;
break;
}
case 11:
{
system("cls");
design();
fff1.createhash();
getch();
system("cls");
design();
goto l;
break;
}
case 12:
{
system("cls");
design();
fff2.createhash();
getch();
system("cls");
design();
goto l;
break;
}
case 13:
{
system("cls");
design();
goto ab;
break;
}
case 14:
    {
        exit(0);
    }
default:
{
cout<<"\n INVALID CHOICE";
cout<<"\n PLEASE ENTER AGAIN:";
goto k;
break;
}
}
}
}
break;
case 2:
{
g:
system("cls");
design();
cout<<"\n WELCOME USER";
cout<<"\n 1.BOOK LOCAL TRAIN TICKETS ";
cout<<"\n 2.BOOK EXPRESS TRAIN TICKETS ";
cout<<"\n 3.CANCEL LOCAL TRAIN TICKET ";
cout<<"\n 4.CANCEL EXPRESS TRAIN TICKET ";
cout<<"\n 5.RETURN TO MAIN MENU ";
cout<<"\n ENTER YOUR CHOICE:(1-2-3)";
v:
validation_int(ch5);
switch(ch5)
{
case 1:
system("cls");
		  design();
		  fff1.searchbook();
		  getch();
		  system("cls");
		  design();
		  goto g;
		  break;
case 2:
system("cls");
		  design();
		  fff2.searchbook();
		  getch();
		  system("cls");
		  design();
		  goto g;
		  break;
case 3:
{
system("cls");
design();
s.cancel_ticket();
getch();
system("cls");
design();
goto g;
break;
}

case 4:
{
system("cls");
design();
s.cancel_ticket();
getch();
system("cls");
design();
goto g;
break;
}
case 5:
{

		  system("cls");
		  design();
		  goto ab;

break;
}

default :
	{
		cout<<"INVALID CHOICE \n";
		goto v;
		break;
	}
getch();
system("cls");
design();
goto ab;
break;
}
}

case 3:{

system("cls");
design();
s.checkmystatus();
getch();
system("cls");
design();
goto ab;
break;

}
case 4:{

exit(0);
default:
{
cout<<"\n INVALID CHOICE";
cout<<"\n PLEASE ENTER AGAIN:";
goto w;
break;
}
}
}
}

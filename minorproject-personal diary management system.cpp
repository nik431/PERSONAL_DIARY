#include<iostream> //c++ header file
#include<fstream>  //header  files for file handling use
#include<string.h> //used in search,editing fx for searching names
#include<stdio.h>  //used in function delete

using namespace std;

void addrecord();       // TO add records
void viewrecord();     // TO view records
void editrecord();     // TO edit record
void deleterecord();   // to delete record
void searchrecord();  // TO search record
void updaterecord();  //TO update a record

struct diary{

char date[10];
char name[20];
char time[10];   /*created a structure named diary to store date,name,time,place,note */
char place[20];
char note [500];
};


char chr;    //global declaration to be used in functions

int main(){
int choice;
char ch;

do{

cout<<"\n\n\t\t*****************************"<<endl;
cout<<"\t\t*       PERSONAL DIARY      *"<<endl;
cout<<"\t\t*****************************\n"<<endl;
cout<<"\t\t-------------\n";
cout<<"\t\t| MAIN MENU:|\n";
cout<<"\t\t-------------\n";
cout<<"\t\t|---------------------------------|"<<endl;
cout<<"\t\t| ADD RECORD    [1]               |"<<endl;
cout<<"\t\t| VIEW RECORD   [2]               |"<<endl;
cout<<"\t\t| EDIT RECORD   [3]               |"<<endl;
cout<<"\t\t| DELETE RECORD [4]               |"<<endl;
cout<<"\t\t| SEARCH RECORD [5]               |"<<endl;
cout<<"\t\t| EXIT PROGRAM  [6]               |"<<endl;
cout<<"\t\t|---------------------------------|"<<endl;
cout<<"\t\t ENTER YOUR CHOICE -> "; cin>>choice;
cout<<"\nPROGRAM BY -NIKHIL SEJKAR";


switch(choice){
  case 1:
    addrecord();
    break;
  case 2:
   viewrecord();
   break;
   case 3:
   editrecord();
    break;
  case 4:
   deleterecord();
   break;
  case 5:
    searchrecord();
    break;
  case 6:
    exit(0);
    break;

 default:
    cout<<"\n \t You entered incorrect choice \n";
}

cout<<"\t Do you want to go to MAIN MENU? (y/n)=";
cin>>ch;
system("cls"); //system cls clear the screen
}while(ch=='y');


return 0;
}

//*****************************
//FUNCTION For ADDING RECORDS *
//*****************************

void addrecord(){
system("cls");  //clears the screen and show new page
diary record; //structure initialize

cout<<"\n\n\t\t~ ~ ~ ~ ~ ~ WELCOME TO ADD MENU ~ ~ ~ ~ ~ ~\n\n";

ofstream addrecord("addrecord.dat",ios::binary|ios::app);  //ofstream used for writing data
if(!addrecord){                                            //ios type binary | ios type append(to print at end)
   cout<<"error in opening file";
}
else{
    char until='y';
 while(until=='y')
  {

      cin.ignore(); /* this is used because else it skips the values */
      cout<<"\t\tToday's Date=";
      cin.getline(record.date,10);
      cin.ignore();
      cout<<"\t\tEnter NAME= ";
      cin.getline(record.name,20);
      cin.ignore();
      cout<<"\t\tEnter PLACE= ";
      cin.getline(record.place,20);
      cin.ignore();
      cout<<"\t\tEnter TIME[00:00]= ";
      cin.getline(record.time,10);
      cin.ignore();
      cout<<"\t\tEnter note= ";
      cin.getline(record.note,500);




    addrecord.write((char *)&record,sizeof(record));
    /*we use above syntax to write the data*/

    cout<<"\n Do you want to continue y/n=";
    cin>>(until);

 }
 addrecord.close();
 }
}
//******************************
//FUNCTION For EDITING RECORDS *
//******************************

void editrecord(){
system("cls");
diary record;

cout<<"\n\n\t\t~ ~ ~ ~ ~ ~ WELCOME TO EDIT RECORD ~ ~ ~ ~ ~ ~\n\n";

fstream addrecord("addrecord.dat",ios::binary|ios::in|ios::out);
addrecord.seekg(0);
if(!addrecord){
   cout<<"error in opening file";
}

else{
int r,srh=0;
char name[20];
cin.ignore();
cout<<"\t\tEnter name to search= ";
cin.getline(name,20);

while(addrecord.read((char *)&record,sizeof(record))) {
  if(strcmp(record.name,name)==0){
   cout<<"\t" <<record.date <<"\t" <<record.name <<"\t" <<record.time <<record.place <<record.note <<"\t"<<endl;
   srh=1;
     cout<<"PRESS ENTER TO EDIT VALUES\n";
    cout<<"enter date";
    cin.getline(record.date,20);
    cout<<"name ";
    cin.getline(record.name,20);
    cout<<"place ";
    cin.getline(record.place,20);
    cout<<"note ";
    cin.getline(record.note,500);

    addrecord.seekp(-sizeof(record),ios::cur);
    addrecord.write((char *)&record,sizeof(record));
  }

   }
   addrecord.close();
    if(srh==0)
    cout<<"\t\tnot found!"<<endl;

}

}
//******************************
//FUNCTION For VIEWING RECORDS *
//******************************

void viewrecord(){
system("cls");
diary record;
cout<<"\n\n\t\t~ ~ ~ ~ ~ ~ WELCOME TO VIEW MENU ~ ~ ~ ~ ~ ~\n\n";
 cout<<"\t\tENTRIES ARE: \n\n";
ifstream addrecord("addrecord.dat",ios::binary|ios::in);
if(!addrecord){
   cout<<"error in opening file";
}
else{
  cout<<"\t\tDATE\t   NAME\t\t PLACE \tTIME \t\t NOTE\t \n";
  while(addrecord.read((char *)&record,sizeof(record))){
   cout<<"\t\t" <<record.date <<"\t" <<record.name <<"\t" <<record.place <<"\t" <<record.time <<"\t" <<record.note <<"\n" <<endl;
  }
  addrecord.close();
}

}

//********************************
//FUNCTION For SEARCHING RECORDS *
//********************************

void searchrecord(){
system("cls");
diary record;
cout<<"\n\n\t\t~ ~ ~ ~ ~ ~ WELCOME TO SEARCH RECORD ~ ~ ~ ~ ~ ~\n\n";
ifstream addrecord("addrecord.dat",ios::binary|ios::in);
if(!addrecord){
   cout<<"error in opening file";
}

else{
int srh=0;
char name[20];
cin.ignore();
cout<<"\t\tEnter name to search= ";
cin.getline(name,20);


while(addrecord.read((char *)&record,sizeof(record))) {
    if(strcmp(record.name,name)==0)
    {
   cout<<"\t\t" <<record.name <<"\t" <<record.time <<"\t" <<record.place <<"\t" <<record.note <<"\t\n" <<endl;
    srh=1;
    }

    }
    addrecord.close();
    if(srh==0){
    cout<<"not found!";
    }
}

}
//*******************************
//FUNCTION For DELETING RECORDS *
//*******************************
void deleterecord(){

system("cls");
diary record;

cout<<"\n\n\t\t~ ~ ~ ~ ~ ~ WELCOME TO DELETE RECORD ~ ~ ~ ~ ~ ~\n\n";
fstream addrecord("addrecord.dat",ios::binary|ios::in);
fstream delrecord("temp.dat",ios::binary|ios::app);

addrecord.seekg(0);
if(!addrecord || !delrecord){
   cout<<"error in opening file";
}

else{
char name[10];
cin.ignore();
cout<<"\t\tEnter name to delete ";
cin.getline(name,20);

while(addrecord.read((char *)&record,sizeof(record))) {
  if(strcmp(record.name,name)!=0) {

  delrecord.write((char *)&record,sizeof(record));
  }
}
 addrecord.close();
 delrecord.close();
 remove("addrecord.dat");
 rename("temp.dat","addrecord.dat");
}
}


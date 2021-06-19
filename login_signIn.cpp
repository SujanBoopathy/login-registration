#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

class User
{
   string line1,line2,name,password,regName,regPassword,inName,inPassword;
   
   public:
     void userName();
     void securityPassword();
     void login();
};

void User::login()
{
    int flag;   
    ifstream userPtr;
    userPtr.open("Details.txt");
    cout<<"Enter userName :"<<endl;cin>>inName;
    cout<<"Enter Password :"<<endl;cin>>inPassword;
    while(!userPtr.eof())
    {  
       getline (userPtr,name,'\n');
       getline (userPtr,password,'\n');
       if(name==inName && password==inPassword){
         flag=1;
         cout<<"\n\nlogin successful"<<endl;break;
       }

    }
    if(flag!=1)
       cout<<"\nInvalid username or password"<<endl;
}

void User::securityPassword()
{
  fstream userpass;
    userpass.open("Details.txt",ios::app|ios::in|ios::out);
    if(userpass.is_open()){
      cout<<"Create new password :"<<endl;cin>>regPassword;
      userpass<<regPassword<<'\n';
    }
    else
    {
      cout<<"\nCould not open !!!Try again later"<<endl;
    }
}

void User::userName()
{
   fstream userfile;
    
    userfile.open("Details.txt",ios::app|ios::in|ios::out);
    if(!userfile.is_open())
    {  cout<<"\nError!!! we have some problem Try again later"<<endl;}
    else
    {
      cout<<"Enter userName :"<<endl;
      cin>>regName;
      userfile<<regName<<"\n";
      userfile.close();
    }
    
}

class userDetails
{
    string email,name;
    unsigned long long  int  phneNo;
   public:
    void getDetails();

};

void userDetails::getDetails()
{
  fstream userfile;
    
    userfile.open("DetailsUser.txt",ios::app|ios::in|ios::out);
    if(!userfile.is_open())
    {  cout<<"\nError!!! we have some problem Try again later"<<endl;}
    else
    {
      cout<<"\nEnter e-mail id         :"<<endl;cin>>email;
      cout<<"\nEnter your Name         :"<<endl;cin>>name;
      cout<<"\nEnter your mobile number:"<<endl;cin>>phneNo;
      userfile<<email<<'\n'<<name<<'\n'<<phneNo<<'\n';
      userfile.close();
    }
}

int main(){
  int choice;
  User objUser;
  system("cls");
  while(1)
  {
    int gexit,flag=0;
    userDetails objDetails;
    cout<<"\n\nACCESS THE MAIN PAGE THROUGH "<<endl;
    cout<<"1.sign up \t 2.login "<<endl;
    cout<<"Enter 1 or 2 "<<endl;cin>>choice;

    switch(choice)
    {
      case 1:       
       objUser.userName();
       objUser.securityPassword();
       objDetails.getDetails();
       break;
      case 2:        
        objUser.login();
        flag=1;
        break;    
      default:
       cout<<"I think you entered the wrong value !! Try again "<<endl;

    }
    cout<<"\n\n\npress 1 to continue(1|0): "<<endl;cin>>gexit;
    system("cls");
    if(flag==1) break;

    if(gexit==0){
      break;
    }
  }
  
    return 0;
}
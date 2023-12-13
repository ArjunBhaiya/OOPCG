#include<iostream>
#include<fstream>
using namespace std;
class student
{public:
int rollno;
char name[20];
void accept()
   {
    cout<<"Enter the name:"<<endl;
    cin>>name;
    cout<<"Enter the roll number:"<<endl;
    cin>>rollno;
   }
void display()
   {
    cout<<"Name is:"<<name<<endl;
    cout<<"Roll number is:"<<rollno<<endl;
   }
};
int main()
{
student obj[5];
fstream f;
int i,n;
f.open("student.txt");
cout<<"how many records you want?"<<endl;
cin>>n;
cout<<"enter the information"<<endl;
   for(i=0;i<n;i++)
     {
     obj[i].accept();
     f.write((char*)&obj[i],sizeof obj[i]);
     }
     f.open("student.txt",ios::in);
     cout<<"info is as follows"<<endl;
   for(i=0;i<n;i++)
     {
     f.write((char*)&obj[i],sizeof obj[i]);
     obj[i].display();
     }
     f.close();
}

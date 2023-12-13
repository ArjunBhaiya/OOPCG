#include<iostream>
using namespace std;
class complex{
    public:
    float real,img;
    complex(){}
    complex operator+(complex);
    complex operator*(complex);
    friend ostream &operator<<(ostream &,complex &);
    friend istream &operator>>(istream &,complex &);
};
complex complex::operator+ (complex obj){
    complex temp;
    temp.real = real + obj.real;
    temp.img = img + obj.img;
    return (temp);
}
istream &operator>>(istream &is,complex &obj){
    is>>obj.real;
    is>>obj.img;
    return is;
}
ostream &operator<<(ostream &out,complex &obj){
    out<<" "<<obj.real;
    out<<"+"<<obj.img<<"i";
    return out;
}
complex complex::operator* (complex obj){
    complex temp;
    temp.real = real * temp.real - img*obj.img;
    temp.img = img*obj.real + real*obj.img;
    return temp;
}
int main(){
    complex a,b,c,d;
    cout<<"\n The first complex number is: ";
    cout<<"\n enter the real and img";
    cin>>a;
    cout<<"\n The second complex number is: ";
    cout<<"\n enter the real and img";
    cin>>b;
    c = a + b;
    d = a * b;
    cout<<c;
    cout<<endl;
    cout<<d;
}
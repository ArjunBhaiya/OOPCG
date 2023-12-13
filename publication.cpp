#include <iostream>
using namespace std;

class publication
{
public:
   string title;
   float price;
   void getthat()
   {
      cout << "Enter the title:";
      cin >> title;
      cout << "Enter the price:";
      cin >> price;
   }
};
class book : public publication
{
public:
   int pagecount;
   void page()
   {
      cout << "\n Page count:";
      cin >> pagecount;
   }
};
class tape : public publication
{
public:
   float time;
   void play()
   {
      cout << "Playing time in minutes:";
      cin >> time;
   }
};

void display(string title, float price, int pagecount, float time)
{
   cout << "\nTitle:" << title << endl;
   cout << "price:" << price << endl;
   cout << "pagecount:" << pagecount << endl;
   cout << "time:" << time << endl;
}
int main()
{
   book b1;
   b1.getthat();
   b1.page();
   tape t1;
   t1.play();
   display(b1.title, b1.price, b1.pagecount, t1.time);
}
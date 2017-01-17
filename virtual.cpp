#include<iostream>
using namespace std;

class Parent
{
         public:
                virtual void show() {cout<<"Inside parent"<<endl;}
};

class child : public Parent
{
        public:
                void show() {cout<<"Inside child"<<endl;}
};

int main()
{
        Parent *p = new Parent();
        child *ch = dynamic_cast<child*>(p);
        ch->show();
        return 0;
}

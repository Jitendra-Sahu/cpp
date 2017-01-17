#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;

class Box
{
        public:
                Box();
                Box(int, int, int);
                Box(const Box& b);
                ~Box();

                int getLength() const;
                int getBreadth() const;
                int getHeight() const;
                long long CalculateVolume();

                friend bool operator <(Box& b1, Box& b2)
		{
			
        		if (b1.length < b2.length)
        		{
                		return true;
        		}
        		else if (b1.length > b2.length)
        		{
                		return false;
        		}
        		else
        		{
                		if (b1.breadth < b2.breadth)
                		{
                        		return true;
                		}
                		else if (b1.breadth > b2.breadth)
                		{
                        		return false;
                		}
                		else
                		{
                        		if (b1.height < b2.height)
                        		{
                                		return true;
                        		}
                        		else if (b1.height > b2.height)
                        		{
                                		return false;
                        		}
                        		else
                        		{
						return false;
                        		}
                		} 
        		} 
		}

                friend ostream& operator <<(ostream& out, const Box& b);
        private:
                long int length;
                long int breadth;
                long int height;
};

Box::Box()
{
        length = breadth = height = 0;
        ++BoxesCreated;
}

Box::Box(int l, int b, int h)
{
        this->length = l;
        this->breadth = b;
        this->height = h;
        ++BoxesCreated;
}

Box::Box(const Box& b)
{
        this->length = b.length;
        this->breadth = b.breadth;
        this->height = b.height;
        ++BoxesCreated;
}

Box::~Box()
{
        ++BoxesDestroyed;
}

int Box::getLength() const
{
        return length;
}

int Box::getBreadth() const
{
        return breadth;
}

int Box::getHeight() const
{
        return height;
}

long long Box::CalculateVolume()
{
        return (length * breadth * height);
}
/*
friend bool operator<(Box& b1,Box& b2) 
{ 
	if (b1.length < b2.length) 
	{ 
		return true; 
	} 
	else if (b1.length > b2.length) 
	{ 
		return false; 
	} 
	else 
	{ 
		if (b1.breadth < b2.breadth) 
		{ 
			return true; 
		} 
		else if (b1.breadth > b2.breadth) 
		{ 
			return false; 
		} 
		else 
		{ 
			if (b1.height < b2.height) 
			{ 
				return true; 
			} 
			else if (b1.height > b2.height) 
			{ 
				return false; 
			} 
			else 
			{ 
				return false; 
			} 
		} 
	} 
}
*/
ostream& operator <<(ostream& os, const Box& b)
{
        ++BoxesCreated;
        ++BoxesDestroyed;
        os << b.getLength()<<" "<<b.getBreadth()<<" "<<b.getHeight();
        return os;
}

void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
    {
    int type;
    cin>>type;
    if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
        }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}

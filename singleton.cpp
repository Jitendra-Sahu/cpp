#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

class Number
{
	public:
		static Number *instance();
		static void setType(string t)
		{
			type = t;
			delete inst;
			inst = 0;
		}
		virtual void setValue(int in)
		{
			value = in;
		}
		virtual int getValue()
		{
			return value;
		}
	protected:
		int value;
		Number()
		{
			cout<<"\n Ctor....."<<endl;
		}
		static string type;
		static Number *inst;
};

string Number::type = "decimal";
Number *Number::inst = 0;

class Octal: public Number
{
	public:
		friend class Number;
		void setValue(int in)
		{
			char buf[10];
			sprintf(buf, "%o", in);
			sscanf(buf, "%d", &value);
		}
	protected:
		Octal(){}
};

Number *Number::instance()
{
	if(!inst)
	{
		if(type == "octal")
		{
			inst = new Octal();
		}
		else
		{
			inst = new Number();
		}
	}
	return inst;
}

int main()
{
	Number::instance()->setValue(42);
	cout<<"\n Value is: "<<Number::instance()->getValue()<<endl;

	Number::instance()->setType("octal");
	Number::instance()->setValue(64);
	cout<<"\n Value is: "<<Number::instance()->getValue()<<endl;

	return 0;
}
	


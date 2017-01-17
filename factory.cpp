#include<iostream>

using namespace std;

class shape{
	public:
		shape()
		{
			id_ = total_++;
		}
		virtual void draw() = 0;
	protected:
		int id_;
		static int total_;
};
int shape::total_ = 0;

class circle : public shape {
	public:
		void draw()
		{
			cout<<"\n circle "<<id_<<" draw"<<endl;
		}
};

class square : public shape {
        public:
                void draw()
                {
                        cout<<"\n square "<<id_<<" draw"<<endl;
                }
};

class ellipse : public shape {
        public:
                void draw()
                {
                        cout<<"\n ellipse "<<id_<<" draw"<<endl;
                }
};

class rectangle : public shape {
        public:
                void draw()
                {
                        cout<<"\n rectangle "<<id_<<" draw"<<endl;
                }
};

class factory {
	public:
		virtual shape* createcurvedinstance() = 0;
		virtual shape* createstraightinstance() = 0;
};

class simpleshapefactory : public factory {
	public:
		shape* createcurvedinstance() {
			return (new circle);
		}
		shape* createstraightinstance() {
			return (new square);
		}
};

class robustshapefactory : public factory {
	public:
		shape* createcurvedinstance() {
			return (new ellipse);
                }
                shape* createstraightinstance() {
			return (new rectangle);
		}
};

int main()
{
	factory* fac_s = new simpleshapefactory;
	factory* fac_r = new robustshapefactory;

	shape* shapes[3];

	shapes[0] = fac_s->createcurvedinstance();
	shapes[1] = fac_s->createstraightinstance();
	shapes[2] = fac_r->createstraightinstance();

	for(int i = 0 ; i < 3; ++i)
	{
		shapes[i]->draw();
	}
}

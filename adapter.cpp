#include<iostream>

using namespace std;

typedef int coordinate;
typedef int dimension;

class rectangle
{
	public:
		virtual void draw() = 0;
};

class Legacyrectangle
{
	public:
		Legacyrectangle(coordinate x1, coordinate y1, coordinate x2, coordinate y2) : _x1(x1), _y1(y1), _x2(x2), _y2(y2)
		{
			cout << "LegacyRectangle:  create.  (" << _x1 << "," << _y1 << ") => ("<< _x2 << "," << _y2 << ")" << endl;
		}
		void old_draw()
		{
			cout << "LegacyRectangle:  oldDraw.  (" << _x1 << "," << _y1 <<") => (" << _x2 << "," << _y2 << ")" << endl;
		}
	private:
		coordinate _x1;
		coordinate _y1;
		coordinate _x2;
		coordinate _y2;
};

class rectangleAdapter : public rectangle, public Legacyrectangle
{
	public:
		rectangleAdapter(coordinate x, coordinate y, dimension w, dimension h): Legacyrectangle(x, y, x+w, y+h)
		{
			cout << "RectangleAdapter: create.  (" << x << "," << y <<"), width = " << w << ", height = " << h << endl;
		}
		void draw()
		{
			cout<<"RectangularAdapter draw()"<<endl;
			old_draw();
		}
};

int main()
{
	rectangle *r = new rectangleAdapter(120, 200, 60, 40);
	r->draw();

	return 0;
}
			

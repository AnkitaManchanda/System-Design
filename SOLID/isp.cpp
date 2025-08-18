#include<iostream>
#include<vector>
#include<stack>
#include<math.h>
using namespace std;
class TwoD{
	public:
		virtual double area()=0;
};
class ThreeD{
	public:
		virtual double area()=0;
		virtual double volume()=0;
};
class Square:public TwoD{
	private:
		double side;
	public:
		Square(double side):side(side){
		}
		double area() override{
			return (side*side);
		}
};
class Rectangle:public TwoD{
	private:
		double l,b;
	public:
		Rectangle(double l,double b):l(l),b(b){
		}
		double area() override{
			return (l*b);
		}
};
class Cuboid:public ThreeD{
	private:
		double l,b,h;
	public:
		Cuboid(double l,double b,double h):l(l),b(b),h(h){
		}
		double area() override{
			return 2*(l*b+b*h+h*l);
		}
		double volume() override{
			return l*b*h;
		}
};
class Cube:public ThreeD{
	private:
		double l;
	public:
		Cube(double l):l(l){
		}
		double area() override{
			return 6*l*l;
		}
		double volume() override{
			return pow(l,3);
		}
};
int main(){
    return 0;
}

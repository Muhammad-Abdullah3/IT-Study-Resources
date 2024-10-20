#include<iostream>
using namespace std;
class Shape{
	public:
	 double getArea(){
			return 0;
	}
};
class Circle : public Shape{
	public:
	double getArea(double r){
		double area = 3.14*(r*r);
		return area;
	}
}; 
class Rectangle : public Shape{
	public:
	double getArea(double length, double width){
		double result = length* width;
		return result;
	}
}; 
int main(){
    Shape* shapes[2];
    
	double r,l,w;
	cout<<"Enter the radius to calculate the area of CIRCLE: ";
	cin>>r;
	//Circle obj1;
    shapes[0]=new Circle();
	//double result = obj1.getArea(r);
    double result = ((Circle*)shapes[0])->getArea(r);
    cout<<"Area Of Circle is : "<<result<<endl<<endl;
	cout<<"Enter the length to calculate the area of RECTANGLE : ";
	cin>>l;
	cout<<"Enter the width to calculate the area of RECTANGLE : ";
	cin>>w;
	//Rectangle obj2;
    shapes[1]=new Rectangle();
	//double Result = obj2.getArea(l,w);
    double Result = ((Rectangle*)shapes[1])->getArea(l,w);
	cout<<"Area Of Rectangle is : "<<Result<<endl<<endl;
	return 0;
}
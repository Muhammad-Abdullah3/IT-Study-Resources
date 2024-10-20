#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Shape {
    double getArea() {
        return 0;
    }
};

class Circle: public Shape {
    private:
    double radius;
    public:
    void setPerimeter() {
        double rad;
        cout<<"Enter Radius for Circle: ";
        cin>>rad;
        radius = rad;
    }
    double getArea() {
    return 3.14*radius*radius;
    }
};

class Rectangle: public Shape {
    private:
    double length, width;
    public:
    void setPerimeter() {
        double len;
        cout<<"Enter Length for Rectangle: ";
        cin>>len;
        length = len;
        double wid;
        cout<<"Enter Width for Rectangle: ";
        cin>>wid;
        width = wid;
    }
    double getArea() {
        return (double) length*width;
    }
};

int main() {
    vector<Shape*> shapes;
    //vector<Circle> circles;
    //vector<Rectangle> rectangles;
    int n;
    cout<<"Enter number of shapes to find area of: ";
    cin>>n;
    for(int i = 0; i < n; i++) {
        int choice;
        cout<<"Enter even for Circle, odd for Rectangle: ";
        cin>>choice;
        //shapes.push_back(choice%2==0 ?  new Circle(): new Rectangle());
        if(choice%2==0) {
            shapes.push_back(new Circle());
            ((Circle*)shapes[i])->setPerimeter();
            cout<<"Area of Circle "<<i+1<<": "<<((Circle*)shapes[i])->getArea()<<endl;
        }
        else {
            shapes.push_back(new Rectangle());
            ((Rectangle*)shapes[i])->setPerimeter();
            cout<<"Area of Rectangle "<<i+1<<": "<<((Rectangle*)shapes[i])->getArea()<<endl;
        }
    }
    /*cout<<"\n\t\t\t\tArea of Circles: \t\t\t\t\n";
    for(int i=0;i<circles.size();i++) {
        cout<<"Area of Circle "<<i+1<<": "<<circles[i].getArea()<<endl;
    }
    cout<<"\n\t\t\t\tArea of Rectangles: \t\t\t\t\n";
    for(int i=0;i<rectangles.size();i++) {
        cout<<"Area of Rectangle "<<i+1<<": "<<rectangles[i].getArea()<<endl;
    }*/
    return 0;
}
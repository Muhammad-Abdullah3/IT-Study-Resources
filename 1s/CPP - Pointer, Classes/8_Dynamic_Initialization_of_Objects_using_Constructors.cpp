// is program mein ham dekhenge ke aik object ko ham dynamically kese initialize kar 
// sakte hain using constructors
#include<iostream>
#include<string>
using namespace std;
// First way ham new keyword se use karenge and second ham constructors se
class Car {
    private:
    string color;
    int speed;
    public:
    // yahan tu simple class banani hai without a paremeterized constructor
    Car() {
        color = "Red";
        speed = 150;
    }
    // yahan ham paremeterized constructor banayenge
    Car(string c, int s): color (c),speed (s) {}
    void display() {
        cout << "Color: " << color << endl;
        cout << "Speed: " << speed << endl;
    }
};
// ab main mein ham dono ways dekhenge
int main() {
    // dynamic allocation se pehle simple allocation with default constuctor
    Car c1;// default constructor chalega aur default values store karwa dega
    c1.display();
    Car c2;
    // first dekhenge parameterized constructor se kese run time mein aik object ko 
    // values pass hoti hain
    string color; int speed;
    cout<<"Enter Color of the car: ";
    getline(cin,color);
    cout<<"Enter speed limit of the car: ";
    cin>>speed;
    c2 = Car(color,speed);// ab pehle run tme pe 2 values ham user se enter karwayenge aur 
    // uske bad ham c2 object ko allocate karenge jabke wo initialize pehle se ho chuka hai
    c2.display(); // ab ham isko run time pe memory mil rahi hai

    // ab ham new keyword use karenge aur ham aise hi delete bhi kar sakte aik object ko
    Car* c3 = new Car();
    // new keyword ke sath jab hamne koi object ko create karna hu to pointer use karte hain
    c3->display();// because hamne pointer use kia so ham -> operator se access karenge class members ko
    // ab ham delete karte hain c3 ko
    delete c3; // ab c3 ke sare objects meaning variable ki memory delete ho jayegi (deallocate)
    // ab c3 mein ham parameterized constructor use karke new values store karwa denge
    c3 = new Car("Blue",200);
    c3->display(); 
    // is program mein dekha ke ham aik hi object ke andar ke memory ko allocate aur de allocate 
    // kese kar sakte hain runtime mein
    return 0;
}

#include<iostream>
#include<string>
using namespace std;

// is program mein ham previous program ki tarah intialize karwana sekhenge but parameters 
// ke sath

#include<iostream>
#include<string>
using namespace std;
// is program mein constructor ke 2 mukhtalif tareeke se use karna explain kia gaya hai
class Calculator1 {
    private:
    int num1;
    int num2;
    public:
    // constructor 1 jo ham simple tareeke se banayenge
    Calculator1(int a,int b) {
        num1 = a;
        num2 = b; 
    }
    // addition
    void add() {
        cout<<"Addition of num1 and num2 = "<<num1+num2<<endl;
    }
};
class Calculator2 {
    private:
    float num1;
    float num2;
    public:
    // constructor 2 jo ham different tareeke se banayenge, is constructor mein bhi ham
    // values ko intialize karwayenge
    Calculator2(float a,float b): num1 (a) , num2 (b) {}
    // ye basically jo kam kar raha hai wo is tarah ka hai
    // num1 = a
    // num2 = b
    // so agar colon laga ke uske bad variables ko is tarah initialize karte hain and 
    //(,) comma hamen show karta hai ke ye aik line khatam ho chuki hai
    // is tarah ham ek constructor ko 2 mukhtalif tareeke se likh sakte hain
    // ab add ka funciton
    void sum() {
        cout<<"Addition of num1 and num2 = "<<num1+num2<<endl;
    }
};

int main() {
    Calculator1 c1(19,31);
    Calculator2 c2(50.2,123.5);
    c1.add();
    c2.sum();
    return 0;
}
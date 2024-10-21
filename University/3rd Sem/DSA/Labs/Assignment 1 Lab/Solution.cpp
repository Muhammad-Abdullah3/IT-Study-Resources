#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
// I like to play with pointers so I'll use them excessively
class IceCreamShake {
    private:
    string flavour;
    int scoops;
    float volume,calories;
    bool fruitToping;
    float totPrice;
    public:
    // Parameterized constructor
    
    /*IceCreamShake(string t,int s,float vol,float cal,bool top) :
    flavour(t), scoops(s), volume(vol), calories(cal), fruitToping(top) {}*/


    // I'm changing the parameterized Constructors to my thinking and that is only give it
    // three parameters flavour,scopes and toping . Because we can calculate the remaining 
    // two with scoops
    IceCreamShake(string t,int s,bool top) :
    flavour(t), scoops(s), volume(75*scoops), calories(100*scoops), fruitToping(top) {}
    // If parameterized constructor is not used then and only then we will use setter methods
    void setFlavour(string s) { flavour = s;}
    void setScoops(int s) { scoops = s;}
    void setVolume() { volume = 75*scoops;}
    void setCalories() { calories = 100*scoops;}
    void setFruitTopping(bool top) { fruitToping = top;}
    // Getter for every variable
    string getFlavour() { return flavour; }
    int getScoops() { return scoops; }
    float getVolume() { return volume; }
    float getCalories() {return calories;}
    bool getTopping() { return fruitToping;}
    // Add scoop function
    void addScoops() { 
        if(scoops<=6) {
            scoops = scoops + 1;
            volume = volume+75;
            this->calories = this->calories+100;
        }
        else {
            cout<<"You can't add more scoops because you have already 6 scoops.";
        }
    }

    // Now we will drink our iceCreamShake or eat it? I'm confused
    void takeSip() {
        this->volume = this->volume-5;
    }
    // Have you finished (drinking) ,.... (eating ) your shake? I'm still confused
    // mam please give me this answer
    bool isEmpty() {
        return this->volume <= 0? true:false;// Ternary condition sure taste good
    }
    // Now you have eaten let's discuss about the price, friend.
    float calculatePrice() {
        if(flavour=="Chocolate") {
            this->totPrice = 60*this->scoops;// This keyword is used because I was bored
        }
        else if(flavour=="Vanilla") {
            this->totPrice = 50*this->scoops;
        }  
        else if(flavour=="Strawberry") {
            this->totPrice = 80*this->scoops;
        }
        else {
            this->totPrice = 100*this->scoops;
        }
        this->totPrice = this->fruitToping ? totPrice+150:totPrice+0;
        // Above line is so you don't get bored
        return this->totPrice;
    }
};
// display menu function is from my side to you
    void displayMenu() {
        cout<<"\t\t\t\t\tMenu"<<endl;
        cout<<"1- Chocolate....................../- 60 (Scoop)"<<endl;
        cout<<"2- Vanilla........................./- 50 (Scoop)"<<endl;
        cout<<"3- Strawberry...................../- 80 (Scoop)"<<endl;
        cout<<"4- Special........................./- 100 (Scoop)"<<endl;// other would look bad
        // This is business
    }
// Now the main course of code
int main() {
    IceCreamShake* shake;
    string fl;int sc;bool frTop;int choice;
    cout<<"\t\t\t\t\tWelcome to Ice Cream Shake shop"<<endl;
    cout<<"\t\t\t\t\t----------------------------------------"<<endl;
    displayMenu();
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
    switch(choice) {
        case 1:
            fl="Chocolate";
            break;
        case 2:
            fl="Vanilla";
            break;
        case 3:
            fl="Strawberry";
            break;
        case 4:
            fl="Special";
            break;
        default:
            fl = "Chocolate"; // because kids like it you know
    }
    cout<<"How many sccops would you like? "<<endl;
    cin>>sc;
    cout<<"Would you like fruit topping? "<<endl;
    cout<<"Press Y/y for yes and any other for no"<<endl;
    char fr;
    cin>>fr;
    frTop = fr=='Y'||fr=='y'? true:false;
    // now we will call object with parameterized constructor
    shake = new IceCreamShake(fl,sc,frTop);
    cout<<"Want another scoop?"<<endl;
    cout<<"Press Y/y for yes and any other for no"<<endl;
    char anSc;
    cin>>anSc;
    if(anSc=='Y'||anSc=='y') 
        shake->addScoops();// I decisively didn't use brackets
    float totVol = shake->getVolume();
    while(!shake->isEmpty()) {
        shake->takeSip();
    }
    cout<<"\t\t\t\t------Your Bill------"<<endl;
    cout<<"Flavour: "<<shake->getFlavour()<< endl;
    cout<<"Scoops: "<<shake->getScoops()<<endl;
    cout<<"Total Calories: "<<shake->getCalories()<<endl;
    cout<<"Fruit Topping: "<<(shake->getTopping() ? "Yes\n":"No\n");
    cout<<"Total Volume: "<<totVol<<endl;
    cout<<"Price of Shake: "<<shake->calculatePrice();
    delete shake;
    getch();
    return 0;
}
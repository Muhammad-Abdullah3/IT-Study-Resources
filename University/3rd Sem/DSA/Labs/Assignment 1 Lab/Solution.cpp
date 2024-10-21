#include<iostream>
#include<string>
using namespace std;
// I like to play with pointers so I'll use them excessively
class IceCreamShake {
    private:
    string flavour;
    int scoops;
    float volume,calories;
    bool fruitToping;
    public:
    // Parameterized constructor
    
    /*IceCreamShake(string t,int s,float vol,float cal,bool top) :
    flavour(t), scoops(s), volume(vol), calories(cal), fruitToping(top) {}*/


    // I'm changing the parameterized Constructors to my thinking and that is only give it
    // three parameters flavour,scopes and toping . Because we can calculate the remaining 
    // two with scoops
    IceCreamShake(string t,int s,float vol,float cal,bool top) :
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
        
    }
};
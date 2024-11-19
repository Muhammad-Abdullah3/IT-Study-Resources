// is program mein aik object ko ham as a function ka argument pass karenge
#include<iostream>
#include<string>
using namespace std;
// sabse pehle aik class bana lete hain let's say ke customer ki class hai
class Customer {
    // yahan  double type ke items ka bill hoga
    double bill;
    private:
    // ab bill ke set get function honge
    public:
    void setBill(double bi) {
        bill = bi;
        }
    double getBill() {
        return bill;
    }
    // abhi let's say ke aik banda hai wo chahta hai ke wo apne dost ka bhi bill pay kare
    // dono restaurant mein gaye the individually but aik dost dikh gaya tu ab jo dost a hai
    // wo dost b ka bhi bill pay karna chahta hai
    // uske liye aik function bana lete hain
    double combinedBill(Customer cust) {
        // yahan hum dono customer ka bill add karenge
        // isi object ka bill
        double localBill = this->getBill();
        // aur dost ka bill
        double friendBill= cust.getBill();
        return localBill+friendBill;
    }
};

int main() {
    Customer c1, c2;
    // ab c1 ka bill 1000 hai aur c2 ka bill 2000 hai
    c1.setBill(1000);
    c2.setBill(2000);
    // ab c1 ka bill 3000 hai because wo hi c2 ka bill pay kar raha hai
    cout<<"Total Bill of Customer: "<<c1.combinedBill(c2);
    return 0;

}
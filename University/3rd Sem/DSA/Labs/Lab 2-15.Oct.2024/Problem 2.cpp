#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CustomerData {
private:
    int customerNumber;
    string customerName;
    string customerAddress;
    bool mailingList;
    string mailingAddress;

public:
    
    CustomerData() {
        customerNumber = 0; 
        customerName = ""; 
        customerAddress = "";
        mailingList = false;
        mailingAddress = "";
    }

    
    CustomerData(int num, string name, string address, bool mailingListStatus, string mailingAddr) {
        customerNumber = num;
        customerName = name;
        customerAddress = address;
        mailingList = mailingListStatus;
        mailingAddress = mailingAddr;
    }

    
    int getCustomerNumber() {
        return customerNumber;
    }

    string getCustomerName()  {
        return customerName;
    }

    string getCustomerAddress()  {
        return customerAddress;
    }

    bool getMailingList()  {
        return mailingList;
    }

    string getMailingAddress()  {
        return mailingAddress;
    }

    
    void setMailingList(bool status) {
        mailingList = status;
    }

    void setMailingAddress(string address) {
        mailingAddress = address;
    }
};


class PreferredCustomer : public CustomerData {
private:
    double purchasesAmount;
    double discountLevel;

    
    void setDiscountLevel() {
        if (purchasesAmount >= 2000) {
            discountLevel = 0.10;
        } else if (purchasesAmount >= 1500) {
            discountLevel = 0.07;
        } else if (purchasesAmount >= 1000) {
            discountLevel = 0.06;
        } else if (purchasesAmount >= 500) {
            discountLevel = 0.05;
        } else {
            discountLevel = 0.0;
        }
    }

public:
    
    PreferredCustomer() : CustomerData() {
        purchasesAmount = 0;
        discountLevel = 0;
    }

    
    PreferredCustomer(int num, string name, string address, bool mailingListStatus, string mailingAddr, double purchases)
        : CustomerData(num, name, address, mailingListStatus, mailingAddr), purchasesAmount(purchases) {
        setDiscountLevel();
    }

    
    double getPurchasesAmount()  {
        return purchasesAmount;
    }

    double getDiscountLevel()  {
        return discountLevel;
    }

    double getDiscountAmount()  {
        return purchasesAmount * discountLevel;
    }

    
    void displayCustomerDetails()  {
        cout << "Number: " << getCustomerNumber() << endl;
        cout << "Name: " << getCustomerName() << endl;
        cout << "Address: " << getCustomerAddress() << endl;
        cout << "Mailing List: " << (getMailingList() ? "Yes" : "No") << endl;
        cout << "Mailing Address: " << getMailingAddress() << endl;
        cout << "Total Purchases: $" << purchasesAmount << endl;
        cout << "Discount Level: " << (discountLevel * 100) << "%" << endl;
        cout << "Discount Amount: $" << getDiscountAmount() << endl;
    }
};

int main() {
    vector<PreferredCustomer> customers;

    
    customers.push_back(PreferredCustomer(1, "Muhammad Abdullah", "D.I.Khan", true, "abdullah@gmail.com", 2100));
    customers.push_back(PreferredCustomer(2, "Waheed Akhtar", "Gujrat", true, "waheed@gmail.com", 1500));
    customers.push_back(PreferredCustomer(3, "Faizan Umer", "Lahore", false, "faizan@gmail.com", 1200));

    
    for (int i = 0; i < customers.size(); i++) {
        cout << "\n\t\t\tCustomer " << i + 1 << " Details:\n";
        customers[i].displayCustomerDetails();
    }

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class CustomerData {
private:
    int *customerNumber = new int[3];
    string *customerName = new string[3];
    string *customerAddress = new string[3];
    bool *mailingList = new bool[3];
    string *mailingAddress = new string[3];

public:
    CustomerData() {
        
        for (int i = 0; i < 3; i++) {
            customerNumber[i] = 0;
            customerName[i] = "";
            customerAddress[i] = "";
            mailingList[i] = false;
            mailingAddress[i] = "";
        }
    }


    void setCustomerData(int num, string name, string address) {
        customerNumber[num] = num;
        customerName[num] = name;
        customerAddress[num] = address;
    }

    int getCustomerNumber(int index) {
        return customerNumber[index];
    }

    string getCustomerName(int index) {
        return customerName[index];
    }

    string getCustomerAddress(int index) {
        return customerAddress[index];
    }

    bool getMailingList(int index) {
        return mailingList[index];
    }

    string getMailingAddress(int index) {
        return mailingAddress[index];
    }

    void setMailingList(int index, bool status) {
        mailingList[index] = status;
    }

    void setMailingAddress(int index, string address) {
        mailingAddress[index] = address;
    }
};

int main() {
    
    CustomerData customerData;

    
    customerData.setCustomerData(0, "Muhammad Abdullah", "D.I.Khan");
    customerData.setCustomerData(1, "Waheed Akhtar", "Gujrat");
    customerData.setCustomerData(2, "Faizan Umer", "Lahore");

    
    cout << "\t\t\t\tCustomer 1" << endl;
    cout << "Number: " << customerData.getCustomerNumber(0) << endl;
    cout << "Name: " << customerData.getCustomerName(0) << endl;
    cout << "Address: " << customerData.getCustomerAddress(0) << endl;
    cout << "Mailing List: " << (customerData.getMailingList(0) ? "Yes" : "No") << endl;
    cout << "Mailing Address: " << customerData.getMailingAddress(0) << endl;

    customerData.setMailingList(1, true);
    customerData.setMailingAddress(1, "maabdullah.rhs@gmail");


    cout << "\n\t\t\t\tCustomer 2:" << endl;
    cout << "Number: " << customerData.getCustomerNumber(1) << endl;
    cout << "Name: " << customerData.getCustomerName(1) << endl;
    cout << "Address: " << customerData.getCustomerAddress(1) << endl;
    cout << "Mailing List: " << (customerData.getMailingList(1) ? "Yes" : "No") << endl;
    cout << "Mailing Address: " << customerData.getMailingAddress(1) << endl;
    return 0;
}
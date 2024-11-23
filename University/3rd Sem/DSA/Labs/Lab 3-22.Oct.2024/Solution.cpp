/*#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

// Creating a class
class Student {
    private:
    string name,uniName,className;
    int rollNum;
    public:
    // Default Constructor
    Student(): name (""),rollNum(0),uniName(""),className("") {}
    // Parameterized Constructor
    Student(string n, int r, string u, string c): name(n),rollNum(r),uniName(u),className(c) {}
    //Copy Constructor
    Student(Student &s): name(s.name),rollNum(s.rollNum),uniName(s.uniName),className(s.className) {}
    // Display Function of All Details
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNum << endl;
        cout << "University Name: " << uniName << endl;
        cout << "Class Name: " << className << endl;
    }
};

int main() {
    // Creating an object of Student class with default Constructor
    Student s1;
    cout<<"\t\t\tDetails of Student 1"<<endl;
    s1.displayDetails();
    cout<<"\n\n";
    cout<<"\t------------------------------------------------------------------"<<endl;
    // Creating an object of Student class with Parameterized Constructor
    Student* s2;
    s2 = new Student("Muhammad Abdullah", 53457, "Riphah International University", "DSA");
    cout<<"\t\t\tDetails of Student 2"<<endl;  
    s2->displayDetails();
    cout<<"\n\n";
    cout<<"\t------------------------------------------------------------------"<<endl;
    // Creating an object of Student class with Copy Constructor
    Student s3;
    s3 = new Student(*s2);
    cout<<"\t\t\tDetails of Student 3"<<endl;
    s3->displayDetails();
    cout<<"\n\n";
    cout<<"\t------------------------------------------------------------------"<<endl;
    getch();
    return 0;
}*/

/*#include<iostream>
using namespace std;
void bubblesort(int arr[]){
	for(int i=0;i<5-1;i++){
		for(int j=0;j<5-i-1;j++){
		if(arr[j]>arr[j+1]){
		int temp;
		temp=arr[j];
		arr[j]=arr[j+1];
		arr[j+1]=temp;
		}
	}
}
}
int main(){
	int arr[5]={2,5,7,1,3};
     bubblesort( arr);
	cout<<"Sorting Array is : { ";
	for(int i=0;i<5;i++){
		cout<<arr[i]<<"  ";
	}
	cout<<" }";
	
	return 0;
}*/

/*#include<iostream>
using namespace std;
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                arr[j] = key;
            } else {
                break; // Exit loop once the correct position is found
            }
        }
    }
}

}
int main(){
	int arr[5]={9,5,-1,4,3};
     insertionsort( arr);
	cout<<"Sorting Array is : { ";
	for(int i=0;i<5;i++){
		cout<<arr[i]<<"  ";
	}
	cout<<" }";
	
	return 0;
}*/
/*#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = size - 1; // Set minimum to the last index initially
        for (int j = size - 1; j > i; j--) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update the index of the minimum element
            }
        }
        // Swap the found minimum with the element at index `i`
        if (arr[minIndex] < arr[i]) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int arr[] = {20, 12, 10, 15, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, size);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}*/
#include<iostream>
using namespace std;
void selectionsort(int arr[5]){
	for(int i=0;i<5;i++){
		int min=i;
		for(int j=i+1;j<5;j++){
			  if (arr[j] < arr[min]){
			min=j;
			  }
		}
		if(min!=i){
			swap(arr[i],arr[min]);
		}
	}	
}
int main(){
	int arr[5]={2,9,5,3,1};
	selectionsort(arr);
	cout<<"Sorted array is : { ";
	for (int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<" }";
	
	return 0;
}


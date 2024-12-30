#include<iostream>
#include<string>
using namespace std;
int main(){

char  arr[3][4]={{'A','C','A','T'},{'S','O','U','H'},{'A','D','E','E'}};
cout<<"Grid is "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
        cout<<arr[i][j]<<"  ";
        }
    cout<<endl;
    }
string word;
cout<<"Enter a word : ";
getline(cin,word);
int indexArr[word.length()] = {0};
int wordIndex = 0;
bool wordFound = false;
for(int i=0;i<3;i++){
    wordFound=false;
    for(int j=0;j<4;j++){  
        if(j==indexArr[wordIndex]) {
            continue;
        }
        if(arr[j]==word.at(j)) {
            indexArr[wordIndex] = j;
            wordIndex++;
            wordFound = true;
            break;
        }
        if(!wordFound) {
            cout<<"False";
            exit(0);
        }
    }

    cout<<endl;
}
if(wordFound)
{
    cout<<"True";
}
return 0;
}
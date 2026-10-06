//read file
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream file("India.txt");
    char ch;
    //char str[400];
    
    while(file.get(ch)){
        cout<<ch<<endl;
    }

    file.close();

}
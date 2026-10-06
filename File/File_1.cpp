//write file
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream file;//ofstream means output fiwe want to write data into file
    file.open("Student.txt",ios::app);//if student file dle stream, when oesnt exist then created. with normal ofstream. 
    //existing content ovewritten 
    if(!file){//here check file is perfectly open or not 
        cout<<"File not opend!";
        return 1;
    }

    file<<"\nRoll N0: 401";
    file<<"\nName : Ravi";//writes data into opend file
    file<<"\nMarks: 64.4";

    file.close();//always close after writing file
    cout<<"Data written successfully";

    return 0;
}
#include <iostream>

#include<cstring>

using namespace std;
int main() {

    string s1("kamal");

    string s2 = "Hello world";

    string s3 = s2;


    char a[] = {'a' ,'b','c','d','e' ,'\0'};

    string s4(a);


    cout<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl;

    s1 = s1 + s3;
    cout<<s1;

    s2.clear();

    cout<<s2<<endl<<s3<<endl;
 
}

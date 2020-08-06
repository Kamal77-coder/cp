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
 //string basics part 2
#include <iostream>

#include<cstring>

using namespace std;
int main() {

     string s1,s2;

     s1 = "apple";
     s2 = "mango";
 
     cout<<s1.compare(s2)<<endl;  //-12 

     cout<<s2.compare(s1)<<endl; //12

     cout<<s1.compare(s1)<<endl; //0

     //< and > are overloaded on strings
 
      //finding substrings

      string s6 = "I love apple and mang0";

      int idx = s6.find("apple");  //starting index of word apple is 7
      cout<<idx<<endl;

      string word = "apple";
      
      int len = word.length();
      s6.erase(idx , len);  

      cout<<s6<<endl;  //I love  and mang0

      //iterating all the characters of string

      for(char ch : s6)
      cout<<ch;

      cout<<endl;

      //iterating using iterators

      for(auto it = s6.begin() ; it!= s6.end() ;it++)
      cout<<*it;
}

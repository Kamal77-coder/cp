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
      //iterators are defined for a class to declare an iterator the syntax would be
    
      string :: iterator it;
      //iterating using iterators

      for(auto it = s6.begin() ; it!= s6.end() ;it++)
      cout<<*it;
}
 //part 3 string sorting
#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
int main() {
  
    vector<string> dict = {"kamal" ,"rohilla","mukul" ,"aman","ksmad"};

    sort(dict.begin() ,dict.end() , [](string a ,string b)
    {
        return a<b ;
    });

    for(string x : dict) 
    /*aman
    kamal
    ksmad
    mukul
    rohilla */
     cout<<x<<endl;

     //comparing on the basis of lenght
    sort(dict.begin() ,dict.end() , [](string a ,string b)
    {
        if(a.length() == b.length())return a>b;
        return a.length()<b.length() ;
    });

    for(string x : dict) 
     cout<<x<<endl;

}

//string basic part 3 : string tokeniser
#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
int main() {
  
   //string tokenisation

   //char* strtok(char* s ,char* delimitter)
   //returns token on each subsequent call
   //on the first call function should be passed with string arguemnet for 's'
   //on subsequent calls we should pass the string as NULL

   //example:


   char s[] = "today is a rainy day";

   cout<<s<<endl;   //today is a rainy day

    /*char* ptr = strtok(s , " "); //delimitter is space in this case

   cout<<ptr<<endl;  //today

   ptr = strtok( NULL , " ");  //is
   cout<<ptr<<endl ;

   ptr = strtok( NULL , " ");  //a
   cout<<ptr<<endl ;  */

   //or simply we could do this

   
   char *ptr = strtok( s , " ");         

   while(ptr != NULL)
   {
       cout<<ptr<<endl;
       ptr = strtok(NULL , " ");
   }

/*today is a rainy day
today
is
a
rainy
day*/

}
//part 4 :Our own string tokeniser implimentation

#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

char* mystrtok(char* s ,char delim)
{
    //string and single char act as NULL

    static char *input = NULL;

    if( s!= NULL) 
    {
        //we aree making the first call
        input = s;
    }
    //base case 
    //after the final token has been returned

    if(input == NULL)
     return NULL;
    //start extracting the tokens and store them in an array
    //we want this memory to exist even after the function call is over

    char* output = new char[strlen(input)+1];
   
   int i;
   for(i=0 ;input[i] != '\0' ;i++)
   {
      if(input[i] != delim)
      {
          output[i] = input[i];
      }
      else
      {
          output[i] ='\0';
          input = input + i +1 ;  //we want to jump to the next character after delimitter
          return output;
      }
   }
   
   //corner case when the last token does not have delimitter

   output[i] = NULL;
   input = NULL;
   return output;


}
int main() {
  
  //Designing our own string tokeniser
  char s[] = "today is a rainy day";

  char* ptr = mystrtok( s ,' ');

  while(ptr != NULL)
  {
      cout<<ptr<<"\n";

      ptr = mystrtok(NULL , ' ');
  }

}

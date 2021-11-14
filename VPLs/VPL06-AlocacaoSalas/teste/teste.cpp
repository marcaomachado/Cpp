// list::begin
#include <iostream>
#include <list>


using namespace std;
int main ()
{
//   int myints[] = {75,23,65,42,13};
//   std::list<int> mylist (myints,myints+5);

//   std::cout << "mylist contains:";
//   for (std::list<int>::iterator it=mylist.begin(); it != mylist.end(); it++)
//     std::cout << " " << *it;

//   std::cout << std::endl;
    string nanda ="nanda";
    string marco = "marco";
    string jussara = "jussara";

    list<string> nomes = {nanda, marco, jussara};

    // for(list<string>::iterator it = nomes.begin(); it!= nomes.end(); it++){
    //     cout<< *it << endl;
    // }

    nomes.sort([] (string a, string b){return a.compare(b) < 0;});

    for(list<string>::iterator it = nomes.begin(); it!= nomes.end(); it++){
        cout<< *it << endl;
    }


    return 0;
}
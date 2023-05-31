#include <iostream>
#include "Automatom.h"
using namespace std;



void test (){
    string w = "a12dd";
    vector<char> values1 = {'0','1','2','3'};
    vector<char> values2 = {'a','b','c','d'};
    vector<char> values3 = {'.',};
    vector<char> values4 = {'-',};
    vector<char> values5 = {'0','1','2','3','a','b','c','d'};
    vector<char> values6 = {' ',};



    Automatom automata;
    automata.addState(0, "Espacio");
    automata.addState(1, "Entero");
    automata.addState(2, "Double");
    automata.addState(3, "Identificador");
    automata.addState(4, "");


    // q0 ->

    automata.addTransition(0,0,values6);
    automata.addTransition(0,1,values1);
    automata.addTransition(0,3,values2);
    automata.addTransition(0,4,values4);

    // q1 ->
    automata.addTransition(1,1,values1);
    automata.addTransition(1,2,values3);



    // Q2 ->
    automata.addTransition(2,2,values1);


    // Q3 ->
    automata.addTransition(3,3,values5);

    // Q4 ->
    automata.addTransition(4,1,values1);

    if(automata.test(w))
        cout<< "successfull" << endl;
    else
        cout<< "error" << endl;

}

int main()
{

    string w = "a12dd  233.41 434.23 -2323 abc a -12 1 d";


    test();

    return 0;
}

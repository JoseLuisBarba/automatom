#ifndef AUTOMATOM_H
#define AUTOMATOM_H
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Transition{
    public:
        Transition(int next, vector<char> values){
            this->next = next;
            this->values = values;
        }

        /**
         * @brief agrega un valor en la losta de valores de la transición.
         * @param value El valor que se agregar.
         * @return NULL
         */
        void addValue(char value){
            if (!this->existsInVector(value))
                this->values.push_back(value);
        }
        /**
         * @brief Busca la existencia de  un valor dentro de los valores de transición. O(logn)
         * @param value El valor que se desea buscar.
         * @return true si encuentra el valor, sino, false
         */
        bool existsInVector(char value){
            return find(this->values.begin(), this->values.end(), value) != this->values.end();
        }
        int next;
        vector<char> values;
};




class Automatom
{
    public:
        Automatom();
        /**
         * @brief Agrega un estado al automata
         * @param number Es el numero del estado
         * @param type 1 si es estado final, de lo contrario 0
         * @return NULL
         */
        void addState(int number, string type){
            this->states.push_back(number);
            this->types.insert({number, type});
            vector<Transition> x = {};
            this->graph.insert({number, x});
        }

        /**
         * @brief inserta una transición entre dos estados
         * @param initialState El estado inicial de la transición
         * @param finalState El estado final de la transición
         * @param values Lista de caracteres.
         * @return NULL
         */
        void addTransition(int initialState,int finalState, vector<char> values){
            if (!this->existsInVector(initialState)){
                this->addState(initialState, "");
                //this->types.insert({initialState, ""})
            }

            if (!this->existsInVector(finalState)){
                this->addState(finalState, "");
                //this->types.insert({finalState, ""})
            }

            Transition transition (finalState,values);
            this->graph[initialState].push_back(transition);
            //graph.insert({initialState, transition});
        }

        bool test(string text){
            this->currentState = this->states[0];
            int i = 0;

            while(i < text.length()){
                next:
                for (Transition transition : this->graph[this->currentState]){
                    if(transition.existsInVector(text[i])){
                        if (this->types[this->currentState] != "" && i == text.length() - 1){
                            this->currentState = transition.next; //siguiente estado
                            cout << this->types[this->currentState] << endl;
                            return true; // reconoce cadena
                        }
                        this->currentState = transition.next; //siguiente estado
                        i++;
                        cout << "check" << endl;
                        goto next; // salta al siguiente
                    }
                }
                return false;
            }
            return false;

        }

        virtual ~Automatom();

    protected:

    private:
        /**
         * @brief Busca la existencia de  un estado. O(logn)
         * @param state numero del estado a buscar su existencia dentro del vector states.
         * @return true si encuentra el estado, sino, false
         */
        bool existsInVector(int  state){
            return find(this->states.begin(), this->states.end(), state) != this->states.end();
        }
        int currentState;
        vector<int> states;
        map<int, vector<Transition> > graph;
        map<int, string> types;

};

#endif // AUTOMATOM_H

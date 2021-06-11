#ifndef NODE_
#define NODE_

#include <iostream>
#include <list>
#include <string>
using namespace std;

struct MyNode {
    public:
        /*
        Each Patient's Attributes :
        */
        // Priority
        int patient_priority;

        // ID & Name 
        string patient_id, patient_name;

        // Symptoms Shown
        list<string> patient_symptoms;

        /*
        Connection Between Nodes
        */
        MyNode* link;
};

#endif

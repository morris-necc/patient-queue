#ifndef _THE_NODE
#define _THE_NODE

#include <iostream>
#include <list>
#include <string>
using namespace std;

typedef struct node {
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
        node *link;
}MyNode;

#endif
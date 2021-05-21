#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "node.h"
using namespace std;

class priorityQueue {
    private:
        MyNode *front;
        MyNode *rear;
    public:
        priority_queue();
        ~priority_queue();
        bool isEmpty() const;

        // ???
        int calculate_priority();

        // insert patient data
        void insert_patient_records(const int& priority, const string& id, const string& name, const list<string>& symptoms);

        // Search and delete by referring to patient's name.
        void search_patient_records(string& name);
        void delete_patient_records(string& name);

        // Which patient to be treated right now ?
        myNode get_front();

        void print_contents();

        // Creates new .txt file for every time method is called.
        void write_to_txt() const;

        // Loads new data from txt file
        void load_from_txt(string& filename) const;
};

#endif

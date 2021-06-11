#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "priorityQueue.h"
using namespace std;
 
priorityQueue::priorityQueue(){
    front = nullptr;
    rear = nullptr;
}

priorityQueue::~priorityQueue(){
    // ptr is traverse pointer to node
    MyNode* ptr;
    MyNode* temp;
    ptr = front;
    while(ptr != nullptr){
        temp = ptr->link; //eventually temp = rear->link = nullptr
        delete ptr;
        ptr = temp; //which ends the loop because ptr = nullptr
    } //i think this will be the process that explains how the destructor method works.
}

int priorityQueue::calculate_priority(list<string> symptoms_list){
    //untested
    ifstream symptomsDatabase("symptoms.txt"); //open list of implemented symptoms
    map<string, int> symptomsPriority;
    int priority = 0;

    //puts every symptom and its corresponding priority into a map
    string text;
    while(getline(symptomsDatabase, text)){
        int last = 0;
        string arr[2];
        for(int i = 0; i < 2; i++){
            // Separate symptom and priority_val.
            arr[i] = text.substr(last, text.find(","));
            last++;
            last = last + arr[i].length();
        }
        // Cast priority_val to integer dtype using the method stoi(*args).
        symptomsPriority.insert(pair<string, int>(arr[0], stoi(arr[1]))); //stoi converts string to int
    }

    //calculate sum of priority based on the map
    for(auto it : symptoms_list){
        string symptom = it;
        auto x = symptomsPriority.find(symptom); //x = iterator for the element
        priority = priority + x->second; //don't know if this works
    }
    return priority;
}

void priorityQueue::insert_patient_records(const int& priority, const string& id, const string& name, const list<string>& symptoms){
    MyNode *temp;

    // Pointer Node.
    MyNode *q;

    // Creates New Node.
    temp = new MyNode;
    temp->patient_priority = priority;
    temp->patient_id = id;
    temp->patient_name = name;
    temp->patient_symptoms = symptoms;

    // Insert At Frontmost Position.
    if((front == nullptr) || (priority > front->patient_priority)){
        temp->link = front;
        front = temp;
    }
    else{
        q = front;
        // Linear Traversal To Compare To Each Node's Priority + Finding Position.
        while(q->link != nullptr){ //nullptr has no patient_priority
            if(priority > q -> link -> patient_priority){
                break;
            }
            q = q->link;
        }
        temp->link = q->link;
        q->link = temp;
    }
}

void priorityQueue::delete_patient_records(string& name){
    MyNode* ptr;
    MyNode* prev;
    ptr = front;
    prev = front;
    if(front == nullptr){
        cout << "QUEUE IS EMPTY" << endl;
    } else {
        // Linear search.
        while(ptr -> link != nullptr){
            ptr = ptr -> link;
            if(ptr -> patient_name == name){
                prev -> link = ptr -> link;
                delete ptr;
                break;
            }
            prev = prev -> link;
        }
    }
}

MyNode* priorityQueue::get_front(){
    //untested
    if(front == nullptr){
        cout << "QUEUE IS EMPTY" << endl;
    } else {
        return front;
    }
}

void priorityQueue::print_contents(){
    //untested
    MyNode* ptr;
    ptr = front;
    if(ptr == nullptr){
        cout << "The queue is empty" << endl;
    } else {
        while(ptr){
            cout << ptr -> patient_id << "\t";
            cout << ptr -> patient_priority << "\t";
            cout << ptr -> patient_name << "\t";
            for(string symptom: ptr->patient_symptoms){
                cout << symptom << ",";
            }
            cout << endl;
            ptr = ptr->link;
        }
        cout << endl;
    }
}

void priorityQueue::write_to_txt(){
    //untested
    //same logic as above, but writing to file instead
    //every attribute of the node is separated by ';' without quotation marks
    ofstream File("patients.txt"); //feel free to change the name later on
    MyNode* ptr;
    ptr = front;
    if(ptr == nullptr){
        cout << "The queue is still empty" << endl;
    } else {
        while(ptr){
            File << ptr -> patient_id << ";" << ptr -> patient_priority << ";" << ptr -> patient_name << ";";
            for (string symptom: ptr->patient_symptoms){
                File << symptom << ",";
            }
            File << endl;
            ptr = ptr -> link;
        }
    }
    File.close();

}

// Debug
void priorityQueue::load_from_txt(string& filename){
    //untested, most likely broken somewhere
    //clean the queue
    MyNode* ptr;
    MyNode* temp;
    ptr = front;
    while(ptr != nullptr){
        temp = ptr->link; //eventually temp = rear->link = nullptr
        delete ptr;
        ptr = temp; //which ends the loop because ptr = nullptr
    } //i think you can use this for the destructor method as well

    string text, text_symptoms;
    string temp_string = "";
    string arr[4];
    ifstream ReadFile(filename);
    ptr = new MyNode;
    front = ptr;
    while(getline(ReadFile, text)){
        temp = ptr;
        //substrings into array
        // int last = 0;
        // for(int i = 0; i<4; i++){
        //     arr[i] = text.substr(last, text.find(";"));
        //     last++;
        //     last = last + arr[i].length();
        // }
        int i = 0, last = 0;
        for(auto x: text){
            if(x == ';'){
                arr[i] = temp_string;
                temp_string = "";
                i++;
            } else {
                temp_string = temp_string + x;
            }
        }
        arr[i] = temp_string;
        temp_string = "";
        ptr -> patient_id = arr[0];
        ptr -> patient_priority = stoi(arr[1]);
        ptr -> patient_name = arr[2];
        text_symptoms = arr[3];
        //now split text_symptoms into elements inside a list
        list<string> list_symptoms;
        int start = 0;
        last = text_symptoms.find(","); //reuse the last
        while(last != -1){
            list_symptoms.push_back(text_symptoms.substr(start, last - start));
            start = last + 1;
            last = text_symptoms.find(",", start);
        }
        ptr -> patient_symptoms = list_symptoms;
        ptr = new MyNode;
        temp->link = ptr; //temp is used to link current node with new node
    }
    rear = temp;
    rear -> link = nullptr;
    delete ptr; //because the 2nd last line of the while loop
    ReadFile.close();
}

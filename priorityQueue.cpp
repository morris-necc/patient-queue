#include <iostream>
#include <fstream>
#include <map>
#include "priorityQueue.h"
using namespace std;

priorityQueue::priority_queue(){
    front = nullptr;
    rear = nullptr;
}

priorityQueue::~priority_queue(){
    MyNode* ptr, temp;
    ptr = front;
    while(ptr != nullptr){
        temp = ptr->link; //eventually temp = rear->link = nullptr
        delete ptr;
        ptr = temp; //which ends the loop because ptr = nullptr
    } //i think you can use this for the destructor method as well
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
        string[] arr = new string[2];
        for(int i = 0; i < 2; i++){
            arr[i] = text.substr(last, text.find(","));
            last = last + arr[i].length();
        }
        symptomsPriority.insert(pair<string, int>(arr[0], stoi(arr[1]))); //stoi converts string to int
    }

    //calculate sum of priority based on the map
    for(auto const& it : symptoms_list){
        string symptom = *it;
        auto x = symptomsPriority.find(symptom); //x = iterator for the element
        priority = priority + x->second; //don't know if this works
    }

    return priority;
}

void priorityQueue::insert_patient_records(const int& priority, const string& id, const string& name, const list<string>& symptoms){
    //empty
}

void priorityQueue::search_patient_records(string& name){
    //empty
}

void priorityQueue::delete_patient_records(string& name){
    //empty
}

myNode priorityQueue::get_front(){
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
        while(ptr!=rear){
            cout << ptr -> patient_id << "\t";
            cout << ptr -> patient_priority << "\t";
            cout << ptr -> patient_name << "\t";
            for(string symptom: ptr->patient_symptoms){
                cout << symptom << ",";
            }
            cout << endl;
            ptr = ptr->link;
        }
        // ptr = rear because rear->link is nullptr
        cout << ptr -> patient_id << "\t"; 
        cout << ptr -> patient_priority << "\t";
        cout << ptr -> patient_name << "\t";
        for(string symptom: ptr->patient_symptoms){
            cout << symptom << ",";
        }
        cout << endl;
    }
}

void priorityQueue::write_to_txt() const{
    //untested
    //same logic as above, but writing to file instead
    //every attribute of the node is separated by ';' without quotation marks
    ofstream File("test.txt"); //feel free to change the name later on
    MyNode* ptr;
    ptr = front;
    if(ptr == nullptr){
        cout << "The queue is still empty" << endl;
    } else {
        while(ptr != rear){
            File << ptr -> patient_id << ";" ptr -> patient_priority << ";" << ptr -> patient_name;
            for (string symptom: ptr->patient_symptoms){
                File << symptom << ",";
            }
            File << endl;
        }
        File << ptr -> patient_id << ";" ptr -> patient_priority << ";" << ptr -> patient_name;
        for (string symptom: ptr->patient_symptoms){
            File << symptom << ",";
        }
        File << endl;
    }
    File.close()

}

void priorityQueue::load_from_txt(string& filename) const{
    //untested, most likely broken somewhere
    //clean the queue
    MyNode* ptr, temp;
    ptr = front;
    while(ptr != nullptr){
        temp = ptr->link; //eventually temp = rear->link = nullptr
        delete ptr;
        ptr = temp; //which ends the loop because ptr = nullptr
    } //i think you can use this for the destructor method as well

    string text, text_symptoms;
    string[] arr = new string[4]
    ifstream ReadFile(filename);
    ptr = new MyNode;
    front = ptr;
    while(getline(ReadFile, text)){
        temp = ptr;
        //substrings into array
        int last = 0;
        for(int i = 0; i<4; i++){
            arr[i] = text.substr(last, text.find(";"));
            last = last + arr[i].length()
        }
        ptr -> patient_id = arr[0];
        ptr -> patient_priority = arr[1];
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
        ptr ->patient_symptoms = list_symptoms;
        ptr = new MyNode;
        temp->link = ptr; //temp is used to link current node with new node
    }
    rear = temp;
    rear -> link = nullptr;
    delete ptr; //because the 2nd last line of the while loop
    ReadFile.close()
}
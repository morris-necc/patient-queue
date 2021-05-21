#include <iostream>
#include "priorityQueue.h"
using namespace std;

priorityQueue::priority_queue(){
    front = nullptr;
    rear = nullptr;
}

priorityQueue::~priority_queue(){
    
}

int priorityQueue::calculate_priority(){
    //???
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
    if(front == nullptr){
        cout << "QUEUE IS EMPTY" << endl;
    } else {
        return front;
    }
}

void priorityQueue::print_contents(){
    //empty (dibs on this one - morris)

}

void priorityQueue::write_to_txt() const{
    //empty (dibs on this one - morris)
}

void priorityQueue::load_from_txt(string& filename) const{
    //empty (dibs on this one - morris)
}
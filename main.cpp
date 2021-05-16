#include <iostream>
#include "priorityQueue.cpp"
using namespace std;

int main(){
    int choice = 0;
    string name, filename;
    priorityQueue patients;

    while(choice != 5){
        cout << "===============MAIN MENU===============" << endl;
        cout << "Patient With Highest Priority: " << patients.get_front().patient_name << endl; //don't forget to complete this part
        cout << "1. Update queue" << endl;
        cout << "2. View queue" << endl;
        cout << "3. Save current queue" << endl;
        cout << "4. Load queue" << endl;
        cout << "5. Exit" << endl;
        cout << "\nPlease enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                //placeholder for a menu i can't bother doing rn
                //add patient (which means asking the user for their name, id & symptoms)
                //remove patient (ask for their name)    

                break;
            case 2:
                patients.print_contents();
                break;
            case 3:
                patients.write_to_txt();
                break;
            case 4:
                cout << "Please enter the .txt filename: ";
                cin >> filename;
                patients.load_from_txt(filename);
                break;
            case 5:
                break;
            default:
                cout << "Please enter a valid choice(0-5)!!!" << endl;
                break;
        }
    }
}

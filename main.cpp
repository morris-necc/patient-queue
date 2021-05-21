#include <iostream>
#include "priorityQueue.cpp"
using namespace std;

int main(){
    int choice = 0, choice2 = 0, p_id;
    string name, filename, symptoms;
    list<string> symptoms_list;
    priorityQueue patients;

    while(choice != 5){
        cout << "===============MAIN MENU===============" << endl;
        cout << "Current high-priority patient: " << patients.get_front().patient_name << endl;
        cout << "1. Update queue" << endl;
        cout << "2. View queue" << endl;
        cout << "3. Save current queue" << endl;
        cout << "4. Load queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                //add patient (which means asking the user for their name, id & symptoms)
                //remove patient (ask for their name)
                //clean this up if you can please
                while(choice2 != 3){
                    cout << "===============UPDATE MENU===============" << endl;
                    cout << "1. Add patient" << endl;
                    cout << "2. Remove patient" << endl;
                    cout << "3. Back" << endl;
                    cout << "Please enter your choice: ";
                    cin >> choice2;
                    switch(choice2){
                        case 1:
                            // unsure whether id should be something that is incremented or input by the admin
                            // also unsure about the purpose of id other than for immersion i guess
                            // cout << "Please enter patient id: ";
                            // cin >> p_id;
                            cout << "Enter the patient's name: ";
                            cin >> name;
                            cout << "Please enter their symptoms(separated by ',', no spaces): ";
                            cin >> symptoms;
                            //clear symptoms_list
                            //split symptoms into values in symptoms_list
                            //calculate priority
                            //insert into queue
                            break;
                        case 2:
                            cout << "Enter the patient's name: ";
                            cin >> name;
                            patients.delete_patient_records(name);
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Please enter a valid choice(0-3)!!!" << endl;
                            break;
                    }
                }
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

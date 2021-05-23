#include <iostream>
#include "priorityQueue.cpp"
using namespace std;

int main(){
    int choice = 0, choice2 = 0, start = 0, end = 0, priority;
    string name, filename, symptoms, p_id;
    list<string> symptoms_list;
    priorityQueue patients;

    while(choice != 5){
        cout << "\n";
        cout << "===============MAIN MENU===============" << endl;
        cout << "Patient With Highest Priority : " << patients.get_front().patient_name << endl;
        cout << "1. Update queue" << endl;
        cout << "2. View queue" << endl;
        cout << "3. Save current queue" << endl;
        cout << "4. Load queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                //clean this up if you can/want to
                while(choice2 != 3){
                    cout << "===============UPDATE MENU===============" << endl;
                    cout << "1. Add patient" << endl;
                    cout << "2. Remove patient" << endl;
                    cout << "3. Back" << endl;
                    cout << "Please enter your choice: ";
                    cin >> choice2;
                    switch(choice2){
                        case 1:
                            cout << "Please enter patient id: ";
                            cin >> p_id;
                            cout << "Enter the patient's name: ";
                            cin >> name;
                            cout << "Please enter their symptoms(separated by ',', no spaces): ";
                            cin >> symptoms;
                            symptoms_list.clear(); // clears list
                            //split symptoms into values in symptoms_list
                            start = 0;
                            end = symptoms.find(",");
                            while(end != -1){
                                symptoms_list.push_back(symptoms.substr(start, end - start));
                                start = end + 1;
                                end = symptoms.find(",", start);
                            } // taken from the load_from_txt method, untested and probably broken somewhere
                            //calculate priority
                            priority = patients.calculate_priority(); //placeholder, don't forget to change this if you decide to add parameters to the method
                            //insert into queue
                            patients.insert_patient_record(priority, p_id, name, symptoms_list);
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
                cout << "Please enter the name of the text file : ";
                cin >> filename;
                patients.load_from_txt(filename);
                break;
            case 5:
                exit(0)
                break;
            default:
                cout << "Please enter a valid choice(0-5) !" << endl;
                break; 
        }
    }
}

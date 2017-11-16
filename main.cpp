#include <iostream>
#include <string>
#include <limits>
using namespace std;
struct Node {
    int znach;
    Node *next;
};
struct List {
    Node *head;
    Node *last;
};
void fill(List &list, int integer1) {
    Node *curr = new Node{integer1, nullptr};
    if (list.head == nullptr)
        list.head = curr;
    else {
        if (list.head->next == nullptr) list.head->next = curr;
        if (list.last != nullptr) list.last->next = curr;
        list.last = curr;
    }
}
void outputting(Node *&curr) {
    do {
        if (curr->next == nullptr)
            cout << curr->znach << endl;
        else
            cout << curr->znach << "->";
        curr = curr->next;
    } while (curr != nullptr);
}
void increase_count(List &list) {
    int k = 0;
    int integer1;
    string number_array;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, number_array);
    string integer_str;
    while (true) {
        for (int i = k; i < number_array.length(); i++) {
            if (number_array[i] == ' ') {
                k++;
                break;
            }
            integer_str = integer_str + number_array[i];
            k++;
        }
        if (integer_str == "") break;
        integer1 = atoi(integer_str.c_str());
        Node *curr = new Node{integer1, nullptr};
        if (list.head == nullptr) {
            list.head = list.last = curr;
        } else {
            list.last->next = curr;
            list.last = curr;
        };
        integer_str = "";
    }
}
void delete_element (List &list, int value) {
    Node *curr= list.head;
    Node *curr_previous= list.head;
    int count_deleting=0;
    if (list.head!= nullptr) {
        if (list.head->znach== value) {
            count_deleting++;
            list.head= list.head->next;
        } else {
            if ((curr->next)!= nullptr) {
                curr= curr->next;
                while ((count_deleting==0) && ((curr->next)!=nullptr)) {
                    if (curr->znach== value) {
                        curr_previous->next= curr->next;
                        count_deleting++;
                    } else {
                        curr= curr->next;
                        curr_previous= curr_previous->next;
                    }
                }
                if (curr->znach== value) {
                    curr_previous->next= nullptr;
                    list.last= curr_previous;
                    count_deleting++;
                }
            }
        }
        if (count_deleting==0) cout<< "Element "<< value << " not found"<< endl;
        else delete curr;
    } else cout << "List is empty!!! Error!!!" << endl;
}

void search_pozition (List &list, int value) {
    int pozition=0;
    int counter=0;
    if (list.head != nullptr) {
        Node *curr = list.head;
        while (curr!= nullptr) {
            if (curr-> znach == value) {
                cout << pozition <<" ";
                pozition++;
                counter++;
            } else {
                pozition++;
            };
            curr= curr->next;
        }
        if (counter == 0) cout<< "Element "<< value << " not found" << endl;
        else cout<< endl;
    } else cout << "List is empty!!! Error!!! " << endl;
}

void change_value (List &list, int pozition, int value) {
    if (list.head != nullptr) {
        Node * curr= list.head;
        int counter=0;
        int index=0;
        while ((curr!= nullptr) && (counter==0)) {
            if (index == pozition) {
                curr->znach= value;
                index++;
                counter++;
            } else {
                index++;
            };
            curr= curr->next;
        }
        if (counter == 0) cout<< "Element number "<< pozition << " does not exist" << endl;
        else cout<< endl;

    } else cout << "Error!!! List is empty!!!"<<endl;
}
void sort_elements (List &list) {
    if (list.head== nullptr) cout << "Error!!! List is empty!!!" << endl;
    else {
        Node *curr= list.head;
        int count_elements=0;
        while (curr!=nullptr) {
            count_elements++;
            curr= curr->next;
        }
        curr= list.head;
        for (int i=0; i< count_elements-1; i++) {
            for (int j=0; j< count_elements- i-1; j++) {
                if ((curr->znach) > (curr->next->znach)) swap ((curr->znach),(curr->next->znach));
                if ((curr->next)!= nullptr) curr= curr->next;
            }
            curr = list.head;
        }
    }
}
void Menu(List &list) {
    Node *curr = nullptr;
    string exit;
    int choise;
    int value;
    int pozition;
    while ((exit != "y") && (exit != "yes") && (exit != "Y") && (exit != "Yes") &&
            (exit != "YES")) {
        cout << "Select one of the operations:" << endl;
        cout << "1.Print the list" << endl;
        cout << "2.Add items to the list" << endl;
        cout << "3.Delete item" << endl;
        cout << "4.Find positions of iteams" << endl;
        cout << "5.Replace the item on the other" << endl;
        cout << "6.Sort the list items" << endl;
        cout << "7.Сomplete the program" << endl;
        cin >> choise;
        switch (choise) {
        case 1:
            if (list.head == nullptr)
                cout << "List is empty" << endl;
            else {
                curr = list.head;
                outputting(curr);
                curr = nullptr;
            }
            break;
        case 2:
            cout << " Enter elements" << endl;
            increase_count(list);
            break;
        case 3:
            cout << " Enter the value of element:" << endl;
            cin >> value;
            delete_element (list, value);
            break;
        case 4:
            cout << " Enter the value of element:" << endl;
            cin >> value;
            search_pozition (list, value);
            break;
        case 5:
            cout << "Enter the pozition and new value:" << endl;
            cin >> pozition;
            cin >> value;
            change_value (list, pozition, value);
            break;
        case 6:
            sort_elements (list);
            break;
        case 7:
            cout << "Do you want to leave program? ( yes, no )" << endl;
            cin >> exit;
            if ((exit == "y") || (exit == "yes") || (exit == "Y") ||
                    (exit == "Yes") || (exit == "YES"))
                cout << "Good by!";
            break;
        }
    }
}
void deleting (List &list) {
    if (list.head!=nullptr) {
        Node*curr= list.head;
        Node*next_curr= list.head->next;
        while (next_curr!=nullptr) {
            delete curr;
            curr= next_curr;
            next_curr= next_curr->next;
        };
        delete curr;
    }
}


int main(int argc, char *argv[]) {
    int integer1;
    List list;
    list.head = nullptr;
    list.last = nullptr;
    if (argc == 2) {
        int k = 0;
        string number_array;
        number_array = argv[1];
        string integer_str;
        while (true) {
            for (int i = k; i < number_array.length(); i++) {
                if (number_array[i] == ',') {
                    k++;
                    break;
                }
                integer_str = integer_str + number_array[i];
                k++;
            }
            if (integer_str == "") break;
            integer1 = atoi(integer_str.c_str());
            fill(list, integer1);
            integer_str = "";
        }
    } else {
        int n = 1;
        while (n < argc) {
            integer1 = atoi(argv[n]);
            fill(list, integer1);
            n++;
        }
    }
    Menu(list);
    deleting (list);
}

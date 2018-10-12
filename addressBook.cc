#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Person {
    string first_name;
    string last_name;
    string name;
    string phone;
    string address;
    struct Person* next;
};

//prototypes
void insertPerson(struct Person*);
int menuChoice();
void printAddressBook();
void printEntry(struct Person*);
void search();
int searchChoice();
void searchMenu(struct Person*);

//make head global
struct Person* head = NULL;


void addPerson() {
    struct Person* newPerson = new Person;
    newPerson->first_name = "";
    newPerson->last_name = "";
    newPerson->phone = "";
    newPerson->address = "";
    newPerson->next = NULL;

    cout << endl << endl;
    cout << "Enter the first name : ";
    getline(cin, newPerson->first_name);

    cout << setw(23) << left << "Enter the last name : ";
    getline(cin, newPerson->last_name);

    cout << setw(23) << left << "Enter phone number : ";
    getline(cin, newPerson->phone);

    cout << setw(23) << left << "Enter address : ";
    getline(cin, newPerson->address);

    insertPerson(newPerson);
    printAddressBook();
}

void buildList() {
    struct Person* current = NULL;

    //allocate memory for new entries
    current = new Person;
    current->first_name = "Siouxsie";
    current->last_name = "Sioux";
    current->phone = "702-555-5555";
    current->address = "3570 S Las Vegas Blvd, Las Vegas, NV 89109";
    insertPerson(current);

    current = new Person;
    current->first_name = "Morticia";
    current->last_name = "Addams";
    current->phone = "415-666-1313";
    current->address = "13 Funston Street, San Francisco, CA 94129";
    insertPerson(current);

    current = new Person;
    current->first_name = "Norman";
    current->last_name = "Bates";
    current->phone = "323-555-5555";
    current->address = "1070 272nd Street, Aldergrove, BC V4W 2P8, Canada";
    insertPerson(current);

    //user enter address book
    /*cout << "Enter the first name : ";
    getline(cin, current->first_name);

    cout << setw(23) << left << "Enter the last name : ";
    getline(cin, current->last_name);

    cout << setw(23) << left << "Enter phone number : ";
    getline(cin, current->phone);

    cout << setw(23) << left << "Enter address : ";
    getline(cin, current->address);
    insertPerson(current);
    cout << endl;

    cout << "Enter the first name : ";
    getline(cin, current->first_name);

    cout << setw(23) << left << "Enter the last name : ";
    getline(cin, current->last_name);

    cout << setw(23) << left << "Enter phone number : ";
    getline(cin, current->phone);

    cout << setw(23) << left << "Enter address : ";
    getline(cin, current->address);
    insertPerson(current);
    cout << endl;

    cout << "Enter the first name : ";
    getline(cin, current->first_name);

    cout << setw(23) << left << "Enter the last name : ";
    getline(cin, current->last_name);

    cout << setw(23) << left << "Enter phone number : ";
    getline(cin, current->phone);

    cout << setw(23) << left << "Enter address : ";
    getline(cin, current->address);
    insertPerson(current);
    cout << endl; */
}

//edit menu
int editChoice() {
  int choice;
  do {
    cout << endl;
    cout << "1. Edit First Name" << endl;
    cout << "2. Edit Last Name" << endl;
    cout << "3. Edit Phone Numer" << endl;
    cout << "4. Edit Address" << endl;
    cout << "5. Edit All" << endl;
    cout << "6. Return To Main Menu" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;
    cin.ignore();
  } while (!(choice > 0 && choice < 7));

  return choice;
}

void editEntry(struct Person* current){
  int choice = editChoice();
  string newUserInput;
  switch (choice) {
    case 1 :  cout << endl;
              cout << current->first_name << endl;
              cout << "Enter New First Name : ";
              getline(cin, current->first_name);
              printEntry(current);
              break;
    case 2 :  cout << endl;
              cout << current->last_name << endl;
              cout << "Enter New Last Name : ";
              getline(cin, current->last_name);
              printEntry(current);
              break;
    case 3 :  cout << endl;
              cout << current->phone << endl;
              cout << "Enter New Phone Number : ";
              getline(cin, current->phone);
              printEntry(current);
              break;
    case 4 :  cout << endl;
              cout << current->address << endl;
              cout << "Enter New Address : ";
              getline(cin, current->address);
              printEntry(current);
              break;
    case 5 :  cout << endl;
              cout << current->first_name << endl;
              cout << "Enter New First Name : ";
              getline(cin, current->first_name);

              cout << endl;
              cout << current->last_name << endl;
              cout << "Enter New Last Name : ";
              getline(cin, current->last_name);

              cout << endl;
              cout << current->phone << endl;
              cout << "Enter New Phone Number : ";
              getline(cin, current->phone);

              cout << endl;
              cout << current->address << endl;
              cout << "Enter New Address : ";
              getline(cin, current->address);
              printEntry(current);
              break;
  }
}

//insert entry in list alphabetically by last name
void insertPerson(struct Person* newPerson) {
  struct Person* current = head;
  if(head == NULL || newPerson->last_name < head->last_name) {
    newPerson->next = head;
    head = newPerson;
  }
  else {
    while(current->next != NULL) {
      if(newPerson->last_name < current->next->last_name) {
        break;
      }
      else
        current = current->next;
    }
    newPerson->next = current->next;
    current->next = newPerson;
  }
}

void menu() {
  //menu and user choice
    int choice;
    do {
      choice = menuChoice();
      switch (choice) {
        case 1 :    addPerson();
                    break;
        case 2 :    //delete person
                    break;
        case 3 :    search();
                    break;
        case 4 :    printAddressBook();
                    break;
        case 5 :    search();
                    break;
      }
   }while (choice != 6);
}

int menuChoice () {
  int choice;
  do {
    cout << endl;
    cout << "1. Add New Entry" << endl;
    cout << "2. Delete An Entry" << endl;
    cout << "3. Edit An Entry" << endl;
    cout << "4. List All Entries" << endl;
    cout << "5. Search For An Entry" << endl;
    cout << "6. Quit Program" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;
    cin.ignore();
  } while (!(choice > 0 && choice < 7));

  return choice;
}

//prints whole address book
void printAddressBook() {
  struct Person* iter = head;
  cout << endl << endl;

  while (iter != NULL) {
      printEntry(iter);
      iter = iter->next;
  }
}

//prints one entry 
void printEntry(struct Person* iter) {
  cout << endl;
  cout << iter->last_name << ", ";
  cout << iter->first_name << endl;
  cout << iter->phone << endl;
  cout << iter->address << endl;
  cout << endl;
}

void search() {
  struct Person* iter = head;
  string userSearch;
  int choice;
  cout << endl;

  choice = searchChoice();

  switch (choice) {
    case 1 :    cout << endl;
                cout << "Enter Last Name : ";
                getline(cin, userSearch);

                while (iter != NULL) {
                  if(userSearch == iter->last_name) {
                    printEntry(iter);
                    break;
                  }
                  else
                    iter = iter->next;
                }

                if(iter == NULL) {
                  cout << endl;
                  cout << "Entry not in address book" << endl;
                  cout << endl;
                }
                else
                  searchMenu(iter);
                break;
    case 2 :    cout << endl;
                cout << "Enter First Name : ";
                getline(cin, userSearch);

                while (iter != NULL) {
                  if(userSearch == iter->first_name) {
                    printEntry(iter);
                    break;
                  }
                  else
                    iter = iter->next;
                }

                if(iter == NULL) {
                  cout << endl;
                  cout << "Entry not in address book" << endl;
                  cout << endl;
                }
                else
                  searchMenu(iter);
                break;
    case 3 :    cout << endl;
                cout << "Enter Phone Number  (###-###-####): ";
                getline(cin, userSearch);

                while (iter != NULL) {
                  if(userSearch == iter->phone) {
                    printEntry(iter);
                    break;
                  }
                  else
                    iter = iter->next;
                }

                if(iter == NULL) {
                  cout << endl;
                  cout << "Entry not in address book" << endl;
                  cout << endl;
                }
                else
                  searchMenu(iter);
                break;
    case 4 :    cout << endl;
                cout << "Enter Address : ";
                getline(cin, userSearch);

                while (iter != NULL) {
                  if(userSearch == iter->address) {
                    printEntry(iter);
                    break;
                  }
                  else
                    iter = iter->next;
                }

                if(iter == NULL) {
                  cout << endl;
                  cout << "Entry not in address book" << endl;
                  cout << endl;
                }
                else
                  searchMenu(iter);
                break;
  }
}

//search by what parameters
int searchChoice() {
  int choice;
  do {
    cout << "1. Search By Last Name" << endl;
    cout << "2. Search By First Name" << endl;
    cout << "3. Search By Phone Number" << endl;
    cout << "4. Search By Address" << endl;
    cout << "5. Return To Main Menu" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> choice;
    cin.ignore();
  } while (!(choice > 0 && choice < 6));

  return choice;
}

//post search menu
void searchMenu(struct Person* iter) {
  int choice;
  cout << endl;

  do {
    cout << "1. Edit The Entry" << endl;
    cout << "2. Delete The Entry" << endl;
    cout << "3. Return to Main Menu" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.ignore();
  } while (!(choice > 0 && choice < 4));

  switch (choice) {
    case 1 :  editEntry(iter);
              break;
    case 2 :  //delete entry
              break;
    }
}

int main() {
    buildList();
    //printAddressBook();
    menu();

    return 0;
}

#include <iomanip>
#include <iostream>
using namespace std;

struct Person {
    string first_name;
    string last_name;
    string phone;
    string address;
    struct Person* next;
    //struct Person* previous;
};

void addPerson(struct Person*);
//int count(struct Person*, int);
int editChoice();
void editEntry(struct Person*);
//void insertSort(struct Person*);
void menu(struct Person*);
int menuChoice();
struct Person* buildList();
void printAddressBook(struct Person*);
void printEntry(struct Person*);
void search(struct Person*);
int searchChoice();
void searchMenu(struct Person*);
//void sortBook(struct Person*);
//void sortedInsert(struct Person**, struct Person*);
struct Person* head;

void addPerson(struct Person* head) {
    struct Person* current = head;
    struct Person* newPerson = new Person;
    string first_name;
    string last_name;
    string phone;
    string address;
    newPerson->first_name = first_name;
    newPerson->last_name = last_name;
    newPerson->phone = phone;
    newPerson->address = address;
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

    while(current->next != NULL)
        current = current->next;
    current->next = newPerson;
    //sortedInsert(head, newPerson);
    printAddressBook(head);
}

struct Person* buildList() {
    struct Person* head = NULL;
    struct Person* current = NULL;

    //allocate memory for new entries
    head = new Person;

    current = head;
    current->first_name = "Siouxsie";
    current->last_name = "Sioux";
    current->phone = "702-555-5555";
    current->address = "3570 S Las Vegas Blvd, Las Vegas, NV 89109";
    current->next = new Person;

    current = current->next;
    current->first_name = "Morticia";
    current->last_name = "Addams";
    current->phone = "415-666-1313";
    current->address = "13 Funston Street, San Francisco, CA 94129";
    current->next = new Person;

    current = current->next;
    current->first_name = "Norman";
    current->last_name = "Bates";
    current->phone = "323-555-5555";
    current->address = "1070 272nd Street, Aldergrove, BC V4W 2P8, Canada";
    current->next = nullptr;

    //sortBook(head);
    /*cout << "Enter the first name : ";
    getline(cin, head->first_name);

    cout << setw(23) << left << "Enter the last name : ";
    getline(cin, head->last_name);

    cout << setw(23) << left << "Enter phone number : ";
    getline(cin, head->phone);

    cout << setw(23) << left << "Enter address : ";
    getline(cin, head->address);
    head->next = second;
    head->previous = nullptr;
    cout << endl;

    cout << "Enter the first name : ";
    getline(cin, second->first_name);

    cout << setw(23) << left << "Enter the last name : ";
    getline(cin, second->last_name);

    cout << setw(23) << left << "Enter phone number : ";
    getline(cin, second->phone);

    cout << setw(23) << left << "Enter address : ";
    getline(cin, second->address);
    second->next = third;
    second->previous = head;
    cout << endl;

    cout << "Enter the first name : ";
    getline(cin, third->first_name);

    cout << setw(23) << left << "Enter the last name : ";
    getline(cin, third->last_name);

    cout << setw(23) << left << "Enter phone number : ";
    getline(cin, third->phone);

    cout << setw(23) << left << "Enter address : ";
    getline(cin, third->address);
    third->next = nullptr;
    third->previous = second;
    cout << endl; */

    return head;

}

/*int count(struct Person* head, int searchFor) {
   struct Person* current = head;
   int count = 0;
   while (current != NULL) {
      if (current->data == searchFor) count++;
      current = current->next;
    }
   return count;
}*/

int editChoice() {
  int choice;
  do {
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

// Given a list, change it to be in sorted order (using SortedInsert()).
/*void insertSort(struct Person** headRef) {
   struct Person* result = NULL;      // build the answer here
   struct Person* current = *headRef; // iterate over the original list
   struct Person* next;
   while (current!=NULL) {
      next = current->next;   // tricky - note the next pointer before we change it
      sortedInsert(result, current);
      current = next;
}
   *headRef = result;
}*/

void menu(struct Person* head) {
  //menu and user choice
    int choice;
    do {
      choice = menuChoice();
      switch (choice) {
        case 1 :    addPerson(head);
                    break;
        case 2 :    //delete person
                    break;
        case 3 :    search(head);
                    break;
        case 4 :    printAddressBook(head);
                    break;
        case 5 :    search(head);
                    break;
      }
   }while (choice != 6);
}

int menuChoice () {
  int choice;
  do {
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

void printAddressBook(struct Person* head) {
  struct Person* iter = head;
  cout << endl << endl;

  while (iter != 0) {
      printEntry(iter);
      iter = iter->next;
  }
}

void printEntry(struct Person* iter) {
  cout << iter->last_name << ", ";
  cout << iter->first_name << endl;
  cout << iter->phone << endl;
  cout << iter->address << endl;
  cout << endl;
}

void search(struct Person* head) {
  struct Person* iter = head;
  string userSearch;
  int choice;
  cout << endl;

  choice = searchChoice();

  switch (choice) {
    case 1 :    cout << "Enter Last Name : ";
                getline(cin, userSearch);

                while (iter != 0) {
                  if(userSearch == iter->last_name) {
                    printEntry(iter);
                    break;
                  }
                  else
                    iter = iter->next;
                }
                searchMenu(iter);
                break;
    case 2 :    cout << "Enter First Name : ";
                getline(cin, userSearch);

                while (iter != 0) {
                  if(userSearch == iter->first_name) {
                    printEntry(iter);
                    break;
                  }
                  else
                    iter = iter->next;
                }
                searchMenu(iter);
                break;
    case 3 :    cout << "Enter Phone Number  (###-###-####): ";
                getline(cin, userSearch);

                while (iter != 0) {
                  if(userSearch == iter->phone) {
                    printEntry(iter);
                    break;
                  }
                  else
                    iter = iter->next;
                }
                searchMenu(iter);
                break;
    case 4 :    cout << "Enter Address : ";
                getline(cin, userSearch);

                while (iter != 0) {
                  if(userSearch == iter->address) {
                    printEntry(iter);
                    break;
                  }
                  else
                    iter = iter->next;
                }
                searchMenu(iter);
                break;
  }
}

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

void searchMenu(struct Person* head) {
  struct Person* iter = head;
  string userSearch;
  int choice, counter;
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

/*void sortBook(struct Person* head) {
  struct Person* iter = head;
  struct Person* current = head;
  while(current->next != NULL) {
      }
      current = current->next;
  }
  current->next = iter;
}*/

// Local references strategy for the head end
/*void sortedInsert(struct Person** headRef, struct Person* newPerson) {
   struct Person** currentRef = headRef;
   while (*currentRef!=NULL && (*currentRef)->last_name < newPerson->last_name) {
      currentRef = &((*currentRef)->next);
}
   newPerson->next = *currentRef;
   *currentRef = newPerson;
}*/

int main() {
    struct Person* head = buildList();
    printAddressBook(head);
    menu(head);

    return 0;
}

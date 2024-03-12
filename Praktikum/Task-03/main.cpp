#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;

struct node {
    // bagian data
    char data;
    // pointer ke node selanjutnya
    node* next;
};

void AddFirst(char item);
void AddLast(char item);
void printList();
void searchNode(char item);
void deleteNode(char item);
void insertNode(char item, int pos);
void editNode(char oldIt, char newIt);

node* head, * tail, *curr;

int main() {
    char del, find, insert, edit, newEdit;
    int pos;
    head = tail = NULL;
    cout << "Add First: " << endl;
    AddFirst('A');
    AddFirst('B');
    AddFirst('C');
    AddFirst('D');
    printList();

    cout << "\nAdd Last: " << endl;
    head = tail = NULL;
    AddLast('A');
    AddLast('B');
    AddLast('C');
    AddLast('D');
    printList();

    cout << "\nDelete Node: " << endl;
    cout << "Input by item wanna to delete: ";
    cin >> del;
    deleteNode(del);
    printList();

    cout << "\nInsert Node: " << endl;
    cout << "Input item wanna to insert: ";
    cin >> insert;
    cout << "Input position wanna to insert: ";
    cin >> pos;
    insertNode(insert, pos);
    printList();

    cout << "\nSearch Node: " << endl;
    cout << "Input item wanna to search: ";
    cin >> find;
    searchNode(find);

    cout << "\nEdit Node: " << endl;
    cout << "Input item wanna to edit: ";
    cin >> edit;
    cout << "Input new item: ";
    cin >> newEdit;
    editNode(edit, newEdit);
    printList();

    getch();
    return EXIT_SUCCESS;
}

void AddLast(char item) { // Add Node After Tail
    node* pNew;
    pNew = new node;
    pNew->data = item;
    pNew->next = NULL; // Menyetel next dari node baru ke NULL
    if (head == NULL) {
        head = pNew;
    }
    else {
        tail->next = pNew;
    }
    tail = pNew;
}

void AddFirst(char item) { // AddNodeBeforeHead
    node* pNew;
    pNew = new node;
    pNew->data = item;
    pNew->next = head; // Menyetel next dari node baru ke head
    head = pNew;
}

void printList() {
    curr = head;
    while (curr != NULL) {
        cout << curr->data << "->"; // Mencetak data dari setiap node
        curr = curr->next; // Pindah ke node berikutnya
    }
    cout << "NULL" << endl; // Menandai akhir dari daftar
}

void searchNode(char item){
    if (head == NULL)
    {
        cout << "Data was Empty!";
        return; //kembalikan
    }
    node *temp;
    temp = head;
    bool found = false;

    while (temp != NULL) {
        if (temp->data == item) {
            cout << "Found: " << item << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    
    if (!found) {
        cout << "Data " << item << " not found!" << endl;
    }
}

void deleteNode(char item){
    if (head == NULL)
    {
        cout << "Data was Empty!";
        return; //kembalikan
    }
    
    node *temp = head;
    node *prev = NULL;

    while (temp != NULL && item != temp->data )
    {
        //mengecek apakah data yang dimasukkan sesuai atau tidak
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Data was not found!" << endl;
        return; // kembalikan
    }

    if (prev != NULL)
    {
        prev->next = temp->next; 
        //Visualisasi menghapus (B) A->B->C
        // Maka menjadi A->C
    } else {
        //Visualisasi menghapus node pertama A->B->C
        // Maka menjadi B->C
        head = temp->next;
    }

    if (temp == tail)
    {
        //Visualisasi menghapus node terakhir A->B->C
        // Maka menjadi A->B
        tail = prev;
    }
    
    delete temp;
}

void insertNode(char item, int pos){
    if (head == NULL)
    {
        cout << "Data was Empty!";
        return; //kembalikan
    }

    node *newNode = new node;
    newNode->data = item;
    newNode->next = NULL;

    if (pos <= 0)
    {
        //ketika menginputkan 0
        cout << "Invalid Position";
    }

    if(pos == 1){ // agar mulai dari indeks pertama
        //ketika menyisipkan pada data pertama
        head = newNode;
        newNode->next = head;
    } else {
        //ketika menyisipkan setelah data pertama
        node* curr = head;
        int currPos = 1;

        while(curr != NULL && currPos < pos -1){
            curr = curr->next;
            currPos++;
        }

        if (curr == NULL)
        {
            cout << "Your input not valid" << endl;
        }
        
        newNode->next = curr->next;
        curr->next = newNode;
    }
    
}

void editNode(char oldIt, char newIt){
    if (head == NULL)
    {
        cout << "Data was Empty!";
        return; //kembalikan
    }

    node *temp;
    temp = head;
    bool found = false;

    while(temp != NULL){
        if(temp->data == oldIt){
            temp->data = newIt;
            cout << "Node was updated!" << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if(!found) {
        cout << "your input " << oldIt << "not found!" << endl;
        char correctData;
        cout << "Enter the correct data: ";
        cin >> correctData;
        editNode(correctData, newIt);
    }
}
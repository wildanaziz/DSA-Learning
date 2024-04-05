#include <iostream>
#include <string>
#include <limits>

struct Song {
    std::string title;
    std::string artist;
    int year;

    Song(std::string t, std::string a, int y) : title(t), artist(a), year(y) {}
};

struct Node {
    Song data;
    Node *next;
    Node *prev;

    Node(Song data) : data(data), next(nullptr), prev(nullptr) {}
};

struct Playlist{
    Node *head;
    Node *tail;
    int length;
    Node *current;

    Playlist() : head(nullptr), tail(nullptr), length(0), current(nullptr) {}

    void addLast(Song data){
        Node *newNode = new Node(data);

        if(length == 0){
            tail = newNode;
            head = newNode;
            tail->next = head;
            head->prev = tail;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        }
        length++;
    }

    bool DELETE(int index){
        if(index < 0 || index >= length){
            return false;
        }

        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }

        if(temp == current){
            current = current->next;
        }

        if(length == 1){
            delete temp;
            head = nullptr;
            tail = nullptr;
            current = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == head) {
                head = temp->next;
            }
            if (temp == tail) {
                tail = temp->prev;
            }
            delete temp;
        }
        length--;
        return true;
    }
};

void SHOWS(Playlist &playlist);
void SHOWSCURR(Playlist &playlist);
void ADDS(Playlist &playlist);
void DELETES(Playlist &playlist);
void NEXTS(Playlist &playlist);
void PREVS(Playlist &playlist);

int main() {
    int option;
    enum {SHOW = 1, ADD, REMOVE, NEXT, PREVIOUS, EXIT};
    Playlist playlist;

    do{
        std::cout << "===Welcome to Sepongetipay===" << std::endl;
        std::cout << "1. Show All Songs\n2. Add Song\n3. Remove Song\n";
        std::cout << "4. Next Song\n5. Previous Song\n6. Rearrange Song\n0. Exit\n";
        SHOWSCURR(playlist);
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch (option)
        {
        case SHOW:
            SHOWS(playlist);
            break;
        
        case ADD:
            ADDS(playlist);
            break;
        
        case REMOVE:
            DELETES(playlist);
            break;
        
        case NEXT:
            NEXTS(playlist);
            break;

        case PREVIOUS:
            PREVS(playlist);
            break;

        case EXIT:
            std::cout << "===EXIT PROGRAMS===" << std::endl;
            return 0;
        
        default:
            std::cout << "Invalid option!" << std::endl;
            break;
        }
    } while(option != EXIT);
}

void SHOWS(Playlist &playlist){
    Node *temp = playlist.head;

    if(temp == nullptr){
        std::cout << "Playlist is empty! Add songs." << std::endl;

        char choice;
        std::cout << "Do you want to add a song? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            ADDS(playlist);
            return;
        } else {
            std::cout << "Returning to the main menu." << std::endl;
            return;
        }

        return;
    }
    std::cout << "|---Show Song---|" << std::endl;
    for(int i = 0; i < playlist.length; i++){
        std::cout << "Song " << i + 1 << std::endl;
        std::cout << "Title: " << temp->data.title << std::endl;
        std::cout << "Artist: " << temp->data.artist << std::endl;
        std::cout << "Year: " << temp->data.year << std::endl;
        std::cout << std::endl;
        temp = temp->next;
    }
    std::cout << "|--------------|" << std::endl;
}

void SHOWSCURR(Playlist &playlist) {
    Node *temp = playlist.current;
    if (temp == nullptr) {
        std::cout << "No song is currently playing." << std::endl;
        return;
    }
    std::cout << "Currently playing:" << std::endl;
    std::cout << "Title: " << temp->data.title << std::endl;
    std::cout << "Artist: " << temp->data.artist << std::endl;
    std::cout << "Year: " << temp->data.year << std::endl;
    std::cout << std::endl;
}

void NEXTS(Playlist &playlist) {
    if(playlist.length == 0) {
        std::cout << "Playlist is empty! Add songs before trying to play!." << std::endl;

        char choice;
        std::cout << "Do you want to add a song? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            ADDS(playlist);
            return;
        } else {
            std::cout << "Returning to the main menu." << std::endl;
            return;
        }
    }

    if (playlist.current == nullptr) {
        playlist.current = playlist.head;
        return;
    }
    playlist.current = playlist.current->next;
}

void PREVS(Playlist &playlist) {
    if(playlist.length == 0) {
        std::cout << "Playlist is empty! Add songs before trying to play!." << std::endl;

        char choice;
        std::cout << "Do you want to add a song? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            ADDS(playlist);
            return;
        } else {
            std::cout << "Returning to the main menu." << std::endl;
            return;
        }
    }
    
    if (playlist.current == nullptr) {
        playlist.current = playlist.tail;
        return;
    }
    playlist.current = playlist.current->prev;
}

void ADDS(Playlist &playlist) {
    std::string title, artist;
    int year;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "|---Add Music---|" << std::endl;
    std::cout << "Input title: ";
    std::getline(std::cin, title);
    std::cout << "Input artist: ";
    std::getline(std::cin, artist);
    std::cout << "Input year: ";
    std::cin >> year;

    playlist.addLast(Song(title, artist, year));
    std::cout << "Song added successfully." << std::endl;
}

void DELETES(Playlist &playlist) {
    if(playlist.length == 0) {
        std::cout << "Playlist is empty! Add songs before trying to delete!." << std::endl;

        char choice;
        std::cout << "Do you want to add a song? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            ADDS(playlist);
            return;
        } else {
            std::cout << "Returning to the main menu." << std::endl;
            return;
        }
    }

    int index;
    std::cout << "Input index of the song to remove: ";
    std::cin >> index;

    if (playlist.DELETE(index - 1)) {
        std::cout << "Song removed successfully." << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

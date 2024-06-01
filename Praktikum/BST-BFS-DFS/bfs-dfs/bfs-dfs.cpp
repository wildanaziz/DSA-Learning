/* Nama: Wildan Aziz Hidayat
   NIM: 235150301111028
   Kelas: Teknik Komputer B
   Tugas: Tugas Graph BFS-DFS
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {
    char value;
    vector<Node> children;

public:
    Node(char c) {
        value = c;
    }

    void addChild(Node n) {
        children.push_back(n);
        return;
    }

    void addChild(char n) {
        Node foo(n);
        children.push_back(foo);
    }

    char getValue() {
        return value;
    }

    vector<Node> getChildren() {
        return children;
    }

    bool isLeaf() {
        return children.size() == 0;
    }

    bool operator==(Node b) {
        return b.value == value;
    }
};

void construct(Node *r) {
    string foo;
    cout << "Masukkan nilai anak dari " << r->getValue() << " (-1 untuk berhenti) : ";
    cin >> foo;
    if (foo == "-1")
        return;
    else {
        for (int i = 0; i < foo.length(); i++) {
            Node t(foo[i]);
            construct(&t);
            r->addChild(t);
        }
    }
}

string breadthFirstSearch(Node root, Node goal) {
    queue<Node> Q;
    vector<Node> children;
    string path = "";

    Q.push(root);
    while (!Q.empty()) {
        Node t = Q.front();
        path += t.getValue();
        Q.pop();
        if (t == goal) {
            return path;
        }
        children = t.getChildren();
        for (int i = 0; i < children.size(); ++i) {
            Q.push(children[i]);
        }
    }
    return path;
}

string depthFirstSearch(Node root, Node goal) {
    stack<Node> Q;
    vector<Node> children;
    string path = "";

    Q.push(root);
    while (!Q.empty()) {
        Node t = Q.top();
        path += t.getValue();
        Q.pop();
        if (t == goal) {
            return path;
        }
        children = t.getChildren();
        reverse(children.begin(), children.end());
        for (int i = 0; i < children.size(); ++i) {
            Q.push(children[i]);
        }
    }
    return path;
}

int main(int argc, char** args) {
    cout << "Program membuat tree dan mencari menggunakan BFS dan DFS" << endl;
    cout << "Angka yang dimasukkan adalah angka dari 0 s.d. 9" << endl;
    cout << "Masukkan node root (1 digit angka) : ";

    char r;
    cin >> r;
    cout << "Memasukkan nilai anak, 1 digit untuk 1 anak dan lebih dari 1 digit untuk lebih dari satu node anak..." << endl;

    Node root(r);
    construct(&root);

    cout << endl << "Masukkan nilai node yang dicari: ";
    cin >> r;
    cout << endl;

    cout << "BFS Traversal: " << breadthFirstSearch(root, Node(' ')) << endl;
    cout << "BFS Search Path: " << breadthFirstSearch(root, Node(r)) << endl << endl;

    cout << "DFS Traversal: " << depthFirstSearch(root, Node(' ')) << endl;
    cout << "DFS Search Path: " << depthFirstSearch(root, Node(r)) << endl;

    cout << endl << "tekan 'q' untuk keluar";
    char c;
    while (cin.get(c)) {
        if (c == 'q') break;
        cout << c;
    }

    return 0;
}

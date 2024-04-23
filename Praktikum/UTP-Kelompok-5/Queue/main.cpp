/* ASD Kelompok 5 Queue
Anggota:
1. Hanna Lailatul Islamiyah (235150301111024)
2. Nisrina Indriani Jatmiko (235150307111022)
3. Wildan Aziz Hidayat (235150301111028)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// Deklarasi struktur Node untuk linked list
struct Node {
    char data;
    int intData;
    Node* next;

    Node(char x);
    Node(int x);
};

// Deklarasi class Stack untuk operasi stack
class Stack {
public:
    Node* top;

    Stack();
    void push(char data);
    void push(int data);
    char pop();
    int popInt();
    char peek() const;
    bool isEmpty() const;
};

// Prototipe fungsi
bool operasi(char c);
int prio(char op);
void addtopostfix(string& postfix, char c);
string infixtopostfix(const string& infix);
int hitung(const string& postfix);

int main() {
    string infix;
    cout << "~~=Infix to Postfix Converter=~~" << endl;
    cout << "Masukkan notasi infix : " << endl;
    getline(cin, infix);

    string hasilkonversi = infixtopostfix(infix);
    cout << "Notasi postfixnya: " << hasilkonversi << endl;

    int hasil = hitung(hasilkonversi);
    cout << "Hasil perhitungan: " << hasil << endl;

    return 0;
}

// Implementasi Node constructors
Node::Node(char x) : data(x), next(nullptr) {}
Node::Node(int x) : intData(x), next(nullptr) {}

// Implementasi Stack methods
Stack::Stack() : top(nullptr) {}

void Stack::push(char data) {
    Node* node = new Node(data);
    node->next = top;
    top = node;
}

void Stack::push(int data) {
    Node* node = new Node(data);
    node->next = top;
    top = node;
}

char Stack::pop() {
    if (!top) return '\0';
    Node* temp = top;
    top = top->next;
    char data = temp->data;
    delete temp;
    return data;
}

int Stack::popInt() {
    if (!top) return 0;
    Node* temp = top;
    top = top->next;
    int data = temp->intData;
    delete temp;
    return data;
}

char Stack::peek() const {
    return top ? top->data : '\0';
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

// Implementasi operasi checker dan prioritas
bool operasi(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int prio(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}

// Implementasi untuk menambahkan ke postfix
void addtopostfix(string& postfix, char c) {
    postfix += c;
    postfix += ' ';
}

// Implementasi konversi infix ke postfix
string infixtopostfix(const string& infix) {
    string postfix;
    Stack stack;

    for (char c : infix) {
        if (isdigit(c)) {
            addtopostfix(postfix, c);
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                addtopostfix(postfix, stack.pop());
            }
            stack.pop();  // Pop '(' from the stack
        } else if (operasi(c)) {
            while (!stack.isEmpty() && prio(stack.peek()) >= prio(c)) {
                addtopostfix(postfix, stack.pop());
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        addtopostfix(postfix, stack.pop());
    }

    return postfix;
}

// Implementasi hitung nilai dari postfix
int hitung(const string& postfix) {
    stringstream ss(postfix);
    Stack stack;
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            stack.push(stoi(token));
        } else if (operasi(token[0])) {
            int operand2 = stack.popInt();
            int operand1 = stack.popInt();
            switch (token[0]) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                case '^':
                    int hasil = 1;
                    for (int i = 0; i < operand2; ++i) hasil *= operand1;
                    stack.push(hasil);
                    break;
            }
        }
    }

    return stack.popInt();
}
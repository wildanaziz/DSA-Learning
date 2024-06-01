#include <iostream>
#include <cstdlib>

struct Node {
    int key;
    Node *left, *right;
};

// Fungsi utilitas untuk membuat node BST baru
Node* newNode(int item) {
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

// Fungsi utilitas untuk melakukan inorder traversal pada BST
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

// Fungsi utilitas untuk memasukkan node baru dengan kunci yang diberikan ke dalam BST
Node* insert(Node* node, int key) {
    if (node == nullptr) return newNode(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

// Fungsi utilitas untuk mencari node dengan kunci tertentu di dalam BST
Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key) return root;

    if (root->key < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr){
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // kalau misal dua anak
        if (root->left != nullptr && root->right != nullptr) {
            Node* temp = root->right;
            
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        } else { // kalau misal satu anak
            Node* temp = root;
            if (root->left == nullptr) {
                root = root->right;
            } else if (root->right == nullptr) {
                root = root->left;
            }
            delete temp;
        }
    }
    // kalau misal tidak ada anak
    return root;
}

Node *minNode(Node *subright){
    Node* current = subright;

    // Loop down to find the leftmost leaf
    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

Node *deleteMinRightNode(Node *root, int key){
    if (root == nullptr){
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // kalau misal dua anak
        if (root->left != nullptr && root->right != nullptr) {
            Node* temp = minNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        } else { // kalau misal satu anak
            Node* temp = root;
            if (root->left == nullptr) {
                root = root->right;
            } else if (root->right == nullptr) {
                root = root->left;
            }
            delete temp;
        }
    }
    // kalau misal tidak ada anak
    return root;
}

void reverseInorder(Node* root) {
    if (root != nullptr) {
        reverseInorder(root->right);
        std::cout << root->key << " ";
        reverseInorder(root->left);
    }
}


int main() {

    int pilihan;
    std::cout << "Masukkan Pilihan anda\n1. Soal 1-5\n2. Soal 6\n3. Soal 7\nPilihan anda: ";
    std::cin >> pilihan;
    if (pilihan == 1) {
        std::cout << "Soal Nomor 1 - 3" << std::endl;
        Node* root = nullptr;
        root = insert(root, 50);
        insert(root, 30);
        insert(root, 20);
        insert(root, 40);
        insert(root, 70);
        insert(root, 60);
        insert(root, 80);
        insert(root, 2);
        insert(root, 7);
        insert(root, 1);
        insert(root, 70);
        insert(root, 60);
        insert(root, 89);

        // Mencetak inorder traversal dari BST
        std::cout << "Mencetak data yang ada: \n";
        inorder(root);

        std::cout << "Mencetak data yang telah dihapus: \n";
        deleteNode(root, 89);
        inorder(root);

        std::cout << "Mencetak data yang telah dihapus: \n";
        deleteNode(root, 5);
        inorder(root);
        

        std::cout << "Mencetak data yang telah dihapus: \n";
        deleteNode(root, 23);
        inorder(root);
        
    } else if (pilihan == 2) {
        std::cout << "Soal Nomor 6" << std::endl;

        Node* root = nullptr;
        root = insert(root, 50);
        insert(root, 30);
        insert(root, 20);
        insert(root, 40);
        insert(root, 70);
        insert(root, 60);
        insert(root, 80);

        // Mencetak inorder traversal dari BST
        std::cout << "Mencetak data yang ada: \n";
        inorder(root);

        std::cout << "Mencetak data yang telah dihapus: \n";
        deleteMinRightNode(root, 70);
        inorder(root);
    } else if (pilihan == 3) {
        std::cout << "Soal Nomor 7" << std::endl;
        Node* root = nullptr;
        root = insert(root, 50);
        insert(root, 30);
        insert(root, 20);
        insert(root, 40);
        insert(root, 70);
        insert(root, 60);
        insert(root, 80);
        insert(root, 2);
        insert(root, 7);
        insert(root, 1);
        insert(root, 70);
        insert(root, 60);
        insert(root, 89);

        // Mencetak reverse inorder traversal dari BST
        std::cout << "Mencetak data yang ada: \n";
        reverseInorder(root);
    }

    return 0;
}


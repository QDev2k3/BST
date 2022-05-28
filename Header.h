#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;  
    return p;
}

Node *insertNode(Node *p, int x) {
    if (p == NULL) {
        Node *temp = createNode(x);
        return temp;
    }
    else {
        if (x < p->data)
            p->left = insertNode(p->left,x);
        else 
            p->right = insertNode(p->right,x);
    }
} 

void inputKey(Node *&tree) {
    int n,x;
    cout << " (+) Nhap so phan tu: ";
    cin >> n;
    cout << " (+) Nhap gia tri cho "<< n << " phan tu: " << endl;
    for (int i=0; i<n; i++) {
        cin >> x;
        tree = insertNode(tree,x);
    }
}

void inputFile(Node *&tree) {
    ifstream myFile;
    myFile.open("input.txt", ios_base::in);
    int n,x;
    myFile >> n;
    for (int i=0; i<n; i++) {
        myFile >> x;
        tree = insertNode(tree,x);
    }
    myFile.close();
}

/* DUYỆT CÂY THEO 6 CÁCH */

void LNR(Node *p) {
    if (p!=NULL) {
        LNR(p->left);
        cout << p->data << " ";
        LNR(p->right);
    }
}

void RNL(Node *p) {
    if (p!=NULL) {
        RNL(p->right);
        cout << p->data << " ";
        RNL(p->left);
    }
}

void NLR(Node *p) {
    if (p!=NULL) {
        cout << p->data << " ";
        NLR(p->left);
        NLR(p->right);
    }
}

void NRL(Node *p) {
    if (p!=NULL) {
        cout << p->data << " ";
        NRL(p->right);
        NRL(p->left);
    }
}

void RLN(Node *p) {
    if (p!=NULL) {
        RLN(p->right);
        RLN(p->left);
        cout << p->data << " ";
    }
}

void LRN(Node *p) {
    if (p!=NULL) {
        LRN(p->left);
        LRN(p->right);
        cout << p->data << " ";
    }
}

/* TÌM XEM X CÓ TRONG CÂY HAY KHÔNG */

int getDepth(Node* root, int x) {       // Trả về mức của nút trong cây
    if (root == NULL)
        return -1;
    int dist = -1;
    if ((root->data == x) || (dist = getDepth(root->left, x)) >= 0 || (dist = getDepth(root->right, x)) >= 0) {
        return dist + 1;
    }
    return dist;
}

void findNode(Node *tree) {
    int x;
    cout << "(+) Nhap gia tri can tim: ";
    cin >> x;
    int level = getDepth(tree,x);
    if (level == -1) 
        cout << x << " NOT FOUND!" << endl;
    else
        cout << x << " found at level " << level << endl;
}

/* TÍNH SỐ NÚT TRONG CÂY */

int getNode(Node *tree) {
    if (tree == NULL) {
        return 0;
    }
    return (1 + getNode(tree->left) + getNode(tree->right));
}

/* TÍNH SỐ NÚT LÁ TRONG CÂY */

int getLeaf(Node *tree) {
    if (tree == NULL)
        return 0;
    if (tree->left == NULL && tree->right == NULL)
        return 1;
    return (getLeaf(tree->left) + getLeaf(tree->right));
}

/* TÍNH CHIỀU CAO CỦA CÂY */

int getHeight(Node *tree) {
    if (tree == NULL)
        return -1;
    else {
        int l = getHeight(tree->left);
        int r = getHeight(tree->right);
        if (l > r)
            return(l + 1);
        else return(r + 1);
    }
}

/* ĐẾM SỐ CHÍNH PHƯƠNG TRONG CÂY */

bool isSquare(int x) {
    int k = sqrt(x);
    if (k*k == x)
        return true;
    else 
        return false;
}

int getSquareNum(Node *p) {
    if (p == NULL)
        return 0;
    if (isSquare(p->data) == false)
        return (getSquareNum(p->left) + getSquareNum(p->right));
    else 
        return (1 + getSquareNum(p->left) + getSquareNum(p->right));
}

/* TÌM MIN/MAX TRONG CÂY */

int getMax(Node *tree) {
    if (tree == NULL) 
        return -1;
    Node *p = tree;
    while (p->right != NULL)
        p = p->right;
    return p->data;
}

int getMin(Node *tree) {
    if (tree == NULL) 
        return -1;
    Node *p = tree;
    while (p->left != NULL)
        p = p->left;
    return p->data;
}

/* TÍNH TỔNG CÁC GIÁ TRỊ TRONG CÂY (DÙNG KHI TÍNH TBC) */

int getSum(Node *tree) {
    if (tree == NULL) {
        return 0;
    }
    return (tree->data + getSum(tree->left) + getSum(tree->right));
}
#include "Header.h"

int main() {
    Node *tree = NULL;
    int x,n,k;
    cout << "================== INPUT ==================" << endl;
    cout << "(i) Chon cach nhap [1.File  2.Keyboard]: "; cin >> k;
    if (k == 1) {
        inputFile(tree);
    }
    else inputKey(tree);
    cout << "\n============= INPUT COMPLETED =============" << endl;

    cout << "\n+============ Duyet Cay ==============" << endl;
    cout << " (1) LNR: "; LNR(tree);
    cout << "\n (2) RNL: "; RNL(tree);
    cout << "\n (3) NLR: "; NLR(tree);
    cout << "\n (4) NRL: "; NRL(tree);
    cout << "\n (5) RLN: "; RLN(tree);
    cout << "\n (6) LRN: "; LRN(tree);
    cout << endl;

    cout << "\n+============ Tim X trong Cay ==============" << endl;
    findNode(tree);
    cout << endl;

    cout << "\n+============== Dem so node ===============" << endl;
    k = getNode(tree);
    cout << "Cay co " << k << " node\n";

    cout << "\n+============= Dem so node la =============" << endl;
    n = getLeaf(tree);
    cout << "Cay co " << n << " node la\n";

    cout << "\n+============ Tinh chieu cao ==============" << endl;
    n = getHeight(tree);
    cout << "Chieu cao cua cay la " << n << "\n";

    cout << "\n+============ Dem so chinh phuong  ==============" << endl;
    n = getSquareNum(tree);
    cout << "Cay co " << n << " so chinh phuong\n";

    cout << "\n+============== Max/Min trong Cay ===============" << endl;
    x = getMax(tree);
    cout << "Gia tri lon nhat " << x << endl;
    x = getMin(tree);
    cout << "Gia tri be nhat " << x << endl;

    cout << "\n+============ Trung Binh Cong =============" << endl;
    x = getSum(tree);
    cout << "Trung binh cong cua cay la " << (float) x/k*1.0 << endl;

    cout << "\n=================== END ===================" << endl;
    system("pause");
    return 0;
}
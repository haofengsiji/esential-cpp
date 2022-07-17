#include "BTnode.h"

int main() {
    BinaryTree<string> bt;

    bt.insert("Piglet");
    bt.insert("Eeyore");
    bt.insert("Roo");
    bt.insert("Tigger");
    bt.insert("Chris");
    bt.insert("Pooh");
    bt.insert("Kanga");

    cout << "Preorder traversal: \n";
    bt.preorder();

    bt.remove("Piglet");
    cout << "\n\nPreorder traversal after Piglet removal: \n";
    bt.preorder();


    bt.remove("Eeyore");
    cout << "\n\nPreorder travarsal aser Eeyore removal: \n";
    bt.preorder();

    return 0;
}
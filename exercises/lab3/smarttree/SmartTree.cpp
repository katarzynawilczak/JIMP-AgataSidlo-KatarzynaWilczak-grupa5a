#include <ostream>
#include <string>
#include <memory>
#include "SmartTree.h"
#include <regex>

namespace datastructures {


    std::unique_ptr<SmartTree> CreateLeaf(int value) {

        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>(value);
        leaf->value = value;
        leaf->right = nullptr;
        leaf->left = nullptr;
        return leaf;
    }

    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        tree->left = std::move(left_subtree);
        return tree;
        }

    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right=std::move(right_subtree);
        return tree;
    }

 void PrintTreeInOrder(const std::unique_ptr <SmartTree> &unique_ptr, std::ostream *out) {
    if(unique_ptr==nullptr)
        return;
     PrintTreeInOrder(unique_ptr->left, out);
     *out << unique_ptr->value << ", ";
     PrintTreeInOrder(unique_ptr-> right, out);

}
std::string DumpTree(const std::unique_ptr <SmartTree> &tree){
    std::string dtree;
    if(tree!=nullptr){
        dtree.append("[");
        std::string str = std::to_string(tree->value);
        dtree.append(str);
        if(tree->left!=nullptr) {
            dtree.append(" ");
            dtree.append(DumpTree(tree->left));
        }
        else {
            dtree.append(" ");
            dtree.append("[none]");
        }

        if(tree->right!=nullptr) {
            dtree.append(" ");
            dtree.append(DumpTree(tree->right));
        }
        else {
            dtree.append(" ");
            dtree.append("[none]");
        }
        dtree.append("]");
    }
    return dtree;
}

   // std::unique_ptr <SmartTree> RestoreTree(const std::string &tree)

}

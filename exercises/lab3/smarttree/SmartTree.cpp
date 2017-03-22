#include <ostream>
#include <string>
#include <memory>
#include "SmartTree.h"

namespace datastructures {


    std::unique_ptr<SmartTree> CreateLeaf(int value) {

        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>(value);
        leaf->value = value;
        leaf->right = nullptr;
        leaf->left = nullptr;
        return leaf;
    }

    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        if(tree=nullptr){
            tree=std::move(left_subtree);
            return tree;
        }
        else {
            tree->left = std::move(left_subtree);
            return tree;
        }
    }

    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right=std::move(right_subtree);
        return tree;
    }
}
//void datastructures::PrintTreeInOrder(const std::unique_ptr <SmartTree> &unique_ptr, std::ostream *out){

//}


/*

std::string DumpTree(const std::unique_ptr<SmartTree> &tree);
std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);
 */
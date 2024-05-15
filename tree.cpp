#include "tree.h"

tree::tree()
{
    root = nullptr;
}

tree::~tree()
{
    delete root;
}

node* tree::getRoot()
{
    return root;
}

void tree::setRoot(node* node)
{
    root = node;
}

bool tree::isTreeEmpty()
{
    return root == nullptr;
}
#include "node.h"

node::node(int value)
{
    data = value;
}

node::~node()
{
    for (node* child : childrens)
    {
        delete child;
    }
}
int node::getData()
{
    return data;
}

int node::getNumOfChildrens()
{
    return childrens.size();
}

list<node*> node::getChildrensList()
{
    return childrens;
}

void node::addChild(node* child)
{
    childrens.push_back(child);
}

bool node::removeChild(node* child)
{
    for (auto currentNode = childrens.begin(); currentNode != childrens.end(); currentNode++)
    {
        if (*currentNode == child)
        {
            childrens.erase(currentNode);
            return true;
        }
    }
    return false;
}
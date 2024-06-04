#include "node.h"

node::node(int value)
{
    data = value;
}

node::~node()
{
    for (node* child : children)
    {
        delete child;
    }
}

int node::getData() const
{
    return data;
}

int node::getNumOfChildren() const
{
    return (int)children.size();
}

list<node*> node::getChildrenList()
{
    return children;
}

void node::addChild(node* child)
{
    children.push_back(child);
}

bool node::removeChild(node* child)
{
    for (auto currentNode = children.begin(); currentNode != children.end(); currentNode++)
    {
        if (*currentNode == child)
        {
            children.erase(currentNode);
            return true;
        }
    }
    return false;
}
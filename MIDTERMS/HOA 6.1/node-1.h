#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    T data;
    Node *next;
};

template <typename T>
Node<T> *new_node(T newData)
{
    Node<T> *new_node = new Node<T>;
    new_node->data = newData;
    new_node->next = nullptr;
    return new_node;
}

#endif
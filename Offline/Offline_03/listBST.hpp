#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * Binary Search Tree implementation using linked list structure
 *
 * @tparam Key - The type of keys stored in the BST
 * @tparam Value - The type of values associated with keys
 */
template <typename Key, typename Value>
class ListBST : public BST<Key, Value>
{
private:
    /**
     * Node class for the binary search tree
     */
    class Node
    {
    public:
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node *root;
    size_t node_count;

    // TODO: Implement private helper functions as needed
    // Start your private helper functions here
    Node *insertIntobst(Node *root, Key k, Value v, bool &isInserted)
    {
        if (root == NULL)
        {
            Node *newNode = new Node(k, v);
            node_count++;
            isInserted = true;
            return newNode;
        }

        if (root->key > k)
            root->left = insertIntobst(root->left, k, v, isInserted);
        else if (root->key < k)
            root->right = insertIntobst(root->right, k, v, isInserted);
        else
            isInserted = false;
        return root;
    }

    Node *Successor(Node *root) const
    {
        while (root != NULL && root->left != NULL)
            root = root->left;

        return root;
    }

    Node *removeFrombst(Node *root, Key k, bool &isRemoved)
    {
        if (root == NULL)
        {
            isRemoved = false;
            return NULL;
        }

        if (root->key > k)
            root->left = removeFrombst(root->left, k, isRemoved);
        else if (root->key < k)
            root->right = removeFrombst(root->right, k, isRemoved);
        else
        {
            isRemoved = true;
            node_count--;
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node *successor = Successor(root->right);
                root->key = successor->key;
                root->value = successor->value;
                bool flag;
                root->right = removeFrombst(root->right, successor->key, flag);
                node_count++;
            }
        }
        return root;
    }

    Node *findInbst(Node *root, Key k) const
    {
        if (root == NULL || root->key == k)
            return root;

        else if (root->key > k)
            return findInbst(root->left, k);
        else
            return findInbst(root->right, k);
    }

    void clear_bst(Node *root)
    {
        if (root == NULL)
            return;

        clear_bst(root->left);
        clear_bst(root->right);
        delete root;
    }

    void defaultOrder(Node *root) const
    {
        if (root == NULL)
            return;

        cout << "(" << root->key << ":" << root->value;

        if (root->left != NULL || root->right != NULL)
        {
            cout << " ";
            if (root->left != NULL)
                defaultOrder(root->left);
            else
                cout << "()";

            if (root->right != NULL)
            {
                cout << " ";
                defaultOrder(root->right);
            }
        }
        cout << ")";
    }

    void preOrder(Node *root) const
    {
        if (root == NULL)
            return;
        cout << "(" << root->key << ":" << root->value << ") ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node *root) const
    {
        if (root == NULL)
            return;
        inOrder(root->left);
        cout << "(" << root->key << ":" << root->value << ") ";
        inOrder(root->right);
    }

    void postOrder(Node *root) const
    {
        if (root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << "(" << root->key << ":" << root->value << ") ";
    }
    // End your private helper functions here

public:
    /**
     * Constructor
     */
    ListBST() : root(nullptr), node_count(0) {}

    /**
     * Destructor
     */
    ~ListBST()
    {
        // TODO: Implement destructor to free memory
        clear();
    }

    /**
     * Insert a key-value pair into the BST
     */
    bool insert(Key key, Value value) override
    {
        // TODO: Implement insertion logic
        bool isInserted = false;
        root = insertIntobst(root, key, value, isInserted);
        return isInserted;
    }

    /**
     * Remove a key-value pair from the BST
     */
    bool remove(Key key) override
    {
        // TODO: Implement removal logic
        bool isRemoved = false;
        root = removeFrombst(root, key, isRemoved);
        return isRemoved;
    }

    /**
     * Find if a key exists in the BST
     */
    bool find(Key key) const override
    {
        // TODO: Implement find logic
        if (findInbst(root, key) == NULL)
            return false;
        return true;
    }

    /**
     * Find a value associated with a given key
     */
    Value get(Key key) const override
    {
        // TODO: Implement get logic
        Node *result = findInbst(root, key);
        if (result == NULL)
        {
            cerr << "Key not found" << endl;
            throw runtime_error("Key not found");
        }
        return result->value;
    }

    /**
     * Update the value associated with a given key
     */
    void update(Key key, Value value) override
    {
        // TODO: Implement update logic
        Node *result = findInbst(root, key);
        if (result == NULL)
            return;
        result->value = value;
    }

    /**
     * Clear all elements from the BST
     */
    void clear() override
    {
        // TODO: Implement clear logic

        clear_bst(root);
        root = NULL;
        node_count = 0;
    }

    /**
     * Get the number of keys in the BST
     */
    size_t size() const override
    {
        // TODO: Implement size logic
        return node_count;
    }

    /**
     * Check if the BST is empty
     */
    bool empty() const override
    {
        // TODO: Implement empty check logic
        return node_count == 0;
    }

    /**
     * Find the minimum key in the BST
     */
    Key find_min() const override
    {
        // TODO: Implement find_min logic
        if (root == NULL)
        {
            cerr << "Key not found" << endl;
            throw runtime_error("Key not found");
        }
        Node *minNode = Successor(root);
        return minNode->key;
    }

    /**
     * Find the maximum key in the BST
     */
    Key find_max() const override
    {
        // TODO: Implement find_max logic
        if (root == NULL)
        {
            cerr << "Key not found" << endl;
            throw runtime_error("Key not found");
        }
        Node *current = root;
        while (current->right != NULL)
            current = current->right;
        return current->key;
    }

    /**
     * Print the BST using specified traversal method
     */
    void print(char traversal_type = 'D') const override
    {
        // TODO: Implement print logic
        if (empty())
            return;

        if (traversal_type == 'P')
        {
            cout << "BST (Pre-order): ";
            preOrder(root);
            cout << endl;
        }
        else if (traversal_type == 'I')
        {
            cout << "BST (In-order): ";
            inOrder(root);
            cout << endl;
        }
        else if (traversal_type == 'S')
        {
            cout << "BST (Post-order): ";
            postOrder(root);
            cout << endl;
        }
        else
        {
            cout << "BST (Default): ";
            defaultOrder(root);
        }
    }
};

#endif // LISTBST_H
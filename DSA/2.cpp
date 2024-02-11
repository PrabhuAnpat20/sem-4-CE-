//============================================================================
// Name        : prac2.cpp
// Author      : s
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class BST
{

public:
    node *insertInBST(node *root, int data)
    {

        if (root == NULL)
        {
            root = new node(data);

            return root;
        }
        if (data < root->data)
        {
            root->left = insertInBST(root->left, data);
        }
        else
        {
            root->right = insertInBST(root->right, data);
        }
        return root;
    }
    void takeInput(node *&root)
    {
        int data;
        // cout<<"enter data for root "<<endl;
        cin >> data;
        while (data != -1)
        {

            root = insertInBST(root, data);
            // cout<<"enter data for node "<<endl;
            cin >> data;
        }
    }
    void insert(node *root, int data)
    {
        root = insertInBST(root, data);
    }

    void display(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        queue<node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout << temp->data << " ";
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)

                {
                    q.push(temp->right);
                }
            }
        }
    }
    void min(node *root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        cout << "min:" << root->data << endl;
    }
    void max(node *root)
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
        cout << "max:" << root->data << endl;
    }
    bool search(node *root, int data)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        if (root->data > data)
        {
            search(root->left, data);
        }
        else
        {
            search(root->right, data);
        }
    }

    void swap(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        if (root)
        {
            if (root->left && root->right)
            {
                node *temp = root->left;
                root->left = root->right;
                root->right = temp;
            }
        }
        swap(root->left);
        swap(root->right);
    }
};
int main()
{

    node *root = NULL;
    BST b1;

    while (true)
    {
        cout << "**************************************************************************************" << endl;
        cout << "enter choice" << endl;
        cout << "1->create tree\n2->insert a new node  into tree\n3->minimum and max data\n4->swap nodes\n5->search\n6->display\n7->exit" << endl;
        cout << "**************************************************************************************" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            b1.takeInput(root);
        }
        else if (choice == 2)
        {

            cout << "data to insert" << endl;
            int d;
            cin >> d;
            b1.insert(root, d);
        }
        else if (choice == 3)
        {
            b1.min(root);
            b1.max(root);
        }
        else if (choice == 4)
        {
            b1.swap(root);
        }
        else if (choice == 5)
        {
             cout << "data to search" << endl;
            int d;
            cin >> d;
            if (b1.search(root, d))
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else if (choice == 6)
        {
             b1.display(root);
        }

   
    
        else if (choice == 7)
        {
            cout << "exited ....";
            break;
        }
    }

    // b.takeInput(root);
    // b.display(root);
    // b.insert(root, 6);
    // b.display(root);
    // b.min(root);
    // b.max(root);
    // if (b.search(root, 9))
    // {
    //     cout << "yes" << endl;
    // }
    // else
    // {
    //     cout << "no" << endl;
    // }
    // b.swap(root);
    // b.display(root);

    return 0;
}

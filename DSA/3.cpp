
#include <iostream>

using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int Lflag;
    int Rflag;
    int data;

    Node(int data)
    {

        this->data = data;
        left = NULL;
        right = NULL;
        Lflag = 0;
        Rflag = 0;
    }
};

class BTST
{
public:
    Node *head, *root;
    BTST()
    {
        head = new Node(9999);
        root = NULL;
    }

    void insert(int data)
    {
        if (root == NULL)
        {
            root = new Node(data);
            head->left = root;
            head->right = head;
            head->Lflag = 1;
            root->right = head;
            root->left = head;
        }
        else
        {
            Node *parent = root;
            Node *newnode = new Node(data);
            while (true)
            {
                if (data < parent->data)
                {

                    // go left
                    if (parent->Lflag == 1)
                    {
                        parent = parent->left;
                    }
                    else
                    {
                        newnode->left = parent->left;
                        parent->left = newnode;
                        parent->Lflag = 1;
                        newnode->right = parent;
                        return;
                    }
                }
                else
                {
                    if (parent->Rflag == 1)
                    {
                        parent = parent->right;
                    }
                    else
                    {
                        newnode->right = parent->right;
                        parent->right = newnode;
                        parent->Rflag = 1;
                        newnode->left = parent;
                        return;
                    }
                }
            }
        }
    }

    void inorder()
    {
        Node *temp = root;
        while (temp->Lflag != 0)
        {
            temp = temp->left;
        }
        while (temp != head)
        {
            cout << temp->data << " ";

            if (temp->Rflag == 1)
            {
                temp = temp->right;
                while (temp->Lflag != 0)
                {
                    temp = temp->left;
                }
            }
            else
            {
                temp = temp->right;
            }
        }
        cout << endl;
    }
    void preorder()
    {
        Node *temp = root;
        while (temp != head)
        {
            while (temp->Lflag != 0)
            {
                cout << temp->data << " ";
                temp = temp->left;
            }
            cout<<temp->data<<" ";

            while(temp->Rflag==0){
                temp=temp->right;
                if(temp==head)return;
            }
            temp=temp->right;

        }
        cout<<endl;
    }

};

int main()
{

    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    BTST b;
    int n;
    cout << "how many nodes to enter" << endl;
    cin >> n;
    while (n--)
    {
        int d;
        cout << "enter data" << endl;
        cin >> d;
        b.insert(d);
    }
    // b.inorder();
    b.inorder();
    return 0;
}
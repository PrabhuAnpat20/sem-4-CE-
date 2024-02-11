// Beginning with an empty binary tree, construct binary tree by insreting the values in the order given .After constructing a binary tree perform folowing operations
// 1>Perform inoerder ,preorder and Postorder traversal
// 2>Change a tree so that the roles of the left and right pointers are swapped at every Node
// 3>Find height of tree
// 4>Copy this tree to another [operator=]
// 5>Count no. of leaves , number of internal nodes
// 6>erase all nodes (implement both recursive and non recursive)




#include <iostream>

#include <queue>

using namespace std;

class Node

{

public:
    int data;

    Node *right;

    Node *left;

    Node(int data)

    {

        this->data = data;

        right = NULL;

        left = NULL;
    }
};

class Binary_Tree

{

public:
    Node *root;

    Node *CreateTree()

    {

        int data;

        cout << "enter data for root node:";

        cin >> data;

        root = new Node(data);

        cout << "tree created succesfully" << endl;

        return root;
    }

    void Insert(Node *&root)
    {
        queue<Node *> q;

        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            cout << "enter data for left of " << temp->data << ":";
            int leftData;
            cin >> leftData;

            if (leftData != -1)
            {
                temp->left = new Node(leftData);
                q.push(temp->left);
            }
            cout << "enter data for right of " << temp->data << ":";
            int rightData;
            cin >> rightData;

            if (rightData != -1)
            {
                temp->right = new Node(rightData);
                q.push(temp->right);
            }
        }
    }

    void Inorder(Node *root)

    {

        if (root == NULL)

        {

            return;
        }

        Inorder(root->left);

        cout << root->data << " ";

        Inorder(root->right);
    }

    void Preorder(Node *root)

    {

        if (root == NULL)

        {

            return;
        }

        cout << root->data << " ";

        Preorder(root->left);

        Preorder(root->right);
    }

    void Postorder(Node *root)

    {

        if (root == NULL)

        {

            return;
        }

        Postorder(root->left);

        Postorder(root->right);

        cout << root->data << " ";
    }
      void eraseTree(Node * node) {
		if (node != NULL) {
			eraseTree(node->left);
			eraseTree(node->right);

			delete node;
			// node = NULL;
		}
		return;
	}
    int Height(Node *root)

    {

        if (root == NULL)

        {

            return 0;
        }

        int lh = Height(root->left);

        int rh = Height(root->right);

        return 1 + max(lh, rh);
    }

    void leafnodes(Node *root, int &c)

    {

        if (root == NULL)
        {

            return;
        }

        if (root->left == NULL && root->right == NULL)
        {

            c++;
        }

        leafnodes(root->left, c);

        leafnodes(root->right, c);
    }

    void display(Node *root)

    {

        if (root == NULL)
        {

            return;
        }

        queue<Node *> q;

        q.push(root);

        q.push(NULL);

        while (!q.empty())

        {

            Node *temp = q.front();

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

    void swap(Node *root)
    {

        if (root == NULL)
        {

            return;
        }

        if (root)
        {

            if (root->left && root->right)
            {

                Node *temp = root->left;

                root->left = root->right;

                root->right = temp;
            }
        }

        swap(root->left);

        swap(root->right);
    }


    int Num_Nodes(Node *root,int & n){
      if((root->right==NULL) &&(root->left==NULL) ){
        n++;
        return n;
      }
      n++;
      Num_Nodes(root->left,n);
      Num_Nodes(root->right,n);
  }

    Node *copy(Node *root)
    {

        if (root == NULL)
        {

            return root;
        }

        Node *temp = new Node(root->data);

        temp->left = copy(root->left);

        temp->right = copy(root->right);

        return temp;
    }

    Binary_Tree operator=(Binary_Tree obj)
    {

        Binary_Tree t;

        t.root = copy(obj.root);

        t.display(t.root);

        return t;
    }
};

int main()

{
    Binary_Tree b1;

    Node *root = NULL;

    while (true)
    {
        cout << "**************************************************************************************" << endl;
        cout << "enter choice" << endl;
        cout << "1->create tree\n2->insert nodes into tree\n3->traversal\n4->display\n5->Get No.of leaf nodes\n6->swap\n7->copy\n8->get height of tree\n9->get No. of nodes\n10->erase nodes\n11->exit" << endl;
        cout << "**************************************************************************************" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            root = b1.CreateTree();
        }
        else if (choice == 2)
        {

            b1.Insert(root);
        }
        else if (choice == 3)
        {
            int t;
            cout << "1->inorder\n2->preorder\n3->postoreder" << endl;
            cin >> t;
            if (t == 1)
                b1.Inorder(root);
            if (t == 2)
                b1.Preorder(root);
            if (t == 3)
                b1.Postorder(root);

            else
            {
                cout << "enter valid choice" << endl;
            }
        }
        else if (choice == 4)
        {
            b1.display(root);
        }
        else if (choice == 5)
        {
            int c = 0;
            b1.leafnodes(root, c);
            cout << "No.of leafnodes=" << c << endl;
        }
        else if (choice == 6)
        {
            b1.swap(root);
        }
        else if (choice == 7)
        {
            Binary_Tree b2;
            b2 = b1;
            // b2.display(b2.root);
            cout << "tree copied successfuilly" << endl;
            cout << "Address of orignal root node" << &(root) << endl;
            cout << "Address of copied root node" << &(b2.root) << endl;
        }
        else if (choice == 8)
        {
            cout << "height of tree :" << b1.Height(root) << endl;
        }
        else if (choice == 9)
        {
            int n = 0;
            cout << "number of node=" << b1.Num_Nodes(root, n)<<endl;
        }
        else if(choice==10){
            b1.eraseTree(root);
            cout<<"nodes erased succesfully"<<endl;
        }
        else if (choice == 11)
        {
            cout << "exited ....";
            break;
        }
    }

   

    return 0;
}

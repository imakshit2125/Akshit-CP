#include<bits/stdc++.h>
using namespace std;

struct node //Structure to build node of 2-3 tree
{
    int data1;
    int data2;
    node* left;
    node* mid;
    node* right;
};

struct TwoThreeNode //Structure to handle the return value of insert function
{
    int m;
    node* n1;
    node* n2;
};

TwoThreeNode* Make_Node_box(int min, node* nt1, node* nt2) //function to create a Node_box struct from 1 int value and two node pointers
{
    TwoThreeNode* newNode_box = new TwoThreeNode;
    newNode_box->m = min;
    newNode_box->n1 = nt1;
    newNode_box->n2 = nt2;

    return newNode_box;
}

node* Create_NULL() //function for creating NULL node
{
    node* newnode = new node;
    newnode->data1 = -1;
    newnode->data2 = -1;
    newnode->left = NULL;
    newnode->mid = NULL;
    newnode->right = NULL;

    return newnode;
}

node* CreateTwoNode(int m, node* n1, node* n2) //function to create a node with 2 children
{
    node* newnode = new node;
    newnode->data1 = m;
    newnode->data2 = -1;
    newnode->left = n1;
    newnode->mid = n2;
    newnode->right = NULL;

    return newnode;
}

node* CreateThreeNode(int m1, int m2, node* n1, node* n2, node* n3) //function to create a node with 3 children
{
    node* newnode = new node;
    newnode->data1 = m1;
    newnode->data2 = m2;
    newnode->left = n1;
    newnode->mid = n2;
    newnode->right = n3;
    
    return newnode;
}

bool Is_Null(node* n) //function to check if the given node is null node
{
    if(n->data1==-1 and n->data2==-1 and n->left==NULL and n->mid==NULL and n->right==NULL) 
        return true;
    else 
        return false;
}

bool IsLeaf(node* n) //function to check if the given node is leaf node
{
    if(n->data1>=1 and n->data2==-1 and n->left==NULL and n->mid==NULL and n->right==NULL) 
        return true;
    else 
        return false;
}

bool IsTwoNode(node* n) //function to check if the given node is 2 children node
{
    if(n->data1>=1 and n->data2==-1 and n->left!=NULL and n->mid!=NULL and n->right==NULL)
        return true;
    else 
        return false;
}
bool IsThreeNode(node* n) //function to check if the given node is 3 children node
{
    if(n->data1>=1 and n->data2>=1 and n->left!=NULL and n->mid!=NULL and n->right!=NULL) 
        return true;
    else 
        return false;
}

int find_height(node* root) // function to find height of tree
{
    if(Is_Null(root))
        return 0;

    int height = 1;

    while(!IsLeaf(root))
    {
        root = root->left;
        height++;
    }

    return height;
}

TwoThreeNode* InsertT1(node* T, node* U, int height1, int height2, int min1, int min2, int depth) // Insert in Tree 1
{

    if(height2-height1-1 == depth )
    {
        if(IsTwoNode(U))
        {
            TwoThreeNode* Node_box = Make_Node_box(-1, CreateThreeNode(min1, U->data1, T, U->left, U->mid), NULL);
            return Node_box;
        }

        else
        {
            TwoThreeNode* Node_box = Make_Node_box(U->data1, CreateTwoNode(min1, T, U->left), CreateTwoNode(U->data2, U->mid, U->right));
            return Node_box;
        }
    }

    else if(IsTwoNode(U))
    {
        TwoThreeNode* ib = InsertT1(T,U->left,height1,height2,min1,min2,depth+1);
        
        if(ib->n2==NULL)
        {
            TwoThreeNode* Node_box = Make_Node_box(-1, CreateTwoNode(U->data1, ib->n1, U->mid), NULL);
            return Node_box;
        }
        else
        {
            TwoThreeNode* Node_box = Make_Node_box(-1, CreateThreeNode(ib->m, U->data1, ib->n1, ib->n2, U->mid), NULL);
            return Node_box;
        }
    }

    else
    {
        TwoThreeNode* ib = InsertT1(T,U->left,height1,height2,min1,min2,depth+1);

        if(ib->n2==NULL)
        {
            TwoThreeNode* Node_box = Make_Node_box(-1, CreateThreeNode(U->data1, U->data2, ib->n1, U->mid, U->right), NULL);
            return Node_box;
        }
        else
        {
            TwoThreeNode* Node_box = Make_Node_box(U->data1, CreateTwoNode(ib->m, ib->n1, ib->n2), CreateTwoNode(U->data2, U->mid, U->right));
            return Node_box;
        }
    }
}

TwoThreeNode* InsertT2(node* T, node* U, int height1, int height2, int min1, int min2, int depth) // Insert in Tree 2
{
    if(depth == height1-height2-1)
    {
        if(IsTwoNode(T))
        {
            TwoThreeNode* Node_box = Make_Node_box(-1, CreateThreeNode(T->data1, min2, T->left, T->mid, U), NULL);
            return Node_box;
        }

        else
        {
            TwoThreeNode* Node_box = Make_Node_box(T->data2, CreateTwoNode(T->data1, T->left, T->mid), CreateTwoNode(min2, T->right, U));
            return Node_box;
        }
    }

    else if(IsTwoNode(T))
    {
        TwoThreeNode* ib = InsertT2(T->mid,U,height1,height2,min1,min2,depth+1);
        
        if(ib->n2==NULL)
        {
            TwoThreeNode* Node_box = Make_Node_box(-1, CreateTwoNode(T->data1, T->left, ib->n1), NULL);
            return Node_box;
        }
        else
        {
            TwoThreeNode* Node_box = Make_Node_box(-1, CreateThreeNode(T->data1, ib->m, T->left, ib->n1, ib->n2), NULL);
            return Node_box;
        }
    }

    else
    {
        TwoThreeNode* ib = InsertT2(T->right,U,height1,height2,min1,min2,depth+1);

        if(ib->n2==NULL)
        {
            TwoThreeNode* Node_box = Make_Node_box(-1, CreateThreeNode(T->data1, T->data2, T->left, T->mid, ib->n1), NULL);
            return Node_box;
        }
        else
        {
            TwoThreeNode* Node_box = Make_Node_box(T->data2, CreateTwoNode(T->data1, T->left, T->mid), CreateTwoNode(ib->m, ib->n1, ib->n2));
            return Node_box;
        }
    }
}

node* Merge(node* T, node* U, int min1, int min2) // function to merge Tree1 and Tree2
{
    int height1, height2;
    height1 = find_height(T);
    height2 = find_height(U);

    if(height1==height2)
    {
        node* finalroot = CreateTwoNode(min2, T, U);
        return finalroot;
    }
    
    else if(height1>height2)
    {
        TwoThreeNode* b = InsertT2(T,U,height1,height2,min1,min2,0);
        if(b->n2==NULL)
            return b->n1;
        else
            return CreateTwoNode(b->m, b->n1, b->n2);
    }
    
    else
    {
        TwoThreeNode* b = InsertT1(T,U,height1,height2,min1,min2,0);
        if(b->n2==NULL)
            return b->n1;
        else
            return CreateTwoNode(b->m, b->n1, b->n2);

    }
}

void Extract(node* V) // Function to Extract and print the Merged Tree
{
    if(Is_Null(V))
        return;

    else if(IsLeaf(V))
        cout << V->data1 << endl;

    else
    {
        Extract(V->left);
        Extract(V->mid);
        if(V->right)
            Extract(V->right);
    }
}

node* MakeSingleton(int x) //function for creating leaf node
{
    node* newnode = new node;
    newnode->data1 = x;
    newnode->data2 = -1;
    newnode->left = NULL;
    newnode->mid = NULL;
    newnode->right = NULL;

    return newnode;
}

void Test() // Function to test our Programe
{
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;

    node* T = MakeSingleton(l1);
    

    for (int i = l1+1; i <=r1; i++)
    {
        T = Merge(T,MakeSingleton(i), l1, i+1);
    }
    
    node* U = MakeSingleton(l2);


    for (int i = l2+1; i <=r2; i++)
    {
        U = Merge(U,MakeSingleton(i), l2, i+1);
    }

    node* V = Merge(T,U,l1,l2);

    Extract(V);

}

int main()
{
    
    Test();

    return 0;
}
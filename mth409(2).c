#include <iostream.h>
#include <stdlib.h>
using namespace std;

struct node //node of a 2-3 tree
{
    int d1;
    int d2;
    node* left;
    node* mid;
    node* right;
};

struct boxOutput //struct to handle the return value of insert function
{
    int m;
    node* n1;
    node* n2;
};

boxOutput* makeBox(int min, node* nt1, node* nt2) //function to create a box struct from 1 int value and tw node pointers
{
    boxOutput* newbox = (boxOutput*) malloc(sizeof(boxOutput));
    newbox->m = min;
    newbox->n1 = nt1;
    newbox->n2 = nt2;

    return newbox;
}

node* makeNull() //function to create a null node
{
    node* newnode = (node*) malloc(sizeof(node));
    newnode->d1 = -1;
    newnode->d2 = -1;
    newnode->left = nullptr;
    newnode->mid = nullptr;
    newnode->right = nullptr;

    return newnode;
}

node* makeLeaf(int v) //function to create a leaf node
{
    node* newnode = (node*) malloc(sizeof(node));
    newnode->d1 = v;
    newnode->d2 = -1;
    newnode->left = nullptr;
    newnode->mid = nullptr;
    newnode->right = nullptr;

    return newnode;
}

node* makeTwoNode(int m, node* n1, node* n2) //function to create a node with 2 children
{
    node* newnode = (node*) malloc(sizeof(node));
    newnode->d1 = m;
    newnode->d2 = -1;
    newnode->left = n1;
    newnode->mid = n2;
    newnode->right = nullptr;

    return newnode;
}

node* makeThreeNode(int m1, int m2, node* n1, node* n2, node* n3) //function to create a node with 3 children
{
    node* newnode = (node*) malloc(sizeof(node));
    newnode->d1 = m1;
    newnode->d2 = m2;
    newnode->left = n1;
    newnode->mid = n2;
    newnode->right = n3;
    
    return newnode;
}

bool checkNull(node* n) //function to check if the given node is null node
{
    if(n->d1==-1 && n->d2==-1 && n->left==nullptr && n->mid==nullptr && n->right==nullptr) return true;
    else return false;
}

bool checkLeaf(node* n) //function to check if the given node is leaf node
{
    if(n->d1>=1 && n->d2==-1 && n->left==nullptr && n->mid==nullptr && n->right==nullptr) return true;
    else return false;
}

bool checkTwoNode(node* n) //function to check if the given node is 2 children node
{
    if(n->d1>=1 && n->d2==-1 && n->left!=nullptr && n->mid!=nullptr && n->right==nullptr) return true;
    else return false;
}
bool checkThreeNode(node* n) //function to check if the given node is 3 children node
{
    if(n->d1>=1 && n->d2>=1 && n->left!=nullptr && n->mid!=nullptr && n->right!=nullptr) return true;
    else return false;
}

int height(node* root)
{
    if(checkNull(root))
        return 0;

    int h = 1;

    while(!checkLeaf(root))
    {
        root = root->left;
        h++;
    }

    return h;
}

boxOutput* insert1(node* T, node* U, int h1, int h2, int min1, int min2, int depth)
{

    if(depth = h2-h1-1)
    {
        if(checkTwoNode(U))
        {
            boxOutput* box = makeBox(-1, makeThreeNode(min1, U->d1, T, U->left, U->mid), nullptr);
            return box;
        }

        else
        {
            boxOutput* box = makeBox(U->d1, makeTwoNode(min1, T, U->left), makeTwoNode(U->d2, U->mid, U->right));
            return box;
        }
    }

    else if(checkTwoNode(U))
    {
        boxOutput* ib = insert1(T,U->left,h1,h2,min1,min2,depth+1);
        
        if(ib->n2==nullptr)
        {
            boxOutput* box = makeBox(-1, makeTwoNode(U->d1, ib->n1, U->mid), nullptr);
            return box;
        }
        else
        {
            boxOutput* box = makeBox(-1, makeThreeNode(ib->m, U->d1, ib->n1, ib->n2, U->mid), nullptr);
            return box;
        }
    }

    else
    {
        boxOutput* ib = insert1(T,U->left,h1,h2,min1,min2,depth+1);

        if(ib->n2==nullptr)
        {
            boxOutput* box = makeBox(-1, makeThreeNode(U->d1, U->d2, ib->n1, U->mid, U->right), nullptr);
            return box;
        }
        else
        {
            boxOutput* box = makeBox(U->d1, makeTwoNode(ib->m, ib->n1, ib->n2), makeTwoNode(U->d2, U->mid, U->right));
            return box;
        }
    }
}

boxOutput* insert2(node* T, node* U, int h1, int h2, int min1, int min2, int depth)
{
    if(depth == h1-h2-1)
    {
        if(checkTwoNode(T))
        {
            boxOutput* box = makeBox(-1, makeThreeNode(T->d1, min2, T->left, T->mid, U), nullptr);
            return box;
        }

        else
        {
            boxOutput* box = makeBox(T->d2, makeTwoNode(T->d1, T->left, T->mid), makeTwoNode(min2, T->right, U));
            return box;
        }
    }

    else if(checkTwoNode(T))
    {
        boxOutput* ib = insert2(T->mid,U,h1,h2,min1,min2,depth+1);
        
        if(ib->n2==nullptr)
        {
            boxOutput* box = makeBox(-1, makeTwoNode(T->d1, T->left, ib->n1), nullptr);
            return box;
        }
        else
        {
            boxOutput* box = makeBox(-1, makeThreeNode(T->d1, ib->m, T->left, ib->n1, ib->n2), nullptr);
            return box;
        }
    }

    else
    {
        boxOutput* ib = insert2(T->right,U,h1,h2,min1,min2,depth+1);

        if(ib->n2==nullptr)
        {
            boxOutput* box = makeBox(-1, makeThreeNode(T->d1, T->d2, T->left, T->mid, ib->n1), nullptr);
            return box;
        }
        else
        {
            boxOutput* box = makeBox(T->d2, makeTwoNode(T->d1, T->left, T->mid), makeTwoNode(ib->m, ib->n1, ib->n2));
            return box;
        }
    }
}

node* merge(node* T, node* U, int min1, int min2)
{
    int h1, h2;
    h1 = height(T);
    h2 = height(U);

    if(h1==h2)
    {
        node* finalroot = makeTwoNode(min2, T, U);
        return finalroot;
    }
    
    else if(h1>h2)
    {
        boxOutput* b = insert2(T,U,h1,h2,min1,min2,0);
        if(b->n2==nullptr)
            return b->n1;
        else
            return makeTwoNode(b->m, b->n1, b->n2);
    }
    
    else
    {
        boxOutput* b = insert1(T,U,h1,h2,min1,min2,0);
        if(b->n2==nullptr)
            return b->n1;
        else
            return makeTwoNode(b->m, b->n1, b->n2);

    }
}

void extract(node* V)
{
    if(checkNull(V))
        return;

    else if(checkLeaf(V))
        cout << V->d1 << " ";

    else
    {
        extract(V->left);
        extract(V->mid);
        if(V->right)
            extract(V->right);
    }
}

int main()
{
    int a,b,c,d;

    cout << "Provide space saperated 4 natural numbers (a,b,c,d) in incresing order." << endl;
    cout << "Output will be space saperated range of natural numbers a to b and c to d." << endl;
    cout << "Note:- a and b can be same, c and d can be same, but b andd c has to be distinct" <<endl;

    cin >> a >> b >> c >> d;

    node* T = makeLeaf(a);
    node* U = makeLeaf(c);

    for (int i = a; i < b; i++)
    {
        T = merge(T,makeLeaf(i+1), a, i+1);
    }
    
    for (int j = c; j < d; j++)
    {
        U = merge(U,makeLeaf(j+1), c, j+1);
    }

    node* V = merge(T,U,a,c);

    extract(V);

    return 0;
}
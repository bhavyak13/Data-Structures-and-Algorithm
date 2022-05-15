#include <bits/stdc++.h>
using namespace std;

struct node
{
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
};

class AVL
{
private:
    struct node *root = NULL;

public:
    node *insert(node *t, int key);
    int nodeHeight(node *p);
    int balanceFactor(node *p);
    node *LLrotaion(node *p);
    node *RRrotaion(node *p);
    node *LRrotaion(node *p);
    node *RLrotaion(node *p);
    void preorder(node *t)
    {
        if (t == NULL)
        {
            return;
        }
        cout << t->data << " ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
};
int AVL::balanceFactor(node *p)
{
    int hr, hl;
    if (p->lchild && p)
    {

        hl = (p->lchild->height);
    }
    else
        hl = 0;
    if (p->rchild && p)
    {
        hr = (p->rchild->height);
    }
    else
        hr = 0;
    return (hl - hr);
}
int AVL::nodeHeight(node *p)
{
    // cout << p->data << " ";
    if ((!p->lchild && !p->rchild) || !p)
        return 1;
    else if (p->lchild && p->rchild)
        return max(p->lchild->height, p->rchild->height) + 1;
    else if (p->lchild)
        return p->lchild->height + 1;
    else
        return p->rchild->height + 1;
}
node *AVL::LLrotaion(node *p)
{
    node *pl = p->lchild;
    node *plr = p->lchild->rchild;
    p->lchild->rchild = p;
    p->lchild = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    if (p == root)
        root = pl;
    return pl;
}
node *AVL::LRrotaion(node *p)
{
    node *plr = p->lchild->rchild;
    node *plrl = plr->lchild;
    node *plrr = plr->rchild;
    plr->rchild = p;
    plr->lchild = p->lchild;
    p->lchild->rchild = plrl;
    p->lchild = plrr;
    p->height = nodeHeight(p);
    plr->lchild->height = nodeHeight(plr->lchild);
    plr->height = nodeHeight(plr);
    if (p == root)
        root = plr;
    return plr;
}
node *AVL::RLrotaion(node *p)
{
    node *prl = p->rchild->lchild;
    node *prll = prl->lchild;
    node *prlr = prl->rchild;
    prl->rchild = p->rchild;
    prl->lchild = p;
    p->rchild->lchild = prlr;
    p->rchild = prll;
    p->height = nodeHeight(p);
    prl->rchild->height = nodeHeight(prl->rchild);
    prl->height = nodeHeight(prl);
    if (p == root)
        root = prl;
    return prl;
}
node *AVL::RRrotaion(node *p)
{
    node *pr = p->rchild;
    node *prl = p->rchild->lchild;
    p->rchild->lchild = p;
    p->rchild = prl;
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);
    if (p == root)
        root = pr;
    return pr;
}
node *AVL::insert(node *p, int key)
{
    if (!root) //root==NULL
    {
        root = new node;
        root->data = key;
        root->lchild = root->rchild = NULL;
        root->height = 1;
        return root;
    }
    if (!p) //p==NULL
    {
        p = new node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        p->height = 1;
        return p;
    }
    if (key < p->data)
        p->lchild = insert(p->lchild, key);
    else
        p->rchild = insert(p->rchild, key);
    p->height = nodeHeight(p);
    if (balanceFactor(p) == 2)
    {
        if (balanceFactor(p->lchild) == 1)
            p = LLrotaion(p);
        else if (balanceFactor(p->lchild) == -1)
            p = LRrotaion(p);
    }
    else if (balanceFactor(p) == -2)
    {
        if (balanceFactor(p->rchild) == 1)
            p = RLrotaion(p);
        else if (balanceFactor(p->rchild) == -1)
            p = RRrotaion(p);
    }
    return p;
}

int main()
{
    AVL t;
    node *root = NULL;
    root = t.insert(root, 40);
    root=t.insert(root, 50);
    root=t.insert(root, 20);
    root=t.insert(root, 30);
    root=t.insert(root, 10);
    root=t.insert(root, 60);
    root=t.insert(root, 5);
    root=t.insert(root, 25);
    root=t.insert(root, 35);
    root=t.insert(root, 26);
    // root=t.insert(root, 40);
    // root=t.insert(root, 5);
    t.preorder(root);
    return 0;
}
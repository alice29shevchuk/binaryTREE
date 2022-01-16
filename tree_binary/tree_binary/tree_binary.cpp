#include <iostream>
struct Node
{
    int x;
    Node* l;
    Node* r;
};
Node* tree = NULL;
void add(int value,Node**tmp)
{
    if ((*tmp) == NULL)
    {
        (*tmp) = new Node;
        (*tmp)->x = value;
        (*tmp)->l = (*tmp)->r = NULL;
        return;
    }
    else
    {
        if (value > (*tmp)->x)
        {
            add(value, &(*tmp)->r);
        }
        else
        {
            add(value, &(*tmp)->l);
        }
    }
}
void show(Node*t)
{
    if (t == NULL)
    {
        return;
    }
    else
    {
        show(t->l);
        std::cout << t->x << "\n";            
    }
    show(t->r);
}
Node* dtree(Node* root, int key)
{
    Node* p, * p2;

    if (!root)
    {
        return root;                    
    }

    if (root->x == key)                 
    { 
        if (root->l == root->r)         
        {
            free(root);
            return NULL;
        }
        else if (root->l == NULL)        
        {
            p = root->r;
            free(root);
            return p;
        }
        else if (root->r == NULL) 
        {
            p = root->l;
            free(root);
            return p;
        }
        else                               
        {
            p2 = root->r;
            p = root->r;
            while (p->l) p = p->l;
            p->l = root->l;
            free(root);
            return p2;
        }
    }
    if (root->x < key)
    {
        root->r= dtree(root->r, key);
    }
    else
    {
        root->l = dtree(root->l, key);
    }
    return root;
}
int main()
{
    setlocale(0, "");
    int n;
    int val;
    std::cout << "Введите кол-во элементов: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите число: ";
        std::cin >> val;                       
        add(val, &tree);                 
    }
    std::cout << "Полученное дерево:\n";
    show(tree);
    std::cout << "\n";
    int ch;
    std::cout << "Введите что хотите удалить: ";
    std::cin >> ch;
    tree = dtree(tree, ch);
    std::cout << "\n";
    show(tree);
}


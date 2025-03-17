#include <iostream>
#include <map>

using namespace std;

struct child {
    char left;
    char right;
};

map <char, child> traversal;

void PrintPreorder(char print_node); 
void PrintInorder(char print_node); 
void PrintPostorder(char print_node); 

int main()
{
    int node_number;
    cin>>node_number;
    
    for(int i=0;i<node_number;i++) {
        char data, left_child, right_child;
        cin >> data >> left_child >> right_child;
        
        traversal[data].left = left_child;
        traversal[data].right = right_child;
    }
    
    PrintPreorder('A');
    cout<<"\n";
    PrintInorder('A');
    cout<<"\n";
    PrintPostorder('A');
    

    return 0;
}

void PrintPreorder(char print_node) 
{
    if(print_node == '.') return ;
    cout<<print_node;
    PrintPreorder(traversal[print_node].left);
    PrintPreorder(traversal[print_node].right);
}

void PrintInorder(char print_node) 
{
    if(print_node == '.') return ;
    PrintInorder(traversal[print_node].left);
    cout<<print_node;
    PrintInorder(traversal[print_node].right);
}

void PrintPostorder(char print_node) 
{
    if(print_node == '.') return ;
    PrintPostorder(traversal[print_node].left);
    PrintPostorder(traversal[print_node].right);
    cout<<print_node;
}

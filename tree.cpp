#include <iostream>
#include <string.h>
using namespace std;

struct node 
{
    string label;
    //char label[10];
    int ch_count;
    struct node *child[10];
}*root;


class bookTree
{
public:
    void create_tree();
    void display(node *r1);
   // struct node *root;

    bookTree()
    {
        root = NULL;
    }
};

void bookTree::create_tree()
{
    int tbooks, tchapters, i, j, k;
    root = new node;
    cout << "Enter name of book : ";
    getline(cin,root->label);
    cout << "Enter number of chapters in book : ";
    cin >> tchapters;
    root->ch_count = tchapters;
    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;
        cout << "Enter the name of Chapter " << i + 1 << " : ";
        getline(cin,root->child[i]->label);
        cout << "Enter number of sections in Chapter : " << root->child[i]->label << " : ";
        cin >> root->child[i]->ch_count;
        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout<<"Enter the name of Section "<<j+1<<" : ";
            getline(cin,root->child[i]->child[j]->label);
            
        }
    }
}

void bookTree ::display(node *r1){
    int i,j,k,tchapters;
    if(r1== NULL){
        cout<<"Empty tree";
    }
    else{
        cout<<"Book tile : "<<r1->label;
        tchapters = r1->ch_count;
        for(i = 0;i<tchapters;i++){
            cout<<"\n - Chapters : "<<i+1;
            cout<<r1->child[i]->label;
            cout<<"\n -- Sections : ";
            for(j= 0; j<r1->child[i]->ch_count;j++){
                cout<<"\n "<<r1->child[i]->child[j]->label;
            }
        }
    }
    cout<<endl;

}

int main(){
    bookTree b;
    b.create_tree();
    b.display(root);
}
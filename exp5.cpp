#include<iostream>
#include<string.h>


using namespace std;


struct node {
    char k[20];
    char m[20];
    node *l;
    node *r;
};


class dict{
    public:
    node *root;
    dict(){
        root = NULL;
    }
    void create();
    void insert(node *root,node *temp);
    void dispA(node *root);
    void update(node *root,char[20]);
};


void dict:: create(){
    char ch;
    node *temp;
    do{
        temp = new node;
        cout<<"Enter the key : ";
        cin>>temp->k;
        cout<<"Enter the meaning : ";
        cin>>temp->m;
        temp->r = NULL;
        temp->l = NULL;
        if(root == NULL){
            root = temp;
        }
        else{
            insert(root,temp);
        }
        cout<<"add more (y/n) : ";
        cin>>ch;
    }while(ch =='y');
}

void dict :: insert(node *root, node *temp){
    if(strcmp(temp->k,root->k)<0){
        if(root->l == NULL){
            root->l = temp;
        }
        else{
            insert(root->l,temp);
        }
    }
    else{
        if(root->r == NULL){
            root->r = temp;
        }
        else{
            insert(root->r, temp);
        }
    }
}

void dict :: dispA(node *root){
    if(root != NULL){
        dispA(root->l);
        cout<<"\n Key : "<<root->k;
        cout<<"\t Meaning : "<<root->m;
        dispA(root->r);
    }
    
}

void dict :: update(node *root, char nk[20]){
    while(root != NULL){
        if(strcmp(nk,root->k)==0){
            cout<<"Enter the Changes : ";
            cin>>root->m;
            cout<<"Meaning Updated Successfully";
            break;
        }
        else if(strcmp(nk,root->k)<0){
            update(root->l,nk);
        }
        else{
            update(root->r,nk);
        }
    }
    if(root== NULL)
    cout<<"Invalid Key ";
}



int main(){
    dict d;
    int ch;
    char k[20];
    do{
        cout<<" 1. Create \n 2. Display Ascending \n 3. Update : \n 0. Exit ";
        cin>>ch;
        if(ch==1)
        d.create();
        else if(ch==2)
        d.dispA(d.root);
        else if(ch == 3){
            cout<<"Enter the key to update : ";
            cin>>k;
            d.update(d.root,k);
            
        }

    }while(ch!=0);

    
}
#include<iostream>
#include<string>

using namespace std;


struct node{
    int data;
    node *r;
    node *l;
};
int count;

class bst{
    public:
    node *root,*temp;
    bst(){
        root = NULL;
        count = 0;
    }
    void create();
    void insert(node*,node*);
    void preOrder(node *root);
    void postOrder(node *root);
    void search(node *root,int key);
    int height(node *root);
};
void bst:: create(){
    char ans;
    do{
    temp = new node;
    cout<<"Enter the data : ";
    cin>>temp->data;
    if(root == NULL){
        root = temp;
        count++;
    }
    else{
        insert(root,temp);
        count++;
    }
    cout<<"Do you want to insert more value : ";cin>>ans;
    cout<<endl;
    }while(ans == 'y');
    cout<<"Total No. of nodes is : "<<count<<endl;
}

void bst:: insert(node *root, node *temp){
    if(temp->data>=root->data){
        if(root->r == NULL){
            root->r = temp;
        }else{
            insert(root->r,temp);
        }
    }
    else{
        if(root->l== NULL){
            root->l = temp;
        }
        else{
            insert(root->l,temp);
        }
    }


}


void bst :: preOrder(node *root){

    if(root!=NULL){
        cout<<" "<<root->data;
        preOrder(root->l);
        preOrder(root->r);
    }
}

void bst :: postOrder(node *root){
    if(root!=NULL){
        postOrder(root->l);
        postOrder(root->r);
        cout<<" "<<root->data;
    }
}

void bst :: search(node *root,int key){
    temp = root;
    int flag=0;
    while(temp!=NULL){
        if(temp->data== key){
            cout<<"Key found";
            flag = 1;
            break;
        }
        node *parent = temp;
        if(key>parent->data){
            temp = temp->r;
        }
        else{
            temp = temp->l;
        }

    }
    if(flag == 0){
        cout<<"key not found";
    }

}


int bst :: height(node *root){
    int hr,hl;
    if(root == NULL){
        return 0;
    }else if(root->l == NULL && root->r== NULL)
    {
        return 1;
    }
    hr = 1+ height(root->r);
    hl= 1+height(root->l);
    if(hr>hl){
        return hr;
    }
    else{
        return hl;
    }
}





int main(){
    bst t;
    t.create();
    cout<<"Preorder : ";
    t.preOrder(t.root);
    cout<<endl;
    cout<<"Postorder : ";
    t.postOrder(t.root);
    cout<<endl;
    //t.search(t.root,9);
    cout<<"Height of tree : "<<t.height(t.root);

}
#include<iostream>
#include<string>

using namespace std;

struct node {
    string label;
    int count;
    node *child[10];

   
    
}*root;

class tree{
    public:
 tree(){
        root = NULL;
    }

    void createTree();
    void displayTree();
    
};

void tree :: createTree(){
    int i,j,tchapters;
    root = new node;
    cout<<"Enter the name of book : ";
    
    getline(cin,root->label);
    cout<<"Enter the number of chapters : ";
    cin>>tchapters;
    root->count = tchapters;

    for(i = 0; i<tchapters;i++){
        cin.ignore();
        root->child[i]= new node;
       
        cout<<"Enter the name of chapter "<<i+1<<" : ";
       
        getline(cin,root->child[i]->label);
        cout<<"Enter the number of sections : ";
        cin>>root->child[i]->count;
        for(j = 0;j<root->child[i]->count;j++){
            cin.ignore();
            root->child[i]->child[j] = new node;
            cout<<"Enter the name of section "<<j+1<<" of "<<root->child[i]->label<<" : ";
            
            getline(cin,root->child[i]->child[j]->label);
           

        }
    }
    

}

void tree :: displayTree(){
    
    cout<<"            Book Structure           ";
    cout<<endl;
   
    cout<<"Title : \t"<<root->label;

    cout<<endl;

    cout<<"Chapters : "<<endl;


    for(int i= 0;i<root->count;i++){
        cout<<"\t\t"<<i+1<<" "<<root->child[i]->label<<endl;
        

        for(int j = 0; j<root->child[i]->count;j++){
            cout<<"\t\t\t"<<root->child[i]->child[j]->label<<endl;
        }


    }



}


int main(){
    tree t;
    t.createTree();
    t.displayTree();
}


// #include<iostream>
// #include<string>

// using namespace std;

// struct node {
//     string label;
//     int count;
//     node* child[10];

//     node() {
//         for (int i = 0; i < 10; i++) {
//             child[i] = nullptr;
//         }
//     }
// };

// class tree {
// public:
//     tree() {
//         root = nullptr;
//     }

//     void createTree();
//     void displayTree(node* root);

//     node* root;
// };

// void tree::createTree() {
//     int i, j, tchapters;
//     root = new node;
//     cout << "Enter the name of the book: ";
//     cin.ignore();  // Ignore any previous newline character
//     getline(cin, root->label);
//     cout << "Enter the number of chapters: ";
//     cin >> tchapters;
//     root->count = tchapters;

//     for (i = 0; i < tchapters; i++) {
//         root->child[i] = new node;
//         cout << "Enter the name of chapter " << i + 1 << ": ";
//         cin.ignore();  // Ignore any previous newline character
//         getline(cin, root->child[i]->label);
//         cout << "Enter the number of sections: ";
//         cin >> root->child[i]->count;
//         for (j = 0; j < root->child[i]->count; j++) {
//             root->child[i]->child[j] = new node;
//             cout << "Enter the name of section " << j + 1 << " of " << root->child[i]->label << ": ";
//             cin.ignore();  // Ignore any previous newline character
//             getline(cin, root->child[i]->child[j]->label);
//         }
//     }
// }


// void tree::displayTree(node *currNode) {
//     if (currNode == nullptr)
//         return;

//     cout <<currNode->label;

//     for (int i = 0; i < currNode->count; i++) {
//         displayTree(currNode->child[i]);
//     }
// }

// int main() {
//     tree t;
//     t.createTree();
//     cout << "Book structure:";
//     t.displayTree(t.root);

//     return 0;
// }

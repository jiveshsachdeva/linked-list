/*
************************MADE BY MADHAV ANEJA*********************************
It is a singly linked list code containing all the basic operations...Yes i know what you're thinking
that it is similar to a code seen by you earlier at some website
yes i've learned from the same website but it is an improved version(That code had 2 errors in it)
and it has a lot of comments for beginners so happy learning  :)
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
struct node{//defining node(user defined data type
int info;//value of node
struct node *next;//address of next node
}*start;
class singly
{
    public:
        node *create_node(int);//this function will create node and return it's address
        void insert_begin();
        void insert_pos();//for inserting the node at the given position
        void insert_end();
        void delete_pos();
        void sort1();
        void search();
        void update();
        void reverse();
        void display();
        singly()//constructor used for making an empty linked list
        {
            start = NULL;
        }
};
node* singly::create_node(int val){
struct node *temp;
temp=new(struct node);//allocating memory for a new node
if(temp==NULL){
    cout<<"Memory not allocated"<<endl;
    return 0;
}
else{
    temp->info=val;//putting value in it
    temp->next=NULL;//Because it can be the last node
}
return temp;//returning the node created
}
void singly::insert_begin(){
int val;
cin>>val;//value to be put in the new node
struct node *temp,*p;
temp=create_node(val);//node created with an address temp
if(start==NULL){//empty list case
    start=temp;
    temp->next=NULL;
}
else{
    p=start;
    start=temp;
    start->next=p;
}
}
void singly::insert_end(){
int val;
cin>>val;
struct node *temp,*p;
temp=create_node(val);
if(start==NULL){
    start=temp;
    temp->next=NULL;
}
else{
    p=start;
    while(p->next!=NULL){//traversing the array
        p=p->next;//incrementing the node
    }
    p->next=temp;
    temp->next=NULL;
}
}
void singly::display(){
struct node *p;
if(start==NULL){
    cout<<"List is empty"<<endl;//empty list case
    return;
}
    for(p=start;p!=NULL;p=p->next)//just for making you learn using for loop instead of while ;)
    {
        cout<<p->info;
        if(p->next!=NULL)
            cout<<"->";
    }
}
void singly::insert_pos(){
    struct node *temp,*p,*s,*ptr;
    int count=0;
    p=start;
    while(p!=NULL){//traversing
        count++;//counting the number of nodes
        p=p->next;//incrementing node
    }
 int value,pos;
 cout<<"Enter the value to be inserted: ";
    cin>>value;
cout<<"Enter the position";
cin>>pos;
temp=create_node(value);
if(pos==1){
if(start==NULL){
    start=temp;
    temp->next=NULL;
}
else{
    p=start;
    start=temp;
    start->next=p;
}
}
else if(pos>1&&pos<=count){
        int i;
        s=start;
for(i=1;i<pos;i++){
    ptr=s;//ptr will be the previous node for changing the address when i==pos
    s=s->next;
}
ptr->next=temp;
temp->next=s;
}
else{
    cout<<"position out of range";
}
}
void singly::sort1(){
struct node *ptr,*s;
ptr=start;
int value;
if (start == NULL)
    {
        cout<<"The List is empty"<<endl;
        return;
    }
while(ptr!=NULL){//complexity O(n^2)
    for(s=ptr->next;s!=NULL;s=s->next){
        if(ptr->info > s->info){//swap
            value=ptr->info;
            ptr->info=s->info;
            s->info=value;
        }
    }
    ptr=ptr->next;//incrementing loop 1
}
}
void singly::delete_pos(){
int pos,counter=0;
struct node *p,*s;
p=start;
if(start==NULL){
    cout<<"list is empty";//empty list case
    return;
}
cout<<"enter the position to be deleted";
cin>>pos;
if(pos==1){
    p=start;
    start=start->next;
}
else{
    while(p!=NULL){
            p=p->next;//incrementing
            counter++;//counting nodes
    }
    s=start;
    struct node *ptr;

    if(pos>1&&pos<=counter){//pos in range
            s=start;
        for(int i=1;i<pos;i++){
            ptr=s;
        s=s->next;
    }
    ptr->next=s->next;
    free(s);//deallocating the memory

}
    else
        cout<<"position out of range";

}
}
void singly::search(){
cout<<"enter the value to be searched";
int val,pos=0;
cin>>val;
if(start==NULL)
    cout<<"List is empty";
struct node *p;
p=start;
while(p->info!=val&&p->next!=NULL){
    pos++;
    p=p->next;
}
if(p->info==val)
    cout<<"found at position "<<pos+1<<endl;//as it is starting from start so pos+1(not pos)
if(p==NULL)
cout<<"not found"<<endl;
}
void singly::update(){
if(start==NULL){
    cout<<"list is empty";
    return;
}
struct node *s,*ptr;
int pos,value,counter=0;
cout<<"enter the position to be updated";
cin>>pos;
cout<<"enter the value";
cin>>value;

for(s=start;s!=NULL;s=s->next){
    counter++;
}
if(pos==1)
{
start->info=value;
}
if(pos>counter){
    cout<<"position out of range"<<endl;
}
s=start;
if(pos>1&&pos<=counter){//in range
    for(int i=1;i<pos;i++){
        s=s->next;//incrementing node
}
s->info=value;//value updated
}
}
void singly::reverse(){
if(start==NULL){
    cout<<"list is empty";//empty list case
    return;
}
if(start->next==NULL)//The case if there is only one node
    return;
    struct node *ptr1,*ptr2,*ptr3;
ptr1=start;//at present points at node1
ptr2=ptr1->next;//at present points at node2
ptr3=ptr2->next;//at present points at node3
ptr1->next=NULL;//making the first element the last one
ptr2->next=ptr1;//making second element first especially for the case if it has 2 nodes
while(ptr3!=NULL){
    ptr1=ptr2;
    ptr2=ptr3;//moving forward node by node(eg fibbonaci series :D)
    ptr3=ptr3->next;
    ptr2->next=ptr1;
}
start=ptr2;
}
int main(){
    int ch, nodes, element, position, i;
    singly sl;
    start = NULL;
    while (1)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"4.Sort Link List"<<endl;
        cout<<"5.Delete a Particular Node"<<endl;
        cout<<"6.Update Node Value"<<endl;
        cout<<"7.Search Element"<<endl;
        cout<<"8.Display Linked List"<<endl;
        cout<<"9.Reverse Linked List "<<endl;
        cout<<"10.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            sl.insert_begin();
            cout<<endl;
            break;
        case 2:
            cout<<"Inserting Node at Last: "<<endl;
            sl.insert_end();
            cout<<endl;
            break;
        case 3:
            cout<<"Inserting Node at a given position:"<<endl;
            sl.insert_pos();
            cout<<endl;
            break;
        case 4:
            cout<<"Sort Link List: "<<endl;
            sl.sort1();
            cout<<endl;
            break;
        case 5:
            cout<<"Delete a particular node: "<<endl;
            sl.delete_pos();
            break;
        case 6:
            cout<<"Update Node Value:"<<endl;
            sl.update();
            cout<<endl;
            break;
        case 7:
            cout<<"Search element in Link List: "<<endl;
            sl.search();
            cout<<endl;
            break;
        case 8:
            cout<<"Display elements of link list"<<endl;
            sl.display();
            cout<<endl;
            break;
        case 9:
            cout<<"Reverse elements of Link List"<<endl;
            sl.reverse();
            cout<<endl;
            break;
        case 10:
            cout<<"Exiting..."<<endl;
            exit(0);
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
return 0;
}

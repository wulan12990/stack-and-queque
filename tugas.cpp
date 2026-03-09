#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top = NULL;
Node* front = NULL;
Node* rear = NULL;

void push(int x){
    Node* baru = new Node;
    baru->data = x;
    baru->next = top;
    top = baru;
}

void pop(){
    if(top == NULL){
        cout<<"Stack kosong\n";
    }else{
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void displayStack(){
    Node* temp = top;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void enqueue(int x){
    Node* baru = new Node;
    baru->data = x;
    baru->next = NULL;

    if(front == NULL){
        front = rear = baru;
    }else{
        rear->next = baru;
        rear = baru;
    }
}

void dequeue(){
    if(front == NULL){
        cout<<"Queue kosong\n";
    }else{
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void displayQueue(){
    Node* temp = front;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int fib(int n){
    if(n<=1)
        return n;
    else
        return fib(n-1) + fib(n-2);
}

int main(){
    push(10);
    push(20);
    push(30);

    cout<<"Stack: ";
    displayStack();

    enqueue(1);
    enqueue(2);
    enqueue(3);

    cout<<"Queue: ";
    displayQueue();

    cout<<"Fibonacci: ";
    for(int i=0;i<6;i++){
        cout<<fib(i)<<" ";
    }

    return 0;
}
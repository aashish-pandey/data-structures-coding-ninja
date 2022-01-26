/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
#include<iostream>
using namespace std;

Node * reverse(Node *head){
    if(head == NULL || head->next == NULL)return head;
    
    Node *sm = reverse(head->next);
    
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return sm;
}

Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(head == NULL || k <= 1)return head;
    
    int n = 0;
    Node *tmp = head;
    
    while(head != NULL){
        n++;
        head = head->next;
    }
    
    
    head = tmp;
    if(n == k){
        return reverse(head);
    }
    Node *nh[n];
    
    int i = 0, x = 1;
    
    while(head != NULL){
        if(x%k == 1){
            nh[i] = head;
            x++;
            head = head->next;
        }
        else if(x%k == 0){
            Node *rt = head->next;
            head -> next = NULL;
            head = rt;
            x++;
            if(head!= NULL)
            i++;
        }
        else{
            x++;
            head = head->next;
        }
    }
    
    int y = i;
    
    for(i = 0; i <= y; i++){
        
        nh[i] = reverse(nh[i]);
    }
    
    for(int i = 0; i < y; i++){
        Node *yu = nh[i];
        
        while(yu != NULL){
            cout<<yu->data<<" ";
            yu = yu->next;
        }
        
        yu = nh[i+1];
    }
    
    return nh[y];
        
}

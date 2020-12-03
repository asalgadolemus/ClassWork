/*************************************************************************
	Programmer:			Mary Norwood, Oberon Ilano, Antonio Salgado-Lemus
	Author(s):       	Dr. Janet Jenkins, Mary Norwood 
						Antonio Salgado-Lemus, Oberon Ilano	
	Assignment:			3 - Templates with dependent classes
	Description:		Linked List with template class
	Due Date:			January 24, 2019
	Course:				CS355 - Data Structures and Algorithms
*************************************************************************/
#include <iostream>
using namespace std;

//**************************************************************
//Forward Declaration
//**************************************************************
template <class T>
class Node;

template <class T>
class LL;

template <class T>
class Node{
    T data;
    Node<T>* next;
    Node(T d);
    Node(T d, Node<T>* n);
    friend class LL<T>;

};

template <class T>
class LL{
    Node<T>* head;
public:
    LL();
	// copy constructor, assignment operator, destructor to handle deep
	// copying and destroying of data
    LL(const LL<T>& src);
    LL<T>& operator=(const LL<T>& src);
	~LL();
	bool InsertFront(T e);
    void Print()const;
	 
};

//**************************************************************
//Node Implementation 
//**************************************************************
template <class T>
Node<T>::Node(T d):data(d), next(NULL){}

template <class T>
Node<T>::Node(T d, Node<T>* n):data(d), next(n){}

//**************************************************************
//Linked List Implementation
//**************************************************************
template <class T>
LL<T>::LL():head(NULL){}

//**************************************************************
//Deep copy constructor
//**************************************************************
template <class T>
LL<T>::LL(const LL<T>& src){
    if (src.head != NULL){
       head = new Node<T>(src.head -> data); 
       Node<T>* NTemp = head; 
       Node<T>* temp = src.head -> next; 
       while (temp != NULL){  
             NTemp -> next = new Node<T>(temp -> data); 
             temp = temp -> next;  
             NTemp = NTemp -> next; 
       } 
    }                
    else
        head = NULL; 
}

//**************************************************************
//Assignment Operator
//**************************************************************
template <class T>
LL<T>& LL<T>::operator=(const LL<T>& src){
 	if(this != &src){
 		//~LL();
		while(head != NULL){
	        Node<T>* temp = head; 
	        head = head -> next; 
	        delete temp;
	    }
	}
    if (src.head != NULL){
        head = new Node<T>(src.head -> data); 
        Node<T>* NTemp = head; 
        Node<T>* temp = src.head -> next; 
        while (temp != NULL){  
            NTemp -> next = new Node<T>(temp -> data); 
            temp = temp -> next;  
            NTemp = NTemp -> next; 
       } 
    }                
    else
        head = NULL; 
      
    return *this;
}

//**************************************************************
//Destructor
//**************************************************************
template <class T>
LL<T>::~LL(){
	while(head != NULL){
        Node<T>* temp = head; 
        head = head -> next; 
        delete temp;
    }
}

//**************************************************************
//Erase function
//**************************************************************
/*template <class T>
void LL<T>::Erase(){
	Node<T>* curr = head;
	Node<T>* temp = head;
	while(curr != NULL){
	  curr = curr -> next;
      delete temp;
	}
	head = NULL;
}*/

//**************************************************************
//Insert function
//**************************************************************
template <class T>
bool LL<T>::InsertFront(T e)
{
    head = new Node<T>(e, head);
    return head;    
}

//**************************************************************
//Print function
//**************************************************************
template <class T>
void LL<T>::Print()const
{
     Node<T>* curr = head;
     while(curr != NULL)
       {
        cout << curr -> data << endl;
        curr = curr -> next;
       }
}

int main(){
    LL <int> list;
   // LL <int> list2;
   
    cout << "First pass " << endl;
    list.InsertFront(10);
    list.Print();

    cout << "Second pass " << endl;
    list.InsertFront(15);
    list.Print();

    cout << "Third pass " << endl;
    list.InsertFront(20);
    list.Print();
    
   // list2 = list;
   // cout << "Print list 2" << endl;
   // list1.Print();

    return 0;
}

#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
#include "llrec.cpp"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

struct IsOdd
{
    bool operator()(int num) {
        return (num % 2) != 0;
    }
};

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------


int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    //Node* head = nullptr;
	
    cout << "Original list: ";
    print(head);

    // Test out your linked list code

    //readList(const char* filename)
    /*Node* small = (Node*) &head; // set to a non-null address
	Node* large = (Node*) &head; // set to a non-null address
	llpivot(head, small, large, 5);

    cout << "new head: ";
    print(head);
    print(small);
    print(large);*/


    Node* help = llfilter(readList(argv[1]), IsOdd());
    cout << "new list: " << endl;
    print(help);



    
    return 0;

}

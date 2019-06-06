/*
CH08-320143
a1_p4.cpp
Aashish Paudel
a.paudel@jacobs-university.de
*/

/**
 * @list: tail->elem_s->head
 * @push_back-> tail->elem_s->prev_head->head
 * @push_front-> tail->prev_tail->elem_s->head
 */
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

/**
 * Behaves as a doubly linkedlist to store the values for our
 * List 
 */
template <class T>
class Node {
 public:
  Node* next;
  Node* prev;
  T data;
};

template <class T>
class List {
 private:
  Node<T>* tail;
  Node<T>* head;
  int size;

 public:
    // Initializing default constructor
    List() : size(0){}

    // returns the size of the list
    int getSize() {
        return size;
    }

    // returns first element of the list
    T get_front(){
        return (tail)->data;
    }

    // returns last element of the list
    T get_last() {
        return (head)->data;
    }
  
    //Removes the last elment and returns the value
    T r_last() {
        Node<T>* temp = (head); 
        T data = temp->data;
        head = (head)->prev;
        size--;
        delete temp;
        return data;
    }

  // Removes the last elements and returns the value
    T r_front(){
        T data = (tail)->data; 
        tail = (tail)->next;
        size--;
        return data;
  }

    // push_back (adds element to the last)
    void push_back(T data) {
        Node<T>* new_elem = new Node<T>;

        new_elem->data = data;
    
        if (size == 0) {
            new_elem->next = NULL;
            new_elem->prev = NULL;
            head = new_elem;
            tail = new_elem;
        }
        
        new_elem->next = NULL;
        new_elem->prev = head;
        head = new_elem;

        size++;
    }

  // Adds element to the first
  void push_front(T data) {
    Node<T>* new_elem = new Node<T>;

    new_elem->data = data;

    if (size == 0) {
        new_elem->next = NULL;
        new_elem->prev = NULL;
        head = new_elem;
        tail = new_elem;
    }
  
    new_elem->prev = NULL;
    new_elem->next = this->tail;
    tail = new_elem;

    size++;
  }
  
  // Destructor
  ~List() {
    Node<T>* new_elem = this->tail;

    while((tail) != NULL) {
      new_elem = (tail)->next;
      delete tail;
      tail = new_elem;
    }
  };
};
#endif
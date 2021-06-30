#ifndef LL_H
#define LL_H

#include <iostream>
#include <vector>

namespace cs126LinkedList {
    
    
    // Template linked list class
    template<typename ElementType>
    class LinkedList {
        // You may add anything here you need to implement the linked list.
        // You will probably want to define the LinkedListNode class here.
        class Node {
        public:
            ElementType data;
            Node* next;
            Node* prev;
        };
    private:
        Node* head_;
        Node* tail_;
        int size_;
    public:
        LinkedList();                                                   // Default constructor
        explicit LinkedList(const std::vector<ElementType> &values);    // Initilize from vector
        
        // Big 5
        LinkedList(const LinkedList& source);                                           // Copy constructor
        LinkedList(LinkedList&& source) noexcept;                                       // Move constructor
        ~LinkedList();                                                                  // Destructor
        LinkedList<ElementType>& operator=(const LinkedList<ElementType>& source);      // Copy assignment operator
        LinkedList<ElementType>& operator=(LinkedList<ElementType>&& source) noexcept;  // Move assignment operator
        
        void push_front(ElementType value);         // Push value on front
        void push_back(ElementType value);          // Push value on back
        ElementType front() const;                  // Access the front value
        ElementType back() const;                   // Access the back valueW
        void pop_front();                           // remove front element
        void pop_back();                            // remove back element
        int size() const;                           // return number of elements
        bool empty() const;                         // check if empty
        void clear();                               // clear the contents
        void RemoveNth(int n);                      // remove the Nth element from the front 0 indexed
        bool operator==(const LinkedList<ElementType> &rhs) const;
        
        // iterator
        class iterator : std::iterator<std::forward_iterator_tag, ElementType> {
            // You may add any data you need here
            Node* current_;
            LinkedList* container_;
        public:
            iterator() : current_(nullptr) {};
            iterator(Node* head, LinkedList* list) : current_(head) , container_(list) {};
            // You may add any constructors you want here
            iterator& operator++();
            ElementType& operator*();
            bool operator!=(const iterator& other);
        };
        
        iterator begin();
        iterator end();
        
        // const_iterator
        class const_iterator : std::iterator<std::forward_iterator_tag, ElementType> {
            // You may add any data you need here
            Node* current_;
            LinkedList* container_;
        public:
            const_iterator() : current_(nullptr) {};
            const_iterator(Node* head, LinkedList* list) : current_(head) , container_(list) {};
            // You may add any constructors you want here
            const_iterator& operator++();
            const ElementType& operator*();
            bool operator!=(const const_iterator& other);
        };
        
        const_iterator begin() const;
        const_iterator end() const;
        
    };
    

    
    template<typename ElementType>
    std::ostream& operator<<(std::ostream& os, const LinkedList<ElementType>& list);
    
    // needed for template instantiation
#include "ll.cpp"
    

} // namespace cs126linkedlist

#endif //LL_H


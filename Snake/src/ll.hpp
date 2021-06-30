// Your .cpp
// You can add any helper functions or headers that you need.
// You should also fill in all the function bodies.

using namespace cs126LinkedList;


template<typename ElementType>
LinkedList<ElementType>::LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {
    head_ = nullptr;
    tail_ = nullptr;
}

template<typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) : head_(nullptr), tail_(nullptr), size_(0) {
    if (values.size() == 0) {
        std::cout << "There are no values";
        return;
    } else {
        for (auto it = values.begin(); it < values.end(); it++) {
            Node* current = new Node;
            if (it == values.begin()) {
                current->data = *it;
                current->prev = NULL;
                head_ = current;
                tail_ = current;
            } else {
                current = new Node;
                current->data = *it;
                current->prev = tail_;
                tail_->next = current;
                tail_ = current;
            }
            size_++;
        }
        tail_->next = NULL;
    }
}

// Copy constructor

template<typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) : head_(nullptr), tail_(nullptr), size_(0) {
    //std::cout << source.head_->data;
    if (source.empty()) {
        std::cout << "This list is empty";
        return;
    } else {
        Node* current = new Node;
        Node* newHead = new Node;
        newHead->data = source.head_->data;
        newHead->prev = nullptr;
        current = source.head_->next;
        head_ = newHead;
        tail_ = newHead;
        size_++;
        while (current != nullptr) {
            newHead = new Node;
            newHead->data = current->data;
            newHead->prev = tail_;
            tail_->next = newHead;
            tail_ = newHead;
            current = current->next;
            size_++;
        }
        tail_->next = nullptr;
    }
}


// Move constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {
    head_ = source.head_;
    tail_ = source.tail_;
    size_ = source.size_;
    source.head_ = nullptr;
    source.tail_ = nullptr;
    source.size_ = 0;
}

// Destructor
template<typename ElementType>
LinkedList<ElementType>::~LinkedList() {
    Node* current = head_;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete (current);
        current = next;
    }
    head_ = nullptr;
    size_ = 0;
}

// Copy assignment operator
template<typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator= (const LinkedList<ElementType>& source) {
    if (source.empty()) {
        std::cout << "This list is empty";
    } else {
        Node* current = new Node;
        Node* newHead = new Node;
        newHead->data = source.head_->data;
        newHead->prev = nullptr;
        current = source.head_->next;
        head_ = newHead;
        tail_ = newHead;
        size_++;
        while (current != nullptr) {
            newHead = new Node;
            newHead->data = current->data;
            newHead->prev = tail_;
            tail_->next = newHead;
            tail_ = newHead;
            current = current->next;
            size_++;
        }
        tail_->next = nullptr;
    }
    return *this;
}

// Move assignment operator
template<typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator= (LinkedList<ElementType>&& source) noexcept {
    head_ = source.head_;
    tail_ = source.tail_;
    size_ = source.size_;
    source.head_ = nullptr;
    source.tail_ = nullptr;
    source.size_ = 0;
    return *this;
}

template<typename ElementType>
void LinkedList<ElementType>::push_front(ElementType value) {
    if (head_ == nullptr) {
        Node* current = new Node;
        current->data = value;
        current->next = nullptr;
        current->prev = nullptr;
        head_ = current;
        size_++;
    } else {
        Node* current = new Node;
        current->data = value;
        current->next = head_;
        current->prev = nullptr;
        if (head_ != nullptr) {
            head_->prev = current;
        }
        head_ = current;
        size_++;
    }
}

template<typename ElementType>
void LinkedList<ElementType>::push_back(ElementType value) {
    if (head_ == nullptr) {
        Node* current = new Node;
        current->data = value;
        current->prev = nullptr;
        current->next = nullptr;
        head_ = current;
        size_++;
    } else {
        Node* current = new Node;
        current->data = value;
        current->prev = tail_;
        current->next = nullptr;
        if (tail_ != nullptr) {
            tail_->next = current;
        }
        tail_ = current;
        size_++;
    }
}

template<typename ElementType>
ElementType LinkedList<ElementType>::front() const{
    return head_->data;
}

template<typename ElementType>
ElementType LinkedList<ElementType>::back() const {
    return tail_->data;
}

template<typename ElementType>
void LinkedList<ElementType>::pop_front() {
    Node* current = head_;
    head_ = head_->next;
    free(current);
}

template<typename ElementType>
void LinkedList<ElementType>::pop_back() {
    Node* current = tail_;
    if (tail_ != nullptr) {
        tail_ = tail_->prev;
    }
    if (tail_ != nullptr) {
        tail_->next = nullptr;
    }
    free(current);
}

template<typename ElementType>
int LinkedList<ElementType>::size() const {
    return size_;
}

template<typename ElementType>
bool LinkedList<ElementType>::empty() const {
    if (head_ == nullptr && size_ == 0 && tail_ == nullptr) {
        return true;
    } else {
        return false;
    }
}

template<typename ElementType>
void LinkedList<ElementType>::clear() {
    Node* current = head_;
    Node* next = new Node;
    
    while (current != nullptr) {
        next = current->next;
        free(current);
        current = next;
    }
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

template<typename ElementType>
std::ostream& operator<<(std::ostream& os, const LinkedList<ElementType>& list) {
    if (list.size() == 0) {
        os << "this is an empty list";
        return os;
    } else {
        LinkedList<ElementType> duplicate = list;
        auto it = duplicate.begin();
        while (it != duplicate.end()) {
            os << *it << " ";
            ++it;
        }
    }
    return os;
}

template<typename ElementType>
void LinkedList<ElementType>::RemoveNth(int n) {
    LinkedList<ElementType> duplicate = *this;
    Node* current = head_;
    if (head_ == nullptr) {
        std::cout << "Element cannot be removed from empty set";
        return;
        
    } else if (size() <= n) {
        std::cout << "Index is too large";
        return;
        
    } else if (n == 0) {
        this->pop_front();
        
    } else if (n == (this->size() - 1)) {
        this->pop_back();
        
    } else {
        for (int i = 0; i < n; i++) {
            current = current->next;
        }
        Node* deleteNode = new Node;
        deleteNode = current;
        current->next->prev = current->prev;
        current->prev->next = current->next;
        free(deleteNode);
        size_--;
    }
}

template<typename ElementType>
bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {
    bool isMatching = false;
    if (size() != rhs.size()) {
        isMatching = false;
    } else {
        Node* leftHand = new Node;
        Node* leftNext = new Node;
        Node* rightHand = new Node;
        Node* rightNext = new Node;
        rightHand->data = rhs.head_->data;
        rightNext = rhs.head_;
        leftHand->data = head_->data;
        leftNext = head_;
        while (rightHand != nullptr) {
            if (rightHand->data == leftHand->data) {
                isMatching = true;
            } else {
                isMatching = false;
            }
            leftNext = leftNext->next;
            rightNext = rightNext->next;
            leftHand = leftNext;
            rightHand = rightNext;
        }
    }
    return isMatching;
}

template<typename ElementType>
bool operator!=(const LinkedList<ElementType>& lhs, const LinkedList<ElementType> &rhs) {
    if (lhs == rhs) {
        return false;
    } else {
        return true;
    }
}

template<typename ElementType>
typename LinkedList<ElementType>::iterator& LinkedList<ElementType>::iterator::operator++() {
    current_ = current_->next;
    return *this;
}

template<typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() {
    return current_->data;
}

template<typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(const LinkedList<ElementType>::iterator& other) {
    if (current_ == other.current_) {
        return false;
    } else {
        return true;
    }
}

template<typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
    return iterator(head_, this);
}

template<typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
    return iterator(tail_->next, this);
}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator& LinkedList<ElementType>::const_iterator::operator++() {
    current_ = current_->next;
    return current_;
}

template<typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() {
    return current_->data;
}

template<typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(const LinkedList<ElementType>::const_iterator& other) {
    if (current_ == other.current_) {
        return false;
    } else {
        return true;
    }
}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::begin() const {
    LinkedList<ElementType> temp = *this;
    return const_iterator(head_, temp);
}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end() const {
    return const_iterator(tail_->next, this);
}

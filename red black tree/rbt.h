#ifndef rbt_h
#define rbt_h

#include <iostream>
#include <utility>
#include <stdexcept>

namespace pic10c
{
    template <typename T, typename compare_type = std::less<T>>
    class rbt
    {
            // have to put here so that iterator recognizes node (node = private class)
        class node
        {   // need this so we can access value, parent, left, right, and color
            friend rbt;
        public:
            /**
             constructs a node with a value of type T and assigns its
             pointers to left&right children and parent nodes
             default value for color is black, unless "red" is passed as an argument
             
             @param val is value of the node
             @param colour is for when nodes are initialized with a color, which will be
             used for every inserted node except the root (all nodes will be red upon
             initial insertion)
             */
            node(T val, std::string colour = "black") : value(std::move(val)), parent(nullptr), left(nullptr), right(nullptr), color(colour) {}
            
        private:
            T value;
            node* parent;
            node* left;
            node* right;
            std::string color;
        };
        
    public:     // need iterator public so the main cpp can use it
        class iterator
        {       // need this so we can access value, parent, left, right, and color
            friend rbt;
        public:
            /**
             constructs an iterator that points to a node in a tree,
             initializes the member variables for the node and tree
             
             @param theNode is the node to which iterator will point
             @param theTree is the tree in which iterator is located
             */
            iterator(node* theNode, rbt* theTree) : curNode(theNode), curTree(theTree) {}
            
            /**
             prefix ++ moves the iterator forward and then returns it

             @return reference to an iterator that is one more than
             the previous position
             */
            iterator& operator++()
            {       // if there's a right child, go right and then all the way left
                if (curNode->right != nullptr)
                {
                    curNode = curNode->right;
                
                    while (curNode->left != nullptr)
                    {
                        curNode = curNode->left;
                    }
                    
                    return *this;
                }       // if there are no more right children
                else
                {
                    node* originalNode = curNode;
                    node* pare = curNode->parent;
                        // if this is the left child, its parent will be next value (left < parent)
                        // otherwise keep going up until you hit new parent where curNode = left child
                    while (pare != nullptr && pare->left != curNode)
                    {
                        curNode = pare;
                        pare = curNode->parent;
                    }
                        // if curNode is the root, ogNode is the last item in the tree
                    if (pare == nullptr)
                    {   // point to null now since no more to traverse
                        curNode = originalNode->right;
                    }
                    else
                    {   // after loop it's a left child, only need to move up to parent node
                        curNode = pare;
                    }
                    
                    return *this;
                }
            }
            
            /**
             postfix ++ copies the iterator, increments it, and then
             returns it
             
             @return an iterator that is one more than the previous
             position
             */
            iterator operator++(int)
            {
                rbt copy(*this);
                ++(*this);
                return copy;
            }
            
            /**
             prefix -- moves the iterator back and then returns it
             
             @return reference to an iterator that is one less than
             the previous position
             */
            iterator& operator--()
            {           // go left and then all the way rihgt
                if (curNode->left != nullptr)
                {
                    curNode = curNode->left;
                    
                    while (curNode->right != nullptr)
                    {
                        curNode = curNode->right;
                    }
                    
                    return *this;
                }       // if there are no more left children
                else
                {
                    node* originalNode = curNode;
                    node* pare = curNode->parent;
                        // if this is the right child, its parent will be next value (right > parent)
                        // otherwise keep going up until you hit new parent where curNode = right child
                    while (pare != nullptr && pare->right != curNode)
                    {
                        curNode = pare;
                        pare = curNode->parent;
                    }
                        // if curNode is the root, ogNode is the last item in the tree
                    if (pare == nullptr)
                    {   // point to null now since no more to traverse
                        curNode = originalNode->left;
                    }
                    else
                    {   // after loop it's a right child, only need to move up to parent node
                        curNode = pare;
                    }
                    
                    return *this;
                }
            }
            
            /**
             postfix -- copies the iterator, decrements it, and then
             returns it
             
             @return an iterator that is one less than the previous
             position
             */
            iterator operator--(int)
            {
                rbt copy(*this);
                --(*this);
                return copy;
            }
            
            /**
             == operator checks if the iterators are equal
             
             @param other is reference to const iterator to which you're
             comparing
             @return true if the nodes are equal, false if they are not
             */
            bool operator==(const iterator& other) const
            {
                return (this->curNode == other.curNode);
            }
            
            /**
             != operator chekcs if the iterators are not equal
             
             @param other is reference to const iterator to which you're
             comparing
             @return true if nodes are unequal, false if they are not
             */
            bool operator!=(const iterator& other) const
            {
                return (this->curNode != other.curNode);
            }
            
            /**
             dereferencing operator returns value of the node to which
             iterator is currently pointing to
             
             @return reference to const T which is the value of the node
             */
            const T& operator*() const
            {
                
                return (curNode->value);
            }
            
            /**
             arrow operator is a pointer to the value of the node to which
             iterator iss currently pointing to
             
             @return pointer to const T which is the value of the node
             */
            const T* operator->() const
            {
                return &(curNode->value);
            }
        private:
            node* curNode;
            rbt* curTree;
        };
                // need iterator public so the main cpp can use it
            class const_iterator
            {   // need this so we can access value, parent, left, right, and color
                friend rbt;
            public:
                /**
                 constructs an iterator that points to a node in a tree,
                 initializes the member variables for the node and tree
                 
                 @param theNode is the const node to which iterator will point
                 @param theTree is the const tree in which iterator is located
                 */
                const_iterator(const node* theNode, const rbt* theTree) : curNode(theNode), curTree(theTree) {}

                /**
                 prefix ++ moves the iterator forward and then returns it

                 @return reference to an iterator that is one more than
                 the previous position
                 */
                const_iterator& operator++()
                {       // if there's a right child, go right and then all the way left
                    if (curNode->right != nullptr)
                    {
                        curNode = curNode->right;
                    
                        while (curNode->left != nullptr)
                        {
                            curNode = curNode->left;
                        }
                        
                        return *this;
                    }       // if there are no more right children
                    else
                    {
                        const node* originalNode = curNode;
                        const node* pare = curNode->parent;
                        // if this is the left child, its parent will be next value (left < parent)
                        // otherwise keep going up until you hit new parent where curNode = left child
                        while (pare != nullptr && pare->left != curNode)
                        {
                            curNode = pare;
                            pare = curNode->parent;
                        }
                            // if curNode is the root, ogNode is the last item in the tree
                        if (pare == nullptr)
                        {   // point to null now since no more to traverse
                            curNode = originalNode->right;
                        }
                        else
                        {   // after loop it's a left child, only need to move up to parent node
                            curNode = pare;
                        }
                        
                        return *this;
                    }
                }
                
                /**
                 postfix ++ copies the iterator, increments it, and then
                 returns it
                 
                 @return an iterator that is one more than the previous
                 position
                 */
                const_iterator operator++(int)
                {
                    rbt copy(*this);
                    ++(*this);
                    return copy;
                }
                
                /**
                 prefix -- moves the iterator back and then returns it
                 
                 @return reference to an iterator that is one less than
                 the previous position
                 */
                const_iterator& operator--()
                {           // go left and then all the way rihgt
                    if (curNode->left != nullptr)
                    {
                        curNode = curNode->left;
                        
                        while (curNode->right != nullptr)
                        {
                            curNode = curNode->right;
                        }
                        
                        return *this;
                    }       // if there are no more left children
                    else
                    {
                        node* originalNode = curNode;
                        node* pare = curNode->parent;
                            // if this is the right child, its parent will be next value (right > parent)
                            // otherwise keep going up until you hit new parent where curNode = right child
                        while (pare != nullptr && pare->right != curNode)
                        {
                            curNode = pare;
                            pare = curNode->parent;
                        }
                            // if curNode is the root, ogNode is the last item in the tree
                        if (pare == nullptr)
                        {   // point to null now since no more to traverse
                            curNode = originalNode->left;
                        }
                        else
                        {   // after loop it's a right child, only need to move up to parent node
                            curNode = pare;
                        }
                        
                        return *this;
                    }
                }
                
                /**
                 postfix -- copies the iterator, decrements it, and then
                 returns it
                 
                 @return an iterator that is one less than the previous
                 position
                 */
                const_iterator operator--(int)
                {
                    rbt copy(*this);
                    --(*this);
                    return copy;
                }
                
                /**
                 == operator checks if the iterators are equal
                 
                 @param other is reference to const iterator to which you're
                 comparing
                 @return true if the nodes are equal, false if they are not
                 */
                bool operator==(const const_iterator& other)
                {
                    return (this->curNode == other.curNode);
                }
                
                /**
                 != operator chekcs if the iterators are not equal
                 
                 @param other is reference to const iterator to which you're
                 comparing
                 @return true if nodes are unequal, false if they are not
                 */
                bool operator!=(const const_iterator& other)
                {
                    return (this->curNode != other.curNode);
                }
                
                /**
                 dereferencing operator returns value of the node to which
                 iterator is currently pointing to
                 
                 @return reference to const T which is the value of the node
                 */
                const T& operator*() const
                {
                    return (curNode->value);
                }
                
                /**
                 arrow operator is a pointer to the value of the node to which
                 iterator iss currently pointing to
                 
                 @return pointer to const T which is the value of the node
                 */
                const T* operator->() const
                {
                    return &(curNode->value);
                }
            private:
                const node* curNode;
                const rbt* curTree;
            };
        
        /**
         constructs a red black tree w/ the provided compare_type argument
         if no argument, compare_type pred is default initialized to compare_type {}
         vector values initialized to be an empty vector of type T
         
         @param predVal used to initialize compare_type pred
         */
        rbt(compare_type predVal = compare_type{}) noexcept : root(nullptr), pred(predVal),
                                                              dupe(false), elem(0) {}
        
        /**
         destructor recursively deletes all notes to clear up the
         memory that was dynamically allocated
         */
        ~rbt()
        {
            destructRec(root);
        }
        
        /**
         copy constructor copies information of other tree to construct
         the new one
         
         @param other is reference to const rbt, whose contents are
         to be copied
         */
        rbt(const rbt& other) : root(other.root), pred(other.pred), dupe(other.dupe), elem(other.elem)
        {
            copyRec(root, other.root);
        }
        
        /**
         move constructor steals the resources of other tree to construct
         the new one
         
         @param other is an lvalue reference to rbt, whose contents are
         swapped with the default constructed (empty) rbt
         */
        rbt(rbt&& other) noexcept : rbt()
        {
            swap(other);
        }
        
        /**
         copy & move assignment operators
         
         @param other is the rbt that you're assigning
         @return reference to rbt with the newly assigned data
         */
        rbt& operator=(rbt other)
        {
            swap(*this, other);
            
            return *this;
        }
        
        /**
         constructs a T using the list of templated given arguments and
         attempts to insert the T into the tree
         
         @param insertVals is a variadic list of arguments
         */
        template <typename... Types>
        void emplace(Types&&... insertVals)
        {
            insert(T(std::forward<Types>(insertVals)...));
        }
        
        /**
         removes the node to which the given iterator is pointing and
         reassigns the necessary pointers
         
         @param I is reference to iterator whose node we are removing
         */
        void erase(iterator I)
        {           // base case of no children
            if (I.curNode->left == nullptr && I.curNode->right == nullptr)
            {       // if there are no children on node, just delete it
                if (I.curNode == root)
                {   // deleting the root
                    --elem;
                    delete I.curNode;
                    I.curNode = nullptr;
                    return;
                }
                else if (pred(I.curNode->value, I.curNode->parent->value))
                {   // if val < parent, then val must be parent's left child
                    if (I.curNode->color == "red")
                    {   // removal case 2
                        --elem;
                        I.curNode->parent->left = nullptr;
                        delete I.curNode;
                        I.curNode = nullptr;
                        return;
                    }
                    else if (I.curNode->color == "black")
                    {
                        I.curNode->color = "dblack";
                    }
                    
                    if (I.curNode->color == "dblack")
                    {
                        fixDB(I);
                    }
                    
                    --elem;
                    I.curNode->parent->left = nullptr;
                    delete I.curNode;
                    I.curNode = nullptr;
                    return;
                }
                else
                {   // if val > parent, then val must be parent's right child
                    if (I.curNode->color == "red")
                    {   // removal case 2
                        --elem;
                        I.curNode->parent->left = nullptr;
                        delete I.curNode;
                        I.curNode = nullptr;
                        return;
                    }
                    else if (I.curNode->color == "black")
                    {
                        I.curNode->color = "dblack";
                    }
                    
                    if (I.curNode->color == "dblack")
                    {
                        fixDB(I);
                    }
                    
                    --elem;
                    I.curNode->parent->right = nullptr;
                    delete I.curNode;
                    I.curNode = nullptr;
                    return;
                }
            }
            else if (I.curNode->left == nullptr || I.curNode->right == nullptr)
            {           // base case if there's only one child
                if (I.curNode->left == nullptr)
                {       // if there is no left child, curNode only has right child
                    if (I.curNode->parent != nullptr)
                    {   // need non-null parent if we're accessing its value and other nodes
                        if (pred(I.curNode->value, I.curNode->parent->value))
                        {   // if val < parent, then curr must be parent's left child
                            I.curNode->parent->left = I.curNode->right;
                            I.curNode->right->parent = I.curNode->parent;
                            
                            if (I.curNode->right->color == "red")
                            {   // removal case 1
                                I.curNode->right->color = "black";
                            }
                            // parent's new left child is the deleted node's right child
                            --elem;
                            delete I.curNode;
                            I.curNode = nullptr;
                            return;
                        }   // deleted node's prev child's parent is deleted's prev parent
                        else
                        {   // otherwise val > parent, so curr is parent's right child
                            I.curNode->parent->right = I.curNode->right;
                            I.curNode->right->parent = I.curNode->parent;

                            if (I.curNode->right->color == "red")
                            {   // removal case 1
                                I.curNode->right->color = "black";
                            }
                            
                            --elem;
                            delete I.curNode;
                            I.curNode = nullptr;
                            return;
                        }
                    }
                    else
                    {       // null parent means just reassign node's parent ptr & root
                        I.curNode->right->parent = I.curNode->parent;
                        root = I.curNode->right;
                        
                        --elem;
                        delete I.curNode;
                        I.curNode = nullptr;
                        return;
                    }
                }
                else
                {       // if there is no right child, curNode only has left child
                    if (I.curNode->parent != nullptr)
                    {   // need non-null parent if we're accessing its value and other nodes
                        if (pred(I.curNode->value, I.curNode->parent->value))
                        {   // if val < parent, then curr must be parent's left child
                            I.curNode->parent->left = I.curNode->left;
                            I.curNode->left->parent = I.curNode->parent;

                            if (I.curNode->left->color == "red")
                            {   // removal case 1
                                I.curNode->left->color = "black";
                            }
                            
                            --elem;
                            delete I.curNode;
                            I.curNode = nullptr;
                            return;
                        }   // deleted node's prev child's parent is deleted's prev parent
                        else
                        {   // otherwise val > parent, curr is parent's right child
                            I.curNode->parent->right = I.curNode->left;
                            I.curNode->left->parent = I.curNode->parent;

                            if (I.curNode->left->color == "red")
                            {   // removal case 1
                                I.curNode->left->color = "black";
                            }
                            
                            --elem;
                            delete I.curNode;
                            I.curNode = nullptr;
                            return;
                        }
                    }
                    else
                    {       // null parent means just reassign node's parent ptr & root
                        I.curNode->left->parent = I.curNode->parent;
                        root = I.curNode->left;
                        
                        --elem;
                        delete I.curNode;
                        I.curNode = nullptr;
                        return;
                    }
                }
            }
            else
            {           // if there are two children, recurse to a base case
                node* prevNode = I.curNode;
                I.curNode = I.curNode->right;
                        // go to leftmost node, swap values w/ previous node we were at
                while (I.curNode->left != nullptr)
                {
                    I.curNode = I.curNode->left;
                }
                        // sets previous value to the "new" one since curNode is being deleted
                prevNode->value = I.curNode->value;
                erase(I);
            }   // ^ recurse til you hit the none/one children left base cases
        }
        
        /**
         if tree is empty, insertVal becomes the root,
         otherwise the fcn goes through the tree and puts insertVal
         in its proper spot (left or right based on its value relative
         to root; left side if < root, right side if > root)
         
         @param insertVal is the value being inserted into the tree
         */
        void insert(T insertVal)
        {   // if root is null, tree is empty, and no color passed bc root is always black
            if (root == nullptr)
            {   // handles insertion case 1 (if the tree is empty)
                root = new node(std::move(insertVal));
            }
            else
            {   // all inserted nodes are red
                node* addedNode = new node(std::move(insertVal), "red");
                insertRec(root, addedNode);
            }
            if (!dupe)
            {   // if duplicate, nothing was added and # of elements shouldn't ++
                elem++;
            }   // reset dupe for next inserted value
            dupe = false;
        }
        
        /**
         prints out the contents of the red-black tree
         */
        void print()
        {
            node* curr = root;
            
            if (curr != nullptr)
            {   // just in case one tries to print an empty tree
                while (curr->right != nullptr)
                {
                    curr = curr->right;
                }
                // calls recursive fcn from rightmost node
                std::cout << '\n';
                printRec(curr);
            }
        }
        
        /**
         swaps the contents of two rbts and uses adl lookup in case
         a better swap fcn from std is needed
         
         @param other is reference to rbt whose contents are to
         be swapped
         */
        void swap(rbt& other)
        {
            using std::swap;

            node* tempRoot = other.root;
            compare_type tempPred = other.pred;
            size_t tempElem = other.elem;
            bool tempDupe = other.dupe;
            
            other.root = this->root;
            other.pred = this->pred;
            other.elem = this->elem;
            other.dupe = this->dupe;
            
            this->root = tempRoot;
            this->pred = tempPred;
            this->elem = tempElem;
            this->dupe = tempDupe;
        }
        
        /**
         uses recursive helper fcn to find the leftmost node,
         lowest value in tree = first element

         @return iterator at the leftmost node
         */
        iterator begin()
        {
            return traverseLeft(root);
        }
        
        /**
         uses recursive helper fcn to find the rightmost node,
         then goes to its right child (one past the last node)
         and points to nullptr
         
         @return iterator at one past the last node
         */
        iterator end()
        {
            return traverseRight(root);
        }
        
        /**
         uses recursive helper fcn to find the leftmost node,
         lowest value in tree = first element (overloaded on const)

         @return iterator at the leftmost node
         */
        const_iterator begin() const
        {
            const node* temp = root;
            return traverseLeftCon(temp);
        }
        
        /**
         uses recursive helper fcn to find the rightmost node,
         then goes to its right child (one past the last node)
         and points to nullptr (overloaded on const)
         
         @return iterator at one past the last node
         */
        const_iterator end() const
        {
            const node* temp = root;
            return traverseRightCon(temp);
        }
        
        /**
         finds the specified value in the tree and returns the
         end node (one of the null children of the last node,
         aka one past the end) if the value is not in the tree
         
         @param valToLocate is the given value that is passed
         (the value that the user is looking for)
         @return an iterator pointing to the node that has the
         desired value
         */
        iterator find(const T& valToLocate)
        {
            iterator found = findRec(root, valToLocate);
            return found;
        }
        
        /**
         finds the specified value in the tree and returns the
         end node (one of the null children of the last node,
         aka one past the end) if the value is not in the tree
         (overloaded on const)
         
         @param valToLocate is the given value that is passed
         (the value that the user is looking for)
         @return an iterator pointing to the node that has the
         desired value
         */
        const_iterator find(const T& valToLocate) const
        {
            const_iterator found = findRecCon(root, valToLocate);
            return found;
        }
        
        /**
         gives number of elements in the tree
         
         @return size_t of number of elements in tree
         elem increments every time insert is called
         */
        size_t size() const
        {
            return elem;
        }
    
    private:
        bool dupe;
        node* root;
        size_t elem;
        compare_type pred;
        
        /**
         helper fcn that recursively copies values from one tree to another
         
         @param copierNode is the pointer node from the tree who's copying
         the nodes from another tree
         @param copieeNode is the pointer node from the tree whose nodes
         are being copied
         */
        void copyRec(node* copierNode, node* copieeNode)
        {
            if (copieeNode->left == nullptr && copieeNode->right == nullptr)
            {       // end case, no more children on left or right
                return;
            }
            else
            {       // if left is null (but right is not since end case wasn't triggered)
                if (copieeNode->left == nullptr)
                {
                    copierNode->right = copieeNode->right;
                    copyRec(copierNode->right, copieeNode->right);
                }   // if right is null (but left is not since end case wasn't triggered)
                else if (copieeNode->right == nullptr)
                {
                    copierNode->left = copieeNode->left;
                    copyRec(copierNode->left, copieeNode->left);
                }
                else
                {   // neither branch is null, so copy left and right branches
                    copierNode->left = copieeNode->left;
                    copierNode->right = copieeNode->right;
                    // recurse down left and right branches
                    copyRec(copierNode->left, copieeNode->left);
                    copyRec(copierNode->right, copieeNode->right);
                }
            }       // these first two if/else ifs avoid some extra recursion if one branch
        }           // has no left/right children

        /**
         recursive helper function destructs nodes when childless
         otherwise it goes down branches of tree until childless (last) node is found
         
         @param theNode is current node you're on
         */
        void destructRec(node*& theNode)
        {
            if (theNode != nullptr)
            {
                if (theNode->left != nullptr)
                {   // if no left child, go down right branch
                      destructRec(theNode->left);
                }
                
                if (theNode->right != nullptr)
                {   // if no right child, go down left branch
                      destructRec(theNode->right);
                }
                
                if (theNode->left == nullptr && theNode->right == nullptr)
                {       // if no children left, delete node
                    if (theNode == root)
                    {   // gives "pointer being freed was not allocated" error
                        // if i try to delete theNode on xcode, works on vis stud and linux
                        delete theNode;
                        --elem;
                        root = nullptr;
                        return;
                    }
                    
                    --elem;
                    delete theNode;
                    theNode = nullptr;
                    return;
                }
            }
        }
        
        /**
         recursively looks through tree to find value (helper fcn for find)
         
         @param current is a reference to pointer to the node we're currently on
         @param locateVal is the value we're looking for in the tree
         @return an iterator pointing to the desired node (points one past the end (null)
         if not found)
         */
        iterator findRec(node*& current, const T& locateVal)
        {               // if equal, then we found the value!
            if (locateVal == current->value)
            {
                iterator I (current, this);
                return I;
            }
            else
            {           // if what we're looking for is less than node, go left
                if (pred(locateVal, current->value))
                {       // if value to locate < parent and right == null, no more nodes left
                    if (current->left == nullptr)
                    {   // returns the nullptr past the end (starts @ current node to save time)
                        return traverseRight(current);
                    }
                    else
                    {
                        return findRec(current->left, locateVal);
                    }
                }
                else    // otherwise go right since value is bigger than node
                {       // if value to locate > parent and right == null, no more nodes left
                    if (current->right == nullptr)
                    {   // returns the nullptr past the end (starts @ current node to save time)
                        return traverseRight(current);
                    }
                    else
                    {
                        return findRec(current->right, locateVal);
                    }
                }
            }
        }
        
        /**
         recursively looks through tree to find value (helper fcn for findCon, overloaded on const)
         
         @param current is a reference to pointer to the node we're currently on
         @param locateVal is the value we're looking for in the tree
         @return an iterator pointing to the desired node (points one past the end (null)
         if not found)
         */
        const_iterator findRecCon(node*& current, const T& locateVal)
        {               // if equal, then we found the value!
            if (locateVal == current->value)
            {
                iterator I(current, this);
                return I;
            }
            else
            {           // if what we're looking for is less than node, go left
                if (pred(locateVal, current->value))
                {       // if value to locate < parent and right == null, no more nodes left
                    if (current->left == nullptr)
                    {   // returns the nullptr past the end (starts @ current node to save time)
                        return traverseRight(current);
                    }
                    else
                    {
                        findRecCon(current->left, locateVal);
                    }
                }
                else    // otherwise go right since value is bigger than node
                {       // if value to locate > parent and right == null, no more nodes left
                    if (current->right == nullptr)
                    {   // returns the nullptr past the end (starts @ current node to save time)
                        return traverseRightCon(current);
                    }
                    else
                    {
                        findRecCon(current->right, locateVal);
                    }
                }
            }
        }
        
        /**
         adds up the number of tabs needed in front of the node when printing by
         counting the number of branches it needs to climb in order to reach
         the root (root has 0 tabs since it's the start)
         
         @param curr the node that's about to be printed
         @return number of tabs you need to print before the node
         */
        int findTabNum(node* curr)
        {
            int tabNum = 0;
            
            if (curr != nullptr)
            {
                while (curr->parent != nullptr)
                {   // add tabs for each branch til you get to root
                    curr = curr->parent;
                    ++tabNum;
                }
            }
            
            return tabNum;
        }
        
        /**
         recursive fcn that fixes double black nodes, handling all the removal
         cases and maintaining black depth
         
         @param I is iterator pointing to the double black node you need to fix
         */
        void fixDB(iterator I)
        {
            node* pare = I.curNode->parent;
            
            if (I.curNode == root)
            {       // removal case I
                I.curNode->color = "black";
            }       // removal case II for left child
            else if (pare->left == I.curNode)
            {       // if curr is the left child, its sibling is the right child
                node* rSib = pare->right;
                
                if (rSib != nullptr)
                {
                    if (rSib->color == "red")
                    {   // if the sibling (right child) is red
                        pare->color = "red";
                        rSib->color = "black";
                        
                        rotateLeft(rSib, pare);
                        fixDB(I);
                    }   // recoloring 1st since ptrs will be switched after rotation (just in case)
                    else// if the sibling (right child) is black
                    {   // removal case III for left child w/ black (right) sibling
                        if (rSib->left != nullptr)
                        {   // if there isn't a left child, don't do anything
                            if (rSib->left->color == "red")
                            {   // if the sibling's left chlid is red
                                if (rSib->right->color != "red")
                                {   // and if the sibling's right child is not red
                                    rSib->left->color = "black";
                                    rSib->color = "red";
                                    
                                    rotateRight(rSib->left, rSib);
                                    fixDB(I);
                                }   // need to recolor 1st since ptrs will be different after rotation
                            }
                        }
                        if (rSib->right != nullptr)
                        {
                            if (rSib->right->color == "red")
                            {   // if the sibling's right child is red
                                if (pare->color == "red")
                                {   // removal case IVa
                                    rSib->color = "red";
                                    pare->color = "black";
                                    I.curNode->color = "black";
                                    rSib->right->color = "black";

                                    rotateLeft(rSib, pare);
                                }
                                else if (pare->color == "black")
                                {   // removal case IVb
                                    I.curNode->color = "black";
                                    rSib->right->color = "black";

                                    rotateLeft(rSib, pare);
                                }
                            }
                        }
                        if (rSib->left != nullptr && rSib->right != nullptr)
                        {
                            if (rSib->left->color == "black" && rSib->right->color == "black")
                            {       // if both of black sibling's children are black
                                if (pare->color == "red")
                                {   // removal case Va (red parent)
                                rSib->color = "red";
                                    pare->color = "black";
                                    I.curNode->color = "black";
                                }
                                else if (pare->color == "black")
                                {   // removal case Vb (black parent)
                                    rSib->color = "red";
                                    pare->color = "dblack";
                                    I.curNode->color = "black";
                                    I.curNode = pare;
                                    fixDB(I);
                                }
                            }
                        }
                    }
                }
            }
            else
            {       // if curr is the right child, its sibling is the left child
                node* lSib = pare->left;
                if (lSib != nullptr)
                {
                    // removal case II for right child
                    if (lSib->color == "red")
                    {   // if the sibling (left child) is red
                        pare->color = "red";
                        lSib->color = "black";
                        
                        rotateRight(lSib, pare);
                        fixDB(I);
                    }   // recoloring 1st since ptrs will be different after rotation (just in case)
                    else// if the sibling (left child) is black
                    {   // removal case III for right child w/ black (left) sibling
                        if (lSib->left != nullptr)
                        {
                            if (lSib->left->color == "red")
                            {       // if the sibling's left child is red
                                if (pare->color == "red")
                                {   // removal case IVa (red parent)
                                    lSib->color = "red";
                                    pare->color = "black";
                                    I.curNode->color = "black";
                                    lSib->left->color = "black";

                                    rotateRight(lSib, pare);
                                }
                                else if (pare->color == "black")
                                {   // removal case IVb (black parent)
                                    I.curNode->color = "black";
                                    lSib->left->color = "black";

                                    rotateRight(lSib, pare);
                                }
                            }
                        }
                        if (lSib->right != nullptr)
                        {
                            if (lSib->right->color == "red")
                            {       // if the sibling's right child is red
                                if (lSib->left->color == "black")
                                {   // and if the sibling's left child is not red (black)
                                    lSib->right->color = "black";
                                    lSib->color = "red";
                                    
                                    rotateLeft(lSib->right, lSib);
                                    fixDB(I);
                                }
                            }
                        }
                        if (lSib->left != nullptr && lSib->right != nullptr)
                        {
                            if (lSib->left->color == "black")
                            {       // if both of black sibling's children are black
                                if (lSib->right->color == "black")
                                {
                                    if (pare->color == "red")
                                    {   // removal case Va (red parent)
                                        lSib->color = "red";
                                        pare->color = "black";
                                        I.curNode->color = "black";
                                    }
                                    else if (pare->color == "black")
                                    {   // removal case Vb (black parent)
                                        lSib->color = "red";
                                        pare->color = "dblack";
                                        I.curNode->color = "black";
                                        I.curNode = pare;
                                        fixDB(I);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        /**
         i made the colors for each node the full word "red" or "black," so
         this function simply returns "r" or "b" depending on the color of
         the node so the print function matches the desired output
         
         @param curr is a pointer to the node whose color we desire
         */
        std::string getColor(node* curr)
        {
            if (curr->color == "red")
            {   // if color is red
                return "r";
            }
            else
            {   // if color is black
                return "b";
            }
        }
        
        /**
         helper fcn that recursively checks if new value belongs on left or right of the
         parent and inserts the new value in its proper spot (and assigns pointers accordingly)
         
         @param parent is the parent node starting at the root and recursively working down
         to the appropriate spot for the new value
         @param child is the new value being inserted into the tree
         */
        void insertRec(node* parent, node* child)
        {
            // no duplicates in the tree, so this stops process and deletes the duplicate
            if (child->value == parent->value)
            {
                dupe = true;
                delete child;
                child = nullptr;
                return;
            }
            else if (pred(child->value, parent->value))
            {           // if child < parent, go left
                if (parent->left == nullptr)
                {       // base case: fill the open child spot (if parent has 1 or 0 children)
                    parent->left = child;
                    child->parent = parent;
                    
                    if (parent->color == "black")
                    {   // insertion case 2
                        return;
                    }   // if node's parent is black, adding red child won't affect black depth
                    else
                    {   // insertion cases 3-5 where parent != black and node != root
                        organize(child);
                        return;
                    }
                }
                else
                {       // now compare w/ left child (new parent)
                    insertRec(parent->left, child);
                }
            }
            else
            {           // if child > parent, go right
                if (parent->right == nullptr)
                {       //base case: fill the open child spot (if parent has 1 or 0 children)
                    parent->right = child;
                    child->parent = parent;
                    
                    if (parent->color == "black")
                    {   // insertion case 2
                        return;
                    }   // if node's parent is black, adding a red child won't affect black depth
                    else
                    {   // insertion cases 3-5 where parent != black and node != root
                        organize(child);
                        return;
                    }
                }
                else
                {   // now compare w/ right child (new parent)
                    insertRec(parent->right, child);
                }
            }
        }
        
        /**
         recursively organizes the tree, handling all the insertion test cases for
         when there are double red nodes (parent & a child that are both red) and
         maintaining black depth
         
         @param curr is a reference to pointer to node that we're currently "on," it's
         the red child of a red parent
         */
        void organize(node*& curr)
        {           // called if parent node and child node are both red
            node* pare = curr->parent;
            node* gran = pare->parent;
        
            if (gran->left == pare)
            {       // if parent is a left child, uncle is right child
                node* uncl = gran->right;
                
                if (uncl != nullptr)
                {
                    if (uncl->color == "red")
                    {   // if uncle's color is red, do insertion case 3
                        pare->color = "black";
                        uncl->color = "black";
                        
                        if (gran != nullptr)
                        {   // if parent's parent is not null (if pare is not root)
                            gran->color = "red";
                            
                            if (gran->parent != nullptr)
                            {   // if gran is not root
                                if (gran->parent->color == "red")
                                {   // if gran's pare is red, we have double red, organize again
                                    return organize(gran);
                                }
                                else
                                {
                                    return;
                                }
                            }
                            else
                            {   // if gran's pare IS null, gran is the root and it needs to be black
                                gran->color = "black";
                                return;
                            }
                        }
                    }   // if uncle's color is black or there is no uncle
                }       // parent is a left child, need curr to be left child to rotate
                if (pare->left == curr)
                {       // insertion case 4
                    rotateRight(pare, gran);
                    pare->color = "black";
                    gran->color = "red";
                    return;
                }       // if pare is left child but curr is pare's right child
                else if (pare->right == curr)
                {       // insertion case 5: need to reduce to test case 4
                    rotateLeft(curr, pare);
                    return organize(pare);
                }       // after rotating, we'll have double red on curr & pare
            }           // organize again, now the lines are straight (not crooked)
            else
            {           // if parent is a right child, uncle is left child
                node* uncl = gran->left;
            
                if (uncl != nullptr)
                {
                    if (uncl->color == "red")
                    {   // if uncle's color is red, do insertion case 3
                        pare->color = "black";
                        uncl->color = "black";
                        
                        if (gran != nullptr)
                        {   // if parent's parent is not null (if pare is not root)
                            gran->color = "red";
                            
                            if (gran->parent != nullptr)
                            {   // if gran is not root
                                if (gran->parent->color == "red")
                                {   // if gran's pare is red, we have double red, organize again
                                    return organize(gran);
                                }
                                else
                                {
                                    return;
                                }
                            }
                            else
                            {   // if gran's pare IS null, gran is the root and it needs to be black
                                gran->color = "black";
                                return;
                            }
                        }
                    }   // if uncle's color is black or there is no uncle
                }       // parent is a right child, need curr to be right child to rotate
                if (pare->right == curr)
                {   // insertion case 4
                    rotateLeft(pare, gran);
                    pare->color = "black";
                    gran->color = "red";
                    return;
                }       // if pare is right child but curr is pare's left child
                else if (pare->left == curr)
                {       // insertion case 5: need to reduce to test case 4
                    rotateRight(curr, pare);
                    return organize(pare);
                }       // after rotating, we'll have double red on curr & pare
            }           // organize again, now the lines are straight (not crooked)
        }
        
        /**
         rotates a node left about another node and reassigns pointers
         accordingly
         
         @param rotator is a reference to a pointer to node that is going to rotate
         about another node
         @param about is a reference to a pointer to node that is serving as the pivot/about
         point of rotation
         */
        void rotateLeft(node*& rotator, node*& about)
        {
            about->right = rotator->left;
            
            if (rotator->left != nullptr)
            {   // if it's null, it won't have a parent node anyways
                rotator->left->parent = about;
            }
                 
            if (about->parent == nullptr)
            {   // if about is the root, don't try to access pare's children bc pare is null
                root = rotator;
                rotator->parent = about->parent;
            }
            else if (about->parent->left == about)
            {   // if about is the left child, rotator is now the left chlid
                about->parent->left = rotator;
                rotator->parent = about->parent;
            }
            else
            {   // if about is the right child, rotator is now the right child
                about->parent->right = rotator;
                rotator->parent = about->parent;
            }   // don't need to reassign right (stays same), but left and parent aren't
             
            rotator->left = about;
            about->parent = rotator;
        }
        
        /**
         rotates a node right about another node and reassigns pointers
         accordingly
         
         @param rotator is a reference to a pointer to node that is going to rotate
         about another node
         @param about is a reference to a pointer to node that is serving as the pivot/about
         point of rotation
         */
        void rotateRight(node*& rotator, node*& about)
        {
            about->left = rotator->right;
            
            if (rotator->right != nullptr)
            {   // if it's null, it won't have a parent node anyways
                rotator->right->parent = about;
            }
            
            if (about->parent == nullptr)
            {   // if about is the root, don't do anything w/ pare bc its pare is null
                root = rotator;
                rotator->parent = about->parent;
            }
            else if (about->parent->left == about)
            {   // if about is the left child, rotator is now the left chlid
                about->parent->left = rotator;
                rotator->parent = about->parent;
            }
            else
            {   // if about is the right child, rotator is now the right child
                about->parent->right = rotator;
                rotator->parent = about->parent;
            }   // don't need to reassign left, that stays the same, but right and parent aren't
             
            rotator->right = about;
            about->parent = rotator;
        }
        
        /**
         recursive helper fcn that prints out the rbt in the desired format
         
         @param curr is node that's about to be printed
         node (for formatting purposes)
         */
        void printRec(node* curr)
        {   // initializes iterator and determines # of tabs needed before node
            iterator I(curr, this);
            int tabNum = findTabNum(I.curNode);
            
            if (curr == root)
            {   // print the dash if it's the root, and no tabs
                std::cout << "-" << *I <<  '(' << getColor(curr) << ')' << '\n';
            }

            for (int tab = 0; tab < tabNum; ++tab)
            {   // prints # of tabs (# of branches away from root for formatting)
                std::cout << '\t';
            }
            
            if (curr == begin().curNode)
            {       // print that last node (begin) and then return
                if (curr->parent != nullptr)
                {   // protects against accessing nonexistent L&R from root's null parent
                    if (curr->parent->left == curr)
                    {   // if it's a left child, give it '\'
                        std::cout << '\\' << *I << '(' << getColor(curr) << ')' << '\n';
                    }
                    else if (I.curNode->parent->right == I.curNode)
                    {   // if it's a right child, give it /
                        std::cout << '/' << *I << '(' << getColor(curr) << ')' << '\n';
                    }
                }   // if begin() is root, its pare is null but we already printed it above
                    // anyways (no need to do the prints in this if)
                return;
            }
            else
            {   // otherwise print normally
                if (curr->parent != nullptr)
                {   // protects against accessing nonexistent L&R from root's null parent
                    if (curr->parent->left == curr)
                    {   // if it's a left child, give it '\'
                        std::cout << '\\' << *I << '(' << getColor(curr) << ')' << '\n';
                    }
                    else if (I.curNode->parent->right == I.curNode)
                    {   // if it's a right child, give it /
                        std::cout << '/' << *I << '(' << getColor(curr) << ')' << '\n';
                    }
                }
            }
            // brings us to next rightmost node
            --I;
            std::cout << '\n';
            return printRec(I.curNode);
        }
        
        /**
         recursive helper fcn to find the leftmost node
         
         @param current is a reference to pointer to a node that we're currently on
         @return iterator at the leftmost node
         */
        iterator traverseLeft(node*& current)
        {       // base case w/ no more left children
            if (current->left == nullptr)
            {
                iterator I(current, this);
                return I;
            }
            else
            {
                return traverseLeft(current->left);
            }
        }
        
        /**
         recursive helper fcn to find the leftmost node (overloaded on const)
         
         @param current is a reference to pointer to a node that we're currently on
         @return iterator at the leftmost node
         */
        const_iterator traverseLeftCon(const node*& current) const
        {       // base case w/ no more left children
            if (current->left == nullptr)
            {
                const_iterator I(current, this);
                return I;
            }
            else
            {
                const node* temp = current->left;
                return traverseLeftCon(temp);
            }
        }
        
        /**
         recursive helper fcn to find the rightmost node, and then return an iterator
         that is the right child of that rightmost node (instructions said to go one
         past the last node)
         
         @param current is a reference to pointer to a node that we're currently on
         @return iterator at one past the rightmost node
         */
        iterator traverseRight(node*& current)
        {       // base case w/ no more right children
            if (current->right == nullptr)
            {   // creates iterator at the nullptr past that final node
                iterator I(current->right, this);
                return I;
            }
            else
            {
                return traverseRight(current->right);
            }
        }
        
        /**
         recursive helper fcn to find the rightmost node, and then return an iterator
         that is the right child of that rightmost node (instructions said to go one
         past the last node) (overloaded on const)
         
         @param current is a reference to pointer to a node that we're currently on
         @return iterator at one past the rightmost node
         */
        const_iterator traverseRightCon(const node*& current) const
        {       // base case w/ no more right children
            if (current->right == nullptr)
            {   // creates iterator at the nullptr past that final node
                const_iterator I(current->right, this);
                return I;
            }
            else
            {
                const node* temp = current->right;
                return traverseRightCon(temp);
            }
        }
    };

    /**
     free swap function to swap two rbts
     
     @tparam J is type of rbt
     @param first is reference to rbt that you're swapping
     @param second is reference to other rbt that you're swapping
     */
    template<typename J>
    void swap (rbt<J>& first, rbt<J>& second)
    {
        first.swap(second);
    }
}

#endif

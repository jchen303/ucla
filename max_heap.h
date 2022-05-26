#ifndef max_heap_h
#define max_heap_h

#include <utility>
#include <vector>
#include <stdexcept>

namespace pic10c
{
    /**
     max_heap places the largest value on the top of the binary tree structure
     when inserting a new value it moves up in the heap until it is larger than
     or equal to its child nodes (slide 237/269 in Topic_DataStructures.pdf)
     
     @tparam T type of data the vector (heap) will store
     @tparam compare_type comparison operator that's set to std::less<T> by default
     */
    template<typename T, typename compare_type = std::less<T>>

    class max_heap
    {
    public:
        /**
         constructs a max heap with the provided compare_type argument
         
         @param predVal used to initialize compare_type pred
         
         if no argument, compare_type pred is default initialized to compare_type {}
         vector values initialized to be an empty vector of type T
         */
        max_heap(compare_type predVal = compare_type{}) noexcept : values(), pred(predVal) {}
        
        /**
         inserts new value at bottom of heap, moves value up heap until it is larger
         than or equal to its child nodes
         
         @param insertVal is a forwarding reference to the value that we insert
         into the heap
         */
        void insert(T&& insertVal)
        {
            std::forward<T>(insertVal);     // preserves l or r value
            values.push_back(insertVal);    // add item to the heap
            size_t childInd = size() - 1;   // the index @ which item is inserted (bottom of heap)
            size_t parentInd = (childInd - 1) / 2;  // the child's parent index
            
            if (size() != 1)                // if it isn't the sole item in the heap
            {
                while (childInd != 0 && pred(values[parentInd], insertVal))
                {                           // while item isn't root node & child > parent
                                            // swap values
                    T tempVal = values[parentInd];
                    values[parentInd] = insertVal;
                    values[childInd] = tempVal;
                    childInd = parentInd;   // update childInd now that it's swapped w/ parent
                    parentInd = (childInd - 1) / 2;
                }                           // update parentInd now that child has moved up,
            }                               // find the next parent that you're comparing to
        }
        
        /**
         gives size of the heap (vector)
         
         @return the size of the heap as a size_t
         */
        size_t size() const
        {
            return values.size();
        }
        
        /**
         gives the value of the heap at the top of the heap
         
         @return the top value of the heap as a T object (whatever type the heap/vector is)
         */
        const T& top() const
        {
            if (size() == 0)                    // can't have a top if there's nothing in the heap
            {
                throw std::logic_error("heap empty");
            }

            return values[0];
        }
        
        /**
         takes away the top value of the heap and replaces it with the last item on the heap.
         the last item then moves down the heap until it is larger than or equal to its
         child nodes
         */
        void pop()
        {
            if (size() == 0)                    // can't pop if there's nothing to pop
            {
                throw std::logic_error("pop empty");
            }

            // put val of last child on top, delete last child's old index
            // movingInd is index of former last child that's now moving down heap to proper spot
            size_t movingInd = size() - 1;
            values[0] = values[movingInd];
            values.pop_back();
            
            movingInd = 0;                      // index of val that will move down (if necessary)
            size_t lcInd = 2 * movingInd + 1;   // left child index
            size_t rcInd = 2 * movingInd + 2;   // right child index
            size_t maxInd = size() - 1;         // last index of heap to stop out of bounds errors
            
            // if there's just a root and no children, maxInd = 0 but lcInd = 1
            if (lcInd > maxInd)
            {
                lcInd = maxInd;
            }
            
            // if there's only one child, rcInd = 2 but maxInd = 1
            if (rcInd > maxInd)
            {
                rcInd = maxInd;
            }
            // the two if statements above prevent out of bounds index errors if the heap is small
            // (cases of one child or no children)
            
            // while the parent node is less than its child, swap it w/ its largest child
            // works if you switch to std::greater too (same code for both cases)
        
            while (pred(values[movingInd], values[lcInd]) || pred(values[movingInd], values[rcInd]))
            {   // won't quit until it has no more children (last node) or if it is >= both children
                if (pred(values[lcInd], values[rcInd]))
                {   // if left child is less/greater than right child, swap w/ right
                    T temp = values[rcInd];
                    values[rcInd] = values[movingInd];
                    values[movingInd] = temp;
                    movingInd = rcInd;  // adjust indices, there are new children now
                    lcInd = 2 * movingInd + 1;
                    rcInd = 2 * movingInd + 2;
                    maxInd = size() - 1;
                    
                    // if child index exceeds the possible indices, set it to equal parent node
                    if (lcInd > maxInd) // since there is no child
                    {
                        lcInd = movingInd;
                    }
                    if (rcInd > maxInd)
                    {
                        rcInd = movingInd;
                    }
                }
                else
                {   // if right child is less/greater than left child, swap w/ left
                    T temp = values[lcInd];
                    values[lcInd] = values[movingInd];
                    values[movingInd] = temp;
                    movingInd = lcInd;  // same as above, changing indices
                    lcInd = 2 * movingInd + 1;
                    rcInd = 2 * movingInd + 2;
                    maxInd = size() - 1;
                    
                    // if child index exceeds the possible indices, set it to equal parent node
                    if (lcInd > maxInd) // prevents out of bounds vector errors
                    {
                        lcInd = movingInd;
                    }
                    if (rcInd > maxInd)
                    {
                        rcInd = movingInd;
                    }
                    // setting r/lcInd to movingInd turns their respective statement in the while loop
                    // condition false, allowing other valid index to continue
                }
            }
        }
        
    private:
        std::vector <T> values;
        compare_type pred;
    };
}

#endif

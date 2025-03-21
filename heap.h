#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> dat_;
  size_t m_;
  PComparator c_;
  void heapifyUp(size_t index);
  void heapifyDown(size_t index);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
  m_ = m;
  c_ = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  if( dat_.size() == 0 ) {
    return true;
  }
  return false;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return dat_.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("Cannot call top on empty heap!");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return dat_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
     throw std::underflow_error("Cannot call pop on empty heap!");
  }
  dat_[0] = dat_[size()-1]; // swap last and first item
  dat_.pop_back(); // remove new last item
  heapifyDown(0); // call helper function 
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  dat_.push_back(item);
  heapifyUp(size() -1 ); // call helper function
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUp(size_t index) {
  if(index == 0) {
    return;
  }

  size_t pIndex = (index - 1) / m_; // get parent index
  if( c_(dat_[index], dat_[pIndex]) ) {
    std::swap(dat_[index], dat_[pIndex]);
    heapifyUp(pIndex); 
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyDown(size_t index) {
  size_t r = index; // highest priority 
  for(size_t i = 1; i <= m_; i++){
    size_t cIndex = (m_ * index) + i;
    if(cIndex < size() && c_(dat_[cIndex], dat_[r])) {
      r = cIndex;
    }
  }

  if(r != index){
    std::swap(dat_[index], dat_[r]);
    heapifyDown(r);
  }
}

#endif


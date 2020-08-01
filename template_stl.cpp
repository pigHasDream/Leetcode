std::lower_bound
std::upper_bound
std::binary_search
std::nth_element

// BidirIt partition( BidirIt first, BidirIt last, UnaryPredicate p );
// returns iterator to the first element of the second group.
// O(N)
std::partition
std::stable_partition

std::iter_swap
std::swap
std::is_sorted_until
std::next_permutation
std::prev_permutation

// OutputIt merge( InputIt1 first1, InputIt1 last1,
//                 InputIt2 first2, InputIt2 last2,
//                 OutputIt d_first );
// return Iter passes the last element inserted.
// O(N)
std::merge

// void inplace_merge( BidirIt first, BidirIt middle, BidirIt last );
// O(N) using extra memory; O(NlogN) not enough memory.
std::inplace_merge 

// Constructs a sorted range beginning at d_first consisting of 
// elements that are found in both sorted ranges [first1, last1) 
// and [first2, last2). If some element is found m times in 
// [first1, last1) and n times in [first2, last2), the first 
// std::min(m, n) elements will be copied from the first range 
// to the destination range. 
// The order of equivalent elements is preserved.
// The resulting range is also sorted.
//
// template< class InputIt1, class InputIt2, class OutputIt >
// OutputIt set_intersection( InputIt1 first1, InputIt1 last1,
//                            InputIt2 first2, InputIt2 last2,
//                            OutputIt d_first );
//
// std::set_intersection(v1.begin(), v1.end(),
//                       v2.begin(), v2.end(),
//                       std::back_inserter(v_intersection));
std::set_intersection

// Constructs a sorted union beginning at d_first consisting 
// of the set of elements present in one or both sorted 
// ranges [first1, last1) and [first2, last2).
//
// If some element is found m times in [first1, last1) and 
// n times in [first2, last2), then all m elements will be 
// copied from [first1, last1) to d_first, preserving order, 
// and then exactly std::max(n-m, 0) elements will be copied 
// from [first2, last2) to d_first, also preserving order.

// If any equivalent values appeared n times in the first 
// range and m times in the second, std::merge would output 
// all n+m occurrences whereas std::set_union would output 
// std::max(n, m) ones only.  

// template< class InputIt1, class InputIt2, class OutputIt >
// OutputIt set_union( InputIt1 first1, InputIt1 last1,
//                     InputIt2 first2, InputIt2 last2,
//                     OutputIt d_first );
std::set_uion


// Copies the elements from the sorted range [first1, last1) 
// which are not found in the sorted range [first2, last2) 
// to the range beginning at d_first.
// The resulting range is also sorted.
//
// template< class InputIt1, class InputIt2, class OutputIt >
// OutputIt set_difference( InputIt1 first1, InputIt1 last1,
//                          InputIt2 first2, InputIt2 last2,
//                          utputIt d_first );
std::set_difference

// often used in set_intersection, etc need destination vector
// iterator case. We can just use back_inserter to do the work.
std::back_inserter
std::rotate

std::isdigit
std::islower
std::isupper
std::isalpha
std::isalnum

std::min_element
std::max_element
std::minmax_element
std::accumulate
std::fill
std::fill_n
std::count_if
std::iota
std::unique_ptr

// array<int, 5> nums = {1,2,3,4,5};
std::array

// doubly-linked list
std::list 

// stl container member function remove vs erase
list::remove // actual deletion of element
// There is no vector::remove!

std::remove // copy and compact the elements no deletion!
// Both std::remove and member remove are using predicate or value check!

list::erase // delete element by iterator!
vector::erase // actual delete element by iterator or position!

// memcpy
void* memcpy( void* dest, const void* src, std::size_t count );

// sizeof
sizeof(type);
sizeof expression;

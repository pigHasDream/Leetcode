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

std::set_uion
std::back_inserter
std::rotate
std::min_element
std::max_element
std::minmax_element
std::accumulate
std::fill
std::fill_n
std::count_if
std::iota
std::unique_ptr

// doubly-linked list
std::list 

template<class Iter>
void merge_sort(Iter first, Iter last)
{
  // std::end - std::begin > 1 only 
  // when more than 2 elements.
  if (last - first > 1) {
    Iter middle = first + (last - first) / 2;
    merge_sort(first, middle);
    merge_sort(middle, last);
    std::inplace_merge(first, middle, last);
  }
}
 

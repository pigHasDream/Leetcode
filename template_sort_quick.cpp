// Always treat as [left, right)

template <class Iter>
void quicksort(Iter first, Iter last)
{
  if(first == last) return;

  auto pivot = *first;
  Iter mid = std::partition(first, last, [pivot](const auto& em){ return em < pivot; });

  // the *mid is in it's correct place.
  // therefore, the next level recursion will skip mid
  quicksort(first, mid);
  quicksort(std::next(mid), last);
}



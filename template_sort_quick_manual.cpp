int partition(vector<int>& A, 
              const int left, 
              const int right) {

  const int pivot = arr[left];
    
  // the next element of left!
  int i = left + 1;
  int j = right;
    
  while (i <= j) {

    // equal case needs to be covered
    while(arr[i] <= pivot)  i++;
    while(arr[j] > pivot) j--;

    if (i < j) 
      std::swap(arr[i], arr[j]);

    // after this swapping, 
    // goes back to i++ check,
    // it'll always success for at least
    // once, due to above swap
  }

  // when exiting, i points to next
  // position, so needs to subtract 1.
  std::swap(A[i - 1], A[left]);

  // return the first element in 2nd part
  return i;
}

void quicksort(vector<int>& A, 
               const int left, 
               const int right){

  if (left >= right) return;

  int midPos = partition(A, left, right);
  quicksort(A, left, pivot - 1);
  quicksort(A, pivot, right);
}


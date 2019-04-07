int partition(vector<int>& A, const int left, const int right) {
  const int pivot = arr[left];
    
  int i = left + 1;
  int j = right;
    
  while (i <= j) {
    while(arr[i] <= pivot) {
        i++;
        }

        while(i <= j && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }
  std::swap(A[i - 1], A[left]);
  return i - 1;
}

void quicksort(vector<int>& A, const int left, const int right){
  if (left >= right) return;

  int pivot = partition(A, left, right);
  quicksort(A, left, pivot - 1, A.size());
  quicksort(A, pivot + 1, right, A.size());
}

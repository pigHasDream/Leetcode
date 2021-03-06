// -----------------------------------------------------
// repeatedly search for the first smaller or larger element
// in an array given index i.
// Use map<int, int> where first int is the value, second is index.
// This is essentially a binary search BST.
// Check for LC_975 lower_ upper_ bound usage to find the first 
// >= and <= element.


// -----------------------------------------------------
// Find middle point of a list
  ListNode* slow = head;
  ListNode* fast = head->next;

  while(fast != nullptr and fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

// -----------------------------------------------------
// Palindrome check
bool isPalindrome(const string& s, int start, int end) {
  for(int i=start, j=end; i<j; ++i, --j)
    if(s[i] != s[j]) return false;

  return true;
}

// -----------------------------------------------------
// Palindrome DP transitional check condition
// isPal[i][j]: if i~j is a palindrome
if (s[i] == s[j] and (i-j<2 or isPal[j+1][i-1]))
  return true;

// -----------------------------------------------------
// simultaneous check incremental numbers
int nthUglyNumber(int n) {

  // initially smaller size
	vector<int> dp(1,1);
	int i =0, j=0, k=0;
	
	while(dp.size() < n) {
		
    // gradually build up the vector
		dp.emplace_back(min(dp[i]*2, min(dp[j]*3, dp[k]*5)));
		
		if(dp.back() == dp[i]*2) ++i;
		if(dp.back() == dp[j]*3) ++j;
		if(dp.back() == dp[k]*5) ++k;
		
	}
	
	return dp.back();
}

// -----------------------------------------------------
// reading through each digit leter to form a number

int num = 0;
for(const auto& c : theString)
	if(isdigit(c)) num = num*10 + c-'0';


// -----------------------------------------------------
// use 1-d array or hash table to mimic a 3-d table
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-546-remove-boxes/
unordered_map<int, int> map_;
int key = (l * d1 + r) * d2 + k;
map_[k] 


// -----------------------------------------------------
// priority_queue with customized comparator
// Same for map, or multimap
// The decltype(cmp) extract the Type of lambda, as it's used as
// a type of the template.
// The heap(cmp) is the constructor of priority_queue and map etc, that
// takes in the comparator functor here.

auto cmp = [](const auto& p1, const auto& p2) { 
              if(p1.first == p2.first) 
                return p1.second > p2.second;

              return p1.first < p2.first; 
             };

priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> heap(cmp);

// -----------------------------------------------------
// std::set with customized comparator
// Same as priority_queue!!
// Here we have to FULLY define the relation in order to use it as a HASH 
// to remove duplication correctly!!
auto cmp = [](const auto& a, const auto& b) {
  if(a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
};

std::set<pair<int,int>, decltype(cmp)> theSet(cmp);
// See below example, the pair<int,int> stores the 2 indexes of the 
// 2 arrays.
// Refer to LC.373

auto cmp = [&](const pair<int,int>& a, const pair<int,int>& b) {
  int sum1 = nums1[a.first] + nums2[a.second];
  int sum2 = nums1[b.first] + nums2[b.second];
  if(sum1 == sum2) {
    if(a.first == b.first)
      return a.second < b.second;
    return a.first < b.first;
  }
  return sum1 < sum2;
};

set<pair<int,int>, decltype(cmp)> theSet(cmp);

// -----------------------------------------------------
// Get count of pairs of a sorted array that each pair
// has difference smaller than a given number
// This is a 2-pointer O(N) scan using the monotone nature
// The count summation can be understood as: use the boundary, 
// how many subarrays: just the length

for(int start=0, end=0; start<nums.size(); ++start) {
	while(end<nums.size() and nums[end]-nums[start] <= target) ++end;
	count += end-start-1;
}

// -----------------------------------------------------
// Check if parenthess is valid. LC301
bool isValid(const string& s) {
	// check for () validness
	int count = 0;
	for(const auto& c : s) {
		if(c=='(') ++count;
		if(c==')') --count;
    // two cases: inside loop, never becomes negative
		if(count<0) return false;
	}
  // outside loop, never becomes non-zero
	return count == 0;
}


// -----------------------------------------------------
// Check how many ( and ) need to be removed! LC301
int left = 0, right = 0;
// This counts how many ( and ) need to be removed, respectively
for(const auto& c : s) {
  left += c=='(';
  if(left == 0) 
    right += c==')';
  else
    left -= c==')';
}

// -----------------------------------------------------
// Find 1-D manhattan distance of a given array
int findManhattanDist(vector<int>& vec) {
  sort(vec.begin(), vec.end());
  int i=0, j=vec.size()-1;
  int dist = 0;
  while(i<j) dist += vec[j--] - vec[i++];
  return dist; 
}

// -----------------------------------------------------
// CPP vector erase-remove idiom
// std::remove shifts all non-removed elements to left
// and return the first matching elem's iter. erase will 
// clean them up. This also applies to string.

std::vector<int>& vec = myNumbers; // use shorter name
vec.erase(std::remove(vec.begin(), vec.end(), number_in), vec.end());
vec.erase(std::remove_if(vec.begin(), vec.end(), [](const auto& a){return a == number_in;}), vec.end());

// -----------------------------------------------------
// CPP remove unordered_map or unordered_set in a loop
for(auto iter = unodered_map_set.begin(); iter != end(XX);) {
  if(iter == TARGET) {
    iter = unodered_map_set.erase(iter);
  }
  else {
    ++iter;
  }
}

// -----------------------------------------------------
// CPP modulo negative handles to make it positive
(x%mod + mod)%mod


// ----------------------------------------------------
// Prime numbers are in 6K+1, 6K-1 are all primes
//

// ----------------------------------------------------
// Find length at least K subarray sum that sum is >=0;
// LC 644 technique
double checkSum(vector<int>& nums, int k) {
	
	double sum = 0;
	double prev = 0;
	double minSum = 0;
	
	// if the first k already meets
	for(int i=0; i<k; ++i) 
		sum += nums[i];
	
	if(sum >=0) return true;
	
	// if first k not meets,
	// we use 2 running prefix sums,
	// the slow one we keeps getting the min value of them,
	// so that when we do the subtraction, we ensure
	// if there is a >= 0, it's always true!
	for(int i=k; i<nums.size(); ++i) {
		sum += nums[i];
		prev += nums[i-k];
		minSum = min(prev, minSum);
		if(sum - minSum >=0) return true;
	}
	
	return false;
}

// -----------------------------------------------------
//    a x b = LCM(a, b) * GCD (a, b)
//    LCM(a, b) = (a x b) / GCD(a, b) 

int gcd(int a, int b) {
  if(a>b) swap(a, b);
  if(a == 0) return b;
  return gcd(b%a, a);
}

// -----------------------------------------------------
// split a cpp string by deliminator
void split(string str) {
  stringstream ss(str);
  unordered_set<int, string> result;
  int idx = 0;
  while(getline(ss, result[idx++], ','));


  // or use boost
  vector<string> res;
  boost::split(res, str, [](const auto& s) { return s == ','; });
};

// -----------------------------------------------------
// string find, rfind returns the target char position

str.find('/');
str.rfind('/');
  
// -----------------------------------------------------
// delete linked list or binary tree requires to remove every
// elem in the list or tree. We can do recursion, but better do iterative
void myList::destroy(TheList* node) {
  while (node) {
    auto old = node;
    node = node->next;
    delete old;
  }
}
  
// -----------------------------------------------------
// for N nodes, how many directed inter connects among them without self connect?
N*(N-1)
      
// -----------------------------------------------------
// For remainder related, if it contains negtative numbers,
// we need to remove its impact. Here is the way to offset
((num % div) + div) % div


// -----------------------------------------------------
// Count number of sub arrays in a 1-D vector that all 1s
// Consecutive subarray counts can be just sum of running length!
int res = 0, length = 0;
for (int i = 0; i < A.length; ++i) {
  length = (A[i] == 0 ? 0 : length + 1);
  res += length;
}
return res;

//-----------------------------------------------------
// Count how many 1 patterns strings
int numSub(string s) {
	const int mod = 1e9 + 7;

	int res = 0;
	int count = 0;

	for(const auto& c : s) {
    // This is the key!
    // while iterating the numbers, we repeatedly
    // add up the count!!
    // The alternative solution is to use (n+1)*n/2
		count = c == '1' ? count + 1 : 0;
		res = (res + count) % mod;
	}

	return res;
}

// ----------------------------------------------------
// subset sum: number of ways to pick subset of elem 
// to get the target sum

vector<int> dp(target+1, 0);
dp.front() = 1;

// This is the backward 1-D dp.
// This is knapsack!!
for(int i=0; i<nums.size(); ++i) 
  for(int sum=target; sum>=nums[i]; --sum)
    dp[sum] += dp[sum-nums[i]];

return dp.back();

// ----------------------------------------------------
// In a sorted ascending number array, what is the
// number of pairs that the pair-difference is no bigger than mid;
// O(n)
//
int count = 0;
// 2-pointers, sorted array! every time j exits,
// we can continue the j, no need to start from 0 for j!!
for(int i=0, j=0; i<nums.size(); ++i) {
  while(j<nums.size() and nums[j]-nums[i]<=mid)
    ++j;

  count += j-i-1;
}

// ----------------------------------------------------
// Search an element in a matrix where the row and column
// each is sorted ascending order respectively!
// We can then use a O(N+M) anti-diagnal search
//
// ----------------------------------------------------
// C++ string split to vector of substrings by '/'
vector<string> parser(string path) {
	replace_if(path.begin(), path.end(), [](auto& c){return c=='/';}, ' ');
	stringstream ss(path);
	string tmp;
	vector<string> res;
	while(ss >> tmp) {
		res.emplace_back(tmp);
	}
	return res;
}
//-----------------------------------------------------
// equal_range below finds the iterator range of a sorted intervals that INTERSECTS with newInterval!
// Note that we use a.back() < b.front() to strictly compare the non-intersected part
// **************************************************************************************************
// That means it returns all interval v that not (v < newInterval) and not (newInterval < v)
// --> neither v is strictly sits left of newInterval, nor newInterval is strictly sits right of v!
// **************************************************************************************************
// So the equal range returns the iterator range that intersect with the newInterval!
// Refer to LC_GC_57_Insert_Interval.cpp

auto [start, stop] = equal_range(res.begin(), res.end(), newInterval, [](const auto& a, const auto& b){
  return a.back() < b.front(); 
});

lower_bound comparator:
binary predicate which returns true if the first argument is less than (i.e. is ordered before) the second.
First argument is the vector type, and second argument is the target value type

upper_bound comparator:
binary predicate which returns true if the first argument is less than (i.e. is ordered before) the second.
First argument is the target value type, and second argument is the vector type


// cpp string
string::find 
string::find_last_of
string::find_first_of
string::find_first_not_of
string::find_last_not_of

string::substr();
  basic_string substr( size_type pos = 0, size_type count = npos ) const;
  constexpr basic_string substr( size_type pos = 0, size_type count = npos ) const;



// --------------------------------------------------
// DP bit masking small util
// We can use (x >> i) & 1 to get i-th bit in state x, where >> is the right shift operation.
// If we are doing this in an if statement (i.e. to check whether the i-th bit is 1), 
// we can also use x & (1 << i), where the << is the left shift operation.
// 
// We can use (x & y) == x to check if x is a subset of y.
// The subset means every state in x could be 1 only if the corresponding state in y is 1.
// 
// We can use (x & (x >> 1)) == 0 to check if there are no adjancent valid states in x.







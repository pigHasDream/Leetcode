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

auto cmp = [](const auto& p1, const auto& p2) { 
              if(p1.first == p2.first) 
                return p1.second > p2.second;

              return p1.first < p2.first; 
             };

priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> heap(cmp);


// -----------------------------------------------------
// Get count of pairs of a sorted array that each pair
// has difference smaller than a given number
// This is a 2-pointer O(N) scan using the monotone nature

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
		if(count<0) return false;
	}
	return count == 0;
}


// -----------------------------------------------------
// Check how many ( and ) need to be removed! LC301
int left = 0, right = 0;
// This counts how many ( and ) need to be removed
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
// clean them up.

std::vector<int>& vec = myNumbers; // use shorter name
vec.erase(std::remove(vec.begin(), vec.end(), number_in), vec.end());

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
      


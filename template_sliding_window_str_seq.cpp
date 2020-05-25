// General template for sliding window
// to solve substring, subsequence contain problems

// 3-basic essense:
// 1. hashtable, 2. two-pointers left and right
// 3. (optional) a counter for condition check.

// ======= For Min Length case ======
// 2-level loop: first level is to extend right
// pointer, once certain condition BREAKS, starts
// the second loop and shrink the left pointer until
// the contidion no longer meets.
// Update the min res in the 2nd loop cauz this is the
// place that barely maintains the condition!

// ======= For Max Length case ======
// 2-level loop: first level is to extend right
// pointer to maintain a valid condition, once breaks, 
// starts the second loop and shrink the left pointer 
// until the condition meets again.
// Update the max res in the 1st loop cauz that's the 
// place to extend the length!

// Using hashtable to connect the 2 strings,
// and ++ -- to compare with 0 to decide whether
// the right/left boundary is a match. 

// Basically: right pointer is to make valid;
// left pointer is to get minimum

// LC_76, LC_340, LC_209, LC_904
// LC_904 is opposite to the condition as it's 
// for maximum

int findSubstring(string s){

  // use int vector of 128 for tyical string hash
  // use unordered_map<char, int> for general case
  vector<int> map(128,0);

  // check whether the substring is valid
  int counter=0; 
  //the length of substring
  int minLen; 
  //two pointers, one point to tail and one head
  int begin=0; 

  for() { /* initialize the hash map here */ }

  // Outer loop extends the right pointer, and to meet 
  // the condition of satisfying!
  for(int end = 0; end < s.size(); ++end) { 

    if(--map[s[end]] ?) { /* modify counter here */ }

    // This inner loop shrinks the left boundary and
    // to get the minimum soluiton that works!
    //
    // sometimes other conditions, just satisfying!
    // The loop is to update then gradually break 
    // the satisfying, then we get to outer loop
    // to extend the range.
    while(/* satisfying condition */){ 
         
      /* update minLen here if finding minimum*/


      //increase begin to make it invalid/valid again
      if(++map[s[begin]] ?){ /*modify counter here*/ }
      ++begin;
    }  

    /* update minLen here*/
  }

  return minLen;
}

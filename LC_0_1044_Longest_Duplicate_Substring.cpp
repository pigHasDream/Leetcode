ass Solution {
public:
    string longestDupSubstring(string &s) {
        // binary search on length of duplicate substring
        int n = s.size();
        int lo = 1, hi = n, mid;
        int startIndex = -1, k = 0;
      
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            int index = check(s, mid);
            if (index != -1) {
                // record
                startIndex = index;
                k = mid;
                // update search range
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return k==0 ? "" : s.substr(startIndex, k);
    }
private:
    // check if there exists two same substring of length k
    // Rabin-Karp, rolling hash
    // time O(N), space O(N)
    int check(string &s, int k) {
        int n = s.size();
        // all prime of the form 6k + 1, 6k - 1
        int q = 6 * (1 << 20) + 1;
        // base
        int b = 26;
        // precompute power = b^(k-1)
        int power = 1;
        for (int i = 1; i < k; i++) {
            power = (power * b) % q;
        }
        // double check by using hash table (key=hash code, value={startIndex})
        unordered_map<int, vector<int>> seen;
        // initialize
        int hash = 0;
        for (int i = 0; i < k; i++) {
            hash = (hash * b % q + s[i]) % q;
        }
        seen[hash].push_back(0);
        
        // rolling hash, Rabin-Karp
        for (int i = k; i < n; i++) {
            // remove old value
            hash = (hash - power * s[i - k] % q + q) % q; 
            // add new value
            hash = (hash * b % q + s[i]) % q;
            if (seen.count(hash)) {
                // double check
                for (int &index : seen[hash]) {
                    if (s.substr(index, k) == s.substr(i - k + 1, k)) {
                        return index;
                    }
                }
            }
            // add to hash table
            seen[hash].push_back(i - k + 1);
        }
        
        // does not find
        return -1;
    }
};

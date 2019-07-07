class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> price(n, 0);
    for(const auto& bk : bookings) {
      price[bk[0]-1] += bk[2];
      if(bk[1] < n) price[bk[1]] -= bk[2];
    }
    
    for(int i=1; i<n; ++i)
      price[i] += price[i-1];

    return price;
  }
};

class Solution {
public:
  vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
    
    vector<int> res;
    
    // key: skill states, value: people state
    // whenever the key is cached, it is the best solution for 
    unordered_map<int, vector<int>> memo;
    memo.reserve(1<<req_skills.size());
    
    vector<int> ppSkill;
    ppSkill.reserve(people.size());
    
    for(const auto& p : people) {
      int sk = 0;
      for(const auto& s: p) {
        sk |= 1 << distance(req_skills.begin(), find(req_skills.begin(), req_skills.end(), s));
      }
      ppSkill.emplace_back(sk);
    }
    
    unordered_map<int, vector<int>> dp;
    dp[0] = { };
    
    // Key idea is to exhaust all possible skill states.
    // For each state, we keep a best solution vector of people
    // when a new guy comes in, we either do not use him (if his skills are all covered)
    // or we add him. 
    // In either case, we compare the number of people needed for the same skill set covered.
    // We update the min solution.
    
    for(int i=0; i<people.size(); ++i) {
      unordered_map<int, vector<int>> tmp(dp);
      for(auto& sol : dp) {
        auto& skill = sol.first;
        auto& people = sol.second;
        
        int skillPlus = skill | ppSkill[i];
        if(tmp.count(skillPlus) == 0 or 
           tmp[skillPlus].size() > tmp[skill].size() + 1) {
          tmp[skillPlus] = people;
          tmp[skillPlus].emplace_back(i);
        }
      }
      
      swap(tmp, dp);
    }
    
    return dp[(1<<req_skills.size())-1];

  }
};





class Solution {
public:
  vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
    
    vector<int> res;
    
    // key: skill states, value: people state
    // whenever the key is cached, it is the best solution for 
    unordered_map<int, vector<int>> memo;
    memo.reserve(1<<req_skills.size());
    
    vector<int> ppSkill;
    ppSkill.reserve(people.size());
    
    for(const auto& p : people) {
      int sk = 0;
      for(const auto& s: p) {
        sk |= 1 << distance(req_skills.begin(), find(req_skills.begin(), req_skills.end(), s));
      }
      ppSkill.emplace_back(sk);
    }
    
    queue<pair<int,vector<int>>> que;
    que.emplace(0,vector<int>());
    
    vector<int> visit((1<<req_skills.size()), 0);
    while(que.size()) {
      for(int k=que.size(); k>0; --k) {
        auto top = que.front(); que.pop();
        
        int skill = top.first;
        auto team = top.second;
        
        if(skill == (1<<req_skills.size())-1)
          return team;
       
        for(int i=0; i<ppSkill.size(); ++i) {
          int newSkill = skill | ppSkill[i];
          if(visit[newSkill]) continue;
          visit[newSkill] = 1;
          auto tmp(team);
          tmp.emplace_back(i);
          que.emplace(newSkill, tmp);
        }
      }
    }
    
    return {};
  }
};

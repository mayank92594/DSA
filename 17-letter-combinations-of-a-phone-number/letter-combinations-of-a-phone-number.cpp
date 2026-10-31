class Solution {
public:
 unordered_map<char, string> mp;
vector<string> ans;
void solve(int i,string& temp,string& digits){
    if(i==digits.length()){
        ans.push_back(temp);
        return;
        }
       string letter=mp[digits[i]];//store mapped value in a string
       for(int j =0;j<letter.length();j++){
        temp.push_back(letter[j]);
        solve(i+1,temp,digits);//explore for next digit
        temp.pop_back();//bactrack
       }

}
    vector<string> letterCombinations(string digits) {
    //letter mapping
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
     string temp ="";
     solve(0,temp,digits);
     return ans;

        
    }
};
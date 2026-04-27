class Solution {
public:
    bool isPalindrome(string s) {

        s.erase(
      remove_if(s.begin(), s.end(),
                [](unsigned char c){
                  return !std::isalnum(c);
                }),
      s.end()
    );

    transform(
      s.begin(), s.end(), s.begin(),
      [](unsigned char c){
        return std::tolower(c);
      }
    );

        int lengthOfPal = s.length();
        cout << "String length: " << s.length() << endl;

        int l = 0;
        int r = s.size() - 1;
        while (l < r){
            if (s[l++] != s[r--]){
                return false;
            }

        }
        return true;

    }
};

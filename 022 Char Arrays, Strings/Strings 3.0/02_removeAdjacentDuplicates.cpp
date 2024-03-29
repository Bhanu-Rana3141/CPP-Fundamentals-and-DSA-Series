#include<iostream>
#include<string.h>
using namespace std;

string removeDuplicates(string s) {

    string ans = "";
    
    for(int i=0; i<s.length(); i++) {
        if((ans.length() > 0) && s[i] == ans[ans.length()-1]) {
            ans.pop_back();
        }
        else{
            ans.push_back(s[i]);
        }
    }
    return ans;
}

void removeDuplicate(string& s) {

    int i=0;
    while(s[i+1] != '\0') {
        if(s[i] == s[i+1]) {
            s.erase(i,2);
            i=0;
        }
        else{
            i++;
        }
    }
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    removeDuplicate(s);
    cout << s;

    // string ans = removeDuplicates(s);
    // cout << ans;
   
    return 0;
}
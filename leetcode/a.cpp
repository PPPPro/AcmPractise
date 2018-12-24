#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<vector>
int numUniqueEmails(std::vector<std::string>& emails) {
    int cnt = 0;
    std::set<std::string> res;
    for(int i = 0; i < emails.size(); i++){
        bool delkey = false;
        for(std::string::iterator it = emails[i].begin(); it != emails[i].end(); it++){
            if(*it == '@')break;
            if(delkey == true){emails[i].erase(it);it--;continue;}
            if(*it == '+'){
                emails[i].erase(it);
                delkey = true;
                it--;
                continue;
            }

            else if(*it == '.')
                emails[i].erase(it);
        }
        res.insert(emails[i]);
    }
    return res.size();
}

int main(){
    vector<string> email;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        email.push_back(s);
    }
    numUniqueEmails(email);
    return 0;
}

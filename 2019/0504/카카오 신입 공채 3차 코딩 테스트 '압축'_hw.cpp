#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dic;
    dic.push_back("");
    for(int i=0;i<26;++i){
        string tmp;
        tmp.push_back('A'+i);
        dic.push_back(tmp);
    }
    int ind=0;
    string sub_msg;
    bool flag=true;
    sub_msg+=msg[0];
    msg.erase(msg.begin());
    while(!msg.empty()){
        for(int i=0;i<dic.size();++i){
            if(sub_msg == dic[i]){
                flag=false;
                ind=i;
                break;
            }
        }
        if(flag){
            answer.push_back(ind);
            dic.push_back(sub_msg.substr(0,sub_msg.size()));
            sub_msg.erase(sub_msg.begin(),sub_msg.end()-1);
            ind=0;
            continue;
        }
        sub_msg+=msg[0];
        msg.erase(msg.begin());
        flag =true;
    }


    for(int i=0;i<dic.size();++i){
        if(sub_msg == dic[i]){
            flag=false;
            ind=i;
            break;
        }
    }
    if(flag){
        answer.push_back(ind);
        dic.push_back(sub_msg.substr(0,sub_msg.size()));
        sub_msg.erase(sub_msg.begin(),sub_msg.end()-1);
        ind=0;
    }
    if(ind ==0){
        for(int i=0;i<dic.size();++i){
            if(sub_msg == dic[i]){
                answer.push_back(i);
                break;
            }
        }
    }
    else
        answer.push_back(ind);
    return answer;
}

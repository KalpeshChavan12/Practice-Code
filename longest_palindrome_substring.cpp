#include<iostream>

using namespace std;

void longestPall(std::string s, int& start, int &len){

    bool **dp;
    dp=new bool*[s.length()];
    for(int i=0;i<s.length() ; i++){
        dp[i]=new bool[s.length()];
    }


    for(int i=0;i<s.length() ; i++){
        dp[i][i]=true;
    }
    for(int i=0;i<s.length()-1 ; i++){
        if(s[i]==s[i+1])
            dp[i][i+1]=true;
    }


    for(int cl=3;cl <= s.length() ; cl++){

        for(int i=0; i<s.length()-cl+1  ; i++){
            int j= i + cl -1 ;
            if( dp[i+1][j-1] && (s[i] == s[j]))
                dp[i][j]=true;
            else
                dp[i][j]=false;
        }
    }

    int max=0;
    for(int i=0;i<s.length() ; i++){
        for(int j=0;j<s.length() ; j++){
// to display DP table Define -DDEBUG
#ifdef DEBUG
            cout<<dp[i][j];
#endif
            if(dp[i][j] && ( max <= (j-i)))
            {
                 max=(j-i);
                 start=i;
                 len=j-i+1;
            }

        }
#ifdef DEBUG
        cout<<endl;
#endif
    }

}

int main(){

    std::string s;
    cin>>s;
    int st,l;
    longestPall(s,st,l);

    cout<<s.substr(st,l)<<endl;

    return 0;

}

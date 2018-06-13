/*
*
* Problem: https://www.hackerrank.com/challenges/ctci-balanced-brackets/problem
*
*/

#include <bits/stdc++.h>

using namespace std;

#define YN(b) ( b ? "YES" : "NO")
        
char getOpp(char c){
    switch(c){
        case ']': return '[';
        case '[': return ']';
        case '{': return '}';
        case '}': return '{';
        case '(': return ')';
        case ')': return '(';            
    }
    return 0;
}

bool isOpen(char c){
    switch(c){
        
        case '[': return true;
        case '{': return true;
        
        case '(': return true;
        
    }
    return false;
}

bool isBalance(std::string s){
    std::stack<char> st;
    
    for(auto c: s){
                if(isOpen(c)){
                    st.push(c);
                }else{
                    if(st.empty())
                        return false;
                    if(getOpp(st.top()) ==  c){
                        st.pop();
                    }else
                        return false;
                }
    }
    if(st.empty())
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string expression;
        getline(cin, expression);
        cout<<YN(isBalance(expression))<<endl;
    }

    return 0;
}

#include<iostream>
#include<climits>
using namespace std;

#define MIN(a,b) (a < b ? a : b )

int *dp;

int min_coin(int *coins, int len , int sum){

        if(sum < 0)
                return INT_MAX;
        if(sum==0)
                return 0;

        if(dp[sum] != INT_MAX)
                return dp[sum];

        int _min= INT_MAX;

        for(int i=0;i<len; i++){
                int tmp=min_coin(coins,len, sum-coins[i]);
                _min= MIN(_min,tmp);

        }
        if(_min == INT_MAX )
                return INT_MAX;
        dp[sum] = _min + 1;
        return _min+1;
}

int main(){

        int max_coins,  sum, *coins;
        cin>>sum;
        cin>>max_coins;

        coins = new int[max_coins];
        for(int idx; idx < max_coins ; idx++){
                cin>>coins[idx];
        }

        dp=new int[sum+1];

        for(int i=1; i< sum+1 ;i++){
                dp[i]=INT_MAX;
        }

        dp[0]=0;

        cout<<endl<<min_coin(coins, max_coins , sum)<<endl;

        return 0;

}

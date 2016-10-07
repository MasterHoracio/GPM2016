#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
ll dp [1005];

void memo(){
	for(ll i = 1; i <= 1000; i++)
		dp[i] = pow(i,3);
} 

int main(){
	ll n, pos, ans;
	bool cont;
	memo();
	while(scanf("%lld",&n)){
		if(n == 0)
			break;
		pos = 1;
		ans = 0;
		while(dp[pos] <= n){
			if(n % dp[pos] == 0)
				ans++;
			pos++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
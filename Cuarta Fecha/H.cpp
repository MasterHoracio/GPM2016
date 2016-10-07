#include <cstdio>
#include <string>
#include <map>

#define MAX 1050

using namespace std;

int main(){
	int cases, len, len2;
	char str[MAX], c;
	string str1, str2;
	map<char,int> mp;
	map<char,int>::iterator it;

	scanf("%d",&cases);

	while(cases--){
		scanf("%d",&len);
		str1 = str2 = "";
		getchar();
		for(int i = 0; i < len; i++){
			c = getchar();
			str[i] = c;
			mp[c]++;
		}
		for(it = mp.begin(); it != mp.end(); it++){
			if(it->second >= 2){
				while(it->second >= 2){
					str1 += it->first;
					str2 += it->first;
					it->second -= 2;
				}
			}
		}

		for(it = mp.begin(); it != mp.end(); it++){
			if(it->second == 1){
				str1 += it->first;
				break;
			}
		}

		len2 = str2.length();
		for(int i = len2 - 1; i >= 0; i--)
			str1+= str2[i];

		printf("%s\n",str1.c_str());
		mp.clear();

	}

	return 0;
}
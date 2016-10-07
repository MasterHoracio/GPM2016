#include <cstdio>
#include <queue>

#define MAX 1000050

using namespace std;

int arr[MAX];

int main(){
	int cases, n, k;
	deque < pair<int, int> > solve;

	scanf("%d",&cases);

	while(cases--){

		scanf("%d %d",&n,&k);

		for(int i = 0; i < n; i++)
			scanf("%d",&arr[i]);

		solve.push_back(make_pair(0,arr[0]));

		if(k == 1)
			printf("%d ",arr[0]);

		for(int i = 1; i < n; i++){

			if(arr[i] > solve.front().second){
				if(i >= (k - 1) )
					printf("%d ",arr[i]);
				solve.push_front(make_pair(i,arr[i]));
			}

			else if(arr[i] < solve.back().second){
				solve.push_back(make_pair(i,arr[i]));
				while(solve.front().first < (i + 1 - k) )//recortamos excedente
					solve.pop_front();
				if(i >= k - 1)
					printf("%d ",solve.front().second);
			}

			else{
				while(solve.back().second < arr[i])//quitamos los menores
					solve.pop_back();
				solve.push_back(make_pair(i,arr[i]));
				while(solve.front().first < (i + 1 - k))//recortamos excedente
					solve.pop_front();
				if(i >= k - 1)
					printf("%d ",solve.front().second);
			}
		}

		printf("\n");
		solve.clear();

	}

	return 0;
}
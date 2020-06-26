#include <bits/stdc++.h>
using namespace std;
const int N = 10;
char a[N], b[N];
int nex[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
map<string, int>maps;
map<string, int>temp;
int BFS()
{
	if(strcmp(a, b)==0)
		return 0;
	queue<string>q;
	q.push(a);
	q.push(b);
	while(!q.empty()) {
		string head = q.front();
		q.pop();
		int x{}, y{}, t;
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++) {
				t = i*3+j;
				if(head[t]=='.') {
					x=i;
					y=j;
					break;
				}
			}
		t=x*3+y;
		for(int i=0; i<4; i++) {
			int tx = x+nex[i][0];
			int ty = y+nex[i][1];
			
			if(tx>=0 && tx<3 && ty>=0 && ty<3) {
				int r=tx*3+ty;
				string tail = head;
				tail[t] = tail[r];
				tail[r] = '.';
				if(!maps[tail]) {
					maps[tail] = maps[head];
					temp[tail] = temp[head]+1;
					q.push(tail);
				}
				else if(maps[head]+maps[tail]==3){
					return temp[head]+temp[tail]+1;
				}
			}
		}	
		
	}
	return -1;
}
int main()
{
	scanf("%s%s", a, b);
	maps[a]=1;
	maps[b]=2;
	printf("%d\n", BFS());
	return 0;
}

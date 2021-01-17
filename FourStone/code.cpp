//copy


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vc vector<int>
#define pi pair<int,int>
int x;
vector<pi>r;
void sort(vc&a){
	sort(a.begin(),a.end());
}
void rev(vector<pi>&a){
	reverse(a.begin(),a.end());
	for(auto &x:a)
		x.first=2*x.second-x.first;
}
void mv(int x,int y,vc&a,vector<pi>&b){
	if(a[x]==a[y])return;
	b.push_back(make_pair(a[x],a[y]));
	a[x]=2*a[y]-a[x];
}
vector<pi> m1(vc&a){
	vector<pi>v;
	int g=__gcd(__gcd(a[3]-a[0],a[3]-a[1]),a[3]-a[2]);  //gcd as a board
	while(a[3]-a[0]>g){
		int d=a[3]-a[0],x=min(a[3]-a[1],a[1]-a[0]),y=min(a[3]-a[2],a[2]-a[0]);
		if(x>=max(1ll,d/4)){
			if(x==a[3]-a[1]){
				mv(3,1,a,v);
				mv(2,1,a,v);
			}
			else mv(0,1,a,v);
		}
		else if(y>=max(1ll,d/4)){
			if(y==a[3]-a[2])mv(3,2,a,v);
			else{
				mv(1,2,a,v);
				mv(0,2,a,v);
			}
		}
		else{
			if(x<y){
				if(y==a[3]-a[2]){
					mv(1,2,a,v);
					mv(1,3,a,v);
				}
				else{
					mv(1,0,a,v);
					mv(1,2,a,v);
				}
			}
			else{
				if(x==a[1]-a[0]){
					mv(2,1,a,v);
					mv(2,0,a,v);
				}
				else{
					mv(2,3,a,v);
					mv(2,1,a,v);
				}
			}
		}
		sort(a);
	}
	return v;
}
void m2(vc&a,int d,vector<pi>&v){
	int g=a[3]-a[0];
	if((a[0]/g)%2!=(d/g)%2){
		mv(0,3,a,v);
		mv(1,3,a,v);
		mv(2,3,a,v);
		sort(a);
	}
	int va=(d-a[0])/2;
	while(a[3]-a[0]<=va){
		mv(2,0,a,v);
		mv(1,3,a,v);
		sort(a);
	}
	while(a[3]-a[0]>g){
		mv(0,1,a,v);
		mv(3,2,a,v);
		sort(a);
		while(a[3]-a[0]<=va){
			mv(0,3,a,v);
			mv(1,3,a,v);
			mv(2,3,a,v);
			sort(a);
			mv(0,3,a,v);
			mv(1,3,a,v);
			mv(2,3,a,v);
			sort(a);
			va-=a[3]-a[0];
		}
	}
}

signed main(){
	vc a,b;
	for(int i=0;i<4;i++){
		cin>>x;
		a.push_back(x);
	}
	for(int i=0;i<4;i++){
		cin>>x;
		b.push_back(x);
	}
	sort(a);
	sort(b);
	if(a[0]==a[3]){
		if(b==a)puts("0");
		else puts("-1");
		exit(0);
	}
	auto c=m1(a),d=m1(b);
	int g=a[3]-a[0];
	if(b[3]-b[0]!=g||b[0]%g!=a[0]%g){
		puts("-1");
		exit(0);
	}
	if(a[0]<b[0])m2(a,b[0],c);
	else m2(b,a[0],d);
	if(a!=b){
		puts("-1");
		exit(0);
	}
	rev(d);
	c.insert(c.end(),d.begin(),d.end());
	cout<<c.size()<<'\n';
	for(auto x:c)
		cout<<x.first<<' '<<x.second<<'\n';
}

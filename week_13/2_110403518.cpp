// 程式設計研討專題 week 13
// UVA 10136 Chocolate Chip Cookies
// Computational Geometry
// 給很多點 問一直徑5公分的圓最多能包含幾個點
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
using namespace std;

typedef struct pnode
{
	double x,y,r;
}point;
point P[202],cl,cr;
 
double dist_p2p(point a, point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void circle(point a, point b, double r, point &c1, point &c2)
{
	double dist_c2ab = sqrt(r*r-dist_p2p(a, b)*dist_p2p(a, b)/4);
	if (a.x == b.x) {
		c1.y = c2.y = (a.y+b.y)/2;
		c1.x = a.x + dist_c2ab;
		c2.x = a.x - dist_c2ab;
	}else {
		double k = atan((b.x-a.x)/(a.y-b.y));
		c1.x = (a.x+b.x)/2+dist_c2ab*cos(k);
		c1.y = (a.y+b.y)/2+dist_c2ab*sin(k);
		c2.x = (a.x+b.x)/2-dist_c2ab*cos(k);
		c2.y = (a.y+b.y)/2-dist_c2ab*sin(k);
	}
}
int main()
{
	int  n;
	char buf[100];
	scanf("%d",&n);getchar();getchar();
	while (n --) {
		int count = 0;
		while (gets(buf) && buf[0]) {
			sscanf(buf,"%lf%lf",&P[count].x,&P[count].y);
			count ++;
		}
		
		int max_count = 1;
		for (int i = 1; i < count; ++ i)
			for (int j = 0; j < i; ++ j)
				if (dist_p2p(P[i], P[j]) <= 5) {
					circle(P[i], P[j], 2.5, cl, cr);
					int l_count = 0,r_count = 0;
					for (int k = 0; k < count; ++ k) {
						if (dist_p2p(P[k], cl) <= 2.5)
							l_count ++;
						if (dist_p2p(P[k], cr) <= 2.5)
							r_count ++;
					}
					if (max_count < l_count)
						max_count = l_count;
					if (max_count < r_count)
						max_count = r_count;
				}
		
		printf("%d\n",max_count);
		if (n) printf("\n");
	}
    return 0;
}
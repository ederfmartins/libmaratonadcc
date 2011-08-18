#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool inRet(int x, int y, int u, int v, float px, float py)
{
	//printf("->%d %d %d %d %f %f\n", x, y, u, v, px, py);
	if (px > x && px < u && py < y && py > v) return true;
	else return false;
}

int main()
{
	int n, cnt = 1;
	
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;

		int x, y, u, v;
		int x1, y1, u1, v1;
		bool nvazio = true;
		scanf("%d %d %d %d", &x, &y, &u, &v);

		for (int i = 1; i < n; i++)
		{
			scanf("%d %d %d %d", &x1, &y1, &u1, &v1);
			
			//printf("bla->%d %d %d %d\n", x, y, u, v);
			//printf("bla1->%d %d %d %d\n", x1, y1, u1, v1);
			
			if (nvazio)
			{
				//faz intersecao dos retangulos
				vector<int> xord;
				vector<int> yord;
				xord.push_back(x); xord.push_back(u); xord.push_back(x1); xord.push_back(u1);
				yord.push_back(y); yord.push_back(v); yord.push_back(y1); yord.push_back(v1);
				sort(xord.begin(), xord.end());
				sort(yord.begin(), yord.end());
				
				int xI = xord[1], yI = yord[2];
				int uI = xord[2], vI = yord[1];
				
				//printf("blaI->%d %d %d %d\n", xI, yI, uI, vI);
				
				if (inRet(x, y, u, v, ((float)(xI+uI))/2, ((float)(yI+vI))/2) && inRet(x1, y1, u1, v1, ((float)(xI+uI))/2, ((float)(yI+vI))/2))
				{
					x = xI; y = yI;
					u = uI; v = vI;
				}
				else nvazio = false;
			}
		}

		if (nvazio) printf("Teste %d\n%d %d %d %d\n\n", cnt++, x, y, u, v);
		else printf("Teste %d\nnenhum\n\n", cnt++);
	}
	
	return 0;
}


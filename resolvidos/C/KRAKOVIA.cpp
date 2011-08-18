#include <iostream>
#include <cstdio>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
	int n,f;
	char numero[25];
	int bill=1;
	while(scanf("%d %d",&n,&f)==2) 
	{
		if(n==0 && f==0) break;
		uint64_t upper=0, lower=0;
		for(int i=0; i < n; i++) {
			scanf("%s\n", numero);
			int len = strlen(numero);
			if(len > 10) {
				char dtmp=numero[len-10];
				numero[len-10]='\0';
				upper+=atoll(numero);
				numero[len-10]=dtmp;
				lower+=atoll(numero+len-10);
			} else
				lower += atoll(numero);
		}
		if(upper) {
			upper += lower/10000000000llu;
			lower = lower%10000000000llu;

			int ra=(upper%f),rb=(10000000000llu%f);
			uint64_t r1=ra*rb, r2=lower%f;
			uint64_t rlower = (lower-r2)/f+(r1+r2)/f;
			uint64_t uupper, ulower, a0, b0, a1, b1, uu14, uu7, Sa, Sb;
			Sb=(10000000000llu/f);
			Sa=upper/f;
			a0=(upper-ra)/10000000llu, a1=(upper-ra)%10000000llu;
			b0=Sb/10000000llu, b1=Sb%10000000llu;
			uu14=a0*b0, uu7=a1*b0+a0*b1+(Sa/10000000llu)*rb+(Sb/10000000llu)*ra;
			ulower=(Sa%10000000llu)*rb+(Sb%10000000llu)*ra+a1*b1+rlower;
			if(ulower/10000000) {
				uu7 += ulower/10000000;
				ulower = ulower%10000000;
			}
			if(uu7/10000000) {
				uu14 += uu7/10000000;
				uu7 = uu7%10000000;
			}

			printf("Bill #%d costs %lld", bill, upper);
			uint64_t zfill=lower?lower:1;

			while(zfill < 1000000000llu) {
				printf("0");
				zfill *= 10;
			}
			if(uu14) {
				printf("%lld: each friend should pay %lld", lower, uu14);
				zfill=uu7?uu7:1;
				while(zfill < 1000000llu) {
					printf("0");
					zfill *= 10;
				}
				printf("%lld", uu7);
				zfill=ulower?ulower:1;
				while(zfill < 1000000llu) {
					printf("0");
					zfill *= 10;
				}
				printf("%lld", ulower);
			} else {
				if(uu7) {
					printf("%lld: each friend should pay %lld", lower, uu7);
					zfill=ulower?ulower:1;
					while(zfill < 1000000llu) {
						printf("0");
						zfill *= 10;
					}
					printf("%lld", ulower);
				}
				else {
					printf("%lld: each friend should pay %lld", lower, ulower);
				}
			}
			printf("\n\n");
		}
		else {
			printf("Bill #%d costs %lld: each friend should pay %lld\n\n", bill, lower, lower/f);
		}
		bill++;
	}
	return 0;
}


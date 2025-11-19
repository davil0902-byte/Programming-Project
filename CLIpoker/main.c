#include <stdio.h>
#include "method.h"

int main() {
	int i, pp, dp, ps = 0 , pr = 0, pr2 = 0, ds = 0, dr = 0, dr2 = 0, cnt = 0;
	struct card deck[52];
	struct card hand[2];
	struct card dealer[2];
	struct card table[5];
	struct card pf[7];
	struct card df[7];

	shuffle(deck);
	printf("핸드 : ");
	for (i = 0; i < 2; i++) {
		dealcard(deck, hand, &cnt, i);
	}
	printf("\n\n");
	for (i = 0; i < 2; i++) {
		dealer[i] = deck[cnt];
		cnt++;
	}
	printf("플랍 : ");
	for (i = 0; i < 3; i++) {
		dealcard(deck, table, &cnt, i);
	}
	printf("\n\n턴 : ");
	dealcard(deck, table, &cnt, 3);
	printf("\n\n리버 : ");
	dealcard(deck, table, &cnt, 4);
	printf("\n\n");

	for (i = 0; i < 2; i++) {
		pf[i] = hand[i];
	}
	for (i = 0; i < 5; i++) {
		pf[i + 2] = table[i];
	}
	for (i = 0; i < 2; i++) {
		df[i] = dealer[i];
	}
	for (i = 0; i < 5; i++) {
		df[i + 2] = table[i];
	}

	printf("플레이어의 패\n");
	determine(pf, &pp, &ps, &pr, &pr2);
	printf("\n\n딜러의 패\n");
	determine(df, &dp, &ds, &dr, &dr2);

	if (winer(pp, pr, ps, pr2, dp, dr, ds, dr2) == 1) {
		printf("\n승리하였습니다!\n");
	}
	else if(winer(pp, pr, ps, pr2, dp, dr, ds, dr2) == 0) {
		printf("\n패배하였습니다\n");
	}
	else {
		printf("\n비기셨습니다\n");
	}

	return 0;
}
#include <stdio.h>
#include "method.h"

int main() {
	int i, c, pp, dp, ps = 0 , pr = 0, pr2 = 0, pchips = 20, ds = 0, dr = 0, dr2 = 0, dchips = 20, bet, cnt = 0, r;
	struct card deck[52];
	struct card hand[2];
	struct card dealer[2];
	struct card table[5];
	struct card pf[7];
	struct card df[7];

	while (pchips > 0 && dchips > 0) {
		printf("-----------------------------------------\n");
		printf("소유한 칩의 양:\n플레이어: %d\n딜러%d\n\n", pchips, dchips);
		bet = 1;
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
		printf("*****\n");
		printf("첫 베팅 라운드\n1.콜     2.레이즈     3.폴드\n\n");
		c = 0;
		do {
			printf("플레이어의 선텍: ");
			scanf_s("%d", &c);
			printf("\n");
			switch (c) {
			case 1:
				if (pchips == bet) {
					printf("올인!\n");
					bet = pchips;
				}
				else {
					printf("콜\n");
				}
				printf("현재 베팅금액: %d\n\n", bet);
				break;

			case 2:
				if (pchips == bet) {
					printf("이미 올인 하셨습니다.\n");
					bet = pchips;
				}
				else {
					printf("레이즈\n");
					printf("레이즈 금액: ");
					scanf_s("%d", &r);
					printf("\n");
					if (bet + r > pchips) {
						printf("소유한 칩의 양을 넘었습니다.\n\n");
						c = 0;
					}
					else {
						bet += r;
					}
				}
				printf("현재 베팅금액: %d\n\n", bet);
				break;

			case 3:
				printf("폴드 하셨습니다.\n\n");
				pchips -= bet;
				dchips += bet;
				break;

			default:
				printf("잘못 입력하셨습니다.\n\n");
				c = 0;
				break;
			}
		} while (c == 0);

		if (c == 3) {
			continue;
		}

		printf("플랍 : ");
		for (i = 0; i < 3; i++) {
			dealcard(deck, table, &cnt, i);
		}
		printf("\n\n");
		printf("*****\n");
		printf("두 번째 베팅 라운드\n1.콜     2.레이즈     3.폴드\n\n");
		c = 0;
		do {
			printf("플레이어의 선텍: ");
			scanf_s("%d", &c);
			printf("\n");
			switch (c) {
			case 1:
				if (pchips == bet) {
					printf("올인!\n");
					bet = pchips;
				}
				else {
					printf("콜\n");
				}
				printf("현재 베팅금액: %d\n\n", bet);
				break;

			case 2:
				if (pchips == bet) {
					printf("이미 올인 하셨습니다.\n");
					bet = pchips;
				}
				else {
					printf("레이즈\n");
					printf("레이즈 금액: ");
					scanf_s("%d", &r);
					printf("\n");
					if (bet + r > pchips) {
						printf("소유한 칩의 양을 넘었습니다.\n\n");
						c = 0;
					}
					else {
						bet += r;
					}
				}
				printf("현재 베팅금액: %d\n\n", bet);
				break;

			case 3:
				printf("폴드 하셨습니다.\n\n");
				pchips -= bet;
				dchips += bet;
				break;

			default:
				printf("잘못 입력하셨습니다.\n\n");
				c = 0;
				break;
			}
		} while (c == 0);

		if (c == 3) {
			continue;
		}

		printf("\n턴 : ");
		dealcard(deck, table, &cnt, 3);
		printf("\n\n");
		printf("*****\n");
		printf("세 번째 베팅 라운드\n1.콜     2.레이즈     3.폴드\n\n");
		c = 0;
		do {
			printf("플레이어의 선텍: ");
			scanf_s("%d", &c);
			printf("\n");
			switch (c) {
			case 1:
				if (pchips == bet) {
					printf("올인!\n");
					bet = pchips;
				}
				else {
					printf("콜\n");
				}
				printf("현재 베팅금액: %d\n\n", bet);
				break;

			case 2:
				if (pchips == bet) {
					printf("이미 올인 하셨습니다.\n");
					bet = pchips;
				}
				else {
					printf("레이즈\n");
					printf("레이즈 금액: ");
					scanf_s("%d", &r);
					printf("\n");
					if (bet + r > pchips) {
						printf("소유한 칩의 양을 넘었습니다.\n\n");
						c = 0;
					}
					else {
						bet += r;
					}
				}
				printf("현재 베팅금액: %d\n\n", bet);
				break;

			case 3:
				printf("폴드 하셨습니다.\n\n");
				pchips -= bet;
				dchips += bet;
				break;

			default:
				printf("잘못 입력하셨습니다.\n\n");
				c = 0;
				break;
			}
		} while (c == 0);

		if (c == 3) {
			continue;
		}

		printf("\n리버 : ");
		dealcard(deck, table, &cnt, 4);
		printf("\n\n");
		printf("*****\n");
		printf("마지막 베팅 라운드\n1.콜     2.레이즈     3.폴드\n\n");
		c = 0;
		do {
			printf("플레이어의 선텍: ");
			scanf_s("%d", &c);
			printf("\n");
			switch (c) {
			case 1:
				if (pchips == bet) {
					printf("올인!\n");
					bet = pchips;
				}
				else {
					printf("콜\n");
				}
				printf("현재 베팅금액: %d\n\n", bet);
				break;

			case 2:
				if (pchips == bet) {
					printf("이미 올인 하셨습니다.\n");
					bet = pchips;
				}
				else {
					printf("레이즈\n");
					printf("레이즈 금액: ");
					scanf_s("%d", &r);
					printf("\n");
					if (bet + r > pchips) {
						printf("소유한 칩의 양을 넘었습니다.\n\n");
						c = 0;
					}
					else {
						bet += r;
					}
				}
				printf("현재 베팅금액: %d\n\n", bet);
				break;

			case 3:
				printf("폴드 하셨습니다.\n\n");
				pchips -= bet;
				dchips += bet;
				break;

			default:
				printf("잘못 입력하셨습니다.\n\n");
				c = 0;
				break;
			}
		} while (c == 0);

		if (c == 3) {
			continue;
		}

		printf("쇼다운\n");

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
			printf("\n승리하였습니다!\n\n");
			pchips += bet;
			dchips -= bet;
		}
		else if(winer(pp, pr, ps, pr2, dp, dr, ds, dr2) == 0) {
			printf("\n패배하였습니다\n\n");
			pchips -= bet;
			dchips += bet;
		}
		else {
			printf("\n비기셨습니다\n\n");
		}
	}
	if (dchips == 0) {
		printf("-----------------------------------------\n\n");
		printf("[승리]\n\n");
		printf("-----------------------------------------\n");
	}
	else {
		printf("-----------------------------------------\n\n");
		printf("[패배]\n\n");
		printf("-----------------------------------------\n");
	}

	return 0;
}
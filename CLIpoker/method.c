#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "method.h"

void shuffle(struct card *d) {
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			d[j+i*13].suit = i+1;
			d[j+i*13].rank = j + 2;
		}
	}
	for (int i = 51; i > 0; i--) {
		int j = rand() % (i + 1);
		struct card temp = d[i];
		d[i] = d[j];
		d[j] = temp;
	}
}

void dealcard(struct card* d, struct card* h, int* cnt, int i) {
	h[i] = d[*cnt];
	switch (h[i].suit) {
	case 1:
		printf("[클로버 ");
		break;

	case 2:
		printf("[하트 ");
		break;

	case 3:
		printf("[다이아 ");
		break;

	case 4:
		printf("[스페이드 ");
		break;
	}

	if (h[i].rank == 11) {
		printf("잭] ");
	}
	else if(h[i].rank == 12) {
		printf("퀸] ");
	}
	else if (h[i].rank == 13) {
		printf("킹] ");
	}
	else if (h[i].rank == 14) {
		printf("에이스] ");
	}
	else {
		printf("%d] ", h[i].rank);
	}

	(*cnt)++;
}

void printcard(s, r) {
	switch (s) {
	case 1:
		printf("[클로버 ");
		break;

	case 2:
		printf("[하트 ");
		break;

	case 3:
		printf("[다이아 ");
		break;

	case 4:
		printf("[스페이드 ");
		break;
	}

	switch (r) {
	case 11:
		printf("잭] ");
		break;

	case 12:
		printf("퀸] ");
		break;

	case 13:
		printf("킹] ");
		break;

	case 14:
		printf("에이스] ");
		break;

	default:
		printf("%d] ", r);
		break;
	}
}

void determine(struct card* f, int* p, int* ks, int* kr, int* kr2) {
	int i, j, tmps = 0, tmpr = 0, tmpr2 = 0, cnt = 0, suit[5] = { 0 }, rank[20] = { 0 };
	*ks = 0;

	for (i = 0; i < 7; i++) {
		suit[f[i].suit]++;
	}
	for (i = 1; i <= 4; i++) {
		if (suit[i] >= 5) {
			*ks = i;
			for (j = 0; j < 7; j++) {
				if (f[j].suit == *ks) {
					rank[f[j].rank]++;
				}
			}
			for (j = 2; j <= 14; j++) {
				if (rank[j] > 0) {
					cnt++;
					if (cnt >= 5) {
						*kr = j;
					}
				}
				else {
					cnt = 0;
				}
			}
			if (*kr != 0) {
				for (j = 4; j >= 0; j--) {
					printcard(*ks, *kr - j);
				}
				if (*kr == 14) {
					printf("\n로얄 플러쉬\n");
					*p = 10;
				}
				else {
					printf("\n스트레이트 플러쉬\n");
					*p = 9;
				}
			}
			else {
				cnt = 0;
				for (j = 14; j >= 2; j--) {
					if (rank[j] > 0) {
						printcard(*ks, j);
						if (cnt == 0) {
							*kr = j;
						}
						cnt++;
					}
					if (cnt == 5) {
						break;
					}
				}
				printf("\n플러쉬\n");
				*p = 6;
			}
			return;
		}
	}

	for (i = 0; i < 7; i++) {
		rank[f[i].rank]++;
	}
	for (i = 2; i <= 14; i++) {
		if (rank[i] > 0) {
			cnt++;
			if (cnt >= 5) {
				*kr = i;
			}
		}
		else {
			cnt = 0;
		}
	}
	if (*kr != 0) {
		for (i = 4; i >= 0; i--) {
			*ks = 0;
			for (j = 0; j < 7; j++) {
				if (f[j].rank == *kr - i && f[j].suit > *ks) {
					*ks = f[j].suit;
				}
			}
			printcard(*ks, *kr - i);
		}
		printf("\n스트레이트\n");
		*p = 5;
		return;
	}
	for (i = 2; i <= 14; i++) {
		if (rank[i] == 4) {
			*kr = i;
			*kr2 = 0;
			*ks = 0;
			for (j = 0; j < 7; j++) {
				if (f[j].rank > *kr2) {
					*kr2 = f[j].rank;
					if (f[j].suit > *ks) {
						*ks = f[j].suit;
					}
				}
			}
			for (j = 1; j <= 4; j++) {
				printcard(j, *kr);
			}
			printcard(*ks, *kr2);
			printf("\n포 카드\n");
			*p = 8;
			return;
		}
	}
	for (i = 2; i <= 14; i++) {
		if (rank[i] == 3) {
			*kr = i;
			for (j = i + 1; j <= 14; j++) {
				if (rank[j] == 3) {
					*kr2 = *kr;
					*kr = j;
				}
				if (rank[j] == 2) {
					*kr2 = j;
				}
			}
			if (*kr2 != 0) {
				for (j = 0; j < 7; j++) {
					if (f[j].rank == *kr) {
						printcard(f[j].suit, *kr);
					}
				}
				for (j = 0; j < 7; j++) {
					if (f[j].rank == *kr2) {
						printcard(f[j].suit, *kr2);
					}
				}
				printf("\n풀 하우스\n");
				*p = 7;
				return;
			}
			else {
				for (j = 0; j < 7; j++) {
					if (f[j].rank == *kr) {
						printcard(f[j].suit, *kr);
					}
				}
				for (j = 0; j < 7; j++) {
					if (f[j].rank > *kr2 && f[j].rank != *kr) {
						*kr2 = f[j].rank;
						tmps = f[j].suit;
					}
				}
				printcard(tmps, *kr2);
				for (j = 0; j < 7; j++) {
					if (f[j].rank > tmpr && f[j].rank != *kr && f[j].rank < *kr2) {
						tmpr = f[j].rank;
						tmps = f[j].suit;
					}
				}
				printcard(tmps, tmpr);
				printf("\n트리플\n");
				*p = 4;
				return;
			}
		}
	}
	for (i = 2; i <= 14; i++) {
		if (rank[i] == 2) {
			*kr = i;
			for (j = i + 1; j <= 14; j++) {
				if (rank[j] == 2) {
					*kr2 = *kr;
					*kr = j;
				}
			}
			if (*kr2 != 0) {
				for (j = 0; j < 7; j++) {
					if (f[j].rank == *kr) {
						printcard(f[j].suit, f[j].rank);
					}
				}
				for (j = 0; j < 7; j++) {
					if (f[j].rank == *kr2) {
						printcard(f[j].suit, f[j].rank);
					}
				}
				for (j = 0; j < 7; j++) {
					if (f[j].rank >= tmpr && f[j].rank != *kr && f[j].rank != *kr2) {
						tmpr = f[j].rank;
						tmps = f[j].suit;
					}
				}
				printcard(tmps, tmpr);
				printf("\n투 페어\n");
				*p = 3;
				return;
			}
			else {
				for (j = 0; j < 7; j++) {
					if (f[j].rank == *kr) {
						printcard(f[j].suit, f[j].rank);
					}
				}
				for (j = 0; j < 7; j++) {
					if (f[j].rank > *kr2 && f[j].rank != *kr) {
						tmps = f[j].suit;
						*kr2 = f[j].rank;
					}
				}
				printcard(tmps, *kr2);
				for (j = 0; j < 7; j++) {
					if (f[j].rank > tmpr && f[j].rank != *kr && f[j].rank < *kr2) {
						tmps = f[j].suit;
						tmpr = f[j].rank;
					}
				}
				printcard(tmps, tmpr);
				for (j = 0; j < 7; j++) {
					if (f[j].rank > tmpr2 && f[j].rank != *kr && f[j].rank < tmpr) {
						tmps = f[j].suit;
						tmpr2 = f[j].rank;
					}
				}
				printcard(tmps, tmpr2);
				printf("\n원 페어\n");
				*p = 2;
				return;
			}
		}
	}
	for (i = 0; i < 7; i++) {
		if (f[i].rank > *kr) {
			tmps = f[i].suit;
			*kr = f[i].rank;
		}
	}
	printcard(tmps, *kr);
	for (i = 0; i < 7; i++) {
		if (f[i].rank > *kr2 && f[i].rank < *kr) {
			tmps = f[i].suit;
			*kr2 = f[i].rank;
		}
	}
	printcard(tmps, *kr2);
	for (i = 0; i < 7; i++) {
		if (f[i].rank > tmpr && f[i].rank < *kr2) {
			tmps = f[i].suit;
			tmpr = f[i].rank;
		}
	}
	printcard(tmps, tmpr);
	for (i = 0; i < 7; i++) {
		if (f[i].rank > tmpr2 && f[i].rank < tmpr) {
			tmps = f[i].suit;
			tmpr2 = f[i].rank;
		}
	}
	printcard(tmps, tmpr2);
	tmpr = 0;
	for (i = 0; i < 7; i++) {
		if (f[i].rank > tmpr && f[i].rank < tmpr2) {
			tmps = f[i].suit;
			tmpr = f[i].rank;
		}
	}
	printcard(tmps, tmpr);
	printf("\n하이 카드\n");
	*p = 1;
	return;
}

int winer(int pp, int pr, int ps, int pr2, int dp, int dr, int ds, int dr2) {
	if (pp > dp) return 1;
	else if (pp < dp) return 0;
	else {
		if (pr > dr) return 1;
		else if (pr < dr) return 0;
		else {
			if (ps > ds) return 1;
			else if (ps < ds) return 0;
			else {
				if (pr2 > dr2) return 1;
				else if (pr2 < dr2) return 0;
				else return 2;
			}
		}
	}
}
#pragma once
struct card {
	char suit;
	int rank;
};

void shuffle(struct card* d);
void dealcard(struct card* d, struct card* h, int* cnt, int i);
void printcard(s, r);
void determine(struct card* f, int* p, int* ks, int* kr, int* kr2);
int winer(int pp, int pr, int ps, int pr2, int dp, int dr, int ds, int dr2);
#include <stdio.h>

int main(void) {

	unsigned char msg[] = "i.imgur.com/gCELd3X.png";
	unsigned char carrier[] = "The pose you make when you write a simple program to embed secret messages into apparently plain text.";

	int msgSize = sizeof(msg);
	int carSize = sizeof(carrier);
	int stenSize = msgSize + carSize;

	char trojan[stenSize];

	FILE *fout = fopen("StegOut.txt", "w");

	int carIndex = 0;
	int troIndex = 0;
	int msgIndex = 0;
	int locVal = msg[msgIndex];

	while (locVal != 0) {
		unsigned char mask = 128;
		for (int i = 0; i < 8; i++) {
			if (msg[msgIndex] & mask) {
				trojan[troIndex] = 173;
			} else {
				trojan[troIndex] = carrier[carIndex];
				carIndex++;
			}
			troIndex++;
			mask >>= 1;
		}
		msgIndex++;
		locVal = msg[msgIndex];
	}

	for (int i = carIndex; i < carSize; i++) {
		trojan[troIndex] = carrier[carIndex];
		troIndex++;
		carIndex++;
	}

	printf("%s\n", trojan);

	fprintf(fout, "%s\n", trojan);

	fclose(fout);

	return 0;
}
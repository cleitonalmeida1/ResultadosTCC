/*
 * main.h
 *
 *  Created on: 19/07/2016
 *      Author: Cleiton Gon�alves
 */


#ifndef MAIN_CPP_
#define MAIN_CPP_

#include "mbed.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "CombSort.h"
#include "../Logger/Logger.h"
#include <iostream>
void desordenarVetor(unsigned short vetor[], unsigned short n) {
	for (int i = n; i > 0; --i) {
		vetor[n - i] = i;
	}
}

int main() {

	Timer t;
	LocalFileSystem fs("local");
	Logger logger("/local/log.txt", false);

	const unsigned short n = 4096;
	unsigned short vetor[n];

	cout << sizeof(vetor) << endl;

	desordenarVetor(vetor, n);

	CombSort comb;
	InsertionSort insertion;
	SelectionSort selection;
	BubbleSort bubble;
	MergeSort merge;

	logger.log("BubbleSort\t");
	logger.log("InsertionSort\t");
	logger.log("SelectionSort\t");
	logger.log("MergeSort\t");
	logger.log("CombSort\r");
	for (unsigned short i = 1; i < 101; ++i) {

		//desordenado vetor
		desordenarVetor(vetor, n);

		t.reset();
		t.start();
		bubble.buble(vetor, n);
		logger.log("%f\t", t.read());
		t.stop();

		//desordenando vetor
		desordenarVetor(vetor, n);

		t.reset();
		t.start();
		insertion.insertion(vetor, n);
		logger.log("%f\t", t.read());
		t.stop();

		//desordenando vetor
		desordenarVetor(vetor, n);

		t.reset();
		t.start();
		selection.selection(vetor, n);
		logger.log("%f\t", t.read());
		t.stop();

		//desordenando vetor
		desordenarVetor(vetor, n);

		t.reset();
		t.start();
		merge.mergeSort(vetor, 0, n-1);
		logger.log("%f\t", t.read());
		t.stop();

		//desordenando vetor
		desordenarVetor(vetor, n);

		t.reset();
		t.start();
		comb.comb(vetor, n);
		logger.log("%f\r", t.read());
		t.stop();
	}
	return 0;
}

#endif /* MAIN_CPP_ */

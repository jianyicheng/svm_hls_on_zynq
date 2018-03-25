#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "fp_svm.h"
#include "svm_classifier.h"
#include "testData.h"

#define ASIZE(a)	(sizeof(a) / sizeof((a)[0]))

int main()
{
	FILE *fp = fopen("classifier.out", "w");
	static const size_t size = 2000;
	data_t *pd = testData;
	bool *pl = testDataLabel;
	size_t err = 0;
	for (unsigned int i = 0; i != size; i++) {
		data_t x[DIMENSION];
		for (unsigned int j = 0; j != DIMENSION; j++)
			x[j] = *pd++;

		bool res;
//		fp_svm(&res, x);
		svm_classifier(x, &res);
		if (*pl != res)
			err++;
		fprintf(fp, "%u\t=> %d%s\n", i, res, *pl != res ? "\t<err>" : "");
		pl++;
	}
	fprintf(fp, "Error rate: %g\n", (double)err / (double)size);
	fprintf(stderr, "Error rate: %g\n", (double)err / (double)size);
	fflush(fp);
	fclose(fp);

	puts("Comparing against reference data");
	if (system("diff -w classifier.out classifier.golden.out")) {
		puts("*********************************************");
		puts("FAIL: Output DOES NOT match the golden output");
		puts("*********************************************");
		return 1;
	} else {
		puts("*******************************************");
		puts("PASS: The output matches the golden output!");
		puts("*******************************************");
		return 0;
	}
}

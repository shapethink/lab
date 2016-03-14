#include <stdio.h>
#include <stdlib.h>

int GetInches(FILE*, float** pDest);

int main() {
	FILE* pInfile = fopen("data/rain.infile", "r");

	float* pInches;
	int nDays = GetInches(pInfile, &pInches);
	fclose(pInfile);

	float totalRain = 0.0;
	for(int day = 0; day < nDays; day++) {
		totalRain += pInches[day];
	}
	free(pInches);

	if(totalRain == 0.0)
		printf("There was no rain during this period.\n");
	else {
		float average = totalRain / nDays;
		printf("The average rainfall over %d days was %f\n", nDays, average);
	}

	return 0;
}

int GetInches(FILE* input, float** pDest) {
	int nDays;
	fscanf(input, "%d\n", &nDays);
	float* data = (float*)malloc(sizeof(float) * nDays);
	for(int day = 0; day < nDays; day++)
	{
		float inches;
		fscanf(input, "%f", &inches);
		data[day] = inches;
	}
	*pDest = data;
	return nDays;
}

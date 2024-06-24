#include <stdio.h>
#include <stdlib.h>

int main()
{
	char nome_file_1[256];
	char nome_file_2[256];

	printf("File da copiare:\n");
	scanf("%s", nome_file_1);
	printf("File destinazione copia:\n");
	scanf("%s", nome_file_2);

	FILE* f1 = fopen(nome_file_1, "rb");
	FILE* f2 = fopen(nome_file_2, "wb");

	if (f1 == NULL || f2 == NULL) {
		printf("Errore durante apertura file(s)!\n");
		return EXIT_FAILURE;
	}

	char buffer[128]; 

	while (1) {
		// lettura
		int byte_letti = fread(buffer, 1, 128, f1);

		// controllo lettura
		if (!feof(f1) && byte_letti < 128) {
			printf("Errore durante la lettura!\n");
			return EXIT_FAILURE;
		}

		// scrittura
		int byte_scritti = fwrite(buffer, 1, byte_letti, f2);

		// controllo scrittura
		if (byte_scritti != byte_letti) {
			printf("Errore durante la scrittura!\n");
			return EXIT_FAILURE;
		}

		// condizione di arresto
		if (feof(f1)) {
			break;
		}
	}

	fclose(f1);
	fclose(f2);	

	printf("Copia completata!\n");
	return 0;
}
#include <stdio.h>
#include <string.h>
#define LINHAS 8
#define COLUNAS 8

//"inicializa_matrix_memoria"->inicializa a matriz "memoria"
// com os valore pre-definidos
void inicializa_matrix_memoria(char* v[LINHAS][COLUNAS]) {
	v[0][0] = "+1A";
	v[0][1] = "+1B";
	v[0][2] = "+1C";
	v[0][3] = "+1D";
	v[0][4] = "+2A";
	v[0][5] = "+2B";
	v[0][6] = "+2C";
	v[0][7] = "+2D";
	v[1][0] = "+3A";
	v[1][1] = "+3B";
	v[1][2] = "+3C";
	v[1][3] = "+3D";
	v[1][4] = "+4A";
	v[1][5] = "+4B";
	v[1][6] = "+4C";
	v[1][7] = "+4D";

	v[2][0] = "-1A";
	v[2][1] = "-1B";
	v[2][2] = "-1C";
	v[2][3] = "-1D";
	v[2][4] = "-2A";
	v[2][5] = "-2B";
	v[2][6] = "-2C";
	v[2][7] = "-2D";
	v[3][0] = "-3A";
	v[3][1] = "-3B";
	v[3][2] = "-3C";
	v[3][3] = "-3D";
	v[3][4] = "-4A";
	v[3][5] = "-4B";
	v[3][6] = "-4C";
	v[3][7] = "-4D";

	v[4][0] = "*1A";
	v[4][1] = "*1B";
	v[4][2] = "*1C";
	v[4][3] = "*1D";
	v[4][4] = "*2A";
	v[4][5] = "*2B";
	v[4][6] = "*2C";
	v[4][7] = "*2D";
	v[5][0] = "*3A";
	v[5][1] = "*3B";
	v[5][2] = "*3C";
	v[5][3] = "*3D";
	v[5][4] = "*4A";
	v[5][5] = "*4B";
	v[5][6] = "*4C";
	v[5][7] = "*4D";

	v[6][0] = "/1A";
	v[6][1] = "/1B";
	v[6][2] = "/1C";
	v[6][3] = "/1D";
	v[6][4] = "/2A";
	v[6][5] = "/2B";
	v[6][6] = "/2C";
	v[6][7] = "/2D";
	v[7][0] = "/3A";
	v[7][1] = "/3B";
	v[7][2] = "/3C";
	v[7][3] = "/3D";
	v[7][4] = "/4A";
	v[7][5] = "/4B";
	v[7][6] = "/4C";
	v[7][7] = "/4D";
}

//"converte_posicao_linha_coluna"->converta a posicao em linha e coluna
void converte_posicao_linha_coluna(int posicao, int* linha, int* coluna) {
	*linha = posicao / 8;
	*coluna = posicao % 8;
}

//"verifica_posicao_valida"->verifica se a posicao inserida pelo utilizador esta entre 0 e 63
int verifica_posicao_valida(int posicao) {
	if (posicao >= 0 && posicao <= (LINHAS * COLUNAS) - 1)
		return 1;
	else
		return 0;
}

void main() {
	char* memoria[LINHAS][COLUNAS];
	int codigo, posicao, linha, coluna;

	// inicializa a matriz "memoria" com os valores iniciais
	inicializa_matrix_memoria(memoria);

	scanf("%d", &codigo);

	if (verifica_posicao_valida(codigo) == 0)
		printf("Carta invalida");
	else {
		converte_posicao_linha_coluna(codigo, &linha, &coluna);
		printf("%s", memoria[linha][coluna]);
	}
}

#include <stdio.h>

int main() {
	int opcao;              // opção escolhida no menu
	float peso, altura, imc;
	float somaIMC = 0;      // acumula todos os IMCs calculados
	int quantidade = 0;     // conta quantos IMCs foram calculados

	// Apresentação do sistema
	printf("=====================================\n");
	printf("      CALCULADORA DE IMC\n");
	printf("=====================================\n");
	printf("Calcule o IMC de varias pessoas e veja a media geral.\n");

	// Loop principal: repete o menu ate o usuario escolher sair (0)
	do {
		printf("\n------------- MENU -------------\n");
		printf("1 - Calcular IMC\n");
		printf("2 - Ver media dos IMCs\n");
		printf("0 - Sair\n");
		printf("Escolha uma opcao: ");

		// scanf retorna 1 se leu um numero com sucesso
		if (scanf("%d", &opcao) != 1) {
			while (getchar() != '\n');  // limpa o que o usuario digitou errado
			opcao = -1;                 // forca cair no "default" do switch
		}

		switch (opcao) {
		case 1:
			// Validacao do peso: repete ate ser maior que 0
			do {
				printf("Digite o peso em kg (ex: 70.5): ");
				if (scanf("%f", &peso) != 1) {
					while (getchar() != '\n');
					peso = -1;
				}
				if (peso <= 0) {
					printf("Peso invalido! Digite um numero maior que zero.\n");
				}
			} while (peso <= 0);

			// Validacao da altura: entre 0.5 m e 2.5 m
			do {
				printf("Digite a altura em metros (ex: 1.75): ");
				if (scanf("%f", &altura) != 1) {
					while (getchar() != '\n');
					altura = -1;
				}
				if (altura < 0.5 || altura > 2.5) {
					printf("Altura invalida! Use metros, entre 0.5 e 2.5.\n");
				}
			} while (altura < 0.5 || altura > 2.5);

			// Calculo do IMC
			imc = peso / (altura * altura);
			printf("\nSeu IMC e: %.2f\n", imc);

			// Classificacao por faixas
			if (imc < 18.5) {
				printf("Classificacao: Abaixo do peso\n");
			} else if (imc < 25) {
				printf("Classificacao: Peso normal\n");
			} else if (imc < 30) {
				printf("Classificacao: Sobrepeso\n");
			} else if (imc < 35) {
				printf("Classificacao: Obesidade grau I\n");
			} else if (imc < 40) {
				printf("Classificacao: Obesidade grau II\n");
			} else {
				printf("Classificacao: Obesidade grau III\n");
			}

			// Guarda para a media
			somaIMC = somaIMC + imc;
			quantidade = quantidade + 1;
			break;

		case 2:
			if (quantidade > 0) {
				printf("\nPessoas calculadas: %d\n", quantidade);
				printf("Media geral dos IMCs: %.2f\n", somaIMC / quantidade);
			} else {
				printf("\nAinda nao ha IMCs calculados. Use a opcao 1 primeiro.\n");
			}
			break;

		case 0:
			// Mensagem de encerramento
			printf("\nObrigado por usar a calculadora de IMC. Ate logo!\n");
			break;

		default:
			printf("\nOpcao invalida! Escolha 1, 2 ou 0.\n");
		}

	} while (opcao != 0);

	return 0;
}
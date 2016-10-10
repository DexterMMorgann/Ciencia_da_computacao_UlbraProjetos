#include <stdio.h>
#include <stdlib.h>

#define STR 100


int leString(char s[], int max){
    int i = 0;
    char letra;

    for (i = 0; i < (max - 1); i++) {
        letra = fgetc(stdin);

        if (letra == 13) {      
		    i--;
            continue;
        }
        if ((letra == 10) && (i == 0)) {
            i = i - 1;
            continue;
        }

        if (letra == 10) {      // Line FEED. Dos e Linux
            break;
        }
        s[i] = letra;
    }
    s[i] = 0;
    return (i);
}


struct ALUNO{
	
	char nMatricula[STR];
	char nomeAluno;
	double G1;
	double G2;
	double G3;
};

struct TURMA{
	
	char nTurma[STR];
	char nomeDisciplina[STR];
	char nomeProfessor[STR];
	int qtdAlunos;
	struct ALUNO listaDeAlunos;
};


main(int qtd, char *parMain[]){
	
	int r;				/* r = resultado da leitura das turmas */
	int i, j;				/* i = j = utilizar no for */
	int qtdTurmas;
	struct TURMA turma;
	
	qtdTurmas = atoi(parMain[1]);
	
	if((qtd > 1) && (qtdTurmas <= 0)){
		printf("Erro %s\n", parMain[1]);
		printf("# ERRO: quantidade de Turmas deve ser maior que 0\n");
		do{
			printf("# Quantas turmas voce quer cadastrar?\n");
			r = scanf("%i", &qtdTurmas);
			if((r == 0) || (qtdTurmas<=0)){
				printf("# ERRO: quantidade de Turmas deve ser maior que 0\n");
				while(fgetc(stdin) != '\n');
				continue;
			}
		}while(qtdTurmas<=0);
	}
	
	if(qtd == 1){
		do{
			printf("# Quantas turmas voce quer cadastrar?\n");
			r = scanf("%i", &qtdTurmas);
			if((r == 0) || (qtdTurmas<=0)){
				printf("# ERRO: quantidade de Turmas deve ser maior que 0\n");
				while(fgetc(stdin) != '\n');
				continue;
			}
		}while(qtdTurmas<=0);	
	}



	printf("\n# Alocado com sucesso espaco para %i turmas! #\n", qtdTurmas);
	/* Início das leituras */
	for (i=0; i<qtdTurmas; i++){
		
		printf("\n# - - - TURMA [%i] - - - #\n\n", i);
		printf("# Codigo da Turma: \n");
		leString(turma[i].nTurma, STR);
		
		printf("# Nome da Disciplina: \n");
		leString(turma[i].nTurma, STR);
		
		printf("# Nome do Professor: \n");
		leString(turma[i].nomeProfessor, STR);
		
		printf("# Quantos alunos tem a turma %s ?", turma[i].nTurma);
		do{
			r = scanf("%i", &livro[i].qtdPaginas);
			if(r == 0){
				printf("ERRO entrada invalida!\n\n");
				printf("# Quantos alunos tem a turma %s ?", turma[i].nTurma);
            	while (fgetc(stdin) != '\n');
            	continue;
			}
		}while (r==0);
		
		printf("# Alocado com sucesso espaco para %i aluno(s) na turma %s! \n", turma[i].qtdAlunos, turma[i].nTurma);
		
		/* Inicio da Leitura dos Alunos da Turma */
		for(j = 0; j<turma[i].qtdAlunos){
			
		}
	
	
	}
	
	system("pause");
	
}


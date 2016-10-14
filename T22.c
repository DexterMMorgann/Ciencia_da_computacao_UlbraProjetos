/*

T22a - Em progresso -> Até 14/10 sexta-feira;

151013010 - MARIO ALVES;
mat - VICTOR OLIVEIRA;
*/

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
	char nomeAluno[STR];
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
	struct TURMA turma[STR];
	struct ALUNO aluno[STR];
	
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
	/* Trecho adicionado para leitura do main; */
	if((qtd == 1)&&(qtdTurmas <= 0)){
		do{
			printf("# Quantas turmas voce quer cadastrar:\n");
			r = scanf("%i", &qtdTurmas);
			if(r == 0){
				printf("ERRO entrada invalida\n");
				while(fgetc(stdin) != '\n');
				continue;
			}
			if(qtdTurmas < 0){
				printf("# ERRO Quantidade de turmas deve ser maior que 0\n\n");
				while(fgetc(stdin) != '\n');
				continue;
        		}
        	}while(r == 0 || qtdTurmas < 0);
	}//Ate aqui;
	
	/* Trecho inserido e alterado no código; */
	if((qtd > 1) && (qtdTurmas <= 0)){
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
	
	/*if(qtd == 1){
		do{
			printf("# Quantas turmas voce quer cadastrar?\n");
			r = scanf("%i", &qtdTurmas);
			if((r == 0) || (qtdTurmas<=0)){
				printf("# ERRO: quantidade de Turmas deve ser maior que 0\n");
				while(fgetc(stdin) != '\n');
				continue;
			}
		}while(qtdTurmas<=0);	
	}*/

	printf("\n# Alocado com sucesso espaco para %i turmas! #\n", qtdTurmas);
	printf("# Digite dados para %d turma(s)\n\n", qtdTurmas);
	/* Início das leituras */
	for (i=0; i<qtdTurmas; i++){
		
		printf("\n# - - - TURMA [%i] - - - #\n\n", i);
		printf("# Codigo da Turma: \n");
		leString(turma[i].nTurma, STR);
		
		printf("# Nome da Disciplina: \n");
		leString(turma[i].nomeDisciplina, STR);
		
		printf("# Nome do Professor: \n");
		leString(turma[i].nomeProfessor, STR);
		
		printf("# Quantos alunos tem a turma %s ?\n", turma[i].nTurma);
		do{ //Trecho inserido para exibir msg que pede;
			r = scanf("%i", &turma[i].qtdAlunos);
			if(r == 0){
				printf("ERRO entrada invalida!\n\n");
				printf("# Quantos alunos tem a turma %s ?\n", turma[i].nTurma);
				printf("# Quantos alunos tem a turma %s?\n", turma[i].nTurma);
            			while (fgetc(stdin) != '\n');
            			continue;
			}if(turma[i].qtdAlunos < 0){
				printf("ERRO %d\n", turma[i].qntdAlunos);
				printf("# Quantidade de alunos deve ser menor ou igual a 0\n\n");
				printf("# Quantos alunos tem a turma %s?\n", turma[i].nTurma);
				while (fgetc(stdin) != '\n');
            			continue;
			}
		}while (r==0 || turma[i].qtdAlunos < 0);
		
		printf("# Alocado com sucesso espaco para %i aluno(s) na turma %s! \n", turma[i].qtdAlunos, turma[i].nTurma);
		
		
		/* Inicio da Leitura dos Alunos da Turma */
		for(j = 0; j<turma[i].qtdAlunos; j++){
			
			printf("# --- ALUNO [%i] DA TURMA [%s] --- #\n", j, turma[i].nTurma);
			printf("# Qual o NUMERO DE MATRICULA do aluno?\n");
			leString(aluno[j].nMatricula, STR);
			
			printf("# Qual o NOME do aluno?\n");
			leString(aluno[j].nomeAluno, STR);
			
			printf("# Quais as NOTAS do(a) %s?\n", aluno[j].nomeAluno);
			printf("\n# NOTA G1: \n");
			do{
				r = scanf("%lf", &aluno[j].G1);
				if(r == 0){ /* Inserido if a mais nas notas dos alunos;*/
					printf("ERRO entrada invalida!\n\n");
					printf("# NOTA G1:\n");
					while (fgetc(stdin) != '\n');
	            			continue;
				}if(aluno[j].G1 < 0){
					printf("ERRO %.0lf\n", aluno[j].G1);
					printf("# ERRO: Nota deve ser maior ou igual a zero\n\n");
					printf("# NOTA G1:\n");
					while (fgetc(stdin) != '\n');
           		 		continue;
				}
			}while (r==0 || (aluno[j].G1 < 0));
					
			printf("# NOTA G2: \n");
			do{
				r = scanf("%lf", &aluno[j].G2);
				if(r == 0){/* Inserido if a mais nas notas dos alunos;*/
					printf("ERRO entrada invalida!\n\n");
					printf("# NOTA G2:\n");
					while (fgetc(stdin) != '\n');
	            			continue;
				}if(aluno[j].G2 < 0){
					printf("ERRO %.0lf\n", aluno[j].G2);
					printf("# ERRO: Nota deve ser maior ou igual a zero\n\n");
					printf("# NOTA G2:\n");
					while (fgetc(stdin) != '\n');
           		 		continue;
				}
			}while (r==0 || (aluno[j].G2 < 0));
			
			printf("# NOTA G3: \n");
			do{
				r = scanf("%lf", &aluno[j].G3);
				if(r == 0){/* Inserido if a mais nas notas dos alunos;*/
					printf("ERRO entrada invalida!\n\n");
					printf("# NOTA G3:\n");
					while (fgetc(stdin) != '\n');
	            			continue;
				}if(aluno[j].G3 < 0){
					printf("ERRO %.0lf\n", aluno[j].G3);
					printf("# ERRO: Nota deve ser maior ou igual a zero\n\n");
					printf("# NOTA G3:\n");
					while (fgetc(stdin) != '\n');
           		 		continue;
				}
			}while (r==0 || (aluno[j].G3 < 0));
			
			printf("# --- ALUNO [%i] --- FIM DO CADASTRO --- #\n", j);
			
		}
		printf("# --- TURMA [%i] --- FIM DO CADASTRO --- #\n", i);
	
	
	}
	
	system("pause");
	
}


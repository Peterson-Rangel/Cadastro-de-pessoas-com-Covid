#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main(){

    //RESPONSAVEL POR ACRECENTEAR ACENTUAÇÕES NO PROGRAMA
    setlocale(LC_ALL, "Portuguese");

    //RESPONSAVEL POR MUDAR A COR DO SISTEMA
    system("color 0");


	char login[] = "admin";
	char login1[10];
	int senha = 1234;

    // ÁREA DE LOGIN E SENHA
    printf("                    .---------------------------------------.\n");
    printf("                    |              BEM VINDO                |\n");
    printf("                    `---------------------------------------´\n");
	printf("\n LOGIN: ");
        scanf("%s", &login1);
            fflush(stdin);

	printf("\n SENHA: ");
        scanf("%d", &senha);
			fflush(stdin);


	//ESRUTURA CONDICIONAL IF E ELSE PARA LOGIN
	if ((strcmp(login,login1)==0) && (senha == 1234)){

  }
	else{
		printf("                 LOGIN OU SENHA INCORRETOS! \n");
            return 0;
      }

        //RESPONSAVEL POR LIMPAR A TELA E CONTINUA ARMAZENANDO DADOS
		system("cls");

	char nomePaciente[30];
    char CPF[15];
    char telefone[16];
	char e_mail[60];
    char rua[60];
    int numerocasa;
    char cidade [50];
    char estado [50];
	char dataDiagnostico [12];

	int idade,ano_atual= 2022,data_nasc,dianasc,mesnasc,anonasc,grupo_risco, fidade, CEP;

		//ABERTURA DO ARQUIVO TXT PARA CADASTRO DE CLIENTE
		FILE *cadastro_p;

		cadastro_p = fopen("pacientes.txt", "a");
            if(cadastro_p == NULL){
                printf("Deu errado");
        return 0;
		}

	//CADASTRO DE DADOS DO PACIENTE
            printf("\n\n\n       ------CADASTRE O(A) PACIENTE ------");

            printf("\n\n______________________________________________________ \n\n");

            printf("           DADOS PESSOAIS DO(A) PACIENTE");


            printf("\n\n NOME COMPLETO:  ");
                fgets(nomePaciente, 30, stdin);
                    fflush(stdin);
                        fprintf(cadastro_p, "\n NOME DO PACIENTE: %s", nomePaciente);

            printf("\n CPF: ");
                fgets(CPF, 12, stdin);
                    fflush(stdin);
                        fprintf(cadastro_p, "\n CPF: %s\n", CPF);

            printf("\n______________________________________________________ \n\n");

            printf("                CONTATOS DO(A) PACIENTE");


            printf("\n\n TELEFONE: ");
                fgets(telefone, 16, stdin);
                    fflush(stdin);
                        fprintf(cadastro_p, "\n TELEFONE: %s", telefone);

            printf("\n E-MAIL: ");
                fgets(e_mail, 60, stdin);
                    fflush(stdin);
                        fprintf(cadastro_p, "\n E-MAIL: %s", e_mail);

                system("cls");



            printf("\n\n\n          ENDEREÇO DO(A) PACIENTE");

            printf("\n\n______________________________________________________");

            printf("\n\n CEP (SOMENTE NÚMEROS): ");
                scanf("%d", &CEP);
                    fflush(stdin);
                        fprintf(cadastro_p, "\n CEP: %d\n", CEP);

            printf("\n RUA: ");
                fgets(rua, 60, stdin);
                    fflush(stdin);
                        fprintf(cadastro_p, "\n RUA: %s", rua);

            printf("\n Nº RESIDÊNCIA: ");
                scanf("%d", &numerocasa);
                    fflush(stdin);
                        fprintf(cadastro_p, "\n Nº RESIDÊNCIA: %d\n", numerocasa);

            printf("\n CIDADE: ");
                fgets(cidade, 60, stdin);
                    fflush(stdin);
                        fprintf(cadastro_p, "\n CIDADE: %s", cidade);

            printf("\n ESTADO: ");
                fgets(estado, 50, stdin);
                    fflush(stdin);
                        fprintf(cadastro_p, "\n ESTADO: %s", estado);

                system("cls");




            printf("\n\n\n                  DIAGNÓSTICO");

            printf("\n\n______________________________________________________\n");

            printf("\n INFORME A DATA QUE FOI DIAGNOSTICADO(DD/MM/AAAA): ");
                fgets(dataDiagnostico, 12, stdin);
                    fflush(stdin);
                        fprintf(cadastro_p, "\n DATA DO DIAGNÓSTICO: %s", dataDiagnostico);

            printf("\n DATA DE NASCIMENTO: \n");
                printf(" INFORME O DIA(DD): ");
                    scanf("%d", &dianasc);
                         fflush(stdin);
                            //fprintf(cadastro_p, "\n DATA NASCIMENTO: %d", dianasc);

            printf(" INFORME O MÊS: ");
                 scanf(" %d", &mesnasc);
                    fflush(stdin);
                        //fprintf(cadastro_p, "\n MÊS DO NASCIMENTO: %d", nasc);

            printf(" INFORME O ANO: ");
               scanf(" %d", &anonasc);
                    fflush(stdin);
                        fprintf(cadastro_p, "\n DATA DE NASCIMENTO: %d/%d/%d\n", dianasc, mesnasc, anonasc);





                idade = 2022 - anonasc;
                    if(idade >= 65){
                        grupo_risco = idade;

                fidade = ano_atual - anonasc;

                fprintf(cadastro_p, "\n IDADE: %d\n", fidade);

			}


                    system("cls");


		// SWITCH CASE PARA SABER SE O PACIENTE POSSUI ALGUMA COMORBIDADE
		int comorbii;
		char outraComorbii[30];

			//ABERTURA DE ARQUIVO TXT PARA COMORBIDADE
			FILE *comorb_p;
			comorb_p = fopen("cadastro_p.txt", "a");
			if(comorb_p == NULL){
				printf(" ERRO NO ARQUIVO CORMORBIDADE PACIENTE");
			}

	  		printf("\n\n PACIENTE POSSUI ALGUMA COMORBIDADE? SE SIM, DIGITE UMA DAS OPÇÕES ABAIXO: \n\n");

                printf(".-------------------------------------------------------.\n");
                printf("|             [1] OBESIDADE                             |\n");
                printf("|             [2] DIABETES                              |\n");
                printf("|             [3] TUBERCULOSE                           |\n");
                printf("|             [4] HIPERTENSÃO                           |\n");
                printf("|             [5] OUTRAS COMORBIDADES                   |\n");
                printf("|             [6] NÃO POSSUI                            |\n");
                printf("`-------------------------------------------------------´\n");

            scanf("%d", &comorbii);
                fflush(stdin);

		system("cls");

    switch(comorbii){

    case 1:
        printf("\n\n O PACIENTE É OBESO");
            fprintf(comorb_p, "\n PACIENTE COM OBESIDADE ");
                fprintf(cadastro_p, "\n COMORBIDADE: OBESIDADE");
                fprintf(cadastro_p, "\n___________________________________________________________\n");

            if(grupo_risco >= 65){

            printf(" PERTENCE AO GRUPO DE RISCO\n");
                fprintf(comorb_p, "\n PERTENCENTE AO GRUPO DE RISCO \n CEP: %d", CEP);
                fprintf(comorb_p, "\n IDADE: %d", idade);
                fprintf(comorb_p, "\n___________________________________________________________\n\n");
                }

                else{
					printf("\n NÃO PERTENCENTE AO GRUPO DE RISCO \n");
                    fprintf(comorb_p, "\n PACIENTE NÃO PERTENTENCE AO GRUPO DE RISCO");

				}
        break;

    case 2:
        printf("\n\n O PACIENTE POSSUI DIABETES");
            fprintf(comorb_p, "\n PACIENTE COM DIABETES");
                fprintf(cadastro_p, "\n COMORBIDADE: DIABETES");
                fprintf(cadastro_p, "\n___________________________________________________________\n");

            if(grupo_risco >= 65){

            printf(" PERTENCE AO GRUPO DE RISCO\n");
                    fprintf(comorb_p, "\n PERTENCENTE AO GRUPO DE RISCO \n CEP: %d", CEP);
                    fprintf(comorb_p, "\n IDADE: %d", idade);
                    fprintf(comorb_p, "\n___________________________________________________________\n\n");
                }

				else{
					printf("\n PACIENTE NÃO PERTENTENCE AO GRUPO DE RISCO \n");
                        fprintf(comorb_p, "\n PACIENTE NÃO PERTENTENCE AO GRUPO DE RISCO");
                }
        break;

    case 3:
        printf("\n\n O PACIENTE POSSUI TUBERTUCULOSE ");
            fprintf(comorb_p, "\n PACIENTE COM TUBERCULOSE");

                fprintf(cadastro_p, "\n COMORBIDADE: TUBERCULOSE");
                fprintf(cadastro_p, "\n___________________________________________________________\n");

                if(grupo_risco >= 65){

                    printf(" PERTENCE AO GRUPO DE RISCO \n");
						fprintf(comorb_p, "\n PERTENCENTE AO GRUPO DE RISCO \n CEP: %d", CEP);
                        fprintf(comorb_p, "\n IDADE: %d", idade);
                        fprintf(comorb_p, "\n___________________________________________________________\n\n");
                }

                else{
                    printf("\n PACIENTE NÃO PERTENTENCE AO GRUPO DE RISCO \n");
                        fprintf(comorb_p, "\n PACIENTE NÃO PERTENTENCE AO GRUPO DE RISCO");
                }
        break;

    case 4:
        printf("\n\n O PACIENTE É HIPERTENSO");
            fprintf(comorb_p, "\n PACIENTE COM HIPERTENSÃO");

                fprintf(cadastro_p, "\n COMORBIDADE: HIPERTENSÃO");
                fprintf(cadastro_p, "\n___________________________________________________________\n");

                if(grupo_risco >= 65){

                    printf(" PERTENCE AO GRUPO DE RISCO \n");
                        fprintf(comorb_p, "\n PERTENCENTE AO GRUPO DE RISCO \n CEP: %d ", CEP);
                        fprintf(comorb_p, "\n IDADE: %d", idade);
                        fprintf(comorb_p, "\n___________________________________________________________\n\n");
                }

                else{
                    printf("\n PACIENTE NÃO PERTENTENCE AO GRUPO DE RISCO \n");
                        fprintf(comorb_p, "\n PACIENTE NÃO PERTENTENCE AO GRUPO DE RISCO");
                }
        break;

    case 5:
        printf("\n\n OUTRAS COMORBIDADES");
        printf(" ESCREVA A COMORBIDADE:");
            fgets(outraComorbii, 30, stdin);
                fflush(stdin);
        printf(" %s", outraComorbii);
                fprintf(comorb_p, "\n PACIENTE POSSUI OUTRA COMORBIDADE: %s", outraComorbii);

                fprintf(cadastro_p, "\n COMORBIDADE: %s", outraComorbii);
                fprintf(cadastro_p, "\n___________________________________________________________\n");

                if(grupo_risco >= 65){

                    printf(" PERTENCE AO GRUPO DE RISCO \n");
                        fprintf(comorb_p, "\n PERTENCENTE AO GRUPO DE RISCO \n CEP: %d", CEP);
                        fprintf(comorb_p, "\n IDADE: %d", idade);
                        fprintf(comorb_p, "\n___________________________________________________________\n");
                }

                else{
                    printf("\n PACIENTE NÃO PERTENTENCE AO GRUPO DE RISCO \n");
                        fprintf(comorb_p, "\n PACIENTE NÃO PERTENTENCE AO GRUPO DE RISCO");
                }
        break;

    case 6:
        printf(" CADASTRO EFETUADO COM SUCESSO! ");
            fprintf(comorb_p, "\n\n CADASTRO EFETUADO COM SUCESSO!");
            fprintf(comorb_p, "\n___________________________________________________________\n\n");

        break;

                    default:

            if(comorbii > 6){
                    printf("\n\n OPÇÃO INVÁLIDA! ");
                    fprintf(comorb_p, "\n\n OPÇÃO INVÁLIDA! ");
												}

									fclose(comorb_p);
									fclose(cadastro_p);
								return 0;

            }
	}

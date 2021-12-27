#include<stdio.h>
#include<string.h>

typedef struct {
    int hora, duracao;
    char compromisso[50];
} dia;

//Funções e procedimentos
void atualizaZero(dia d[7]) {
    int i;
    for(i=0;i<7;i++) {
        d[i].duracao = 0;
        d[i].hora = 0;
        strcpy(d[i].compromisso, " ");
    }
}
int menuPrincipal() {
    int op;
    do {
        printf("# AGENDA DA SEMANA\n1. Agendar um compromisso\n2. Mostrar um compromisso\n3. Consultar o compromisso com maior duracao\n4. Mostrar o total de horas em compromissos na semana\n5. Listar compromissos\n6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        if ((op < 1) || (op > 6))
            printf("\nOpcao Invalida! Digite novamente\n\n");
    } while ((op < 1) || (op > 6));
    return op;
}
void agendarCompromisso(dia d[7], int *cont1) {
    int i, diaSelecionado;
    printf("\nMenu Principal > Opcao 1\n");
    do {
        printf("Informe o dia em que voce deseja agendar compromisso (0 a 6): ");
        scanf("%d", &diaSelecionado);
        if ((diaSelecionado < 0) || (diaSelecionado > 6))
            printf("\nOpcao Invalida! Digite um dia de 0 a 6!\n\n");
    } while ((diaSelecionado < 0) || (diaSelecionado > 6));

    if (d[diaSelecionado].duracao == 0) {
        printf("Dia Disponivel!\n");
        printf("Informe o horario: ");
        scanf("%d", &d[diaSelecionado].hora);
        printf("Informe a duracao: ");
        scanf("%d", &d[diaSelecionado].duracao);
        printf("Informe o compromisso: ");
        scanf("%s", d[diaSelecionado].compromisso);
        printf("\n\n");
    } else
        printf("\n[ERRO] Ja tem compromisso marcado no dia %d\n\n", diaSelecionado);
    *cont1 = 1;
}
void apresentarCompromisso(dia d[7]) {
    int i, diaSelecionado;
    printf("\nMenu Principal > Opcao 2\n");    
    do {
        printf("Digite o dia em que voce deseja consultar (0 a 6): ");
        scanf("%d", &diaSelecionado);
        if ((diaSelecionado < 0) || (diaSelecionado > 6))
            printf("\nOpcao Invalida! Digite um dia de 0 a 6!\n\n");
    } while ((diaSelecionado < 0) || (diaSelecionado > 6));

    if (d[diaSelecionado].duracao == 0) {
        printf("Nao ha compromissos marcados para esse dia.\n\n");
    } else
        printf("Compromisso do dia %d as %dh com duracao de %dh: %s\n\n", diaSelecionado, d[diaSelecionado].hora, d[diaSelecionado].duracao, d[diaSelecionado].compromisso);
}
void consultarMaiorDuracao(dia d[7]) {
    int i, maior=0;
    printf("\nMenu Principal > Opcao 3\n");
    for(i=0; i<7; i++) {
        if (d[i].duracao > maior)
            maior = i;
    }
    printf("Compromisso com maior duracao: dia %d as %dh com duracao de %dh: %s\n\n", maior, d[maior].hora, d[maior].duracao, d[maior].compromisso);
}
void somarTempoDuracao (dia d[7]) {
    int i, soma=0;
    printf("\nMenu Principal > Opcao 4\n");
    for(i=0; i<7; i++)
        soma += d[i].duracao;
    printf("Soma da duracao dos compromissos: %dh\n\n", soma);
}
void apresentarTodosCompromissos(dia d[7]) {
    int i;
    printf("\nMenu Principal > Opcao 5\n");
    for(i=0; i<7; i++) {
        printf("Dia: %d - Hora: %dh - Duracao: %dh - Compromisso: %s\n", i, d[i].hora, d[i].duracao, d[i].compromisso
        );
    }
    printf("\n");
}

//Função principal
int main(void) {
    dia d[7];
    int opcaoMenu, cont1=0;

    atualizaZero(d);

    do {
        opcaoMenu = menuPrincipal();

        switch(opcaoMenu) {
            case 1: agendarCompromisso(d, &cont1); break;
            case 2: apresentarCompromisso(d); break;
            case 3: 
                if (cont1 == 0)
                    printf("\n[ERRO] Nenhum compromisso ainda foi agendado\n\n");
                else 
                    consultarMaiorDuracao(d);
                break;
            case 4: 
                if (cont1 == 0)
                    printf("\n[ERRO] 0h > Nenhum compromisso ainda foi agendado\n\n");
                else
                    somarTempoDuracao(d);
                break;
            case 5: apresentarTodosCompromissos(d);
        }

    } while(opcaoMenu != 6);
    printf("\nFim do programa\n\n");

    return 0;
}
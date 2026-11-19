#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 50

typedef struct data{
        int dia;
        int mes;
        int ano;
    } Data;

typedef struct endereco{
    char rua[50];
    char cidade[50];
    char estado[5];
    int numero;
} Endereco;

typedef struct paciente{
    char CPF[20];
    char nome[50];
    Endereco endereco;
    Data dataNascimento;
} Paciente;

typedef struct vacina {
    int codigoVacina;
    char nome[50];
    int quantidadeDisponivel;
    int quantidadeDoses;    
} Vacina;

typedef struct aplicacao {
    int idAplicacao;
    char cpf[20];
    int codigoVacina;
    int numeroDose;
    Data dataAplicacao;
} Aplicacao;


Paciente cadastrarPaciente(Paciente paciente[]);
Paciente buscarPaciente(Paciente paciente[], char cpf[], Data dataNascimento);
int validarData(Data data);
int validarCPF(char cpfString[]);
int existPacienteComCpf(Paciente paciente[], char cpf[]);
int cpfSemRepeticao(int cpf[]);
Endereco pegarEndereco();
void imprimirMenu();

int main()
{
    Paciente pacientes[MAX_PACIENTES];
    int qtdPacienteAtual = 0, op = 0;

    while (1) {

        imprimirMenu();
        scanf("%d", &op);
        while (getchar() != '\n'); //limpar o buffer

        if(op == 0) {
            printf("Saindo do sistema\n");
            break;
        }

        switch (op) {
        case 1:
            if(qtdPacienteAtual < MAX_PACIENTES) {
                pacientes[qtdPacienteAtual] = cadastrarPaciente(pacientes);
                qtdPacienteAtual++;
                printf("Paciente cadastrado com sucesso!\n");
                continue;
            }
            printf("Erro quantidade maxima de pacientes atingida\n");
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}

Paciente cadastrarPaciente(Paciente paciente[]) {
    Paciente p;
    char cpf[20];
    char dataString[20];
    Data d;
    
    do {
        printf("Preencha o cpf: ");
        fgets(cpf, 20, stdin);

        if(!validarCPF(cpf)){
            printf("\nCpf Invalido, Digite um valido\n");
            continue;
        }

        if(existPacienteComCpf(paciente, cpf)) {
            printf("passou\n");
            printf("Ja existe um paciente cadastrado com esse cpf\n");
            continue;
        }

        strcpy(p.CPF, cpf);

        break;

    } while (1);
    

    printf("Preencha o nome: ");
    fgets(p.nome, 20, stdin);

    do { 
        printf("Preencha sua Data de Nascimento: ");
        fgets(dataString, 20, stdin);
        // sscanf: extrai dados formatados de uma string (dataString) em vez do teclado
        sscanf(dataString, "%d/%d/%d", & d.dia, &d.mes, &d.ano);

        if(!validarData(d)) {
           p.dataNascimento = d; 
           printf("Data de nascimento Invalida, Digite uma valida\n");
           continue;
        }

        p.dataNascimento = d;
        break;
    } while(1);

    p.endereco = pegarEndereco();

    return p;
}

Endereco pegarEndereco() {
    Endereco e;
    printf("Preencha seu Estado: ");
    fgets(e.estado, 5, stdin);

    printf("Preencha sua Cidade: ");
    fgets(e.cidade, 50, stdin);

    printf("Preencha sua Rua: ");
    fgets(e.rua, 50, stdin);

    printf("Preencha seu Numero: ");
    scanf("%d", &e.numero);
    while (getchar() != '\n');

    return e;
}

int validarData(Data data){
    if(data.ano < 1) {
        return 0;
    }
    if(data.mes < 1 || data.mes > 12) {
        return 0;
    }
    
    int diasNoMes;
    switch(data.mes) {
        case(2):
            if((data.ano % 4 == 0 && data.ano % 100 != 0) ||(data.ano % 400 ==0)) {
                diasNoMes = 29;
            } else {
                diasNoMes = 28;
            }
        break;
        case(4):
        case(6):
        case(9):
        case(11):
            diasNoMes = 30;
            break;
        default:
            diasNoMes = 31;
            break;
        
    }
    if(data.dia < 1 || data.dia > diasNoMes) {
        return 0;
        }
    return 1;
} 

int validarCPF(char cpfString[]) {
    int cpf[11];
    int j = 0;
    
    int soma = 0, resto, dv1, dv2;

    for(int i = 0; cpfString[i] != '\0'; i++) {
        if(cpfString[i] >= '0' && cpfString[i] <='9') {
            if(j < 11) {
                cpf[j] = cpfString[i] - '0';
            }
            j++;    
        }
    }

    if(j != 11){
        return 0;
    }

    if(!cpfSemRepeticao(cpf)) {
        return 0;
    }

    for(int i = 0; i < 9; i++) {
        soma += cpf[i] * (10-i);
    }

    resto = soma % 11;
    dv1 = (resto < 2) ? 0 : (11 - resto);

    soma = 0;
    for(int i = 0; i < 9; i++) {
        soma += cpf[i] * (11-i);
    }
    soma += dv1 * 2;
    resto = soma % 11;
    dv2 = (resto < 2) ? 0 : (11 - resto);

    if(cpf[9] == dv1 && cpf[10] == dv2){
        return 1;
    }
    return 0;
}

int existPacienteComCpf(Paciente paciente[], char cpf[]) {
    for(int i = 0; i < MAX_PACIENTES; i++) {
        if(strcmp(paciente[i].CPF, cpf) == 0) {
            return 1;
        }
    }
    return 0;
}

int cpfSemRepeticao(int cpf[]) {
    for(int i =0; i < 11; i++) {
        if(cpf[0] != cpf[i]) {
            return 1;
        }
    }
    return 0;
}

void imprimirMenu() {
    printf("==================================================\n");
    printf("          SISTEMA DE CONTROLE DE VACINAS          \n");
    printf("==================================================\n");
    printf("  [ PACIENTES ]\n");
    printf("  1 - Cadastrar paciente\n");
    printf("  2 - Buscar paciente por CPF\n");
    printf("  3 - Buscar paciente por Data de Nascimento\n");
    printf("--------------------------------------------------\n");
    printf("  [ VACINAS ]\n");
    printf("  4 - Cadastrar vacina\n");
    printf("  5 - Buscar vacina por Codigo\n");
    printf("  6 - Buscar vacina por Nome\n");
    printf("--------------------------------------------------\n");
    printf("  0 - Sair\n");
    printf("==================================================\n");
    printf("Escolha uma opcao: ");
}
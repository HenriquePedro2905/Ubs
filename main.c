#include <stdio.h>



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

int main()
{
    
    
    return 0;
}

Paciente cadastrarPaciente(Paciente paciente[]) {

}

int validarData(Data data){
    if(data.ano < 1) {
        return 0;
    }
    if(data.mes < 1 || data.mes > 12) {
        return 0;
    }
    
    int DiasNoMes;
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
                cpf[j] = cpfString[j] - '0';
            }
            j++;    
        }
    }

    if(j != 11){
        printf("Cpf Invalido")
        return 1;
    }

    if(!cpfSemRepeticao(cpf)) {
        printf("cpf invalido");
        return 1;
    }

    for(int i = 0; i < 9; i++) {
        soma += cpf[i] + (10-i);
    }

    resto = soma % 11;
    dv1 = (resto < 2) ? 0 : (11 - resto);

    soma = 0
    for(int i = 0; i < 9; i++) {
        soma += cpf[i] + (11-i);
    }
    soma =+ dv1 * 2;

    if(cpf[9] == dv1 && cpf[10] == dv2){
        return 0;
    }
    return 1;
}

int cpfSemRepeticao(int cpf[]) {
    for(int i =0; i < 11 i++) {
        if(cpf[i] != cpf[i]) {
            return 0;
        }
    }
    return 1;
}
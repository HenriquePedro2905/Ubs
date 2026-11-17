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
int validarCPF(char cpf[]);

int main()
{
    
    
    return 0;
}

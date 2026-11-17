#include <stdio.h>



typedef struct data{
        int dia;
        int mes;
        int ano;
    } Data;

    typedef struct endereco{
        char rua[50];
        charcidade[50];
        char estado[5];
        int numero;
    } Endereco;

    typedef struct paciente{
        char[20] CPF;
        char[50] nome;
        Endereco endereco;
        Data dataNascimento;
    } Paciente;

Paciente cadastrarPaciente(Paciente paciente[]);
Paciente buscarPaciente(Paciente paciente[], char cpf[], Data dataNascimento);
int validarData(Data data);
int validarCPF(char cpf[]);

int main()
{
    
    
    return 0;
}

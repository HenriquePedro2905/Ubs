#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 50
#define MAX_VACINAS 20

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
Vacina cadastrarVacina(Vacina vacinas[], int qtd);
int existeVacinaComCodigo(Vacina vacinas[], int qtd, int codigo);
int existPacienteComCpf(Paciente paciente[], char cpf[]);
int cpfSemRepeticao(int cpf[]);
int buscarPacientePorCPF(Paciente paciente[], char cpf[]);
int buscarPacientePorData(Paciente paciente[], Data dataNascimento);
Endereco pegarEndereco();
void pegarCpf(char cpf[]);
void imprimirMenu();
void imprimirData(Data data);
void imprimirEndereco(Endereco endereco);
Data pegarData();
void imprimirPaciente(Paciente paciente);
void imprimirSemQuebraLinha(char texto[]);
void esperarEnter(void);
void tirarPontuacaoCpf(char origem[], char destino[]);


int main()
{
    // zera o vetor: posicoes nao usadas ficam com CPF vazio e data 0/0/0
    Paciente pacientes[MAX_PACIENTES] = {0};
    Vacina vacinas[MAX_VACINAS] = {0};
    int qtdPacienteAtual = 0, qtdVacinaAtual = 0, op = 0;

    while (1) {

        imprimirMenu();
        scanf("%d", &op);

        printf("\n");

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
        
        case 2:
            char cpf[20];
            
            pegarCpf(cpf);
            
            int posicaoPaciente = buscarPacientePorCPF(pacientes, cpf);

            if (posicaoPaciente < 0) {
                printf("Nao existe paciente com esse cpf\n");
                break;
            }
            
            imprimirPaciente(pacientes[posicaoPaciente]);
            break;

        case 3:
            Data data = pegarData();
            
            int posicaoPac = buscarPacientePorData(pacientes, data);

            if (posicaoPac < 0) {
                printf("Nao existe paciente com essa data de nascimento\n");
                break;
            }

            imprimirPaciente(pacientes[posicaoPac]);
            break;

        case 4:
            if(qtdVacinaAtual < MAX_VACINAS) {
                vacinas[qtdVacinaAtual] = cadastrarVacina(vacinas, qtdVacinaAtual);
                qtdVacinaAtual++;
                break;
            }
            printf("Erro quantidade maxima de vacinas atingida\n");
            break;
        default:
            break;
        }
    }
    
    return 0;
}

Paciente cadastrarPaciente(Paciente paciente[]) {
    Paciente p;

    // repete a leitura ate o CPF ser valido e ainda nao cadastrado
    while(1) {
        pegarCpf(p.CPF);

        if(!existPacienteComCpf(paciente, p.CPF)) {
            break;
        }
        printf("Ja existe um paciente cadastrado com esse cpf\n");
    }

    printf("Preencha o nome: ");
    fgets(p.nome, 20, stdin);

    p.dataNascimento = pegarData();
    p.endereco = pegarEndereco();

    return p;
}

Endereco pegarEndereco() {
    Endereco e;
    char uf[20];
    int ufValida;

    // estado: exatamente 2 letras seguidas do \n do fgets
    do {
        printf("Preencha seu Estado (sigla com 2 letras): ");
        fgets(uf, 20, stdin);

        ufValida = uf[2] == '\n' &&
                   ((uf[0] >= 'A' && uf[0] <= 'Z') || (uf[0] >= 'a' && uf[0] <= 'z')) &&
                   ((uf[1] >= 'A' && uf[1] <= 'Z') || (uf[1] >= 'a' && uf[1] <= 'z'));

        if(!ufValida) {
            printf("Estado invalido, digite a sigla da UF (ex: PR, SP)\n");
        }
    } while(!ufValida);

    uf[2] = '\0';
    strcpy(e.estado, uf);

    printf("Preencha sua Cidade: ");
    fgets(e.cidade, 50, stdin);

    printf("Preencha sua Rua: ");
    fgets(e.rua, 50, stdin);

    // numero: inteiro maior que zero
    while(1) {
        printf("Preencha seu Numero: ");
        int lido = scanf("%d", &e.numero);
        while (getchar() != '\n');

        if(lido == 1 && e.numero > 0) {
            break;
        }
        printf("Numero invalido, digite um numero maior que zero\n");
    }

    return e;
}

Data pegarData() {
    char dataString[20];
    Data d;

    do { 
        printf("Preencha sua Data de Nascimento: ");
        fgets(dataString, 20, stdin);
        // sscanf: extrai dados formatados de uma string (dataString) em vez do teclado
        sscanf(dataString, "%d/%d/%d", & d.dia, &d.mes, &d.ano);

        if(!validarData(d)) {
        printf("Data de nascimento Invalida, Digite uma valida\n");
        continue;
        }

        return d;
        } while(1);
}

void pegarCpf(char cpf[]) {
    do {
        printf("Preencha o cpf: ");
        fgets(cpf, 20, stdin);
        printf("\n");

        if(!validarCPF(cpf)){
            printf("\nCpf Invalido, Digite um valido\n");
            continue;
        }

        return;
    } while (1);
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
    char cpfCadastroLimpo[20];
    char cpfBuscaLimpo[20];

    tirarPontuacaoCpf(cpf, cpfBuscaLimpo);

    for(int i = 0; i < MAX_PACIENTES; i++) {
        tirarPontuacaoCpf(paciente[i].CPF, cpfCadastroLimpo);
        if(strcmp(cpfCadastroLimpo, cpfBuscaLimpo) == 0) {
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

int existeVacinaComCodigo(Vacina vacinas[], int qtd, int codigo) {
    for(int i = 0; i < qtd; i++) {
        if(vacinas[i].codigoVacina == codigo) {
            return 1;
        }
    }
    return 0;
}

Vacina cadastrarVacina(Vacina vacinas[], int qtd){
    Vacina vacina;

    printf("\n=== Cadastro De Vacina ===\n");
    printf("Codigo da vacina: ");
    scanf("%d", &vacina.codigoVacina);

    while(vacina.codigoVacina <= 0 || existeVacinaComCodigo(vacinas, qtd, vacina.codigoVacina)) {
        printf("Codigo invalido ou ja cadastrado. Digite novamente..: ");
        scanf("%d", &vacina.codigoVacina);
    }
    printf("Nome da vacina: ");
    scanf(" %49[^\n]", vacina.nome);

    printf("Quantidade disponivel: ");
    scanf("%d", &vacina.quantidadeDisponivel);

    while(vacina.quantidadeDisponivel < 0) {
        printf("Quantidade invalida: ");
        scanf("%d", &vacina.quantidadeDisponivel);
    }

    printf("Quantidade de doses: ");
    scanf("%d", &vacina.quantidadeDoses);
        while(vacina.quantidadeDoses <= 0) {
            printf("Quantidade invalida: ");
            scanf("%d", &vacina.quantidadeDoses);
        }
    printf("\nVacina cadastrada com sucesso!\n");
    return vacina;
}

int buscarPacientePorCPF(Paciente paciente[], char cpf[]) {

    char cpfBuscaLimpo[20];
    char cpfCadastroLimpo[20];

    tirarPontuacaoCpf(cpf, cpfBuscaLimpo);

    for(int i=0; i < MAX_PACIENTES; i++) {
        tirarPontuacaoCpf(paciente[i].CPF, cpfCadastroLimpo);
        if(strcmp(cpfCadastroLimpo, cpfBuscaLimpo) == 0) {
            return i;
        }
    }
    return -1;
}

int buscarPacientePorData(Paciente paciente[], Data dataNascimento) {
    for(int i=0; i < MAX_PACIENTES; i++) {
        if(paciente[i].dataNascimento.dia == dataNascimento.dia &&
           paciente[i].dataNascimento.mes == dataNascimento.mes &&
           paciente[i].dataNascimento.ano == dataNascimento.ano) {
            return i;
           }
    }
    return -1;
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

void imprimirPaciente(Paciente p) {

    printf("==================================================\n");

    printf("Nome: ");
    imprimirSemQuebraLinha(p.nome);
    printf("\n");

    printf("Cpf: ");
    imprimirSemQuebraLinha(p.CPF);
    printf("\n");

    printf("Data de Nascimento: ");
    imprimirData(p.dataNascimento);
    printf("\n");


    printf("Endereco: ");
    imprimirEndereco(p.endereco);
    printf("\n");

    printf("==================================================\n");
    esperarEnter();

}

void imprimirData(Data d) {
    printf("%02d/%02d/%04d", d.dia, d.mes, d.ano);
}

void imprimirEndereco(Endereco e) {
    imprimirSemQuebraLinha(e.rua);
    printf(", %d - ", e.numero);
    imprimirSemQuebraLinha(e.cidade);
    printf("-%s", e.estado);
}

void tirarPontuacaoCpf(char origem[], char destino[]) {
    int i = 0;
    int j = 0;

    while (origem[i] != '\0') {
        if (origem[i] != '.' && origem[i] != '-') {
            destino[j] = origem[i];
            j++;
        }
        i++;
    }
    destino[j] = '\0';
}

//o fgets adiciiona um \n antes do \0 isso quebra a stirng na hora de exibir
// essa funcao e pra imprimir sem esse \n
void imprimirSemQuebraLinha(char texto[]) {;
    for (int i = 0; texto[i] != '\0' && texto[i] != '\n'; i++) {
        printf("%c", texto[i]);
    }
}

void esperarEnter(void) {
    printf("Pressione ENTER para voltar ao menu");
    while (getchar() != '\n') {}
}
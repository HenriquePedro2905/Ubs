/*
Nomes: Pedro Henrique de Souza; Gabriel Venâncio Tonasse
Turma.: EC41A-C11 
*/

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
int buscarPacientePorCPF(Paciente paciente[], char cpf[]);
int buscarPacientePorData(Paciente paciente[], Data dataNascimento);
void listarPaciente(Paciente paciente[], int qtd);
int existPacienteComCpf(Paciente paciente[], char cpf[]);
void imprimirPaciente(Paciente paciente);
void imprimirCabecalhoPaciente();   
Vacina cadastrarVacina(Vacina vacinas[], int qtd);
int buscarVacinaPorCodigo(Vacina v[], int codigo);
int buscarVacinaPorNome(Vacina v[], char nome[]);
void listarVacinas(Vacina vacinas[], int qtd);
int existeVacinaComCodigo(Vacina vacinas[], int qtd, int codigo);
void imprimirVacina(Vacina v);
void imprimirCabecalhoVacina();
void imprimirMenu();
void imprimirData(Data data);
void imprimirEndereco(Endereco endereco, int largura);
void imprimirSemQuebraLinha(char texto[]);
int validarData(Data data);
int validarCPF(char cpfString[]);
int cpfSemRepeticao(int cpf[]);
Endereco pegarEndereco();
void pegarCpf(char cpf[]);
Data pegarData();
void esperarEnter(void);
void tirarPontuacaoCpf(char origem[], char destino[]);
void ordenarOrdemAlfabetica(Paciente pacientes[], int qtd);
void imprimirColuna(char texto[], int largura);
int registrarAplicacao(Aplicacao aplicacoes[], int qtdAplicacoes, Paciente pacientes[], int qtdPacientes, Vacina vacinas[], int qtdVacinas);
void consultarCarteirinha(Paciente pacientes[], int qtdPacientes, Vacina vacinas[], int qtdVacinas, Aplicacao aplicacoes[], int qtdAplicacoes);
Data calcularDataPrevista(Data dataUltimaDose);
void listarPacientesEmAtraso(Paciente pacientes[], int qtdPacientes, Vacina vacinas[], int qtdVacinas, Aplicacao aplicacoes[], int qtdAplicacoes);

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
                esperarEnter();
                break;
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
            
            imprimirCabecalhoPaciente();
            imprimirPaciente(pacientes[posicaoPaciente]);
            esperarEnter();
            break;

        case 3:
            Data data = pegarData();
            
            int posicaoPac = buscarPacientePorData(pacientes, data);

            if (posicaoPac < 0) {
                printf("Nao existe paciente com essa data de nascimento\n");
                break;
            }

            imprimirCabecalhoPaciente();
            imprimirPaciente(pacientes[posicaoPac]);
            esperarEnter();
            break;

        case 4: 
            if(qtdPacienteAtual == 0) {
                printf("Nenhum paciente Cadastrado\n");
                esperarEnter();
                break;
            }

            listarPaciente(pacientes, qtdPacienteAtual);
            esperarEnter();
            break;

        case 5:
            if(qtdVacinaAtual < MAX_VACINAS) {
                vacinas[qtdVacinaAtual] = cadastrarVacina(vacinas, qtdVacinaAtual);
                qtdVacinaAtual++;
                printf("Vacina cadstrada com sucesso\n\n");
                esperarEnter();
                break;
            }
            printf("Erro quantidade maxima de vacinas atingida\n");
            break;

        case 6:

            int cod;

            printf("Digite o codigo da vacina: ");
            scanf("%d", &cod);
            while (getchar() != '\n'); //limpar o buffer

            int posVac = buscarVacinaPorCodigo(vacinas, cod);

            if(posVac < 0) {
                printf("Nao existe vacina com esse codigo\n");
                break;
            }

            imprimirCabecalhoVacina();
            imprimirVacina(vacinas[posVac]);
            esperarEnter();
            break;

        case 7:
            char nome[50];
            printf("Digite o nome: ");
            fgets(nome, 50, stdin);
        
            int posVacina = buscarVacinaPorNome(vacinas, nome);

            if(posVacina < 0) {
                printf("Nao existe vacina com esse nome\n");
                break;
            }

            imprimirCabecalhoVacina();
            imprimirVacina(vacinas[posVacina]);
            esperarEnter();
            break;

        case 8:
            if(qtdVacinaAtual == 0) {
                printf("Nenhuma Vacina cadastrada\n");
                esperarEnter();
                break;
            }

            listarVacinas(vacinas, qtdVacinaAtual);
            esperarEnter();
            break;

        case 9: 
            qtdAplicacaoAtual = registrarAplicacao(aplicacoes, qtdAplicacaoAtual, pacientes, qtdPacienteAtual, vacinas, qtdVacinaAtual);
            esperarEnter();
            break;
        
        case 10: 
            if (qtdPacienteAtual == 0) {
                printf("Nenhum pacente cadastrado no sistema.\n");
                esperarEnter();
                break;
            }
            consultarCarteirinha(pacientes, qtdPacienteAtual, vacinas, qtdVacinaAtual, aplicacoes, qtdAplicacaoAtual);
            esperarEnter();
            break;

        case 11: 
            if (qtdPacienteAtual == 0) {
                printf("Nenhum paciente cadastrado no sistema.\n");
                esperarEnter();
                break;
            }
            listarPacientesEmAtraso(pacientes, qtdPacienteAtual, vacinas, qtdVacinas, aplicacoes, qtdAplicacaoAtual);
            esperarEnter();
            break;

        case 12: 
            break;

        default:
            printf("\nOpcao invalida");
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

void listarPaciente(Paciente pacientes[], int qtd) {

    imprimirCabecalhoPaciente();

    for(int i = 0; i < qtd; i++) {
        imprimirPaciente(pacientes[i]);
    }

    esperarEnter();
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

void imprimirPaciente(Paciente p) {
    printf("| ");
    imprimirColuna(p.nome, 25);
    
    printf(" | ");
    imprimirColuna(p.CPF, 15);
    
    printf(" | ");
    imprimirData(p.dataNascimento);
    printf("  "); 
    
    printf(" | ");
    imprimirEndereco(p.endereco, 45);
    
    printf(" |\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
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
    
    while (getchar() != '\n'); //limpar o buffer
 
    printf("Nome da vacina: ");
    fgets(vacina.nome, 50, stdin);

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

    printf("\n");
    
    while(getchar() != '\n'); // limpar o buffer

    return vacina;
}

int buscarVacinaPorCodigo(Vacina v[], int codigo) {
    for (int i = 0; i < MAX_VACINAS; i++) {
        if(v[i].codigoVacina == codigo) {
            return i;
        }
    }
    return -1;
}

int buscarVacinaPorNome(Vacina v[], char nome[]) {
    for(int i = 0; i < MAX_VACINAS; i++) {
        if (strcmp(v[i].nome, nome) == 0) {
            return i;
        }
    }

    return -1;
}

void listarVacinas(Vacina vacinas[], int qtd) {
    imprimirCabecalhoVacina();
    
    for(int i = 0; i < qtd; i++) {
        imprimirVacina(vacinas[i]);
    }
}

int existeVacinaComCodigo(Vacina vacinas[], int qtd, int codigo) {
    for(int i = 0; i < qtd; i++) {
        if(vacinas[i].codigoVacina == codigo) {
            return 1;
        }
    }
    return 0;
}


void imprimirVacina(Vacina v) {
    printf("| %-8d ", v.codigoVacina);
    
    printf("| ");
    imprimirColuna(v.nome, 30);
    
    printf(" | %-12d ", v.quantidadeDisponivel);
    printf("| %-12d |\n", v.quantidadeDoses);
    
    printf("---------------------------------------------------------------------------\n");
}

void imprimirCabecalhoVacina() {
    printf("===========================================================================\n");
    printf("| %-8s | %-30s | %-12s | %-12s |\n", "CODIGO", "NOME", "DISPONIVEL", "DOSES");
    printf("===========================================================================\n");
}

void imprimirMenu() {
  printf("==================================================\n");
    printf("          SISTEMA DE CONTROLE DE VACINAS          \n");
    printf("==================================================\n");
    printf("  [ PACIENTES ]\n");
    printf("  1 - Cadastrar paciente\n");
    printf("  2 - Buscar paciente por CPF\n");
    printf("  3 - Buscar paciente por Data de Nascimento\n");
    printf("  4 - Listar pacientes (ordem alfabetica)\n");
    printf("--------------------------------------------------\n");
    printf("  [ VACINAS ]\n");
    printf("  5 - Cadastrar vacina\n");
    printf("  6 - Buscar vacina por Codigo\n");
    printf("  7 - Buscar vacina por Nome\n");
    printf("  8 - Listar vacinas (ordem alfabetica)\n");
    printf("--------------------------------------------------\n");
    printf("  [ APLICACOES E RELATORIOS ]\n");
    printf("  9  - Registrar aplicacao de vacina\n");
    printf("  10 - Consultar carteirinha de vacinacao (por CPF)\n");
    printf("  11 - Listar pacientes com doses em atraso\n");
    printf("  12 - Relatorio de aplicacoes por periodo\n");
    printf("--------------------------------------------------\n");
    printf("  0 - Sair\n");
    printf("==================================================\n");
    printf("Escolha uma opcao: ");
}

void imprimirCabecalhoPaciente() {
    printf("==============================================================================================================\n");
    printf("| %-25s | %-15s | %-12s | %-45s |\n", "NOME", "CPF", "NASCIMENTO", "ENDERECO");
    printf("==============================================================================================================\n");
}

void imprimirData(Data d) {
    printf("%02d/%02d/%04d", d.dia, d.mes, d.ano);
}

void imprimirEndereco(Endereco e, int largura) {
    int tamRua = strcspn(e.rua, "\n");
    int tamCidade = strcspn(e.cidade, "\n");
    int tamEstado = strcspn(e.estado, "\n");
    int tamNumero = snprintf(NULL, 0, "%d", e.numero);
    
    int tamTotal = tamRua + tamNumero + tamCidade + tamEstado + 6;
    
    imprimirSemQuebraLinha(e.rua);
    printf(", %d - ", e.numero);
    imprimirSemQuebraLinha(e.cidade);
    printf("-");
    imprimirSemQuebraLinha(e.estado);
    
    printf("%*s", (tamTotal < largura ? largura - tamTotal : 0), "");
}

//o fgets adiciiona um \n antes do \0 isso quebra a stirng na hora de exibir
// essa funcao e pra imprimir sem esse \n
void imprimirSemQuebraLinha(char texto[]) {;
    for (int i = 0; texto[i] != '\0' && texto[i] != '\n'; i++) {
        printf("%c", texto[i]);
    }
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

int cpfSemRepeticao(int cpf[]) {
    for(int i =0; i < 11; i++) {
        if(cpf[0] != cpf[i]) {
            return 1;
        }
    }
    return 0;
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

void esperarEnter(void) {
    printf("Pressione ENTER para voltar ao menu");
    while (getchar() != '\n') {}
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

void ordenarOrdemAlfabetica(Paciente pacientes[], int qtd) {
    Paciente aux;

    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) {
            if (strcmp(pacientes[i].nome, pacientes[j].nome) > 0) {
                aux = pacientes[i];
                pacientes[i] = pacientes[j];
                pacientes[j] = aux;
            }
        }
    }
}

// 1. Imprime qualquer texto dentro de uma coluna com largura fixa
void imprimirColuna(char texto[], int largura) {
    int tam = strcspn(texto, "\n");
    imprimirSemQuebraLinha(texto);
    printf("%*s", (tam < largura ? largura - tam : 0), "");
}
int registrarAplicacao(Aplicacao aplicacoes[], int qtdAplicacoes, Paciente pacientes[], int qtdPacientes, Vacina vacinas[], int qtdVacinas) {
    if(qtdAplicacoes >= 1000) {
        printf("\nErro: Limite de aplicações atingido.\n");
        return qtdAplicacoes;
    }

    char cpfBusca[5];
    int codigoVacinaBusca;
    int posPaciente = -1;
    int posVacina = -1;

    printf("\n=== REGISTRO DE APLICAÇÃO DE VACINA ===\n");

    printf("Informe o CPF do paciente (apenas numeros): ");
    scanf("19s", cpfBusca);

    for (int i = 0; i < qtdPacientes; i++) {
        if (strcmp(pacientes[i].CPF, cpfBusca) == 0) {
            posPaciente = i;
            break;
        }
    }

    if (posPaciente == -1) {
        printf("Erro: Paciente com CPF %s não está cadastrado no sistema!\n ", cpfBusca);
        return qtdAplicacoes;
    }

    printf("Informe o Codigo da Vacina: ");
    scanf("%d", &codigoVacinaBusca);

    for (int i = 0; i < qtdVacinas; i++) {
        if (vacinas[i].codigoVacina == codigoVacinaBusca) {
            posVacina = i;
            break;
        }
    }

    if (posVacina == -1) {
        printf("Erro: Vacina com codigo %d nao encontrada no sistema!\n", codigoVacinaBusca);
        return qtdAplicacoes;
    }

    int dose;
    printf("Informe o numero da dose (1 ate %d): ", vacinas[posVacina].quantidadeDoses);
    scanf("%d", &dose);

    if (dose < 1 || dose > vacinas[posVacina].quantidadeDoses) {
        printf("Erro: Dose invalida para a vacina '%s' (previstas: %d doses(s))!\n", vacinas[posVacina].nome, vacinas[posVacina].quantidadeDoses);
        return qtdAplicacoes;
    }

    Data dataApp;
    printf("Data da aplicação (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dataApp.dia, &dataApp.mes, &dataApp.ano);

        if(!validarData(dataApp)) {
            printf("Erro: Data de aplicação invalida!\n");
            return qtdAplicacoes;
        }    

    Aplicacao nova;
    nova.idAplicacao = 1001 + qtdAplicacoes;
    strcpy(nova.cpf, pacientes[posPaciente].CPF);
    nova.codigoVacina = vacinas[posVacina].codigoVacina;
    nova.numeroDose = dose;
    nova.dataAplicacao = dataApp;

    vacinas[posVacina].quantidadeDisponivel--;

    aplicacoes[qtdAplicacoes] = nova;
        printf("\nSucesso: Aplicacao (ID %d) registrada para %s!\n", nova.idAplicacao, pacientes[posPaciente].nome);
        printf("Vacina: %s | Dose: %d | Estoque restante: %d\n", vacinas[posVacina].nome, nova.numeroDose, vacinas[posVacina].quantidadeDisponivel);
        return qtdAplicacoes + 1;
        
    
    void consultarCarteirinha(Paciente pacientes[], int qtdPacientes, Vacina vacinas[], int qtdVacinas, Aplicacao aplicacoes[], int qtdAplicacoes) {
        char cpf[4]; 
        pegarCpf(cpf);

        int posPac = buscarPacientePorCPF(pacientes, cpf);
         if (posPac < 0) {
            printf("Erro: Paciente com CPF %s não está cadastrado no sistema!\n", cpf);
            return;
        }

    printf("\n=======================================================================\n");
    printf(" CARTEIRINHA DE VACINACAO DO PACIENTE \n"); 
    printf("=======================================================================\n"); 
    printf("Nome: %s", pacientes[posPac].nome); 
    printf("CPF: %s\n", pacientes[posPac].CPF); 
    printf("Data de Nascimento: "); 
    imprimirData(pacientes[posPac].dataNascimento); 
    printf("\n=======================================================================\n"); 
    printf(" HISTORICO DE APLICACOES REGISTRADAS: \n"); 
    
    int qtdAplicacoesPaciente = 0;

    for (int i = 0; i < qtdAplicacoes; i++) { 
        char cpfAppLimpo[4];
        char cpfBuscaLimpo[4]; 

        tirarPontuacaoCpf(aplicacoes[i].cpf, cpfAppLimpo); 
        tirarPontuacaoCpf(cpf, cpfBuscaLimpo); 
            if (strcmp(cpfAppLimpo, cpfBuscaLimpo) == 0) 
             { qtdAplicacoesPaciente++;
                int posVac = buscarVacinaPorCodigo(vacinas, aplicacoes[i].codigoVacina); 
                if (posVac >= 0) { 
                    printf(" -&gt; ID Aplicacao: %d | Vacina: %s | Dose: %d | Data: ", aplicacoes[i].idAplicacao, vacinas[posVac].nome, aplicacoes[i].numeroDose);
                } else { printf(" -&gt; ID Aplicacao: %d | Vacina: Vacina Nao Identificada | Dose: %d | Data: ", aplicacoes[i].idAplicacao, aplicacoes[i].numeroDose); 
                } 
                imprimirData(aplicacoes[i].dataAplicacao); 
                printf("\n");
            } 
        }


        if (qtdAplicacoesPaciente == 0) { 
            printf(" Informação: Este paciente ainda nao possui nenhuma aplicacao registrada.\n"); 
        }


        printf("\\n-----------------------------------------------------------------------\\n"); 
        printf(" DESTAQUE DE PENDENCIAS / DOSES EM ATRASO:\\n"); 
        int possuiPendencias = 0; 
        for (int v = 0; v < qtdVacinas; v++) {
             int maiorDoseTomada = 0;

             for (int a = 0; a < qtdAplicacoes; a++) { 
                char cpfAppLimpo[4], cpfBuscaLimpo[4]; 
                tirarPontuacaoCpf(aplicacoes[a].cpf, cpfAppLimpo); 
                tirarPontuacaoCpf(cpf, cpfBuscaLimpo); 
                if (strcmp(cpfAppLimpo, cpfBuscaLimpo) == 0 && aplicacoes[a].codigoVacina == vacinas[v].codigoVacina) { 
                    if (aplicacoes[a].numeroDose > maiorDoseTomada) {
                         maiorDoseTomada = aplicacoes[a].numeroDose; 
                    } 
                } 
            }
                
        if (maiorDoseTomada < vacinas[v].quantidadeDoses) {
            possuiPendencias = 1; 
            printf("Atenção: Vacina '%s' - Proxima dose pendente: %d (Tomou %d de %d doses previstas)\n", vacinas[v].nome, maiorDoseTomada + 1, maiorDoseTomada, vacinas[v].quantidadeDoses); 
                } 
            } 
            if (!possuiPendencias) {
                printf("Ok: Esquema vacinal em dia para todas as vacinas cadastradas no sistema.\n"); 
            } 
        printf("=======================================================================\n"); 
    }

    Data calcularDataPrevista(Data dataUltimaDose) { 
        Data prevista = dataUltimaDose; 
        prevista.mes++; 

            if (prevista.mes > 12) { 
                prevista.mes = 1; prevista.ano++; 
            } 
        return prevista; 
    }

    void listarPacientesEmAtraso(Paciente pacientes[], int qtdPacientes, Vacina vacinas[], int qtdVacinas, Aplicacao aplicacoes[], int qtdAplicacoes) {
        int totalPendencias = 0; printf("\n=======================================================================\n"); 
        printf(" RELATORIO DE PACIENTES COM DOSES DE VACINAS EM ATRASO \n"); 
        printf("=======================================================================\n"); 
            for (int p = 0; p &lt; qtdPacientes; p++) { 
                for (int v = 0; v &lt; qtdVacinas; v++) { 
                    int maiorDoseTomada = 0; 
                    Data dataUltimaDose = {0, 0, 0};

                    for (int a = 0; a &lt; qtdAplicacoes; a++) { 
                        char cpfAppLimpo[4], cpfPacLimpo[4]; 
                        tirarPontuacaoCpf(aplicacoes[a].cpf, cpfAppLimpo); 
                        tirarPontuacaoCpf(pacientes[p].CPF, cpfPacLimpo); 
                            if (strcmp(cpfAppLimpo, cpfPacLimpo) == 0 && aplicacoes[a].codigoVacina == vacinas[v].codigoVacina) { 
                                if (aplicacoes[a].numeroDose > maiorDoseTomada) { 
                                    maiorDoseTomada = aplicacoes[a].numeroDose; 
                                    dataUltimaDose = aplicacoes[a].dataAplicacao; 
            } 
        } 
    } 
                    
    if (maiorDoseTomada < vacinas[v].quantidadeDoses) { 
        int proximaDose = maiorDoseTomada + 1; 
        Data dataPrevista = (maiorDoseTomada > 0) ? calcularDataPrevista(dataUltimaDose) : pacientes[p].dataNascimento;                    
                            
        totalPendencias++; 
        printf("Paciente: %s | CPF: %s\n", pacientes[p].nome, pacientes[p].CPF); 
        printf(" -&gt; Vacina: %s | Proxima Dose Pendente: %d/%d | Data Prevista: ", vacinas[v].nome, proximaDose, vacinas[v].quantidadeDoses); 
        imprimirData(dataPrevista); 
        printf("\\n-----------------------------------------------------------------------\\n"); 
            } 
        } 
    }

    if (totalPendencias == 0) { 
        printf("Informação: Nao existem pacientes com vacinas em atraso.\n"); 
        printf("=======================================================================\n"); 
    } else { printf("Total de registros em atraso/pendentes localizados: %d\n", totalPendencias); 
        printf("=======================================================================\\n"); 
    }
    
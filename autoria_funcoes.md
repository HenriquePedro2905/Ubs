# Quem fez cada funcao e struct

## Pedro Henrique de Souza

Structs:

- `Vacina`
- `Aplicacao`

Funcoes:

- `main`
- `cadastrarPaciente`
- `validarCPF`
- `cpfSemRepeticao`
- `pegarEndereco`
- `existPacienteComCpf`
- `imprimirMenu`
- `pegarData`
- `pegarCpf`
- `tirarPontuacaoCpf`
- `imprimirSemQuebraLinha`
- `esperarEnter`
- `existeVacinaComCodigo`
- `buscarVacinaPorCodigo`
- `buscarVacinaPorNome`
- `listarPaciente`
- `listarVacinas`
- `imprimirCabecalhoVacina`
- `imprimirCabecalhoPaciente`
- `ordenarPacientesOrdemAlfabetica`
- `imprimirColuna`
- `ordenarVacinasOrdemAlfabetica`
- `validarUF`
- `textoVazio`
- `limpar`
- `relatorioAplicacoesPorPeriodo`
- `carregarPacientesIniciais`
- `carregarVacinasIniciais`
- `carregarAplicacoesIniciais`

## Gabriel Venancio Tonasse

Structs:

- `Data`
- `Endereco`
- `Paciente`

Funcoes:

- `validarData`
- `cadastrarVacina`
- `buscarPacientePorCPF`
- `buscarPacientePorData`
- `registrarAplicacao`
- `imprimirPaciente`
- `imprimirData`
- `imprimirEndereco`
- `imprimirVacina`
- `main`
- `dataIgual`
- `buscarUltimaAplicacao`
- `consultarCarteirinha`
- `doseEmAtraso`
- `listarPacientesEmAtraso`
- `calcularDataPrevista`
- `somarDias`
- `diasDoMes`
- `dataParaDias`

---

## Vinculo das funcoes com os itens do documento

| Item | Descricao | Funcao | Quem fez |
|---|---|---|---|
| A | Definir as estruturas | `struct Data` | Gabriel Venancio Tonasse |
| A | Definir as estruturas | `struct Endereco` | Gabriel Venancio Tonasse |
| A | Definir as estruturas | `struct Paciente` | Gabriel Venancio Tonasse |
| A | Definir as estruturas | `struct Vacina` | Pedro Henrique de Souza |
| A | Definir as estruturas | `struct Aplicacao` | Pedro Henrique de Souza |
| B | Funcoes de validacao (CPF e data) | `validarCPF` | Pedro Henrique de Souza |
| B | Funcoes de validacao (CPF e data) | `cpfSemRepeticao` | Pedro Henrique de Souza |
| B | Funcoes de validacao (CPF e data) | `validarData` | Gabriel Venancio Tonasse |
| C | Cadastrar paciente | `cadastrarPaciente` | Pedro Henrique de Souza |
| C | Cadastrar paciente | `pegarEndereco` | Pedro Henrique de Souza |
| C | Cadastrar paciente | `existPacienteComCpf` | Pedro Henrique de Souza |
| C | Cadastrar paciente | `validarUF` | Pedro Henrique de Souza |
| C | Cadastrar paciente | `textoVazio` | Pedro Henrique de Souza |
| D | Buscar paciente por CPF e por data de nascimento | `buscarPacientePorCPF` | Gabriel Venancio Tonasse |
| D | Buscar paciente por CPF e por data de nascimento | `buscarPacientePorData` | Gabriel Venancio Tonasse |
| D | Buscar paciente por CPF e por data de nascimento | `dataIgual` | Gabriel Venancio Tonasse |
| D | Buscar paciente por CPF e por data de nascimento | `pegarCpf` | Pedro Henrique de Souza |
| D | Buscar paciente por CPF e por data de nascimento | `pegarData` | Pedro Henrique de Souza |
| D | Buscar paciente por CPF e por data de nascimento | `tirarPontuacaoCpf` | Pedro Henrique de Souza |
| D | Buscar paciente por CPF e por data de nascimento | `imprimirPaciente` | Gabriel Venancio Tonasse |
| D | Buscar paciente por CPF e por data de nascimento | `imprimirData` | Gabriel Venancio Tonasse |
| D | Buscar paciente por CPF e por data de nascimento | `imprimirEndereco` | Gabriel Venancio Tonasse |
| D | Buscar paciente por CPF e por data de nascimento | `imprimirSemQuebraLinha` | Pedro Henrique de Souza |
| D | Buscar paciente por CPF e por data de nascimento | `esperarEnter` | Pedro Henrique de Souza |
| E | Cadastrar vacina | `cadastrarVacina` | Gabriel Venancio Tonasse |
| E | Cadastrar vacina | `existeVacinaComCodigo` | Pedro Henrique de Souza |
| F | Buscar vacina por codigo e por nome | `buscarVacinaPorCodigo` | Pedro Henrique de Souza |
| F | Buscar vacina por codigo e por nome | `buscarVacinaPorNome` | Pedro Henrique de Souza |
| F | Buscar vacina por codigo e por nome | `imprimirVacina` | Gabriel Venancio Tonasse |
| G | Listar pacientes em ordem alfabetica | `listarPaciente` | Pedro Henrique de Souza |
| G | Listar pacientes em ordem alfabetica | `ordenarPacientesOrdemAlfabetica` | Pedro Henrique de Souza |
| G | Listar pacientes em ordem alfabetica | `imprimirCabecalhoPaciente` | Pedro Henrique de Souza |
| G | Listar pacientes em ordem alfabetica | `imprimirColuna` | Pedro Henrique de Souza |
| H | Listar vacinas em ordem alfabetica | `listarVacinas` | Pedro Henrique de Souza |
| H | Listar vacinas em ordem alfabetica | `ordenarVacinasOrdemAlfabetica` | Pedro Henrique de Souza |
| H | Listar vacinas em ordem alfabetica | `imprimirCabecalhoVacina` | Pedro Henrique de Souza |
| I | Registrar aplicacao de vacina | `registrarAplicacao` | Gabriel Venancio Tonasse |
| I | Registrar aplicacao de vacina | `buscarUltimaAplicacao` | Gabriel Venancio Tonasse |
| J | Consultar carteirinha de vacinacao | `consultarCarteirinha` | Gabriel Venancio Tonasse |
| J | Consultar carteirinha de vacinacao | `doseEmAtraso` | Gabriel Venancio Tonasse |
| K | Pacientes com doses em atraso | `listarPacientesEmAtraso` | Gabriel Venancio Tonasse |
| K | Pacientes com doses em atraso | `calcularDataPrevista` | Gabriel Venancio Tonasse |
| K | Pacientes com doses em atraso | `somarDias` | Gabriel Venancio Tonasse |
| K | Pacientes com doses em atraso | `diasDoMes` | Gabriel Venancio Tonasse |
| K | Pacientes com doses em atraso | `dataParaDias` | Gabriel Venancio Tonasse |
| L | Relatorio de aplicacoes por periodo | `relatorioAplicacoesPorPeriodo` | Pedro Henrique de Souza |
| Geral | Estrutura geral, menu e apoio | `main` | Pedro Henrique de Souza e Gabriel Venancio Tonasse |
| Geral | Estrutura geral, menu e apoio | `imprimirMenu` | Pedro Henrique de Souza |
| Geral | Estrutura geral, menu e apoio | `limpar` | Pedro Henrique de Souza |
| Geral | Estrutura geral, menu e apoio | `carregarPacientesIniciais` | Pedro Henrique de Souza |
| Geral | Estrutura geral, menu e apoio | `carregarVacinasIniciais` | Pedro Henrique de Souza |
| Geral | Estrutura geral, menu e apoio | `carregarAplicacoesIniciais` | Pedro Henrique de Souza |

## Quantidade de funcoes por pessoa

| Item | Pedro Henrique de Souza | Gabriel Venancio Tonasse |
|---|---|---|
| B | 2 | 1 |
| C | 5 | 0 |
| D | 5 | 6 |
| E | 1 | 1 |
| F | 2 | 1 |
| G | 4 | 0 |
| H | 3 | 0 |
| I | 0 | 2 |
| J | 0 | 2 |
| K | 0 | 5 |
| L | 1 | 0 |

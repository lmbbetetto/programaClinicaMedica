#include <iostream>
#include <clocale>
#include <cstring>
#define t 20

using namespace std;

struct Paciente
{
    int cpf;
    char nome[40];
    char sexo[1];
    char telefone[15];
    char end[50];
    char cidade[20];
    char uf[2];
    int status;
};
struct Especializacao
{
    int id;
    char especializacao[20];
};
struct Medico
{
    int crm;
    char nome[40];
    int idade;
    char sexo[1];
    char telefone[15];
    int idEspecializacao;
    float valorConsulta;
    int status;
};
struct Consulta
{
    int cpfPaciente;
    int crmMedico;
    char data[10];
    char horario[5];
};
struct IndexPaciente
{
    int cpf;
    int endF;
};
struct indexEspeci
{
    int id;
    int endF;
};
struct indexMedico
{
    int crm;
    int endF;
};
struct indexConsulta
{
    int cpfPaciente;
    int endF;
};

void leituraPaciente(Paciente pacientes[], IndexPaciente indxPacientes[], int &contPacientes);
void IndexPacientes(Paciente pacientes[], IndexPaciente indxPacientes[], int &contPacientes, int &aux);

void leituraEspecializacao(Especializacao especializacoes[], indexEspeci indxEspeci[], int &contEspeci);
void IndexEspecializacao(Especializacao especializacoes[], indexEspeci indxEspeci[], int &contEspeci, int &aux);

void leituraMedico(Medico medicos[], indexMedico indxMedico[], int &contMedico, int &contEspeci, Especializacao especializacoes[], indexEspeci indxEspeci[]);
void indexMedicos(Medico medicos[], indexMedico indxMedico[], int &contMedico, int &aux);
void buscaEspeci(Especializacao especializacoes[], indexEspeci indxEspeci[], int &codpesq, int &contEspeci, int &cond);

void inclusaoPaciente(Paciente pacientes[], IndexPaciente indxPacientes[], int &contPacientes);
void inclusaoMedico(Medico medicos[], indexMedico indxMedico[], int &contMedico, int &contEspeci, Especializacao especializacoes[], indexEspeci indxEspeci[]);

void buscaEspeci(Medico medicos[], indexMedico indxMedico[], int &contMedico, int &contEspeci, Especializacao especializacoes[], indexEspeci indxEspeci[]);

void agendarConsulta(Consulta consultas[], indexConsulta indxConsultas[], int &contConsulta, Medico medicos[], indexMedico indxMedico[], int &contMedico);
void indexConsultas(Consulta consultas[], indexConsulta indxConsultas[], int &contConsulta, int &aux);
void buscaMedico(Medico medicos[], indexMedico indxMedico[], int &codpesq, int &contMedico, int &cond);

void excluirMedico(Medico medicos[], indexMedico indxMedico[], int &contMedico);
void reorganizacaoMedico(Medico medicos[], indexMedico indxMedico[], int &contMedico, Medico medicosAux[], indexMedico indxMedicoAux[]);

int main()
{
    setlocale(LC_ALL, "");

    Paciente pacientes[t];
    IndexPaciente indxPacientes[t];
    int contPacientes = 0;

    Especializacao especializacoes[t];
    indexEspeci indxEspeci[t];
    int contEspeci = 0;

    Medico medicos[t];
    indexMedico indxMedico[t];
    int contMedico = -1;
    Medico medicosAux[t];
    indexMedico indxMedicoAux[t];

    Consulta consultas[t];
    indexConsulta indxConsultas[t];
    int contConsulta = 0;

    // in?cio switch
    int pont = -1;
    int aux;
    while (pont != 0)
    {
        aux = -1;
        int pont1 = -1, pont2 = -1;
        system("cls");
        cout << "\t\tMenu principal!\n\n\n";
        cout << "1 - Leituras\n";
        cout << "2 - Inclusões\n";
        cout << "3 - Busca Por Especialização\n";
        cout << "4 - Agendar Consulta\n";
        cout << "5 - Excluir Médico\n";
        cout << "6 - Reorganizar Médicos\n";
        cout << "0 - Sair\n\n";
        cout << "Selecione uma opção: ";
        cin >> aux;

        switch (aux)
        {
        case 1:
            while (pont1 != 0)
            {
                aux = -1;
                system("cls");
                cout << "\t\tMenu leituras!\n\n\n";
                cout << "1 - Paciente\n";
                cout << "2 - Especialização\n";
                cout << "3 - Médico\n";
                cout << "0 - Voltar\n\n";
                cout << "Selecione uma opção: ";
                cin >> aux;

                switch (aux)
                {

                case 0:
                    system("cls");
                    cout << "Voltando...\n\n";
                    pont1 = 0;
                    break;

                case 1:
                    system("cls");
                    leituraPaciente(pacientes, indxPacientes, contPacientes);
                    break;

                case 2:
                    system("cls");
                    leituraEspecializacao(especializacoes, indxEspeci, contEspeci);
                    break;

                case 3:
                    system("cls");
                    leituraMedico(medicos, indxMedico, contMedico, contEspeci, especializacoes, indxEspeci);
                    break;

                default:
                    break;
                }
            }
            system("pause");
            break;

        case 2:
            while (pont2 != 0)
            {
                aux = -1;
                system("cls");
                cout << "\t\tMenu Inclusão!\n\n\n";
                cout << "1 - Paciente\n";
                cout << "2 - Médico\n";
                cout << "0 - Voltar\n\n";
                cout << "Selecione uma opção: ";
                cin >> aux;

                switch (aux)
                {
                case 0:
                    system("cls");
                    cout << "Voltando...\n\n";
                    pont2 = 0;
                    break;

                case 1:
                    system("cls");
                    inclusaoPaciente(pacientes, indxPacientes, contPacientes);
                    system("pause");
                    break;

                case 2:
                    system("cls");
                    inclusaoMedico(medicos, indxMedico, contMedico, contEspeci, especializacoes, indxEspeci);
                    for (int i = 0; i <= contMedico; i++)
                    {
                        cout << "CPF: " << indxMedico[i].crm << " | EndF: " << indxMedico[i].endF << "\n\n";
                    }
                    system("pause");
                    break;
                }
            }
            system("pause");
            break;

        case 3:
            system("cls");
            buscaEspeci(medicos, indxMedico, contMedico, contEspeci, especializacoes, indxEspeci);
            system("pause");
            break;

        case 4:
            system("cls");
            agendarConsulta(consultas, indxConsultas, contConsulta, medicos, indxMedico, contMedico);
            system("pause");
            break;

        case 5:
            system("cls");
            excluirMedico(medicos, indxMedico, contMedico);
            system("pause");
            break;

        case 6:
            system("cls");
            reorganizacaoMedico(medicos, indxMedico, contMedico, medicosAux, indxMedicoAux);

            for (int i = 0; i < contMedico; i++)
            {
                cout << "CRM: " << indxMedico[i].crm << " | EndF: " << indxMedico[i].endF << " | Status: " << medicos[i].status << " | Nome: " << medicos[i].nome << endl;
            }

            system("pause");
            break;

        case 0:
            system("cls");
            cout << "Saindo...\n\n\n";
            pont = 0;
            break;
        }
    }
    // Fim switch
}

void leituraPaciente(Paciente pacientes[], IndexPaciente indxPacientes[], int &contPacientes)
{
    for (int i = 0; i < t && pacientes[i - 1].cpf != -1; i++)
    {
        system("cls");
        cout << "Leitura Paciente!\n\n";
        cout << "CPF: ";
        cin >> pacientes[i].cpf;
        if (pacientes[i].cpf != -1)
        {
            cout << "Nome: ";
            cin >> pacientes[i].nome;
            cout << "Sexo: ";
            cin >> pacientes[i].sexo;
            cout << "Telefone: ";
            cin >> pacientes[i].telefone;
            cout << "Endere?o: ";
            cin >> pacientes[i].end;
            cout << "Cidade: ";
            cin >> pacientes[i].cidade;
            cout << "UF: ";
            cin >> pacientes[i].uf;
            pacientes[i].status = 0;
            contPacientes = i;

            IndexPacientes(pacientes, indxPacientes, contPacientes, i);
        }
    }
}

void IndexPacientes(Paciente pacientes[], IndexPaciente indxPacientes[], int &contPacientes, int &aux)
{
    int i;

    if (aux == 0)
    {
        indxPacientes[aux].cpf = pacientes[aux].cpf;
        indxPacientes[aux].endF = aux;
    }
    else
    {
        for (i = contPacientes - 1; indxPacientes[i].cpf > pacientes[aux].cpf && i >= 0; i--)
        {
            indxPacientes[i + 1].cpf = indxPacientes[i].cpf;
            indxPacientes[i + 1].endF = indxPacientes[i].endF;
        }
        indxPacientes[i + 1].cpf = pacientes[aux].cpf;
        indxPacientes[i + 1].endF = aux;
    }
}

void leituraEspecializacao(Especializacao especializacoes[], indexEspeci indxEspeci[t], int &contEspeci)
{
    for (int i = 0; i < t && especializacoes[i - 1].id != -1; i++)
    {
        system("cls");
        cout << "Leitura Paciente!\n\n";
        cout << "ID: ";
        cin >> especializacoes[i].id;
        if (especializacoes[i].id != -1)
        {
            cout << "Especialização: ";
            cin >> especializacoes[i].especializacao;
            contEspeci = i;

            IndexEspecializacao(especializacoes, indxEspeci, contEspeci, i);
        }
    }
}

void IndexEspecializacao(Especializacao especializacoes[], indexEspeci indxEspeci[t], int &contEspeci, int &aux)
{
    int i;

    if (aux == 0)
    {
        indxEspeci[aux].id = especializacoes[aux].id;
        indxEspeci[aux].endF = aux;
    }
    else
    {
        for (i = contEspeci - 1; indxEspeci[i].id > especializacoes[aux].id && i >= 0; i--)
        {
            indxEspeci[i + 1].id = indxEspeci[i].id;
            indxEspeci[i + 1].endF = indxEspeci[i].endF;
        }
        indxEspeci[i + 1].id = especializacoes[aux].id;
        indxEspeci[i + 1].endF = aux;
    }
}

void leituraMedico(Medico medicos[], indexMedico indxMedico[], int &contMedico, int &contEspeci, Especializacao especializacoes[], indexEspeci indxEspeci[])
{
    for (int i = 0; i < t && medicos[i - 1].crm != -1; i++)
    {
        system("cls");
        cout << "Leitura Médico!\n\n";
        cout << "ID: ";
        cin >> medicos[i].crm;
        if (medicos[i].crm != -1)
        {
            cout << "Nome: ";
            cin >> medicos[i].nome;
            cout << "Idade: ";
            cin >> medicos[i].idade;
            cout << "Sexo (M | F): ";
            cin >> medicos[i].sexo;
            cout << "Telefone: ";
            cin >> medicos[i].telefone;

            cout << "Código Especialização: ";
            cin >> medicos[i].idEspecializacao;
            int codpesq = medicos[i].idEspecializacao, cond = 0;
            buscaEspeci(especializacoes, indxEspeci, codpesq, contEspeci, cond);

            if (cond == 0)
            {
                cout << "\nValor da Consulta: ";
                cin >> medicos[i].valorConsulta;
                medicos[i].status = 0;

                contMedico = i;

                indexMedicos(medicos, indxMedico, contMedico, i);
            }
            else
            {
                system("cls");
                i--;
                cout << "\n\nN?o foi poss?vel continuar o cadastro!\n";
                cout << "Error: Especializa??o n?o encontrada!\n\n\n";
                system("pause");
            }
        }
    }
}

void indexMedicos(Medico medicos[], indexMedico indxMedico[], int &contMedico, int &aux)
{
    int i;

    if (aux == 0)
    {
        indxMedico[aux].crm = medicos[aux].crm;
        indxMedico[aux].endF = aux;
    }
    else
    {
        for (i = contMedico - 1; indxMedico[i].crm > medicos[aux].crm && i >= 0; i--)
        {
            indxMedico[i + 1].crm = indxMedico[i].crm;
            indxMedico[i + 1].endF = indxMedico[i].endF;
        }
        indxMedico[i + 1].crm = medicos[aux].crm;
        indxMedico[i + 1].endF = aux;
    }
}

void buscaEspeci(Especializacao especializacoes[], indexEspeci indxEspeci[], int &codpesq, int &contEspeci, int &cond)
{
    int i = 0, f = contEspeci;
    int m = (i + f) / 2;
    for (; f >= i && codpesq != indxEspeci[m].id; m = (i + f) / 2)
    {
        if (codpesq > indxEspeci[m].id)
        {
            i = m + 1;
        }
        else
        {
            f = m - 1;
        }
    }
    if (indxEspeci[m].id == codpesq)
    {
        cout << "Especialização: " << especializacoes[i].especializacao;
    }
    else
    {
        cout << "Especialização não encontrada!";
        cond = 1;
    }
}

void inclusaoPaciente(Paciente pacientes[], IndexPaciente indxPacientes[], int &contPacientes)
{
    for (int i = contPacientes + 1; i < t && pacientes[i - 1].cpf != -1; i++)
    {
        system("cls");
        cout << "Inclusão Paciente!\n\n";
        cout << "CPF: ";
        cin >> pacientes[i].cpf;
        if (pacientes[i].cpf != -1)
        {
            cout << "Nome: ";
            cin >> pacientes[i].nome;
            cout << "Sexo: ";
            cin >> pacientes[i].sexo;
            cout << "Telefone: ";
            cin >> pacientes[i].telefone;
            cout << "Endere?o: ";
            cin >> pacientes[i].end;
            cout << "Cidade: ";
            cin >> pacientes[i].cidade;
            cout << "UF: ";
            cin >> pacientes[i].uf;
            pacientes[i].status = 0;
            contPacientes = i;

            IndexPacientes(pacientes, indxPacientes, contPacientes, i);
        }
    }
}

void inclusaoMedico(Medico medicos[], indexMedico indxMedico[], int &contMedico, int &contEspeci, Especializacao especializacoes[], indexEspeci indxEspeci[])
{
    for (int i = contMedico + 1; i < t && medicos[i - 1].crm != -1; i++)
    {
        system("cls");
        cout << "Leitura Médico!\n\n";
        cout << "ID: ";
        cin >> medicos[i].crm;
        if (medicos[i].crm != -1)
        {
            cout << "Nome: ";
            cin >> medicos[i].nome;
            cout << "Idade: ";
            cin >> medicos[i].idade;
            cout << "Sexo (M | F): ";
            cin >> medicos[i].sexo;
            cout << "Telefone: ";
            cin >> medicos[i].telefone;

            cout << "Código Especialização: ";
            cin >> medicos[i].idEspecializacao;
            int codpesq = medicos[i].idEspecializacao, cond = 0;
            buscaEspeci(especializacoes, indxEspeci, codpesq, contEspeci, cond);

            if (cond == 0)
            {
                cout << "\nValor da Consulta: ";
                cin >> medicos[i].valorConsulta;
                medicos[i].status = 0;

                contMedico = i;

                indexMedicos(medicos, indxMedico, contMedico, i);
            }
            else
            {
                system("cls");
                i--;
                cout << "\n\nNão foi possãvel continuar o cadastro!\n";
                cout << "Error: Especialização não encontrada!\n\n\n";
                system("pause");
            }
        }
    }
}

void buscaEspeci(Medico medicos[], indexMedico indxMedico[], int &contMedico, int &contEspeci, Especializacao especializacoes[], indexEspeci indxEspeci[])
{
    int codpesq, cond = 0;
    cout << "Busca de médico!\n\n";
    cout << "Informe a Especialidade: ";
    cin >> codpesq;
    buscaEspeci(especializacoes, indxEspeci, codpesq, contEspeci, cond);
    cout << "\n\n";

    if (cond == 0)
    {
        int j;
        for (int i = 0; i <= contMedico; i++)
        {
            j = indxMedico[i].endF;
            if (medicos[j].status == 0 && medicos[j].idEspecializacao == codpesq)
            {
                cout << "CRM: " << medicos[j].crm << endl;
                cout << "Nome: " << medicos[j].nome << endl;
                cout << "Nome: " << medicos[j].valorConsulta << endl
                     << endl;
            }
        }
    }
    cout << "\n\n\n";
}

void agendarConsulta(Consulta consultas[], indexConsulta indxConsultas[], int &contConsulta, Medico medicos[], indexMedico indxMedico[], int &contMedico)
{
    for (int i = contConsulta; i < t && consultas[i - 1].cpfPaciente != -1; i++)
    {
        system("cls");
        cout << "Agendamento de Consulta!\n\n";
        cout << "CPF: ";
        cin >> consultas[i].cpfPaciente;
        if (consultas[i].cpfPaciente != -1)
        {
            cout << "CRM: ";
            cin >> consultas[i].crmMedico;
            int cond = 0;
            buscaMedico(medicos, indxMedico, consultas[i].crmMedico, contMedico, cond);
            if (cond == 0)
            {
                cout << "Data: ";
                cin >> consultas[i].data;
                cout << "Horário: ";
                cin >> consultas[i].horario;
                contConsulta = i;

                indexConsultas(consultas, indxConsultas, contConsulta, i);
            }
            else
            {
                system("cls");
                i--;
                cout << "\n\nNão foi possível continuar o cadastro!\n";
                cout << "Error: Médico não encontrado!\n\n\n";
                system("pause");
            }
        }
    }
}

void indexConsultas(Consulta consultas[], indexConsulta indxConsultas[], int &contConsulta, int &aux)
{
    int i;

    if (aux == 0)
    {
        indxConsultas[aux].cpfPaciente = consultas[aux].cpfPaciente;
        indxConsultas[aux].endF = aux;
    }
    else
    {
        for (i = contConsulta - 1; indxConsultas[i].cpfPaciente > consultas[aux].cpfPaciente && i >= 0; i--)
        {
            indxConsultas[i + 1].cpfPaciente = indxConsultas[i].cpfPaciente;
            indxConsultas[i + 1].endF = indxConsultas[i].endF;
        }
        indxConsultas[i + 1].cpfPaciente = consultas[aux].cpfPaciente;
        indxConsultas[i + 1].endF = aux;
    }
}

void buscaMedico(Medico medicos[], indexMedico indxMedico[], int &codpesq, int &contMedico, int &cond)
{
    int i = 0, f = contMedico;
    int m = (i + f) / 2;
    for (; f >= i && codpesq != indxMedico[m].crm; m = (i + f) / 2)
    {
        if (codpesq > indxMedico[m].crm)
        {
            i = m + 1;
        }
        else
        {
            f = m - 1;
        }
    }
    if (indxMedico[m].crm == codpesq)
    {
        cout << "Nome: " << medicos[i].nome << endl;
    }
    else
    {
        cout << "Médico não existe!";
        cond = 1;
    }
}

void excluirMedico(Medico medicos[], indexMedico indxMedico[], int &contMedico)
{
    int codpesq, cond = 0;
    system("cls");
    cout << "Excluir Médico!\n\n\n";
    cout << "CRM: ";
    cin >> codpesq;

    int i = 0, f = contMedico;
    int m = (i + f) / 2;
    for (; f >= i && codpesq != indxMedico[m].crm; m = (i + f) / 2)
    {
        if (codpesq > indxMedico[m].crm)
        {
            i = m + 1;
        }
        else
        {
            f = m - 1;
        }
    }
    if (indxMedico[m].crm == codpesq)
    {
        cout << "Nome: " << medicos[m].nome << endl;
        medicos[m].status = 1;
    }
    else
    {
        cond = 1;
    }

    if (cond == 0)
    {
        cout << "Médico excluído com sucesso!\n\n";
    }
    else
    {
        cout << "Erro: Médico não existe!\n\n";
    }
}

void reorganizacaoMedico(Medico medicos[], indexMedico indxMedico[], int &contMedico, Medico medicosAux[], indexMedico indxMedicoAux[])
{
    int j = 0;
    for (int k = 0; k <= contMedico; k++)
    {
        int i = indxMedico[k].endF;
        if (medicos[i].status == 0)
        {
            indxMedico[j].crm = medicos[i].crm;
            indxMedico[j].endF = j;
            medicosAux[j] = medicos[i];
            j++;
        }
    }

    for (int i = 0; i <= j; i++)
    {
        int k = indxMedico[i].endF;
        medicos[i] = medicosAux[k];
    }
    contMedico = j;
    cout << "Reorganização concluída com sucesso!\n\n\n";
}
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// CARACTER
char chr;
void LerCaracters();
void LerCaracters()
{
    fflush(stdin);
    printf("- Digite um caracter ou / para encerrar: ");
    scanf("%c", &chr);
}

// INTERVALO
int intervalo1, intervalo2;
void Intervalo();
void Intervalo()
{
    printf("Defina os intervalos: ");
    scanf("%i", &intervalo1);
    printf("Defina o segundo intevalo: ");
    scanf("%i", &intervalo2);
}

// INTERVALO REAIS
float IntReais1, IntReais2;
void IntervaloReal();
void IntervaloReal()
{
    printf("\n- Defina os intervalos reais: ");
    scanf("%f", &IntReais1);
    printf("- Defina o segundo intervalo real: ");
    scanf("%f", &IntReais2);
    while (IntReais1 > IntReais2)
    {
        printf("- Número invalido");
        printf("\n- O primeiro intervalo tem que ser menor que o segundo");
        printf("\n- Digite novamente os intervalos: ");
        scanf("%f", &IntReais1);
        printf("- Digite o segundo intervalo: ");
        scanf("%f", &IntReais2);
    }
}

// INTERVALO REAIS 2
float real1, real2;
void Intervalo0e1();
void Intervalo0e1()
{
    printf("Digite dois valores reais entre zero e um\n");
    scanf("%f %f",&real1,&real2);
    while (real1 > real2)
    {
        printf("Como esses valores são para definir um intervalo, o primeiro valor deve ser maior que o segundo\n");
        printf("Reescreva-os novamente: ");
        fflush(stdin);
        scanf("%f %f",&real1,&real2);
    }
    while (real1 < 0 && real1 > 1 || real1 < 0 && real1 > 1)
    {
        printf("Os valores devem estar entre zero e um , por favor reescreva-os\n");
        fflush(stdin);
        scanf("%f %f",&real1,&real2);
    }
}

// 1
int ex01();
void LetraMaiuscula(char strp[51]);
void LerPalavra();

// 2
int ex02();
void LerString();
void Comparar(char strpalavra1[51], char chrcaracter1);

// 3
int ex03();

void ChrMinusculo();
void ChrMaiusculo();
void resultado();

// 4
int ex04();

// 5
int ex05();

// 6
int ex06();
void Repeticao();

// 7
int ex07();
void RepeticaoIntervalo();

// 8
int ex08();
void RepeticaoReais();

// 9
int ex09();
void Intervalorealdefinido();

//10
int ex10();
void lerlinhateclado();
int linha_teclado1[] = {'`','~','!','@','#','$','%','^','&','*','(',')','-','_','=', '+', '1', '2','3','4','5','6','7','8','9','0'};
int linha_teclado2[] = {'q','w','e','r','t','y','u','i','o','p','{','}','[',']'};
int linha_teclado3[] = {'a','s','d','f','g','h','j','k','l',';',':','\'','"','\\','|'};
int linha_teclado4[] = {'z','x','c','v','b','n','m',',','<','>','.','?','/'};

// MAIN

int main()
{
    setlocale(LC_ALL,"portuguese");
    system("CLS");

    menu();
    fflush(stdin);
    return 0;
}

int op;
void menu();
void menu()
{
    int op;

    printf("Escolha uma opção: ");
    printf("\n1 - Exercício 01");
    printf("\n2 - Exercício 02");
    printf("\n3 - Exercício 03");
    printf("\n4 - Exercício 04");
    printf("\n5 - Exercício 05");
    printf("\n6 - Exercício 06");
    printf("\n7 - Exercício 07");
    printf("\n8 - Exercício 08");
    printf("\n9 - Exercício 09");
    printf("\n10 - Exercício 10");
    printf("\n0 - SAIR");
    printf("\n- Escolha: ");
    scanf("%i", &op);

    do
    {
        switch(op)
        {
        case 0:
            return 0;
            break;
        case 1:
            ex01();
            break;
        case 2:
            ex02();
            break;
        case 3:
            ex03();
            break;
        case 4:
            ex04();
            break;
        case 5:
            ex05();
            break;
        case 6:
            ex06();
            break;
        case 7:
            ex07();
            break;
        case 8:
            ex08();
            break;
        case 9:
            ex09();
            break;
        case 10:
            ex10();
            break;
        default:
            return 0;
        }
        system("pause");
    }
    while (op != 0);

    fflush(stdin);
}

// 1. Crie um procedimento para:
// - ler uma palavra do teclado;
// - mostrar todas as letras maiúsculas que estão na palavra digitada.

int ex01()
{
    char strpalavra[51];

    void LerPalavra()
    {
        fflush(stdin);
        printf("Digite uma string: ");
        gets(strpalavra);
    }
    LerPalavra();
    LetraMaiscula(strpalavra);

    fflush(stdin);
    main();
}

void LetraMaiscula(char strp[51])
{
    int i = 0;
    for(i = 0; i < strlen(strp); i++)
    {
        if(strp[i] >= 'A' && strp[i] <= 'Z')
        {
            printf("- Letra %c\n", strp[i]);
        }
    }
}

// 2. Crie um procedimento para:
//- ler uma palavra do teclado;
//- ler um caractere do teclado
//- transforme toda a palavra em maiúscula;
//- contar e mostrar as letras maiúsculas menores que o caractere, e quantas letras são maiores que o caractere, e
// quantas são iguais ao caractere lido

int ex02()
{
    char chrcaracter;
    char strpalavra[51];

    void LerString()
    {
        fflush(stdin);
        printf("Digite uma string: ");
        gets(strpalavra);
    }

    LerString();
    LerCaracters();
    Comparar(strpalavra, chr);

    fflush(stdin);
    main();
}

void Comparar(char strpalavra1[51], char chrc)
{

    int i, maior = 0, menor = 0, igual = 0;

    strupr(strpalavra1);
    toupper(chrc);

    if(chrc>='a' && chrc<='z')
    {
        chrc-=32;
    }
    for(i = 0; strlen(strpalavra1); i++)
    {

        if(strpalavra1[i] > chrc)
        {
            maior++;
        }
        if(strpalavra1[i] == chrc)
        {
            igual++;
        }
        if(strpalavra1[i] < chrc)
        {
            menor++;
        }

    }
    printf("Número de letras maiores: %i", maior);
    printf("Número de letras iguais: %i", igual);
    printf("Número de letras menores: %i", menor);

}

// Crie um procedimento para:
// - ler uma cadeia de caracteres do teclado;
// - contar e mostrar todos símbolos que forem letras, ou maiúsculas ou minúsculas.

int ex03()
{
    int maiusculo = 0, minusculo = 0;
    LerCaracters();

    do
    {
        void ChrMaiusculo()
        {
            if(chr >= 'A' && chr <= 'Z')
            {
                maiusculo++;
            }
        }

        void ChrMinusculo()
        {
            if(chr >= 'a' && chr <= 'z')
            {
                minusculo++;
            }
        }
        ChrMaiusculo();
        ChrMinusculo();

        LerCaracters();

    }
    while(chr != '/');

    printf("\n- Numero de letras maiusculas: %i", maiusculo);
    printf("\n- Numero de letras minusculas: %i\n", minusculo);

    fflush(stdin);
    main();
}

// 4. Crie um procedimento para:
// - ler uma cadeia de caracteres do teclado;
// - contar e mostrar todos os dígitos, percorrendo desde o fim até o início da cadeia de caracteres.

int ex04()
{
    LerCaracters();
    int digito = 0;
    char resp_contrario[50];
    printf("Esses são os digitos existentes na cadeia de caracter: \n");
    for(int i = 0 ; i <= strlen(chr) ; i++)
    {
        strcpy(resp_contrario,strrev(chr));

        if (resp_contrario[i] >= 48 && resp_contrario[i] <= 57)
        {
            digito++;
            printf("%c\n",resp_contrario[i]);
        }
    }

    printf("Existem %d digitos nessa cadeia de caracteres\n",digito);

    fflush(stdin);
    main();
}

// 5. Crie um procedimento para:
//- ler uma cadeia de caracteres do teclado;
//- contar e mostrar tudo o que não for dígito e também não for letra minúscula.

int ex05()
{

    LerCaracters();
    int count;
    printf("Esses são todos os caracteres que não são digitos e nem letras minsculas:\n");
    for(int i = 0 ; i <= strlen(chr) ; i++)
    {
        if (chr >= 48 && chr <= 57)continue;
        else if (chr >= 'a' && chr <= 'z')continue;
        else
        {
            printf("%c\n",chr);
            count++;
        }
    }
    fflush(stdin);
    main();
}

// 6. Crie um procedimento para:
//- ler dois valores inteiros positivos, limites para definirem um intervalo; ( esses valores deverão ser globais
//- ler uma quantidade de valores inteiros a serem testados –FLAG -1; um por vez;
//- contar e mostrar dentre esses valores lidos os que forem múltiplos de 2 e de 3, ao mesmo tempo, e pertençam ao
//intervalo.

int ex06()
{
    Intervalo();
    Repeticao();

    fflush(stdin);
    main();
}

void Repeticao()
{
    int num, i = 0;

    printf("Digite um numero inteiro: ");
    scanf("%i", &num);

    do
    {
        if(num % 2 == 0 && num % 3 == 0)
        {
            if(num > intervalo1 && num < intervalo2 || num > intervalo2 && num < intervalo1)
            {
                i++;
                printf("O número %i cumpre as condições", num);
                printf("Números que atenderam as condições: %i", i);
            }
            else
            {
                printf("Número fora do intervalo");
            }
        }
        else
        {
            printf("Número não cumpriu a condição");
        }

        printf("Digite um numero inteiro ou -1 para encerrar: ");
        scanf("%i", &num);

    }
    while(num != -1);
}

// 7. Crie um procedimento para:
//- ler dois valores inteiros positivos, limites para definirem um intervalo ( esses valores deverão ser globais)
//- ler uma quantidade de valores inteiros a serem testados;- Flag -1, um por vez;
//- contar e mostrar dentre esses valores lidos os que forem múltiplos de 3, que não forem também múltiplos de 5, e
// pertençam ao intervalo.

int ex07()
{
    Intervalo();
    RepeticaoIntervalo();

    fflush(stdin);
    main();
}

void RepeticaoIntervalo()
{
    int num, i = 0;

    printf("Digite um numero inteiro: ");
    scanf("%i", &num);

    do
    {
        if(num % 5 == 0)
        {
            printf("O numero não cumpriu a condição");
        }
        else
        {
            if(num % 3 == 0)
            {
                if(num > intervalo1 && num < intervalo2 || num > intervalo2 && num < intervalo1)
                {
                    i++;
                    printf("O número %i cumpre as condições", num);
                    printf("Números que atenderam as condições: %i", i);
                }
                else
                {
                    printf("Número fora do intervalo");
                }
            }
            else
            {
                printf("Número não é multiplo de 3");
            }
        }

        printf("Digite um numero inteiro ou -1 para encerrar: ");
        scanf("%i", &num);

    }
    while(num != -1);
}
// 8. Crie um procedimento para:
//- ler dois valores reais, o primeiro menor que o segundo, caso não seja emita uma mensagem de erro e peça novamente, para
//definirem um intervalo; ( esses valores deverão ser globais)
//- Crie outro procedimento para:
//- ler a quantidade de valores reais a serem testados, e ler outros tantos valores quantos os indicados por essa quantidade;
//- contar e mostrar todos os valores lidos, pertencentes ao do intervalo, cujas partes inteiras forem números ímpares.

int ex08()
{
    setlocale(LC_ALL,"portuguese");
    IntervaloReal();
    RepeticaoReais();

    getch();
    fflush(stdin);
    main();
}

void RepeticaoReais()
{

    int i,qNum = 0, j = 0;
    float num = 0;

    printf("\n- Digite a quantidade de valores a serem testados: ");
    scanf("%i", &qNum);

    for(i= 0; i <= qNum; i++)
    {
        fflush(stdin);
        printf("\n- Digite um numero real: ");
        scanf("%f", &num);

        if ((int)num % 2 == 0)
        {
            printf("\n- O número não é impar");
        }
        else
        {
            if((int)num % 2 != 0)
            {
                if(num > IntReais1 && num < IntReais2)
                {
                    j++;
                    printf("\n- O número %5.2f cumpre as condições", num);
                    printf("\n- Números que atenderam as condições: %i", j);
                }
                else
                {
                    printf("\n- O número esta fora do intervalo");
                }
            }
        }
    }
    fflush(stdin);
}
// 9. Crie um procedimento para:
//- ler dois valores reais, maiores que 0 e menores que 1, caso não seja emita uma mensagem de erro e peça novamente, para
//definirem um intervalo de precisão; ; ( esses valores deverão ser globais)
//Crie um procedimento para:
//- ler uma quantidade de valores reais a serem testados, e ler outros tantos valores quantos os indicados por essa quantidade; -
//contar e mostrar todos os valores lidos que tenham suas partes fracionárias ao intervalo de precisão. DICA: Usar conformação de
//tipo (type casting) para isolar a parte inteira (int), e obter a parte fracionária mediante a subtração da parte inteira, antes de testar.

int ex09()
{
    Intervalo0e1();
    Intervalorealdefinido();

    fflush(stdin);
    main();
}

 void Intervalorealdefinido(){
    int i = 0, gcontagem = 0;
    printf("\n- Digite a quantidade de valores a serem testados: ");
    scanf("%d",&i);
    float a[i], decimal;
    printf("\n- Digite em seguida todos os números:\n");
    for (int j = 0; j < i ; j++)
    {
        scanf("%f",&a[j]);
    }
    printf("\n- Esses são todos os valores que possuem parte francionária dentro do intervalo:\n");
    for (int j = 0 ; j < i ; j++)
    {
        decimal = a[j] - (int)a[j];
        if (decimal >= real1 && decimal <= real2 )
        {
            gcontagem++;
            printf("%f\n", a[j]);
        }
    }
    printf("%d é a quantidade de números digitados que tem a sua parte decimal dentro dos parámetros\n",gcontagem) ;
 }

// 10. Crie um procedimento para:
//ler uma linha do teclado; defina essa linha como global ;
//- separar em outra cadeia de caracteres e mostrar todos os símbolos não alfanuméricos (letras ou dígitos) na cadeia de caracteres.

int ex10()
{
    lerlinhateclado();
    fflush(stdin);
    main();
}

void lerlinhateclado()
{
    int lt, gcontagem = 0;
    printf("Qual linha do teclado devo analisar ? (de 1 a 4)\n");
    scanf("%d", &lt);
    size_t n1 = sizeof(linha_teclado1)/sizeof(linha_teclado1[0]);
    size_t n2 = sizeof(linha_teclado2)/sizeof(linha_teclado2[0]);
    size_t n3 = sizeof(linha_teclado3)/sizeof(linha_teclado3[0]);
    size_t n4 = sizeof(linha_teclado4)/sizeof(linha_teclado4[0]);
    while (lt < 1 && lt > 4)
    {
        printf("Somente existem 4 linhas no teclado . Logo , escolha entre 1 e 4\n");
        scanf("%d", &lt);
    }
    if (lt == 1)
    {
        for ( int i = 0 ; i < n1 ; i++)
        {
            if (linha_teclado1[i] >= 48 && linha_teclado1[i] <= 57 || linha_teclado1[i] >= 61 && linha_teclado1[i] <= 122)continue;
            else
            {
                printf("%c\n",linha_teclado1[i]);
                gcontagem++;
            }
        }

    }
    if (lt == 2)
    {
        for ( int i = 0 ; i < n2 ; i++)
        {
            if (linha_teclado2[i] >= 48 && linha_teclado2[i] <= 57 || linha_teclado2[i] >= 61 && linha_teclado2[i] <= 122)continue;
            else
            {
                printf("%c\n",linha_teclado2[i]);
                gcontagem++;
            }
        }
    }
    if (lt == 3)
    {
        for ( int i = 0 ; i < n3 ; i++)
        {
            if (linha_teclado3[i] >= 48 && linha_teclado3[i] <= 57 || linha_teclado3[i] >= 61 && linha_teclado3[i] <= 122)continue;
            else
            {
                printf("%c\n",linha_teclado3[i]);
                gcontagem++;
            }
        }

    }
    if (lt == 4)
    {
        for ( int i = 0 ; i < n3 ; i++)
        {
            if (linha_teclado3[i] >= 48 && linha_teclado3[i] <= 57 || linha_teclado3[i] >= 61 && linha_teclado3[i] <= 122)continue;
            else
            {
                printf("%c\n",linha_teclado3[i]);
                gcontagem++;
            }
        }

    }
    printf("Existem %d s�mbolos n�o alfanum�ricos nessa linha\n",gcontagem);
}














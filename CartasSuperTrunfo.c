#include <stdio.h>
#include <locale.h>
#include <string.h>

/* ── Constantes ─────────────────────────────────────────── */
#define TAM_CODIGO   4
#define TAM_CIDADE   30
#define BILHAO       1000000000.0

/* ── Estrutura para organizar os dados ───────────────────── */
typedef struct {
    char estado;
    char codigo[TAM_CODIGO];
    char cidade[TAM_CIDADE];
    unsigned long int populacao;
    double area;
    double pib;
    int nPTuristico;
    double dPopulacional;
    double pPerCapita;
    double superPoder;
} Carta;

/* ── Protótipos ─────────────────────────────────────────── */
void lerCarta(Carta *c, int num);
void calcularAtributos(Carta *c);
void exibirResumo(Carta c1, Carta c2);
void realizarComparacoes(Carta c1, Carta c2);

/* ── Main ───────────────────────────────────────────────── */
int main(void) {
    setlocale(LC_ALL, "Portuguese");

    Carta carta1, carta2;

    printf("========================================\n");
    printf("|     Super Trunfo de Cidades BR       |\n");
    printf("========================================\n\n");

    // Cadastro das cartas
    lerCarta(&carta1, 1);
    printf("\n");
    lerCarta(&carta2, 2);

    // Cálculos automáticos
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Exibição e Comparação
    exibirResumo(carta1, carta2);
    realizarComparacoes(carta1, carta2);

    return 0;
}

/* ── Implementações ─────────────────────────────────────── */

void lerCarta(Carta *c, int num) {
    printf(">>> Cadastro da Carta %d\n", num);
    printf("Estado (A-H): ");
    scanf(" %c", &c->estado);

    printf("Código da carta (ex: A01): ");
    scanf(" %s", c->codigo);
    getchar(); // Limpar buffer

    printf("Nome da cidade: ");
    fgets(c->cidade, TAM_CIDADE, stdin);
    c->cidade[strcspn(c->cidade, "\n")] = '\0';

    printf("População: ");
    scanf(" %lu", &c->populacao);

    printf("Área (km²): ");
    scanf(" %lf", &c->area);

    printf("PIB (em bilhões de reais): ");
    scanf(" %lf", &c->pib);

    printf("Pontos turísticos: ");
    scanf(" %d", &c->nPTuristico);
}

void calcularAtributos(Carta *c) {
    // Cálculo dos atributos do Nível Aventureiro
    c->dPopulacional = (double)c->populacao / c->area;
    c->pPerCapita    = (c->pib * BILHAO) / (double)c->populacao;

    // Cálculo do Super Poder (Nível Mestre)
    // Soma: Pop + Área + PIB(real) + PT + PPC + (1/Densidade)
    c->superPoder = (double)c->populacao + c->area + (c->pib * BILHAO) + 
                    (double)c->nPTuristico + c->pPerCapita + (1.0 / c->dPopulacional);
}

void exibirResumo(Carta c1, Carta c2) {
    printf("\n========================================\n");
    printf("|           Resumo do Cadastro         |\n");
    printf("========================================\n");
    printf("Carta 1: %s (%s) | Poder: %.2f\n", c1.cidade, c1.codigo, c1.superPoder);
    printf("Carta 2: %s (%s) | Poder: %.2f\n", c2.cidade, c2.codigo, c2.superPoder);
}

void realizarComparacoes(Carta c1, Carta c2) {
    printf("\n========================================\n");
    printf("|       Resultado das Comparações      |\n");
    printf("|      (1 = Carta 1 vence | 0 = Carta 2 vence)     |\n");
    printf("========================================\n");

    // No Nível Mestre, comparamos os atributos e exibimos 1 ou 0
    printf("População: %d\n", c1.populacao > c2.populacao);
    printf("Área: %d\n", c1.area > c2.area);
    printf("PIB: %d\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: %d\n", c1.nPTuristico > c2.nPTuristico);
    
    // Densidade: Menor vence (regra especial)
    printf("Densidade Populacional: %d\n", c1.dPopulacional < c2.dPopulacional);
    
    printf("PIB per Capita: %d\n", c1.pPerCapita > c2.pPerCapita);
    printf("Super Poder: %d\n", c1.superPoder > c2.superPoder);
    printf("========================================\n");
}
#include <stdio.h>

int main() {
    // Variáveis da Carta 1
    char Estado1;
    char Codigo1[5];
    char Nome1[100];
    int Populacao1;
    float Area1, PIB1;
    int PontosTuristicos1;

    // Variáveis da Carta 2
    char Estado2;
    char Codigo2[5];
    char Nome2[100];
    int Populacao2;
    float Area2, PIB2;
    int PontosTuristicos2;

    printf("Bem-vindo ao Desafio Super Trunfo!\n");

    // --- Cadastro da Carta 1 ---
    printf("\n--- Cadastro da Carta 1 ---\n");
    printf("Estado: ");
    scanf(" %c", &Estado1); 
    printf("Código da Carta (ex: A01): ");
    scanf("%s", Codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", Nome1); // Lê nomes com espaços
    printf("População: ");
    scanf("%d", &Populacao1);
    printf("Área (km²): ");
    scanf("%f", &Area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &PIB1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &PontosTuristicos1);

    // --- Cadastro da Carta 2 ---
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Estado: ");
    scanf(" %c", &Estado2);
    printf("Código da Carta: ");
    scanf("%s", Codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", Nome2);
    printf("População: ");
    scanf("%d", &Populacao2);
    printf("Área (km²): ");
    scanf("%f", &Area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &PIB2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &PontosTuristicos2);

    // --- Exibição dos Dados ---
    printf("\n-----------------------------------\n");
    printf("Carta 1:\n");
    printf("Estado: %c\n", Estado1);
    printf("Código: %s\n", Codigo1);
    printf("Nome: %s\n", Nome1);
    printf("População: %d\n", Populacao1);
    printf("Área: %.2f km²\n", Area1);
    printf("PIB: %.2f bilhões de reais\n", PIB1);
    printf("Pontos Turísticos: %d\n", PontosTuristicos1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", Estado2);
    printf("Código: %s\n", Codigo2);
    printf("Nome: %s\n", Nome2);
    printf("População: %d\n", Populacao2);
    printf("Área: %.2f km²\n", Area2);
    printf("PIB: %.2f bilhões de reais\n", PIB2);
    printf("Pontos Turísticos: %d\n", PontosTuristicos2);

    return 0;
}
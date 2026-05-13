#include <stdio.h>

// Desafio Super Trunfo - Países
// Nível Mestre - Comparação de cartas 

int main() {

    // Carta 1
    char codigo1[4], nome1[50];
    int populacao1, ptsTuristicos1;
    float area1, pib1;
    float densidade1, pibPerCapita1, superPoder1;

    // Carta 2
    char codigo2[4], nome2[50];
    int populacao2, ptsTuristicos2;
    float area2, pib2;
    float densidade2, pibPerCapita2, superPoder2;

    printf("===== SUPER TRUNFO: PAISES =====\n");

    // Entrada da Carta 1
    printf("\nInsira os dados da Carta 1:\n");
    printf("Codigo da cidade: ");
    scanf("%s", codigo1);

    printf("Nome da cidade: ");
    scanf("%s", nome1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area (km2): ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &ptsTuristicos1);

    // Entrada da Carta 2
    printf("\nInsira os dados da Carta 2:\n");
    printf("Codigo da cidade: ");
    scanf("%s", codigo2);

    printf("Nome da cidade: ");
    scanf("%s", nome2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area (km2): ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &ptsTuristicos2);

    // Cálculos da Carta 1
    densidade1 = (float) populacao1 / area1;
    pibPerCapita1 = pib1 / (float) populacao1;
    superPoder1 = (float) populacao1 + area1 + pib1 + (float) ptsTuristicos1 + densidade1 + pibPerCapita1;

    // Cálculos da Carta 2
    densidade2 = (float) populacao2 / area2;
    pibPerCapita2 = pib2 / (float) populacao2;
    superPoder2 = (float) populacao2 + area2 + pib2 + (float) ptsTuristicos2 + densidade2 + pibPerCapita2;

    // Exibição dos dados da Carta 1
    printf("\n===== CARTA 1 =====\n");
    printf("Codigo: %s\n", codigo1);
    printf("Nome: %s\n", nome1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos Turisticos: %d\n", ptsTuristicos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per Capita: %.2f\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    // Exibição dos dados da Carta 2
    printf("\n===== CARTA 2 =====\n");
    printf("Codigo: %s\n", codigo2);
    printf("Nome: %s\n", nome2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos Turisticos: %d\n", ptsTuristicos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // Comparações
    printf("\n===== RESULTADO DAS Comparacoes =====\n");

    printf("Populacao: %s\n", (populacao1 > populacao2) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("Area: %s\n", (area1 > area2) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("PIB: %s\n", (pib1 > pib2) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("Pontos Turisticos: %s\n", (ptsTuristicos1 > ptsTuristicos2) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("Densidade Populacional: %s\n", (densidade1 < densidade2) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("PIB per Capita: %s\n", (pibPerCapita1 > pibPerCapita2) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("Super Poder: %s\n", (superPoder1 > superPoder2) ? "Carta 1 venceu" : "Carta 2 venceu");

    // Encerramento
    printf("\nObrigado por usar o Sistema de Cadastro e Comparacao de Cartas!\n");
    printf("Suas cartas foram registradas e comparadas, e o programa sera encerrado.\n");
    printf("Ate a proxima!\n");

    return 0;
}
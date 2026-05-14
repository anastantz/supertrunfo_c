#include <stdio.h>

/* Desafio Super Trunfo - Paises
* Tema 2 - Comparacao das Cartas
 * Atributo escolhido para comparacao: Populacao
 * Criterio: maior valor vence.
 *
 * Correcoes aplicadas em relacao a versao anterior:
 * - Adicionado campo "Estado" em ambas as cartas
 * - Nomes de cidade agora aceitam espacos (ex: "Rio de Janeiro")
 * - Comparacao reformulada para exibir atributo, valores e vencedor
 * - Tratado o caso de empate
 * - Removidas comparacoes multiplas (requisito: apenas um atributo) */

int main() {

     /* DECLARACAO DAS VARIAVEIS */
     
    /* Carta 1 */
    char estado1[3];       /* Sigla do estado: 2 chars + terminador nulo */
    char codigo1[4];       /* Codigo da carta: 3 chars + terminador nulo */
    char nome1[50];        /* Nome da cidade */
    int populacao1;
    int ptsTuristicos1;
    float area1;
    float pib1;
    float densidade1;      /* Calculado: populacao / area */
    float pibPerCapita1;   /* Calculado: pib / populacao */

    /* Carta 2 */
    char estado2[3];
    char codigo2[4];
    char nome2[50];
    int populacao2;
    int ptsTuristicos2;
    float area2;
    float pib2;
    float densidade2;
    float pibPerCapita2;

     /* ENTRADA DE DADOS - CARTA 1 */
     
    printf("===== SUPER TRUNFO: CIDADES =====\n");

    printf("\nInsira os dados da Carta 1:\n");

    printf("Estado (sigla): ");
    scanf("%2s", estado1);

    printf("Codigo da carta: ");
    scanf("%3s", codigo1);

    /* %[^\n] le a linha inteira, incluindo espacos.
     * O espaco antes de % descarta o '\n' residual do scanf anterior. */
    printf("Nome da cidade: ");
    scanf(" %49[^\n]", nome1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area (km2): ");
    scanf("%f", &area1);

    printf("PIB (bilhoes R$): ");
    scanf("%f", &pib1);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &ptsTuristicos1);

     /* ENTRADA DE DADOS - CARTA 2 */
     
    printf("\nInsira os dados da Carta 2:\n");

    printf("Estado (sigla): ");
    scanf("%2s", estado2);

    printf("Codigo da carta: ");
    scanf("%3s", codigo2);

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", nome2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area (km2): ");
    scanf("%f", &area2);

    printf("PIB (bilhoes R$): ");
    scanf("%f", &pib2);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &ptsTuristicos2);

     /* CALCULOS DERIVADOS */
     
    /* Cast explicito para float evita divisao inteira */
    densidade1    = (float) populacao1 / area1;
    pibPerCapita1 = pib1 / (float) populacao1;

    densidade2    = (float) populacao2 / area2;
    pibPerCapita2 = pib2 / (float) populacao2;

     /* EXIBICAO DOS DADOS DAS CARTAS */
     
    printf("\n===== CARTA 1 =====\n");
    printf("Estado: %s\n",                   estado1);
    printf("Codigo: %s\n",                   codigo1);
    printf("Nome: %s\n",                     nome1);
    printf("Populacao: %d habitantes\n",     populacao1);
    printf("Area: %.2f km2\n",               area1);
    printf("PIB: %.2f bilhoes R$\n",         pib1);
    printf("Pontos Turisticos: %d\n",        ptsTuristicos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per Capita: %.2f\n",         pibPerCapita1);

    printf("\n===== CARTA 2 =====\n");
    printf("Estado: %s\n",                   estado2);
    printf("Codigo: %s\n",                   codigo2);
    printf("Nome: %s\n",                     nome2);
    printf("Populacao: %d habitantes\n",     populacao2);
    printf("Area: %.2f km2\n",               area2);
    printf("PIB: %.2f bilhoes R$\n",         pib2);
    printf("Pontos Turisticos: %d\n",        ptsTuristicos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f\n",         pibPerCapita2);

     * COMPARACAO - ATRIBUTO ESCOLHIDO: POPULACAO
     *
     * Criterio: maior populacao vence.
     * Para densidade populacional, o criterio seria invertido
     * (menor valor vence), mas esse atributo nao foi escolhido aqui. */
     
    printf("\n===== COMPARACAO DE CARTAS =====\n");
    printf("Atributo: Populacao\n\n");

    printf("Carta 1 - %s (%s): %d habitantes\n", nome1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d habitantes\n", nome2, estado2, populacao2);

    printf("\nResultado: ");

    if (populacao1 > populacao2) {
        printf("Carta 1 (%s) venceu!\n", nome1);
    } else if (populacao2 > populacao1) {
        printf("Carta 2 (%s) venceu!\n", nome2);
    } else {
        /* Empate: ambas com populacao identica */
        printf("Empate! Ambas as cidades tem a mesma populacao.\n");
    }

     /* ENCERRAMENTO */
     
    printf("\n=================================\n");
    printf("Obrigado por usar o Super Trunfo!\n");

    return 0;
}
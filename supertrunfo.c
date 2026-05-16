#include <stdio.h>

/*
 * Projeto: Super Trunfo - Paises
 * Nivel: Aventureiro - Menu interativo com switch e comparacoes multiplas
 *
 * Novidades neste nivel:
 * - Menu interativo com switch para escolha do atributo
 * - Comparacao para todos os atributos numericos
 * - Regra invertida para Densidade Populacional (menor vence)
 * - Tratamento de opcao invalida com default no switch
 * - If-else aninhado dentro de cada case do switch
 */

int main() {

    /* =====================================================
     * DECLARACAO DAS VARIAVEIS
     * ===================================================== */

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

    /* Variavel para armazenar a escolha do menu */
    int opcao;

    /* =====================================================
     * ENTRADA DE DADOS - CARTA 1
     * ===================================================== */

    printf("===== SUPER TRUNFO: PAISES =====\n");
    printf("\nInsira os dados da Carta 1:\n");

    printf("Estado (sigla): ");
    scanf("%2s", estado1);

    printf("Codigo da carta: ");
    scanf("%3s", codigo1);

    /* %[^\n] le a linha inteira incluindo espacos.
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

    /* =====================================================
     * ENTRADA DE DADOS - CARTA 2
     * ===================================================== */

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

    /* =====================================================
     * CALCULOS DERIVADOS
     * ===================================================== */

    /* Cast explicito para float evita divisao inteira */
    densidade1    = (float) populacao1 / area1;
    pibPerCapita1 = pib1 / (float) populacao1;

    densidade2    = (float) populacao2 / area2;
    pibPerCapita2 = pib2 / (float) populacao2;

    /* =====================================================
     * EXIBICAO DOS DADOS DAS CARTAS
     * ===================================================== */

    printf("\n===== CARTA 1 =====\n");
    printf("Estado: %s\n",                            estado1);
    printf("Codigo: %s\n",                            codigo1);
    printf("Nome: %s\n",                              nome1);
    printf("Populacao: %d habitantes\n",              populacao1);
    printf("Area: %.2f km2\n",                        area1);
    printf("PIB: %.2f bilhoes R$\n",                  pib1);
    printf("Pontos Turisticos: %d\n",                 ptsTuristicos1);
    printf("Densidade Populacional: %.2f hab/km2\n",  densidade1);
    printf("PIB per Capita: %.2f\n",                  pibPerCapita1);

    printf("\n===== CARTA 2 =====\n");
    printf("Estado: %s\n",                            estado2);
    printf("Codigo: %s\n",                            codigo2);
    printf("Nome: %s\n",                              nome2);
    printf("Populacao: %d habitantes\n",              populacao2);
    printf("Area: %.2f km2\n",                        area2);
    printf("PIB: %.2f bilhoes R$\n",                  pib2);
    printf("Pontos Turisticos: %d\n",                 ptsTuristicos2);
    printf("Densidade Populacional: %.2f hab/km2\n",  densidade2);
    printf("PIB per Capita: %.2f\n",                  pibPerCapita2);

    /* =====================================================
     * MENU INTERATIVO - ESCOLHA DO ATRIBUTO
     * ===================================================== */

    printf("\n===== ESCOLHA O ATRIBUTO PARA COMPARACAO =====\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Numero de Pontos Turisticos\n");
    printf("5. Densidade Populacional (menor valor vence)\n");
    printf("6. PIB per Capita\n");
    printf("\nDigite o numero da opcao desejada: ");
    scanf("%d", &opcao);

    printf("\n===== RESULTADO DA COMPARACAO =====\n");

    /* =====================================================
     * SWITCH: SELECIONA O ATRIBUTO E EXECUTA A COMPARACAO
     *
     * Cada case exibe o cabecalho da comparacao e usa
     * if-else aninhado para determinar o vencedor.
     *
     * Regra geral: maior valor vence.
     * Excecao:     Densidade Populacional - menor valor vence.
     * ===================================================== */

    switch (opcao) {

        case 1: /* Populacao */
            printf("Atributo: Populacao\n\n");
            printf("Carta 1 - %s (%s): %d habitantes\n", nome1, estado1, populacao1);
            printf("Carta 2 - %s (%s): %d habitantes\n", nome2, estado2, populacao2);
            printf("\nResultado: ");

            /* If-else aninhado: primeiro verifica carta 1, depois carta 2, depois empate */
            if (populacao1 > populacao2) {
                printf("Carta 1 (%s) venceu!\n", nome1);
            } else if (populacao2 > populacao1) {
                printf("Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: /* Area */
            printf("Atributo: Area\n\n");
            printf("Carta 1 - %s (%s): %.2f km2\n", nome1, estado1, area1);
            printf("Carta 2 - %s (%s): %.2f km2\n", nome2, estado2, area2);
            printf("\nResultado: ");

            if (area1 > area2) {
                printf("Carta 1 (%s) venceu!\n", nome1);
            } else if (area2 > area1) {
                printf("Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: /* PIB */
            printf("Atributo: PIB\n\n");
            printf("Carta 1 - %s (%s): %.2f bilhoes R$\n", nome1, estado1, pib1);
            printf("Carta 2 - %s (%s): %.2f bilhoes R$\n", nome2, estado2, pib2);
            printf("\nResultado: ");

            if (pib1 > pib2) {
                printf("Carta 1 (%s) venceu!\n", nome1);
            } else if (pib2 > pib1) {
                printf("Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: /* Pontos Turisticos */
            printf("Atributo: Numero de Pontos Turisticos\n\n");
            printf("Carta 1 - %s (%s): %d pontos\n", nome1, estado1, ptsTuristicos1);
            printf("Carta 2 - %s (%s): %d pontos\n", nome2, estado2, ptsTuristicos2);
            printf("\nResultado: ");

            if (ptsTuristicos1 > ptsTuristicos2) {
                printf("Carta 1 (%s) venceu!\n", nome1);
            } else if (ptsTuristicos2 > ptsTuristicos1) {
                printf("Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: /* Densidade Populacional - REGRA INVERTIDA: menor vence */
            printf("Atributo: Densidade Populacional (menor valor vence)\n\n");
            printf("Carta 1 - %s (%s): %.2f hab/km2\n", nome1, estado1, densidade1);
            printf("Carta 2 - %s (%s): %.2f hab/km2\n", nome2, estado2, densidade2);
            printf("\nResultado: ");

            /* Regra invertida: if-else aninhado com sinal de comparacao trocado */
            if (densidade1 < densidade2) {
                printf("Carta 1 (%s) venceu!\n", nome1);
            } else if (densidade2 < densidade1) {
                printf("Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 6: /* PIB per Capita */
            printf("Atributo: PIB per Capita\n\n");
            printf("Carta 1 - %s (%s): %.2f\n", nome1, estado1, pibPerCapita1);
            printf("Carta 2 - %s (%s): %.2f\n", nome2, estado2, pibPerCapita2);
            printf("\nResultado: ");

            if (pibPerCapita1 > pibPerCapita2) {
                printf("Carta 1 (%s) venceu!\n", nome1);
            } else if (pibPerCapita2 > pibPerCapita1) {
                printf("Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            /* Opcao invalida: qualquer valor fora de 1 a 6 */
            printf("Opcao invalida! Escolha um numero entre 1 e 6.\n");
            printf("O programa sera encerrado. Execute novamente para tentar.\n");
            break;
    }

    /* =====================================================
     * ENCERRAMENTO
     * ===================================================== */

    printf("\n=================================\n");
    printf("Obrigado por usar o Super Trunfo!\n");

    return 0;
}
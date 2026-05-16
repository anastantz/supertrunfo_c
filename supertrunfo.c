        #include <stdio.h>

/*
 * Projeto: Super Trunfo - Paises
 * Nivel: Mestre - Comparacao com dois atributos, menu dinamico e operador ternario
 *
 * Novidades neste nivel:
 * - Jogador escolhe dois atributos diferentes para comparar
 * - Menu do segundo atributo omite a opcao ja escolhida (menu dinamico)
 * - Valores dos atributos sao somados; maior soma vence a rodada
 * - Operador ternario usado nas exibicoes de resultado individuais
 * - Tratamento de entradas invalidas em ambos os menus
 */

int main() {

    /*
     * DECLARACAO DAS VARIAVEIS
     */

    /* Carta 1 */
    char estado1[3];
    char codigo1[4];
    char nome1[50];
    int  populacao1;
    int  ptsTuristicos1;
    float area1;
    float pib1;
    float densidade1;      /* Calculado: populacao / area      */
    float pibPerCapita1;   /* Calculado: pib / populacao       */

    /* Carta 2 */
    char estado2[3];
    char codigo2[4];
    char nome2[50];
    int  populacao2;
    int  ptsTuristicos2;
    float area2;
    float pib2;
    float densidade2;
    float pibPerCapita2;

    /* Controle dos menus e comparacao */
    int opcao1;            /* Primeiro atributo escolhido      */
    int opcao2;            /* Segundo atributo escolhido       */

    /* Valores normalizados para soma: cada atributo extraido para float
     * permite somar grandezas diferentes numa unica variavel por carta. */
    float valorAtrib1Carta1, valorAtrib1Carta2;   /* Atributo 1 de cada carta */
    float valorAtrib2Carta1, valorAtrib2Carta2;   /* Atributo 2 de cada carta */
    float somaCartA1, somaCartA2;                  /* Soma dos dois atributos  */

    /* ENTRADA DE DADOS - CARTA 1 */

    printf("===== SUPER TRUNFO: PAISES =====\n");
    printf("\nInsira os dados da Carta 1:\n");

    printf("Estado (sigla): ");
    scanf("%2s", estado1);

    printf("Codigo da carta: ");
    scanf("%3s", codigo1);

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

    densidade1    = (float) populacao1 / area1;
    pibPerCapita1 = pib1 / (float) populacao1;

    densidade2    = (float) populacao2 / area2;
    pibPerCapita2 = pib2 / (float) populacao2;

    /* EXIBICAO DOS DADOS DAS CARTAS */

    printf("\n===== CARTA 1 =====\n");
    printf("Estado: %s\n",                           estado1);
    printf("Codigo: %s\n",                           codigo1);
    printf("Nome: %s\n",                             nome1);
    printf("Populacao: %d habitantes\n",             populacao1);
    printf("Area: %.2f km2\n",                       area1);
    printf("PIB: %.2f bilhoes R$\n",                 pib1);
    printf("Pontos Turisticos: %d\n",                ptsTuristicos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per Capita: %.2f\n",                 pibPerCapita1);

    printf("\n===== CARTA 2 =====\n");
    printf("Estado: %s\n",                           estado2);
    printf("Codigo: %s\n",                           codigo2);
    printf("Nome: %s\n",                             nome2);
    printf("Populacao: %d habitantes\n",             populacao2);
    printf("Area: %.2f km2\n",                       area2);
    printf("PIB: %.2f bilhoes R$\n",                 pib2);
    printf("Pontos Turisticos: %d\n",                ptsTuristicos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f\n",                 pibPerCapita2);

    /* MENU 1 - ESCOLHA DO PRIMEIRO ATRIBUTO */

    printf("\n===== ESCOLHA O PRIMEIRO ATRIBUTO =====\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Numero de Pontos Turisticos\n");
    printf("5. Densidade Populacional (menor valor vence)\n");
    printf("6. PIB per Capita\n");
    printf("\nDigite o numero da primeira opcao: ");
    scanf("%d", &opcao1);

    /* Valida a primeira escolha antes de continuar */
    if (opcao1 < 1 || opcao1 > 6) {
        printf("\nOpcao invalida! Escolha um numero entre 1 e 6.\n");
        printf("O programa sera encerrado. Execute novamente.\n");
        return 1; /* Encerra com codigo de erro */
    }

    /* MENU 2 - ESCOLHA DO SEGUNDO ATRIBUTO (DINAMICO)
     * O atributo ja escolhido no menu 1 nao aparece aqui.
     * O switch imprime todas as opcoes, pulando a escolhida.
     */

    printf("\n===== ESCOLHA O SEGUNDO ATRIBUTO =====\n");

    /* Cada printf so executa se o numero nao for o ja escolhido */
    if (opcao1 != 1) printf("1. Populacao\n");
    if (opcao1 != 2) printf("2. Area\n");
    if (opcao1 != 3) printf("3. PIB\n");
    if (opcao1 != 4) printf("4. Numero de Pontos Turisticos\n");
    if (opcao1 != 5) printf("5. Densidade Populacional (menor valor vence)\n");
    if (opcao1 != 6) printf("6. PIB per Capita\n");

    printf("\nDigite o numero da segunda opcao: ");
    scanf("%d", &opcao2);

    /* Valida: deve estar entre 1-6 e ser diferente da primeira escolha */
    if (opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1) {
        if (opcao2 == opcao1) {
            printf("\nVoce nao pode escolher o mesmo atributo duas vezes!\n");
        } else {
            printf("\nOpcao invalida! Escolha um numero entre 1 e 6.\n");
        }
        printf("O programa sera encerrado. Execute novamente.\n");
        return 1;
    }

    /* EXTRACAO DOS VALORES DO PRIMEIRO ATRIBUTO
     * O switch popula valorAtrib1Carta1 e valorAtrib1Carta2
     * com os valores correspondentes ao atributo escolhido.
     * Para densidade (regra invertida), o valor e negado:
     * assim a soma final funciona de forma uniforme,
     * pois menor densidade real = maior valor negado.
     */

    switch (opcao1) {
        case 1:
            valorAtrib1Carta1 = (float) populacao1;
            valorAtrib1Carta2 = (float) populacao2;
            break;
        case 2:
            valorAtrib1Carta1 = area1;
            valorAtrib1Carta2 = area2;
            break;
        case 3:
            valorAtrib1Carta1 = pib1;
            valorAtrib1Carta2 = pib2;
            break;
        case 4:
            valorAtrib1Carta1 = (float) ptsTuristicos1;
            valorAtrib1Carta2 = (float) ptsTuristicos2;
            break;
        case 5:
            /* Negacao: inverte o criterio para que maior soma = melhor carta */
            valorAtrib1Carta1 = -densidade1;
            valorAtrib1Carta2 = -densidade2;
            break;
        case 6:
            valorAtrib1Carta1 = pibPerCapita1;
            valorAtrib1Carta2 = pibPerCapita2;
            break;
        default:
            valorAtrib1Carta1 = 0;
            valorAtrib1Carta2 = 0;
            break;
    }

    /* EXTRACAO DOS VALORES DO SEGUNDO ATRIBUTO
     * Mesma logica do switch anterior, para opcao2.
     */

    switch (opcao2) {
        case 1:
            valorAtrib2Carta1 = (float) populacao1;
            valorAtrib2Carta2 = (float) populacao2;
            break;
        case 2:
            valorAtrib2Carta1 = area1;
            valorAtrib2Carta2 = area2;
            break;
        case 3:
            valorAtrib2Carta1 = pib1;
            valorAtrib2Carta2 = pib2;
            break;
        case 4:
            valorAtrib2Carta1 = (float) ptsTuristicos1;
            valorAtrib2Carta2 = (float) ptsTuristicos2;
            break;
        case 5:
            valorAtrib2Carta1 = -densidade1;
            valorAtrib2Carta2 = -densidade2;
            break;
        case 6:
            valorAtrib2Carta1 = pibPerCapita1;
            valorAtrib2Carta2 = pibPerCapita2;
            break;
        default:
            valorAtrib2Carta1 = 0;
            valorAtrib2Carta2 = 0;
            break;
    }

    /* CALCULO DAS SOMAS */

    somaCartA1 = valorAtrib1Carta1 + valorAtrib2Carta1;
    somaCartA2 = valorAtrib1Carta2 + valorAtrib2Carta2;

    /* EXIBICAO DO RESULTADO */

    printf("\n===== RESULTADO DA COMPARACAO =====\n\n");

    printf("Cartas em disputa: %s (%s) vs %s (%s)\n\n",
           nome1, estado1, nome2, estado2);

    /* --- Resultado do primeiro atributo com operador ternario --- */
    printf("--- Atributo 1 ---\n");

    switch (opcao1) {
        case 1:
            printf("Populacao\n");
            printf("  Carta 1 - %s: %d habitantes\n", nome1, populacao1);
            printf("  Carta 2 - %s: %d habitantes\n", nome2, populacao2);
            /* Operador ternario: exibe vencedor individual sem if-else verboso */
            printf("  Resultado parcial: %s\n\n",
                   (populacao1 > populacao2) ? nome1 :
                   (populacao2 > populacao1) ? nome2 : "Empate parcial");
            break;
        case 2:
            printf("Area\n");
            printf("  Carta 1 - %s: %.2f km2\n", nome1, area1);
            printf("  Carta 2 - %s: %.2f km2\n", nome2, area2);
            printf("  Resultado parcial: %s\n\n",
                   (area1 > area2) ? nome1 :
                   (area2 > area1) ? nome2 : "Empate parcial");
            break;
        case 3:
            printf("PIB\n");
            printf("  Carta 1 - %s: %.2f bilhoes R$\n", nome1, pib1);
            printf("  Carta 2 - %s: %.2f bilhoes R$\n", nome2, pib2);
            printf("  Resultado parcial: %s\n\n",
                   (pib1 > pib2) ? nome1 :
                   (pib2 > pib1) ? nome2 : "Empate parcial");
            break;
        case 4:
            printf("Numero de Pontos Turisticos\n");
            printf("  Carta 1 - %s: %d pontos\n", nome1, ptsTuristicos1);
            printf("  Carta 2 - %s: %d pontos\n", nome2, ptsTuristicos2);
            printf("  Resultado parcial: %s\n\n",
                   (ptsTuristicos1 > ptsTuristicos2) ? nome1 :
                   (ptsTuristicos2 > ptsTuristicos1) ? nome2 : "Empate parcial");
            break;
        case 5:
            printf("Densidade Populacional (menor vence)\n");
            printf("  Carta 1 - %s: %.2f hab/km2\n", nome1, densidade1);
            printf("  Carta 2 - %s: %.2f hab/km2\n", nome2, densidade2);
            printf("  Resultado parcial: %s\n\n",
                   (densidade1 < densidade2) ? nome1 :
                   (densidade2 < densidade1) ? nome2 : "Empate parcial");
            break;
        case 6:
            printf("PIB per Capita\n");
            printf("  Carta 1 - %s: %.2f\n", nome1, pibPerCapita1);
            printf("  Carta 2 - %s: %.2f\n", nome2, pibPerCapita2);
            printf("  Resultado parcial: %s\n\n",
                   (pibPerCapita1 > pibPerCapita2) ? nome1 :
                   (pibPerCapita2 > pibPerCapita1) ? nome2 : "Empate parcial");
            break;
    }

    /* --- Resultado do segundo atributo com operador ternario --- */
    printf("--- Atributo 2 ---\n");

    switch (opcao2) {
        case 1:
            printf("Populacao\n");
            printf("  Carta 1 - %s: %d habitantes\n", nome1, populacao1);
            printf("  Carta 2 - %s: %d habitantes\n", nome2, populacao2);
            printf("  Resultado parcial: %s\n\n",
                   (populacao1 > populacao2) ? nome1 :
                   (populacao2 > populacao1) ? nome2 : "Empate parcial");
            break;
        case 2:
            printf("Area\n");
            printf("  Carta 1 - %s: %.2f km2\n", nome1, area1);
            printf("  Carta 2 - %s: %.2f km2\n", nome2, area2);
            printf("  Resultado parcial: %s\n\n",
                   (area1 > area2) ? nome1 :
                   (area2 > area1) ? nome2 : "Empate parcial");
            break;
        case 3:
            printf("PIB\n");
            printf("  Carta 1 - %s: %.2f bilhoes R$\n", nome1, pib1);
            printf("  Carta 2 - %s: %.2f bilhoes R$\n", nome2, pib2);
            printf("  Resultado parcial: %s\n\n",
                   (pib1 > pib2) ? nome1 :
                   (pib2 > pib1) ? nome2 : "Empate parcial");
            break;
        case 4:
            printf("Numero de Pontos Turisticos\n");
            printf("  Carta 1 - %s: %d pontos\n", nome1, ptsTuristicos1);
            printf("  Carta 2 - %s: %d pontos\n", nome2, ptsTuristicos2);
            printf("  Resultado parcial: %s\n\n",
                   (ptsTuristicos1 > ptsTuristicos2) ? nome1 :
                   (ptsTuristicos2 > ptsTuristicos1) ? nome2 : "Empate parcial");
            break;
        case 5:
            printf("Densidade Populacional (menor vence)\n");
            printf("  Carta 1 - %s: %.2f hab/km2\n", nome1, densidade1);
            printf("  Carta 2 - %s: %.2f hab/km2\n", nome2, densidade2);
            printf("  Resultado parcial: %s\n\n",
                   (densidade1 < densidade2) ? nome1 :
                   (densidade2 < densidade1) ? nome2 : "Empate parcial");
            break;
        case 6:
            printf("PIB per Capita\n");
            printf("  Carta 1 - %s: %.2f\n", nome1, pibPerCapita1);
            printf("  Carta 2 - %s: %.2f\n", nome2, pibPerCapita2);
            printf("  Resultado parcial: %s\n\n",
                   (pibPerCapita1 > pibPerCapita2) ? nome1 :
                   (pibPerCapita2 > pibPerCapita1) ? nome2 : "Empate parcial");
            break;
    }

    /* --- Soma e resultado final --- */
    printf("--- Soma dos Atributos ---\n");
    printf("  %s: %.2f\n", nome1, somaCartA1);
    printf("  %s: %.2f\n", nome2, somaCartA2);

    printf("\n--- RESULTADO FINAL ---\n");

    if (somaCartA1 > somaCartA2) {
        printf("Carta 1 (%s) VENCEU A RODADA!\n", nome1);
    } else if (somaCartA2 > somaCartA1) {
        printf("Carta 2 (%s) VENCEU A RODADA!\n", nome2);
    } else {
        printf("EMPATE! As duas cartas somaram valores iguais.\n");
    }

    /* ENCERRAMENTO */
    printf("\n=================================\n");
    printf("Obrigado por usar o Super Trunfo!\n");

    return 0;
}
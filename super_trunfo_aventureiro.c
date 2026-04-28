#include <stdio.h>	 // Incluindo a biblioteca de entrada e saída
#include <windows.h> // Biblioteca para configurar o console no Windows

int main() {
    // Força o console do Windows a exibir caracteres em UTF-8 (acentuação correta)
    SetConsoleOutputCP(65001);
    
    // ========================================================================
    // DADOS CADASTRADOS (Mantidos do nível Novato)
    // ========================================================================
    
    // --- CARTA 1 ---
    char estado1[50] = "GO";
    char codigo1[10] = "G01";
    char cidade1[50] = "Goiânia";
    int populacao1 = 1500000;
    float area1 = 728.84;
    float pib1 = 75.8; // Valor em bilhões
    int pontosTuristicos1 = 70;
    
    float densidade1 = (float)populacao1 / area1;
    float pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;

    // --- CARTA 2 ---
    char estado2[50] = "GO";
    char codigo2[10] = "M01";
    char cidade2[50] = "Morrinhos";
    int populacao2 = 65000;
    float area2 = 2846.29;
    float pib2 = 2.3; // Valor em bilhões
    int pontosTuristicos2 = 10;
    
    float densidade2 = (float)populacao2 / area2;
    float pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    // ========================================================================
    // MENU INTERATIVO
    // ========================================================================
    
    int opcao;

    printf("=======================================\n");
    printf("         SUPER TRUNFO - GOIÁS          \n");
    printf("=======================================\n");
    printf("Escolha o atributo para a batalha:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("=======================================\n");
    printf("Digite o número da sua escolha: ");
    
    // Lê a escolha do jogador
    scanf("%d", &opcao);
    
    printf("\n=======================================\n");
    printf("          RESULTADO DO DUELO           \n");
    printf("=======================================\n\n");

    // ========================================================================
    // LÓGICA DE COMPARAÇÃO COM SWITCH E IF-ELSE
    // ========================================================================

    switch (opcao) {
        case 1: // POPULAÇÃO
            printf("Atributo Escolhido: População\n");
            printf("Carta 1 (%s): %d habitantes\n", cidade1, populacao1);
            printf("Carta 2 (%s): %d habitantes\n", cidade2, populacao2);
            
            if (populacao1 > populacao2) {
                printf("\n>>> VENCEDOR: Carta 1 (%s)! <<<\n", cidade1);
            } else if (populacao2 > populacao1) {
                printf("\n>>> VENCEDOR: Carta 2 (%s)! <<<\n", cidade2);
            } else {
                printf("\n>>> RESULTADO: Empate! <<<\n");
            }
            break;

        case 2: // ÁREA
            printf("Atributo Escolhido: Área\n");
            printf("Carta 1 (%s): %.2f km²\n", cidade1, area1);
            printf("Carta 2 (%s): %.2f km²\n", cidade2, area2);
            
            if (area1 > area2) {
                printf("\n>>> VENCEDOR: Carta 1 (%s)! <<<\n", cidade1);
            } else if (area2 > area1) {
                printf("\n>>> VENCEDOR: Carta 2 (%s)! <<<\n", cidade2);
            } else {
                printf("\n>>> RESULTADO: Empate! <<<\n");
            }
            break;

        case 3: // PIB
            printf("Atributo Escolhido: PIB\n");
            printf("Carta 1 (%s): %.2f bilhões\n", cidade1, pib1);
            printf("Carta 2 (%s): %.2f bilhões\n", cidade2, pib2);
            
            if (pib1 > pib2) {
                printf("\n>>> VENCEDOR: Carta 1 (%s)! <<<\n", cidade1);
            } else if (pib2 > pib1) {
                printf("\n>>> VENCEDOR: Carta 2 (%s)! <<<\n", cidade2);
            } else {
                printf("\n>>> RESULTADO: Empate! <<<\n");
            }
            break;

        case 4: // PONTOS TURÍSTICOS
            printf("Atributo Escolhido: Pontos Turísticos\n");
            printf("Carta 1 (%s): %d\n", cidade1, pontosTuristicos1);
            printf("Carta 2 (%s): %d\n", cidade2, pontosTuristicos2);
            
            if (pontosTuristicos1 > pontosTuristicos2) {
                printf("\n>>> VENCEDOR: Carta 1 (%s)! <<<\n", cidade1);
            } else if (pontosTuristicos2 > pontosTuristicos1) {
                printf("\n>>> VENCEDOR: Carta 2 (%s)! <<<\n", cidade2);
            } else {
                printf("\n>>> RESULTADO: Empate! <<<\n");
            }
            break;

        case 5: // DENSIDADE DEMOGRÁFICA (Regra Invertida)
            printf("Atributo Escolhido: Densidade Demográfica (Vence o MENOR valor)\n");
            printf("Carta 1 (%s): %.2f hab/km²\n", cidade1, densidade1);
            printf("Carta 2 (%s): %.2f hab/km²\n", cidade2, densidade2);
            
            // Atenção à lógica invertida: o sinal de "menor que" (<) determina o vencedor
            if (densidade1 < densidade2) {
                printf("\n>>> VENCEDOR: Carta 1 (%s)! <<<\n", cidade1);
            } else if (densidade2 < densidade1) {
                printf("\n>>> VENCEDOR: Carta 2 (%s)! <<<\n", cidade2);
            } else {
                printf("\n>>> RESULTADO: Empate! <<<\n");
            }
            break;

        default: // TRATAMENTO DE ENTRADA INVÁLIDA (Segurança/Usabilidade)
            printf("Erro: Opção inválida!\n");
            printf("Por favor, reinicie o programa e escolha um número de 1 a 5.\n");
            break;
    }

    return 0;
}

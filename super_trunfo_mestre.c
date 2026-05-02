#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() {
    // Força o console do Windows a exibir caracteres em UTF-8
    SetConsoleOutputCP(65001);
    
    // ========================================================================
    // DADOS CADASTRADOS
    // ========================================================================
    
    // --- CARTA 1 ---
    char estado1[50] = "GO";
    char codigo1[10] = "G01";
    char cidade1[50] = "Goiânia";
    int populacao1 = 1500000;
    float area1 = 728.84;
    float pib1 = 75.8;
    int pontosTuristicos1 = 70;
    float densidade1 = (float)populacao1 / area1;
    
    // --- CARTA 2 ---
    char estado2[50] = "GO";
    char codigo2[10] = "M01";
    char cidade2[50] = "Morrinhos";
    int populacao2 = 65000;
    float area2 = 2846.29;
    float pib2 = 2.3;
    int pontosTuristicos2 = 10;
    float densidade2 = (float)populacao2 / area2;

    // ========================================================================
    // VARIÁVEIS DE CONTROLE E ESCOLHA
    // ========================================================================
    
    int op1, op2;
    float val1_carta1, val1_carta2;
    float val2_carta1, val2_carta2;
    char nome_attr1[50], nome_attr2[50];

    // ========================================================================
    // MENU INTERATIVO 1
    // ========================================================================
    
    printf("=======================================\n");
    printf("      SUPER TRUNFO - DESAFIO MESTRE    \n");
    printf("=======================================\n");
    printf("Escolha o 1º atributo para a batalha:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("=======================================\n");
    printf("Digite o número da sua escolha: ");
    scanf("%d", &op1);

    // Validação inicial do primeiro menu
    if (op1 < 1 || op1 > 5) {
        printf("\nErro: Opção inválida! Reinicie o jogo.\n");
        return 1;
    }

    // ========================================================================
    // MENU INTERATIVO 2 (DINÂMICO COM SWITCH)
    // ========================================================================
    
    printf("\nExcelente! Agora escolha o 2º atributo (diferente do 1º):\n");
    
    // O switch exibe apenas as opções que NÃO foram escolhidas no op1
    switch (op1) {
        case 1:
            printf("2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
            break;
        case 2:
            printf("1 - População\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
            break;
        case 3:
            printf("1 - População\n2 - Área\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
            break;
        case 4:
            printf("1 - População\n2 - Área\n3 - PIB\n5 - Densidade Demográfica\n");
            break;
        case 5:
            printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n");
            break;
        default:
            printf("Erro inesperado.\n");
            return 1;
    }
    
    printf("=======================================\n");
    printf("Digite o número da sua 2ª escolha: ");
    scanf("%d", &op2);

    // Validação de entrada inválida ou repetida
    if (op2 < 1 || op2 > 5 || op1 == op2) {
        printf("\nErro: Opção inválida ou atributo já escolhido! Reinicie o jogo.\n");
        return 1;
    }

    // ========================================================================
    // ATRIBUIÇÃO DE VALORES ESCOLHIDOS (EXTRAÇÃO)
    // ========================================================================
    
    // Switch para pegar os dados do 1º atributo
    switch(op1) {
        case 1: val1_carta1 = (float)populacao1; val1_carta2 = (float)populacao2; strcpy(nome_attr1, "População"); break;
        case 2: val1_carta1 = area1; val1_carta2 = area2; strcpy(nome_attr1, "Área"); break;
        case 3: val1_carta1 = pib1; val1_carta2 = pib2; strcpy(nome_attr1, "PIB"); break;
        case 4: val1_carta1 = (float)pontosTuristicos1; val1_carta2 = (float)pontosTuristicos2; strcpy(nome_attr1, "Pontos Turísticos"); break;
        case 5: val1_carta1 = densidade1; val1_carta2 = densidade2; strcpy(nome_attr1, "Densidade Demográfica"); break;
    }

    // Switch para pegar os dados do 2º atributo
    switch(op2) {
        case 1: val2_carta1 = (float)populacao1; val2_carta2 = (float)populacao2; strcpy(nome_attr2, "População"); break;
        case 2: val2_carta1 = area1; val2_carta2 = area2; strcpy(nome_attr2, "Área"); break;
        case 3: val2_carta1 = pib1; val2_carta2 = pib2; strcpy(nome_attr2, "PIB"); break;
        case 4: val2_carta1 = (float)pontosTuristicos1; val2_carta2 = (float)pontosTuristicos2; strcpy(nome_attr2, "Pontos Turísticos"); break;
        case 5: val2_carta1 = densidade1; val2_carta2 = densidade2; strcpy(nome_attr2, "Densidade Demográfica"); break;
    }

    // ========================================================================
    // SOMA DOS ATRIBUTOS
    // ========================================================================
    
    float somaCarta1 = val1_carta1 + val2_carta1;
    float somaCarta2 = val1_carta2 + val2_carta2;

    // ========================================================================
    // EXIBIÇÃO CLARA DOS RESULTADOS E LÓGICA DE COMPARAÇÃO (TERNÁRIO)
    // ========================================================================
    
    printf("\n=======================================\n");
    printf("             RESULTADO FINAL           \n");
    printf("=======================================\n");

    printf("\n>>> CARTA 1 (%s) vs CARTA 2 (%s) <<<\n\n", cidade1, cidade2);

    // Comparação do 1º Atributo (Tratando a regra invertida da densidade com ternário)
    printf("1º Atributo: %s\n", nome_attr1);
    printf("Carta 1: %.2f | Carta 2: %.2f\n", val1_carta1, val1_carta2);
    
    int vence_attr1;
    if (op1 == 5) {
        vence_attr1 = (val1_carta1 < val1_carta2) ? 1 : (val1_carta2 < val1_carta1) ? 2 : 0; // Vence o menor
    } else {
        vence_attr1 = (val1_carta1 > val1_carta2) ? 1 : (val1_carta2 > val1_carta1) ? 2 : 0; // Vence o maior
    }
    
    printf("Vencedor no 1º atributo: %s\n\n", (vence_attr1 == 1) ? cidade1 : (vence_attr1 == 2) ? cidade2 : "Empate");

    // Comparação do 2º Atributo
    printf("2º Atributo: %s\n", nome_attr2);
    printf("Carta 1: %.2f | Carta 2: %.2f\n", val2_carta1, val2_carta2);
    
    int vence_attr2;
    if (op2 == 5) {
        vence_attr2 = (val2_carta1 < val2_carta2) ? 1 : (val2_carta2 < val2_carta1) ? 2 : 0; // Vence o menor
    } else {
        vence_attr2 = (val2_carta1 > val2_carta2) ? 1 : (val2_carta2 > val2_carta1) ? 2 : 0; // Vence o maior
    }
    
    printf("Vencedor no 2º atributo: %s\n\n", (vence_attr2 == 1) ? cidade1 : (vence_attr2 == 2) ? cidade2 : "Empate");

    // Comparação da Soma
    printf("---------------------------------------\n");
    printf("SOMA DOS ATRIBUTOS (%s + %s):\n", nome_attr1, nome_attr2);
    printf("Soma Carta 1 (%s): %.2f\n", cidade1, somaCarta1);
    printf("Soma Carta 2 (%s): %.2f\n", cidade2, somaCarta2);

    // Determina o vencedor final usando operador ternário aninhado
    int vencedor_final = (somaCarta1 > somaCarta2) ? 1 : (somaCarta2 > somaCarta1) ? 2 : 0;

    printf("\n=======================================\n");
    if (vencedor_final == 1) {
        printf("🏆 GRANDE CAMPEÃO: Carta 1 (%s)!\n", cidade1);
    } else if (vencedor_final == 2) {
        printf("🏆 GRANDE CAMPEÃO: Carta 2 (%s)!\n", cidade2);
    } else {
        printf("🤝 RESULTADO FINAL: Empate!\n");
    }
    printf("=======================================\n");

    return 0;
}

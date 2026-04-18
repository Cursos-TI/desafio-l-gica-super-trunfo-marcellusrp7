#include <stdio.h>
#include <windows.h> // Incluindo a biblioteca do Windows novamente

int main() {
    // Força o console do Windows a exibir caracteres em UTF-8
    SetConsoleOutputCP(65001);
    
    // ========================================================================
    // CADASTRO DA CARTA 1
    // ========================================================================
    char estado1[50] = "GO";
    char codigo1[10] = "G01";
    char cidade1[50] = "Goiânia";
    int populacao1 = 1500000;
    float area1 = 728.84;
    float pib1 = 75.8; // Valor em bilhões
    int pontosTuristicos1 = 70;
    
    // Cálculos da Carta 1
    // Cast (float) usado para garantir que a divisão seja exata
    float densidade1 = (float)populacao1 / area1;
    // Multiplicando por 1 bilhão para calcular o valor real por habitante
    float pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;

    // ========================================================================
    // CADASTRO DA CARTA 2
    // ========================================================================
    char estado2[50] = "GO";
    char codigo2[10] = "M01";
    char cidade2[50] = "Morrinhos";
    int populacao2 = 65000;
    float area2 = 2846.29;
    float pib2 = 2.3; // Valor em bilhões
    int pontosTuristicos2 = 10;
    
    // Cálculos da Carta 2
    float densidade2 = (float)populacao2 / area2;
    float pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    // ========================================================================
    // LÓGICA DE COMPARAÇÃO (ATRIBUTO ESCOLHIDO: POPULAÇÃO)
    // ========================================================================
    
    printf("Comparação de cartas (Atributo: População):\n\n");
    
    // Exibindo os dados das cartas conforme o formato exigido no desafio
    printf("Carta 1 - %s (%s): %d\n", cidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d\n", cidade2, estado2, populacao2);
    
    // Estrutura de decisão if e if-else para determinar o vencedor
    // Regra da População: a carta com o MAIOR valor vence.
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Houve um empate!\n");
    }

    /* NOTA SOBRE DENSIDADE POPULACIONAL (Como exigido no enunciado):
    Se o atributo escolhido fosse Densidade Populacional, a lógica 
    seria invertida, pois o MENOR valor vence. Exemplo:
    
    if (densidade1 < densidade2) {
        printf("Resultado: Carta 1 venceu!\n");
    } else ...
    */

    return 0;
}

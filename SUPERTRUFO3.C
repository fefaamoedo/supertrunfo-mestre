#include <stdio.h>

typedef struct {
    char codigo[4];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos;
    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

static float calcula_super_poder(const Carta *c) {
    float dens_inv = (c->densidade != 0.0f) ? (1.0f / c->densidade) : 0.0f;
    return (float)c->populacao + c->area + c->pib + (float)c->pontos + c->pib_per_capita + dens_inv;
}

int main(void) {
    Carta c1, c2;

    printf("Cadastro da Carta 1\n");
    printf("Codigo (ex: A01): ");
    scanf("%3s", c1.codigo);
    printf("Populacao (unsigned long int): ");
    scanf("%lu", &c1.populacao);
    printf("Area: ");
    scanf("%f", &c1.area);
    printf("PIB: ");
    scanf("%f", &c1.pib);
    printf("Pontos turisticos: ");
    scanf("%d", &c1.pontos);

    printf("\nCadastro da Carta 2\n");
    printf("Codigo (ex: B02): ");
    scanf("%3s", c2.codigo);
    printf("Populacao (unsigned long int): ");
    scanf("%lu", &c2.populacao);
    printf("Area: ");
    scanf("%f", &c2.area);
    printf("PIB: ");
    scanf("%f", &c2.pib);
    printf("Pontos turisticos: ");
    scanf("%d", &c2.pontos);

    c1.densidade = (c1.area != 0.0f) ? ((float)c1.populacao / c1.area) : 0.0f;
    c2.densidade = (c2.area != 0.0f) ? ((float)c2.populacao / c2.area) : 0.0f;

    c1.pib_per_capita = (c1.populacao != 0ul) ? (c1.pib / (float)c1.populacao) : 0.0f;
    c2.pib_per_capita = (c2.populacao != 0ul) ? (c2.pib / (float)c2.populacao) : 0.0f;

    c1.super_poder = calcula_super_poder(&c1);
    c2.super_poder = calcula_super_poder(&c2);

    int r_populacao = (c1.populacao > c2.populacao) ? 1 : 0;
    int r_area = (c1.area > c2.area) ? 1 : 0;
    int r_pib = (c1.pib > c2.pib) ? 1 : 0;
    int r_pontos = (c1.pontos > c2.pontos) ? 1 : 0;
    int r_densidade = (c1.densidade < c2.densidade) ? 1 : 0;
    int r_pibpc = (c1.pib_per_capita > c2.pib_per_capita) ? 1 : 0;
    int r_super = (c1.super_poder > c2.super_poder) ? 1 : 0;

    printf("\n=== CARTA 1 (%s) ===\n", c1.codigo);
    printf("Populacao: %lu\n", c1.populacao);
    printf("Area: %.2f\n", c1.area);
    printf("PIB: %.2f\n", c1.pib);
    printf("Pontos turisticos: %d\n", c1.pontos);
    printf("Densidade: %.6f\n", c1.densidade);
    printf("PIB per Capita: %.6f\n", c1.pib_per_capita);
    printf("Super Poder: %.6f\n", c1.super_poder);

    printf("\n=== CARTA 2 (%s) ===\n", c2.codigo);
    printf("Populacao: %lu\n", c2.populacao);
    printf("Area: %.2f\n", c2.area);
    printf("PIB: %.2f\n", c2.pib);
    printf("Pontos turisticos: %d\n", c2.pontos);
    printf("Densidade: %.6f\n", c2.densidade);
    printf("PIB per Capita: %.6f\n", c2.pib_per_capita);
    printf("Super Poder: %.6f\n", c2.super_poder);

    printf("\n=== COMPARACAO ===\n");
    printf("Populacao: %d\n", r_populacao);
    printf("Area: %d\n", r_area);
    printf("PIB: %d\n", r_pib);
    printf("Pontos turisticos: %d\n", r_pontos);
    printf("Densidade (menor vence): %d\n", r_densidade);
    printf("PIB per Capita: %d\n", r_pibpc);
    printf("Super Poder: %d\n", r_super);

    return 0;
}

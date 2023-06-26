#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRICAO 100
#define MAX_MARCA 50
#define MAX_SITE 100
#define MAX_TELEFONE 20

//Declarar variáveis

typedef struct {
    char descricao[MAX_DESCRICAO];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    char marca[MAX_MARCA];
    char site[MAX_SITE];
    char telefone[MAX_TELEFONE];
    char uf[3];
} Produto;

//Opções do Menu

listarTodasAsMarcas(Produto* produtos, int numProdutos) {
    printf("\n--- Marcas Registradas ---\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("%s\n", produtos[i].marca);
        printf("-------------------------\n");
    }   
}

listarTodosOsProdutos(Produto* produtos, int numProdutos) {
    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto: %s\n", produtos[i].descricao);
        printf("------------------------------\n");
    }
}

listarProdutosPorEstado(Produto* produtos, int numProdutos, char estado[3]) {
    printf("\n--- Produtos no Estado %s ---\n", estado);
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].uf, estado) == 0) {
            printf("Produto: %s\n", produtos[i].descricao);
            printf("------------------------------\n");
        }
    }
}

listarProdutosPorMarca(Produto* produtos, int numProdutos, char marca[MAX_MARCA]) {
    printf("\n--- Produtos da Marca %s ---\n", marca);
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].marca, marca) == 0) {
            printf("Produto: %s\n", produtos[i].descricao);
            printf("------------------------------\n");
        }
    }
}

encontrarProdutoMaisCaro(Produto* produtos, int numProdutos) {
    float maiorValor = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda > maiorValor) {
            maiorValor = produtos[i].valorVenda;
        }
    }
    
    printf("\n--- Estado(s) com Produto Mais Caro ---\n");
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda == maiorValor) {
            printf("%s\n", produtos[i].uf);
        }
    }
    printf("--------------------------------------\n");
}

encontrarFabricanteMaisBarato(Produto* produtos, int numProdutos) {
    float menorValor = produtos[0].valorVenda;
    for (int i = 1; i < numProdutos; i++) {
        if (produtos[i].valorVenda < menorValor) {
            menorValor = produtos[i].valorVenda;
        }
    }
    
    printf("\n--- Fabricante(s) com Produto Mais Barato ---\n");
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda == menorValor) {
            printf("%s\n", produtos[i].marca);
        }
    }
    printf("--------------------------------------------\n");
}

ordenarProdutosPorValor(Produto* produtos, int numProdutos) {
    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorVenda > produtos[j + 1].valorVenda) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
    
    printf("\n--- Produtos em Ordem Crescente de Valor ---\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto: %s\n", produtos[i].descricao);
        printf("Valor de Venda: R$%.2f\n", produtos[i].valorVenda);
        printf("--------------------------------------\n");
    }
}

ordenarProdutosPorLucro(Produto* produtos, int numProdutos) {
    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorLucro > produtos[j + 1].valorLucro) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
    
    printf("\n--- Produtos em Ordem Crescente de Valor do Lucro ---\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto: %s\n", produtos[i].descricao);
        printf("Valor do Lucro: R$%.2f\n", produtos[i].valorLucro);
        printf("-------------------------------------------\n");
    }
}


//Armazenar as informações

int main() {
    int opcao, numProdutos;
    printf("Informe o numero de produtos: ");
    scanf("%d", &numProdutos);
    Produto* produtos = (Produto*)malloc(numProdutos * sizeof(Produto));
    
    printf("\n--- Cadastro de Produtos ---\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Descricao: ");
        scanf(" %[^\n]s", produtos[i].descricao);
        printf("Peso: ");
        scanf("%f", &produtos[i].peso);
        printf("Valor de Compra: ");
        scanf("%f", &produtos[i].valorCompra);
        printf("Valor de Venda: ");
        scanf("%f", &produtos[i].valorVenda);
        produtos[i].valorLucro = produtos[i].valorVenda - produtos[i].valorCompra;
        produtos[i].percentualLucro = (produtos[i].valorLucro / produtos[i].valorCompra) * 100;
        printf("Marca: ");
        scanf(" %[^\n]s", produtos[i].marca);
        printf("Site: ");
        scanf(" %[^\n]s", produtos[i].site);
        printf("Telefone: ");
        scanf(" %[^\n]s", produtos[i].telefone);
        printf("UF: ");
        scanf(" %[^\n]s", produtos[i].uf);
    }
    
    printf("\n--- Menu de Relatorios ---\n");
    printf("1. Listar todas as marcas\n");
    printf("2. Listar todos os produtos\n");
    printf("3. Listar os produtos de um determinado estado\n");
    printf("4. Listar os produtos de uma determinada marca\n");
    printf("5. Apresentar o(s) estado(s) onde esta registrado o produto mais caro\n");
    printf("6. Apresentar o(s) fabricante(s) onde esta registrado o produto mais barato\n");
    printf("7. Listar todos os produtos em ordem crescente de valor\n");
    printf("8. Listar todos os produtos em ordem crescente de valor do lucro\n");
    printf("0. Sair\n");
    
    do {
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                listarTodasAsMarcas(produtos, numProdutos);
                break;
            case 2:
                listarTodosOsProdutos(produtos, numProdutos);
                break;
            case 3:
                printf("Informe o estado: ");
                char estado[3];
                scanf(" %[^\n]s", estado);
                listarProdutosPorEstado(produtos, numProdutos, estado);
                break;
            case 4:
                printf("Informe a marca: ");
                char marca[MAX_MARCA];
                scanf(" %[^\n]s", marca);
                listarProdutosPorMarca(produtos, numProdutos, marca);
                break;
            case 5:
                encontrarProdutoMaisCaro(produtos, numProdutos);
                break;
            case 6:
                encontrarFabricanteMaisBarato(produtos, numProdutos);
                break;
            case 7:
                ordenarProdutosPorValor(produtos, numProdutos);
                break;
            case 8:
                ordenarProdutosPorLucro(produtos, numProdutos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("opcao inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
    
    free(produtos);
    return 0;
}

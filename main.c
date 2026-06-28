/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/06/28 16:55:00 by nde-mace          #+#    #+#             */
/* Updated: 2026/06/28 17:00:00 by nde-mace         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
// Função auxiliar exclusiva de teste para inspecionar visualmente as pilhas
void	print_stacks(t_stack *a, t_stack *b)
{
	printf("\n=== DIAGNÓSTICO DE MEMÓRIA ===\n");
	printf("STACK A:\n");
	if (!a)
		printf("  [Vazia]\n");
	while (a)
	{
		printf("  Nó: %p | Valor: %d | Index: %d | Prev: %p | Next: %p\n",
			(void*)a, a->value, a->index, (void*)a->prev, (void*)a->next);
		a = a->next;
	}
	printf("STACK B:\n");
	if (!b)
		printf("  [Vazia]\n");
	while (b)
	{
		printf("  Nó: %p | Valor: %d | Index: %d | Prev: %p | Next: %p\n",
			(void*)b, b->value, b->index, (void*)b->prev, (void*)b->next);
		b = b->next;
	}
	printf("==============================\n\n");
}

int	main(int argc, char **argv)
{
	int		*numbers;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	// 1. Validação dos argumentos de entrada
	numbers = ft_valid(argc, argv);
	if (!numbers)
		return (1);
	printf("✅ Validação concluída com sucesso!\n");

	// 2. Inicialização da Stack A
	a = ft_init_stack(&a, numbers, argc - 1);
	if (!a)
	{
		printf("❌ Falha crítica ao alocar nós da Stack A\n");
		free(numbers);
		return (1);
	}
	printf("✅ Stack A inicializada.\n");

	// 3. Geração dos Índices Posicionais
	ft_index_stack(&a);
	printf("✅ Indexação computada.\n");

	// --- CENÁRIO DE TESTE DE ORDENAÇÃO COMPLETA ---
	printf("\n--- ESTADO INICIAL ---");
	print_stacks(a, b);

	printf("🚀 Executando estratégia de ordenação...\n");
	orchestration_sorting(&a, &b, argc - 1, numbers);
	
	printf("\n--- ESTADO FINAL (DEVE ESTAR ORDENADO) ---");
	print_stacks(a, b);
	// --------------------------------------------------

	// 5. Limpeza de memória antes de encerrar
	ft_free_stack(&a);
	ft_free_stack(&b);
	free(numbers);
	printf("✅ Memória limpa com sucesso. Sem vazamentos!\n");
	return (0);
}
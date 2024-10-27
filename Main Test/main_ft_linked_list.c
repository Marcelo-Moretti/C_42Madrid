/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:31:34 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/21 16:19:01 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// chat used: https://chatgpt.com/share/67166277-4c64-800c-b665-ad4c260b3c2c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Incluye tu archivo de cabecera con las declaraciones
#include "../libft.h"

// Función para imprimir el contenido de un nodo (asumiendo que el contenido es una cadena)
void print_content(void *content)
{
	if (content)
		printf("%s\n", (char *)content);
	else
		printf("(null)\n");
}

// Función para eliminar el contenido de un nodo
void del_content(void *content)
{
	free(content);
}

// Función para duplicar el contenido (usada en ft_lstmap)
void *duplicate_content(void *content)
{
	if (!content)
		return NULL;
	return strdup((char *)content);
}

int main()
{
	t_list *list = NULL;
	t_list *mapped_list = NULL;
	t_list *temp_node = NULL;
	int size;

	// 1. Probar ft_lstnew con contenido no nulo y nulo
	printf("Probando ft_lstnew:\n");
	t_list *node1 = ft_lstnew(strdup("Nodo 1"));
	t_list *node2 = ft_lstnew(strdup("Nodo 2"));
	t_list *node_null = ft_lstnew(NULL);

	if (!node1 || !node2)
	{
		printf("Error al crear nodos.\n");
		return 1;
	}

	// 2. Probar ft_lstadd_back
	printf("\nProbando ft_lstadd_back:\n");
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node_null);
	ft_lstiter(list, print_content);

	// 3. Probar ft_lstadd_front
	printf("\nProbando ft_lstadd_front:\n");
	t_list *node0 = ft_lstnew(strdup("Nodo 0"));
	ft_lstadd_front(&list, node0);
	ft_lstiter(list, print_content);

	// 4. Probar ft_lstsize
	size = ft_lstsize(list);
	printf("\nEl tamaño de la lista es: %d\n", size);

	// 5. Probar ft_lstlast
	printf("\nProbando ft_lstlast:\n");
	t_list *last = ft_lstlast(list);
	if (last)
		print_content(last->content);
	else
		printf("La lista está vacía.\n");

	// 6. Probar ft_lstiter
	printf("\nProbando ft_lstiter:\n");
	ft_lstiter(list, print_content);

	// 7. Probar ft_lstdelone (eliminando el segundo nodo)
	printf("\nProbando ft_lstdelone (eliminando el segundo nodo):\n");
	temp_node = list->next; // Segundo nodo
	list->next = temp_node->next; // Saltar el nodo a eliminar
	ft_lstdelone(temp_node, del_content);
	ft_lstiter(list, print_content);

	// 8. Probar ft_lstmap
	printf("\nProbando ft_lstmap:\n");
	mapped_list = ft_lstmap(list, duplicate_content, del_content);
	if (mapped_list)
		ft_lstiter(mapped_list, print_content);
	else
		printf("Error al mapear la lista.\n");

	// Modificar contenido de la lista original para verificar independencia
	printf("\nModificando contenido del primer nodo de la lista original:\n");
	free(list->content);
	list->content = strdup("Nodo 0 modificado");
	printf("Lista original:\n");
	ft_lstiter(list, print_content);
	printf("Lista mapeada (debe permanecer sin cambios):\n");
	ft_lstiter(mapped_list, print_content);

	// 9. Probar ft_lstclear
	printf("\nProbando ft_lstclear en la lista original:\n");
	ft_lstclear(&list, del_content);
	if (!list)
		printf("La lista original ha sido eliminada.\n");

	printf("\nProbando ft_lstclear en la lista mapeada:\n");
	ft_lstclear(&mapped_list, del_content);
	if (!mapped_list)
		printf("La lista mapeada ha sido eliminada.\n");

	// 10. Probar funciones con lista vacía
	printf("\nProbando funciones con lista vacía:\n");
	ft_lstiter(list, print_content);
	size = ft_lstsize(list);
	printf("El tamaño de la lista vacía es: %d\n", size);
	last = ft_lstlast(list);
	if (!last)
		printf("ft_lstlast devuelve NULL para lista vacía, como se esperaba.\n");

	// 11. Probar ft_lstadd_back con lista vacía
	printf("\nProbando ft_lstadd_back con lista vacía:\n");
	t_list *new_node = ft_lstnew(strdup("Nuevo nodo en lista vacía"));
	ft_lstadd_back(&list, new_node);
	ft_lstiter(list, print_content);

	// 12. Limpiar lista final
	ft_lstclear(&list, del_content);

	return 0;
}

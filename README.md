Este proyecto ha sido creado como parte del currículo de 42 por <login1> y <criredon>.

Push_swap

1. Descripción General

push_swap es un proyecto de algoritmos escrito en C. El programa recibe una lista de números enteros, los guarda en una pila llamada a y debe imprimir por pantalla una secuencia de instrucciones capaz de dejar esa pila ordenada de menor a mayor. Existe una segunda pila, b, que empieza vacía y sirve como espacio de trabajo.

Para ordenar la lista de números, se dispone únicamente de once operaciones concretas sobre dos pilas (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr). El proyecto también obliga a implementar cuatro estrategias distintas y elegir entre ellas durante la ejecución:

- una estrategia simple de clase O(n²);
- una estrategia intermedia de clase O(n√n);
- una estrategia compleja de clase O(n log n);
- una estrategia adaptativa que decide qué método utilizar según el grado de desorden inicial.

1.1. Objetivos y Requisitos del Proyecto

El programa debe recibir como argumentos una lista de enteros. El primer número recibido representa el elemento situado en la parte superior de la pila a.

Ejemplo:

./push_swap 8 3 5 1

representa inicialmente:

TOP
 ↓
[8]
[3]
[5]
[1]

La pila b comienza vacía.

El objetivo final es:

A                B

[1]              vacío
[3]
[5]
[8]

El programa no imprime los números ordenados. Imprime las operaciones necesarias para conseguir ese resultado.

Por ejemplo:

sa
pb
ra
pa

Cada operación debe aparecer en una línea independiente. Las once instrucciones autorizadas son:

| Tipo | Operación | Qué hace |
|------|-----------|----------|
| swap | sa | intercambia los dos primeros elementos de a |
| swap | sb | intercambia los dos primeros elementos de b |
| swap | ss | ejecuta sa y sb a la vez
| push | pa | mueve el primer elemento de b a la parte superior de a |
| push | pb | mueve el primer elemento de a a la parte superior de b |
| rotate | ra | mueve el primer elemento de a al final de a |
| rotate | rb | mueve el primer elemento de b al final de b |
| rotate | rr | ejecuta ra y rb a la vez |
| reverse rotate | rra | mueve el último elemento de a al principio |
| reverse rotate | rrb | mueve el último elemento de b al principio |
| reverse rotate | rrr | ejecuta rra y rrb a la vez |


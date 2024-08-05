
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h> //malloc, free, exit


typedef struct s_stack {

    int data; //Valor
    int index; //Índice
    int position; //Posición actual
    int ordered_position; //Posición en la que debería estar el nodo ordenado
    int cost_a; //Coste de mov en a
    int cost_b; //Coste de mov en b
    struct s_stack *next; //Puntero a la propia estructura

} t_stack; //Referencia

#endif
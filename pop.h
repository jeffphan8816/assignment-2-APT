/******************************************************************************
 ** Student name:     ...
 ** Student number:     ...
 ** Course:             Advanced Programming Techniques - S2 2018
 ******************************************************************************/

#ifndef POP_H
#define POP_H

#include "gene.h"
#include "invector.h"

#define MUTATE_RATE 5

typedef struct pop_node {
    Gene *gene;
    struct pop_node *next;
} Pop_node;

typedef struct pop_list {
    /* the head of the population list */
    Pop_node *head;
    /* the size of the population */
    int count;
    /* pointers to functions to perform
     * gene chromosome creation, mutation,
     * crossover and evaluation */
    CreateFn create_rand_chrom;
    MutateFn mutate_gene;
    CrossOverFn crossover_genes;
    EvalFn evaluate_fn;
} Pop_list;

/* Create and initialise the population list to a safe state.
 * Returns TRUE on success */
Boolean pop_init(Pop_list **);

/* Set the function pointers of a population list */
void pop_set_fns(Pop_list *p,CreateFn cf,MutateFn mf,CrossOverFn cof,EvalFn ef);

/* This function causes details of the fittest gene of the generation to
 * be printed out.
 * The function also prints out the number of the current generation.
 * This function must not be able to access any generation value outside
 * of the function. */
void pop_print_fittest(Pop_list *p,int);

void pop_create_gene(int popsize, Pop_list *poplist, int width);
void insertNode(Pop_list *p,Pop_node *node);
void printPopList(Pop_list *poplist);
void swapGene(Pop_node *a, Pop_node *b);
void calculateFitness(Pop_list *poplist,InVTable *invt);
Pop_node *create_Node(Pop_list *p,int numAllele);
Gene *rouletteSelection(Pop_list *poplist);
void bubbleSortPop(Pop_list *p);
void reproducePop(Pop_list *gen0,Pop_list *gen1);
Pop_node *cloneNode(Pop_node *node);
void popListFree(Pop_list *poplist);
void freeNode(Pop_node *node);
void pop_list_add(Pop_list *poplist,Gene *gene);
void swapPopList(Pop_list *p,Pop_list *p1);
void freeList(Pop_node *currentNode);
#endif

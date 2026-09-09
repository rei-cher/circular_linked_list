/**
 * Circularly linked list header
 */

#ifndef CIRCLE_H
#define CIRCLE_H

/**
 * @brief A function pointer to a user defined function for freeing data stored
 *        in the linked list.
 */
typedef void (*free_f)(void *);

/**
 * @brief A function pointer to a user defined function for comparing/sorting
 *        the data in the linked list.
 */
typedef int (*comp_f)(const void *, const void *);

/**
 * @brief A function pointer to a user defined function for iterating on
 *        the data stored in the linked list.
 */
typedef void (*iter_f)(void *);

typedef struct circle circle_t;

/**
 * @brief creates new circularly linked list
 *
 * @return a pointer to a linked list, else NULL
 * @param p_free a pointer to a user defined freeing function
 * @param p_comp a pointer to a user defined comparison function
 *
 */
circle_t * circle_create(free_f p_free, comp_f p_comp);

/**
 * @brief destroys a circularly linked list
 *
 * @param pp_circle the address of a circularly linked list to be destroyed
 */
void circle_destroy(circle_t ** pp_circle);

/**
 * @brief adds a void pointer to the circularly linked list
 *
 * @param p_circle a pointer to the circularly linked list
 * @param p_data a pointer to add to the circularly linked list
 *
 * @return 0 on successful addition, else 1
 * @note p_data should be added into the circularly linked list in sorted order
 */
int circle_add(circle_t * p_circle, void * p_data);

/**
 * @brief removes a void pointer from the circularly linked list
 *
 * @param p_circle a pointer to the circularly linked list
 * @param p_data a pointer to remove from the circularly linked list
 *
 * @return 0 on successful removal, else 1
 */
int circle_remove(circle_t * p_circle, void * p_data);

/**
 * @brief returns the number of elements in the circularly linked list
 *
 * @param p_circle a pointer to the circularly linked list
 *
 * @return number of elements in the circularly linked list
 * @note should return 0 for both invalid pointer and an empty list
 */
int circle_size(circle_t * p_circle);

/**
 * @brief checks the linked list for the provided data
 *
 * @param p_circle a pointer to the circularly linked list
 * @param p_data a pointer to the data to be searched for
 *
 * @return 0 on success, else 1
 */
int circle_contains(circle_t * p_circle, void * p_data);

/**
 * @brief performs user provided function on data in the circularly linked list
 *
 * @param p_circle a pointer to the circularly linked list
 * @param p_iter a pointer to a user defined function
 *
 * @return 0 on success, else 1
 */
int circle_iter(circle_t * p_circle, iter_f p_iter);

#endif

// end of circle.h

/*
** main.c for philosophe in /home/gazzol_j/rendu/PSU_2014_philo
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Mon Feb 23 09:36:12 2015 julien gazzola
** Last update Fri Feb 27 11:20:45 2015 Jordan Verove
*/

#include <stdio.h>
#include <stdlib.h>
#include "Philo.h"

int		total_rice = 350;
pthread_mutex_t	*mutex_tab;

void		print_philo_state(t_philo *philo)
{
  static int	i = 0;
  
  if (philo->left == 0 && philo->right == 0)
    printf("Philo : %d - state : sleep - rice : %d\n", philo->id, philo->rice);
  else if (philo->left == 1 && philo->right == 1)
    printf("Philo : %d - state : eat - rice : %d\n", philo->id, philo->rice);
  else
    printf("Philo : %d - state : think - rice : %d\n", philo->id, philo->rice);
  if (i == 6)
    {
      printf("\n");
      i = 0;
    }
  else
    i = i + 1;
}

void	*take_cs(t_philo *philo)
{
  if ((philo->id % 2) == 0 && philo->rice != 0)
    {
      if (pthread_mutex_trylock(&mutex_tab[philo->id % 7]) == 0)
	philo->left = 1;
      if (pthread_mutex_trylock(&mutex_tab[philo->id - 1]) == 0)
	philo->right = 1;
    }
  else if ((philo->id % 2) != 0 && philo->rice != 0)
    {
      if (pthread_mutex_trylock(&mutex_tab[philo->id - 1]) == 0)
	philo->right = 1;
      if (pthread_mutex_trylock(&mutex_tab[philo->id % 7]) == 0)
	philo->left = 1;
    }
}

void			unlock_mutex_tab(t_philo *philo)
{
  if (pthread_mutex_unlock(&mutex_tab[philo->id % 7]) == 0)
    philo->left = 0;
  if (pthread_mutex_unlock(&mutex_tab[philo->id - 1]) == 0)
    philo->right = 0;
  printf("UNLOCK philo[%d]--------------------------------------\n", philo->id);
}

void			eat(t_philo *philo)
{
  pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

  if (philo->left == 1 && philo->right == 1)
    {
      philo->state = TIRED;
      philo->rice -= 10;
      pthread_mutex_lock(&mutex);
      total_rice -= 10;
      //      printf("philo rice[%d] : %d\ntotal rice :%d\n", philo->id, philo->rice, total_rice);
      //unlock_mutex_tab(philo);
      pthread_mutex_unlock(&mutex);
    }
}

void			*philosopher(void *arg)
{
  t_philo		*philo;

  philo = arg;
  //  if (philo->rice == 0)
  //    printf("Philo : %d - state : sleep - rice : %d\n", philo->id, philo->rice);
  while (total_rice != 0)
    {
      if (philo->left == 0 && philo->right == 0 && philo->rice != 0)
	take_cs(philo);
      philo->state == HUNGRY;
      eat(philo);
      print_philo_state(philo);
      // printf("PHILO[%d]: __ left : %c ------- right : %c\n", philo->id, philo->left, philo->right);
      sleep(1);
      unlock_mutex_tab(philo);
    }
  return;
}

t_philo			**create_philo()
{
  t_philo		**philo;
  int			i;

  i = 0;
  if ((philo = malloc(sizeof(t_philo*) * 7)) == NULL)
    return (NULL);
  while (i != 7)
    {
      if ((philo[i] = malloc(sizeof(t_philo))) == NULL)
	return (NULL);
      philo[i]->id = (i + 1);
      philo[i]->rice = 50;
      philo[i]->state = HUNGRY;
      philo[i]->left = 0;
      philo[i]->right = 0;
      if (pthread_create(&(philo[i]->thread), NULL, philosopher, philo[i]))
	return (NULL);
      ++i;
    }
  i = 0;
  while (i != 7)
    if (pthread_join(philo[i++]->thread, NULL))
      return (NULL);
  return (philo);
}

pthread_mutex_t		*create_mutex_tab()
{
  pthread_mutex_t	*tab;
  int			i;

  i = 0;
  if ((tab = malloc(7 *sizeof(pthread_mutex_t))) == NULL)
    return (NULL);
  while (i != 7)
    {
      if (pthread_mutex_init(&tab[i], NULL))
	return (NULL);
      i = i + 1;
    }
  return (tab);
}

int			main()
{
  t_philo		**tab;
  int			i;

  i = 0;
  if ((mutex_tab = create_mutex_tab()) == NULL)
    return (0);
  if ((tab = create_philo()) == NULL)
    return (-1);
  return (0);
}

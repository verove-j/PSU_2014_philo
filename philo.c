/*
** philo.c for philo in /home/gazzol_j/rendu/PSU_2014_philo
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Fri Feb 27 14:31:46 2015 julien gazzola
** Last update Fri Feb 27 14:47:12 2015 julien gazzola
*/

#include <stdio.h>
#include <stdlib.h>
#include "Philo.h"

static void		print_philo_state(t_philo *philo)
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

static void		take_cs(t_philo *philo)
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

static void		unlock_mutex_tab(t_philo *philo)
{
  if (philo->left == 1)
    {
      philo->left = 0;
      pthread_mutex_unlock(&mutex_tab[philo->id % 7]);
    }
  if (philo->right == 1)
    {
      philo->right = 0;
      pthread_mutex_unlock(&mutex_tab[philo->id - 1]);
    }
}

static void		eat(t_philo *philo)
{
  pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

  if (philo->left == 1 && philo->right == 1)
    {
      philo->state = TIRED;
      philo->rice -= 10;
      pthread_mutex_lock(&mutex);
      total_rice -= 10;
      pthread_mutex_unlock(&mutex);
    }
}

void			*philosopher(void *arg)
{
  t_philo		*philo;

  philo = arg;
  while (total_rice != 0)
    {
      if (philo->state == HUNGRY && philo->rice != 0)
	take_cs(philo);
      philo->state = HUNGRY;
      eat(philo);
      print_philo_state(philo);
      sleep(1);
      unlock_mutex_tab(philo);
    }
  return;
}

/*
** main.c for philosophe in /home/gazzol_j/rendu/PSU_2014_philo
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Mon Feb 23 09:36:12 2015 julien gazzola
** Last update Tue Feb 24 14:10:33 2015 julien gazzola
*/

#include <stdio.h>
#include <stdlib.h>
#include "Philo.h"

void			*philosopher(void *arg)
{
  
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
      if (pthread_create(&(philo[i]->thread), NULL, philosopher, philo[i]))
	return (NULL);
      ++i;
    }
  i = 0;
  while (i != 7)
    {
      if (pthread_join(philo[i]->thread, NULL))
	return (NULL);
      ++i;
    }
  return (philo);
}

pthread_mutex_t		*create_mutex_tab()
{
  pthread_mutex_t	*mutex_tab;
  int			i;

  i = 0;
  if ((mutex_tab = malloc(7 *sizeof(pthread_mutex_t))) == NULL)
    return (NULL);
  while (i != 7)
    {
      if (pthread_mutex_init(&mutex_tab[i], NULL))
	return (NULL);
      i = i + 1;
    }
  return (mutex_tab);
}

int			main()
{
  t_philo		**tab;
  int			i;
  pthread_mutex_t	*mutex_tab;

  i = 0;
  if ((tab = create_philo()) == NULL)
    return (-1);
  if ((mutex_tab = create_mutex_tab()) == NULL)
    return (0);
  return (0);
}

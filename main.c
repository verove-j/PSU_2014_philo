/*
** main.c for philosophe in /home/gazzol_j/rendu/PSU_2014_philo
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Mon Feb 23 09:36:12 2015 julien gazzola
** Last update Tue Feb 24 13:18:42 2015 Jordan Verove
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
  if ((philo = malloc(sizeof(philo) * 7)) == NULL)
    return (NULL);
  while (i != 7)
    {
      if ((philo[i] = malloc(sizeof(philo))) == NULL)
	return (NULL);
      philo[0][i].id = i + 1;
      philo[0][i].rice = 50;
      if (pthread_create(&(philo[0][i].thread), NULL, philosopher, &philo[0][i]))
	return (NULL);
      i++;
    }
  i = 0;
  while (i != 7)
    {
      if (pthread_join(philo[0][i++].thread, NULL))
	return (NULL);
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

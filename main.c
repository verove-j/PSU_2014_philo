/*
** main.c for philosophe in /home/gazzol_j/rendu/PSU_2014_philo
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Mon Feb 23 09:36:12 2015 julien gazzola
** Last update Tue Feb 24 10:06:15 2015 julien gazzola
*/

#include <stdio.h>
#include <stdlib.h>
#include "Philo.h"

t_philo		*create_philo()
{
  t_philo	*philo;
  int		i;

  i = 1;
  if ((philo = malloc(sizeof(philo) * 7)) == NULL)
    return (NULL);
  while (i != 8)
    {
      philo[i].id = i;
      pthread_create();
      i++;
    }
  return (philo);
}

int	main()
{
  t_philo	*philo;

  if (create_philo() == NULL)
    return (-1);
  return (0);
}

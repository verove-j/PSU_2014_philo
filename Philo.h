/*
** Philo.h for Philo in /home/gazzol_j/rendu/PSU_2014_philo
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Tue Feb 24 09:20:01 2015 julien gazzola
** Last update Tue Feb 24 09:50:53 2015 julien gazzola
*/

#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>

typedef struct		s_philo
{
  pthread_t		thread;
  int			id;
  pthread_mutex_t	*mutex_left;
  pthread_mutex_t	*mutex_right;
}			t_philo;

#endif	/* !PHILO_H_ */

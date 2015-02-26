/*
** Philo.h for Philo in /home/gazzol_j/rendu/PSU_2014_philo
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Tue Feb 24 09:20:01 2015 julien gazzola
** Last update Thu Feb 26 15:25:39 2015 Jordan Verove
*/

#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>

typedef enum		e_state
  {
    HUNGRY,
    TIRED
  }			t_state;
  
typedef struct		s_philo
{
  pthread_t		thread;
  int			id;
  char			left;
  char			right;
  int			rice;
  t_state      		state;
}			t_philo;

#endif	/* !PHILO_H_ */

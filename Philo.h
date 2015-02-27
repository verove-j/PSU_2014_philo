/*
** Philo.h for Philo in /home/gazzol_j/rendu/PSU_2014_philo
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Tue Feb 24 09:20:01 2015 julien gazzola
** Last update Fri Feb 27 14:42:18 2015 julien gazzola
*/

#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>

extern int		total_rice;
extern pthread_mutex_t	*mutex_tab;

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

/*
**philo.c
*/
void		*philosopher(void *arg);

#endif	/* !PHILO_H_ */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:49:52 by khou              #+#    #+#             */
/*   Updated: 2018/08/31 17:15:36 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void    operate(t_lsflags *store, char *path)
{
	struct dirent *wi;
	DIR		*dr = opendir(path);
 
    if (dr == NULL)
        printf("Could not open current directory" );
    while ((wi = readdir(dr)))
		printf("%s\n", wi->d_name);
    closedir(dr);
	printf("store->pcurrent: %d, path: %s\n", store->pcurrent, path);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:10:15 by khou              #+#    #+#             */
/*   Updated: 2018/10/29 20:25:26 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
/*
//sorting (1.get whether it is a file or dir and mark it in tree)
sort by time or ASCII
//read the tree from direction
or reverse
1. read the tree to the end to print out current. set create_root = 1
2. read the tree again and while loop to find subdir and call recursion

3. (if there is not subdir it should go to next dir in tree)
*/

void	pull_info(t-ls *ls)
{
	if (ls->fi != 0)
		stage4tree();
	if (ls->di != 0)
		stage4tree();
}

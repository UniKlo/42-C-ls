/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:49:52 by khou              #+#    #+#             */
/*   Updated: 2018/10/28 03:41:08 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void inorder(t_node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        ft_printf("%s \n", root->fullpath);
        inorder(root->right);
    }
}

void    operate(t_lsflags *store, char *path)//just read this level. file or dir
{
	struct dirent *file;
	DIR		*dr = opendir(path);
	struct stat sb;
	char *readinto;
//	char	*tmp;
    if (dr == NULL)// either it is a file, or it is not readable.
	{
//if there are multipule files in command line, they  need to be sort.        
		if (store->l && !lstat(path, &sb)) // lstat info on file thru path
			plong(path, &sb);
		else if (lstat(path, &sb))// with no permission
			ft_printf("Could not open current directory\n");
		else
			ft_printf("%s\n", path);
		return;
	}
	path = ft_strjoin(path, "/");//add '/' with no exception
	dr = opendir(path);//pass the dir with /.
	while ((file = readdir(dr)))
	{
		if (!store->a && file->d_name[0] == '.')// take out hiden file before operate
			continue;
		ft_printf("%s\n", file->d_name);// all the right files
		readinto = ft_strjoin(path, file->d_name); //get the full path need to be free
		if (!lstat(readinto, &sb))
		{
/*
			if (create_root)
			{
				insert(root, fullpath, mtime);
				create_root = 0;
	        }
*/
//			sorting(store, readinto, &sb);//sort before print
		}
//			sorting(&store, readinto, &sb);//sort before print
		else
			ft_printf("Error");
		if (store->l) // lstat info on file thru path+filename
		{
			plong(readinto, &sb);
		}
		free(readinto);
	}
    closedir(dr);
//	free(path);
//	inorder(root);
	ft_printf("store->a: %d, path: %s\n", store->a, path);//done
	ft_printf("store->t: %d, path: %s\n", store->t, path);//in binary tree sorting
	ft_printf("store->r: %d, path: %s\n", store->r, path);//in sorting reading
	ft_printf("store->l: %d, path: %s\n", store->l, path);
	ft_printf("store->pcurrent: %d, path: %s\n", store->pcurrent, path);

/*
The letters rwxXst select file mode bits for the affected users: read (r), write (w), execute (or search for directories) (x), execute/search only if the file is a directory or already has execute permission for some user (X), set user or group ID on execution (s), restricted deletion flag or sticky bit (t). Instead of one or more of these letters, you can specify exactly one of the letters ugo: the permissions granted to the user who owns the file (u), the permissions granted to other users who are members of the file's group (g), and the permissions granted to users that are in neither of the two preceding categories (o)
https://unix.stackexchange.com/questions/79395/how-does-the-sticky-bit-work
*/
}

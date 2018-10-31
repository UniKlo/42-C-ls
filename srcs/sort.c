#include "ls.h"

//t_node  *newNode(struct stat *sb, char *fullpath)
t_node  *newNode(struct stat *sb, char *fullpath)
{
    t_node   *node;
    
    if (!(node = (t_node*)malloc(sizeof(t_node))))
      return (NULL);
    sb = 0;
    /*
    struct stat sb;
    if (!lstat(path, &sb)) // lstat info on file thru path
      node->mtime = sb->st_mtimespec;
    else if (lstat(path, &sb))// with no permission
      ft_printf("Could not open current directory\n");
    */
    node->fullpath = fullpath;
        //   node->mtime = sb->st_mtimespec;//??
    node->left = NULL;
    node->right = NULL;
    return (node);
}

//add function pointer argument for comparison
void    insert(t_node *tree, char  *path)
{
        t_node *new;

        if (ft_strcmp(tree->fullpath, path) > 0)
        {
                if (!tree->left)
                {
                        new = newNode(0, path);
                        tree->left = new;
                }
                else
                        insert(tree->left, path);
        }
        else if (ft_strcmp(tree->fullpath, path) < 0)
        {
                if (!tree->right)
                {
                        new = newNode(0, path);
                        tree->right = new;
                }
                else
                        insert(tree->right, path);
        }
        else //file has equal name (error?)
                ;
}

void    print_tree(t_node *tree)
{
        if (tree->left)
                print_tree(tree->left);
        printf("%s\n", tree->fullpath);
        if (tree->right)
                print_tree(tree->right);
}

//void f_sort(t_lsflags *store, t_ls *ls) should pass the flag for cmp
void f_sort( t_ls *ls)
{
  t_node *tree = newNode(0, ls->fil[0]);
  int a = 1;
  while (a < ls->fi)
    {
      insert( tree ,ls->fil[a]);
      a++;
    }
  print_tree(tree);
}

void cmd_sort(t_ls *ls)
{
  if (ls->fi != 0)
    f_sort(ls);
};




void	d_sort();
  

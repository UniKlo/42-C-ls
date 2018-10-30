        if (store->l && !lstat(readinto, &sb)) // lstat info on file thru path:path+file\
name
        {
//          ft_printf("device inode resides on  :%ld\n", (long) sb.st_dev);
//          ft_printf("I-node number:            %ld\n", (long) sb.st_ino);
            ft_printf("Mode:                     %lo (octal)\n",
                   (unsigned long) sb.st_mode);
            ft_printf("whether is dir:           %c\n",
                   (sb.st_mode & S_IFDIR) ? 'd' : '-');
            ft_printf("owner_rwx:                %c%c%c\n",
                   (sb.st_mode & S_IRUSR) ? 'r' : '-',
                   (sb.st_mode & S_IWUSR) ? 'w' : '-',
                   (sb.st_mode & S_IXUSR) ? 'x' : '-') ||
                ((sb.st_mode & S_ISUID) && (sb.st_mode & S_IXUSR) ? 's' : 'S' );
            ft_printf("group_rwx:                %c%c%c\n",
                   (sb.st_mode & S_IRGRP) ? 'r' : '-',
                   (sb.st_mode & S_IWGRP) ? 'w' : '-',
                   (sb.st_mode & S_IXGRP) ? 'x' : '-');
            ft_printf("other_rwx:                %c%c%c\n",
                   (sb.st_mode & S_IROTH) ? 'r' : '-',
                   (sb.st_mode & S_IWOTH) ? 'w' : '-',
                   (sb.st_mode & S_IXOTH) ? 'x' : '-');
            ft_printf("Link count:               %ld\n", (long) sb.st_nlink);
            ft_printf("Ownership:                UID=%ld   GID=%ld\n",
                   (long) sb.st_uid, (long) sb.st_gid);

//          ft_printf("Preferred I/O block size: %ld bytes\n",
//                 (long) sb.st_blksize);
            ft_printf("File size:                %lld bytes\n",
                   (long long) sb.st_size);
//          ft_printf("Blocks allocated:         %lld\n",
//                 (long long) sb.st_blocks);

//          ft_printf("Last status change:       %s", ctime(&sb.st_ctime));
//          ft_printf("Last file access:         %s", ctime(&sb.st_atime));
            ft_printf("Last file modification:   %s", ctime(&sb.st_mtime));// need to cut t\
he string
        }
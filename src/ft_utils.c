#include "../incl/so_long.h"

void ft_error(char *str)
{
    write(2, "Error ", 6);
    printf("%s\n", str); // 📛📛📛📛change to ft_printf 
    exit (1);
}

int ft_check_ber(char *mapfile)
{
    int i;
    i = 0;

    while(mapfile[i])
        i++;
    i--;
    if (mapfile[i] == 'r' && mapfile[i - 1] == 'e' && mapfile[i - 2] == 'b' && mapfile[i - 3] == '.')
        return (1);
    else
        return (0);
}

char *ft_read_map(char *mapfile)
{
    int fd;
    int i = 0;
    char *str;
    //valider que c'est bien un file ber avec une fct exterieure que je cree 
    if(!ft_check_ber(mapfile))
        return(NULL);
    //ouvrir la map avec open
    fd = open(mapfile, O_RDONLY);
    //si apres l'open le fd a une return value negative, error msg -> invalid file
    if (fd < 0)
        ft_error(E_FILE);
    //compter le nombre de char dans la map
    while(*mapfile)
    {
        i++;
        mapfile++;
    }
    //si compte est = 0 emptyfile -> errormsg
    if (i == 0)
        ft_error(E_EMPTYFILE);
    //mallocquer une str pour store la str de la map
    str = (char *)malloc(sizeof(char) * (i + 1));
    // 📛 Pas oublier que j'ai malloc la str et qu'il faudra free un moment
    if (!str)
        ft_error(E_MALLOC);
    //utiliser read pour store la str envoyée dans la str mallocquée
    read(fd, str, O_RDONLY);
    //null terminer
    str[i] = '\0';
    // 📛📛📛📛 Pas oublier de close le fd 📛📛📛📛
    close(fd);
    //renvoyer la str qui store maintenant toutes les char de la map
    return(str);
}
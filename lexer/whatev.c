
void printchar(int fd, int charcode) 
{ 
    if (printable(charcode)) 
    { 
        fprintf(fd, "%c", charcode); 
    }    
    switch (charcode) 
    { 
        case 7: 
            fprintf(fd, "\\a"); 
        case 8: 
            fprintf(fd, "\\b"); 
        case 12: 
            fprintf(fd, "\\f"); 
        case 10: 
            fprintf(fd, "\\n"); 
        case 13: 
            fprintf(fd, "\\r"); 
        case 9: 
            fprintf(fd, "\\t"); 
        case 11: 
            fprintf(fd, "\\v"); 
        case 0: 
            fprintf(fd, "\\0"); 
        default: 
            fprintf(fd, "\\%o", charcode); 
    } 
    return; 
}


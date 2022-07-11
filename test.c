int main (){
    int x,y;

    scanf("%d %d",&x,&y);

    if(x>=0){
        if(y>=x){
            printf("move1");
        }
        if(-y >= x){
            printf("move2");
        }
    }
    if(x<0){
        if(y >= -x){
            printf("move3");
        }
        if(-y >= -x){
            printf("move4");
        }
    }
    return 0;
}
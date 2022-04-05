#include<stdio.h>


const char * into_string(int value){
    const char * ret;
    switch(value){
        case 1:
            ret = "one";
            break;
        case 2:
            ret = "two";
            break;
        case 3:
            ret = "three";
            // break;
        default:
            ret = "less than one eojkr";
    }
    return ret;

}
int main(){
    printf("ninto string =%s",(char*)into_string(2));
    return 0;
}
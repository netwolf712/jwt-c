#include <jwt_helper.h>
#include <stdio.h>

#define PSK "12345678"
#define USERNAME "test-user"
#define EXPIRE_TIME 100
int main(int argc, char* argv[]){
    printf("start jwt encode:\nusername=%s,PSK=%s\n",USERNAME,PSK);
    char szJwt[1024] = {0};
    get_jwt_token(USERNAME,PSK,szJwt);
    printf("get jwt token: %s\n",szJwt);

    printf("start jwt decode...\n");
    char username[256] = {0};
    if(verify_jwt_token(PSK,szJwt,username,EXPIRE_TIME)){
        printf("verify jwt token success(username=%s)\n",username);
    }else{
        printf("verify jwt token failed.\n");
    }
    return 0;
}
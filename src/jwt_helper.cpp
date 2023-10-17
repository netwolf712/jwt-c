#include <jwt_helper.h>
#include "jwt.h"
#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif
//jwt最大负载长度
#define MAX_PAYLOAD_LENGTH 256

/**
 * @brief 生成jwt
 * 
 * @param username 用户名
 * @param psk 加密密钥 
 * @param szJwt 返回值
 */
void get_jwt_token(char* username,char* psk,char* szJwt){
    struct timeval tv;
    char szPayload[MAX_PAYLOAD_LENGTH] = {0};
    gettimeofday(&tv, NULL);
    sprintf(szPayload,"%s,%ld",username,tv.tv_sec);
    JWT jwt(psk);
    jwt.encodeJWT(szPayload,szJwt);
}

/**
 * @brief 校验jwt，并返回用户名
 * 
 * @param psk 加密密钥
 * @param szJwt jwt
 * @param username 返回的用户名
 * @param expireTime 超时时间
 * @return true 校验通过
 * @return false 校验不通过
 */
int verify_jwt_token(char* psk,char* szJwt,char* username,long expireTime){
    struct timeval tv;
    char szPayload[MAX_PAYLOAD_LENGTH] = {0};
    gettimeofday(&tv, NULL);
    JWT jwt(psk);
    if(!jwt.decodeJWT(szJwt,szPayload,MAX_PAYLOAD_LENGTH)){
        return RTN_ERROR;
    }
    const char* sep = ",";
    char* szUsername = strtok(szPayload, sep);
    char* szTime = strtok(NULL, sep);
    if(szUsername == NULL || szTime == NULL){
        return RTN_ERROR;
    }
    //校验是否超时
    if(atol(szTime) + expireTime < tv.tv_sec){
        return RTN_ERROR;
    }
    strcpy(username,szUsername);
    return RTN_SUCCESS;
}
#ifdef __cplusplus
};
#endif
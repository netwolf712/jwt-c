
#ifndef JWT_HELPER_H
#define JWT_HELPER_H

#ifdef __cplusplus
extern "C" {
#endif

#define RTN_ERROR 0
#define RTN_SUCCESS 1
/**
 * @brief 生成jwt
 * 
 * @param username 用户名
 * @param psk 加密密钥 
 * @param szJwt 返回值
 */
void get_jwt_token(char* username,char* psk,char* szJwt);

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
int verify_jwt_token(char* psk,char* szJwt,char* username,long expireTime);
#ifdef __cplusplus
};
#endif
#endif
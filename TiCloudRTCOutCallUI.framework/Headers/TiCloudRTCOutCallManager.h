//
//  TiCloudRTCOutCallManager.h
//  TiCloudRTCOutCallUI
//
//  Created by Joel on 2025/8/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 错误域定义
extern NSString * const TiCloudRTCOutCallManagerErrorDomain;

@protocol TiCloudRTCOutCallManagerDelegate <NSObject>

/**
 *  token即将过期提醒
 *
 * @param accessToken       将在 10 分钟后过期
 */
- (void)onAccessTokenWillExpire:(nonnull NSString *)accessToken;

/**
 * 引擎全局内错误信息事件回调
 *
 * @param errorCode         错误码
 * @param errorMessage   错误描述
 */
 - (void)onError:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage;


 /**
  * 外呼结束
  * @param errorCode         错误码
  * @param errorMessage   错误描述
  * @param sipCode           sip错误码
  *
  */
 - (void)onCallingEnd:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage sipCode:(NSInteger)sipCode;
 
 /**
  * 外呼失败
  *
  * @param errorCode         错误码
  * @param errorMessage   错误描述
  */
 - (void)onCallFailure:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage;


@end

@interface TiCloudRTCOutCallManager : NSObject

+ (void)callOutWithPhoneNumber:(NSString *)phoneNumber
                   rtcEndpoint:(NSString *)rtcEndpoint
                  enterpriseId:(NSInteger)enterpriseId
                        userId:(NSString *)userId
                   accessToken:(NSString *)accessToken
                       success:(void (^)(void))success
                       failure:(void (^)(NSError *error))failure;

+ (void)renewAccessToken:(NSString *)accessToken;

+ (void)setDelegate:(id<TiCloudRTCOutCallManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END

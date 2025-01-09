//
//  TiCloudRTCDefines.h
//  TiCloudRTC
//
//  Created by 高延波 on 2022/8/19.
//

#ifndef TiCloudRTCDefines_h
#define TiCloudRTCDefines_h

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_OSX
#import <AppKit/AppKit.h>
#endif

typedef NS_ENUM(NSInteger, TiCloudRtcErrCode)
{
    /*
     * code 分类方式:
     * 1. 1xxxx  格式错误码为 SDK 自身内部运行所遇到的错误, 19999 为 SDK 未知错误兜底错误码
     * 2. 2xxxx  格式错误码为网关类错误码
     * 3. 3xxxx  格式错误码为 Media-Server 类错误码
     * 4. 4xxxx  格式错误码为 RTC API 接口返回的配置错误类错误码
     */
    
    // SDK 自身相关错误码 ::::::::::::::::::::::::::::::::::::::::::::::::
    SDK_NOT_INIT                            = 10000,   // "SDK未初始化"
    NET_ERROR                               = 10001,   // "网络异常"
    PARSE_HTTP_RESPONSE_FAILED              = 10002,   // "解析 HTTP 响应失败"
    SDK_ON_INITIALIZING_OR_DESTROYING       = 10003,   // "SDK 正在初始化或 SDK 正在销毁"     暂无
    RTC_ENDPOINT_FORMAT_INCORRECT           = 10004,   // "RTC 平台地址格式不正确. 正确格式: ^https://[a-zA-Z0-9\.\-_]+$ "
    ENTERPRISE_ID_FORMAT_INCORRECT          = 10005,   // "企业 ID 格式不正确. 正确格式: ^\d{7}$ "
    USER_ID_FORMAT_INCORRECT                = 10006,   // "用户 ID 格式不正确. 正确格式:   ^[a-zA-Z0-9@\-\.:]{1,512}$ "
    ACCESS_TOKEN_FORMAT_INCORRECT           = 10007,   // "accessToken 格式不正确. 正确格式:   ^[a-zA-Z0-9%/=+]+$ "
    RTM_INIT_FAILED                         = 10008,   // "RTM 初始化失败"
    RTM_NOT_INIT                            = 10009,   // "RTM 未初始化"
    
    HTTP_AUTH_FAILED                        = 11000,   // "HTTP 鉴权失败"
    ACCESS_TOKEN_EXPIRED                    = 11001,   // "AccessToken 已过期"
    ACCESS_TOKEN_PERIOD_TOO_SHORT           = 11002,   // "AccessToken 有效期短于 10 分钟"
    ACCESS_TOKEN_VERSION_INCORRECT          = 11003,   // "AccessToken 版本错误"
    HTTP_REQUEST_UNAUTHORIZED               = 11004,   // "HTTP 未授权"
    HTTP_REQUEST_404                        = 11005,   // "资源未定义(404异常)"
//    HTTP_METHOD_NOT_ALLOWED                 = 11006,   // "请求方式错误"    //移动端发送的请求方法不会出错, 所以可以不支持该错误码
    ACCESS_TOKEN_AND_USER_ID_MISMATCH       = 11007,   // "AccessToken 与 userId 不匹配"
    
    NOT_SUPPORT_CALL_TYPE                   = 12000,   // "不支持的呼叫场景"
    CALL_PARAM_INCORRECT                    = 12001,   // "呼叫参数错误"
    CALL_REPEAT                             = 12002,   // "呼叫重复"
//    OTHER_CLIENTS_ARE_ON_CALL               = 12003,   // "当前有其他客户端正在通话中"     // 移动端有互踢逻辑, 所以不会出现该错误码
    LOCAL_INVITATION_SEND_FAILED            = 12004,   // "发送本地会话邀请失败"
    NOT_SUPPORT_DTMF __attribute__((deprecated("已废弃,SDK 不会再返回此错误码,无论外呼场景还是客服场景都支持传 DTMF,当前错误码将在 5.0.0 版本移除"))) = 12005 ,   // "外呼场景不支持 DTMF"
    DTMF_PARAM_INCORRECT                    = 12006,   // "请输入正确的 DTMF 字符"
    AUDIO_CAPTURE_PERMISSION_DENIED         = 12007,   // "无音频采集权限"
//    PUBLISH_LOCAL_STREAM_FAILED             = 12008  // 当前错误码只有小程序支持
//    JOIN_CHANNEL_FAILED                     = 12009  // 当前错误码只有小程序支持
    
    UNKNOWN_ERROR_WHEN_ACCEPT_REMOTE_INVITATION     = 13000,   // "因意外情况无法接受网关的远端会话邀请"     暂无
    PARSE_REMOTE_INVITATION_CONTENT_FAILED  = 13001,   // "解析网关远端会话邀请内容失败"
    ACCEPT_REMOTE_INVITATION_FAILED         = 13002,   // "接受网关远端会话邀请失败"
    
    SELF_HANGUP    __attribute__((deprecated("已废弃,请用 onLocalHangup 回调,SDK 不会再返回此错误码,当前错误码将在 5.0.0 版本移除")))   = 14001,   // "调用 SDK hangup 接口引发挂断"
    REMOTE_HANGUP  __attribute__((deprecated("已废弃,请用 onRemoteHangup 回调,SDK 不会再返回此错误码,当前错误码将在 5.0.0 版本移除")))   = 14002,   // "对方接起后挂断"
    REMOTE_MISSED_CALL                      = 14003,   // "对方未接起挂断,请检查 sipCode"
    SDK_OFFLINE                             = 14004,   // "通话过程中 SDK 因网络问题断线"
    SAME_USER_ID_LOGIN_ON_OTHER_DEVICE      = 14005,   // "通话过程中同一 userId 在其他端登录导致断线"
    HANGUP_DUE_DESTROY_CLIENT               = 14006,   // "通话过程中调用销毁 SDK 导致断线"
    
    UNKNOWN_SDK_ERROR                       = 19999,   // "未知 SDK 内部错误"
    
    // 网关类错误码 ::::::::::::::::::::::::::::::::::::::::::::::::::::-
    // 此部分由 Gateway 透传 ==============
    LOCAL_INVITATION_PARAM_ERROR            = 20001,   // "本地会话邀请参数错误"
    IB_OB_ERROR                             = 20002,   // "主被叫错误"
    GATEWAY_INNER_ERROR                     = 20003,   // "网关内部错误"
    SDK_SIDE_RTP_TIMEOUT                    = 20004,   // "SDK 侧 RTP 超时"
    SIP_SIDE_RTP_TIMEOUT                    = 20005,   // "SIP 侧 RTP 超时"
    CALL_MEDIA_SERVER_TIMEOUT               = 20006,   // "呼叫 Media-Server 超时"
    
    GATEWAY_OFFLINE                         = 21000,   // "通话过程中网关掉线"
    GATEWAY_NOT_ACCEPT_INVITATION_BECAUSE_OF_OFFLINE    = 21001,   // "网关离线无法接受本地会话邀请"
    GATEWAY_NO_RESPONSE_INVITATION          = 21002,   // "网关对本地会话邀请无响应"
    GATEWAY_ACCEPT_INVITATION_TIMEOUT       = 21003,   // "网关接受邀请超时"
    
    // Media-Server 类错误码 ::::::::::::::::::::::::::::::::::::::::::::
    // 此部由 Media-Server 透传 ===========
    ABNORMAL_ENTERPRISE_STATUS              = 30001,   // "企业状态异常"
    NO_PERMISSION_TO_MAKE_OUTBOUND_CALL     = 30002,   // "没有外呼权限"
    CONCURRENCY_LIMIT_EXCEEDED              = 30003,   // "并发超限"
    INVALID_OUTBOUND_NUMBER_FORMAT          = 30004,   // "外呼号码格式错误"
    CAN_NOT_OBTAIN_CLID_NUMBER              = 30005,   // "未获取到外显号码"
    BLACKLIST_BLOCKED                       = 30006,   // "风控黑名单拦截"
    FREQUENCY_LIMIT_EXCEEDED                = 30007,   // "风控频次拦截"
    TIME_LIMIT_EXCEEDED                     = 30008,   // "风控时间限制拦截"
    AGENT_POLICY_RESTRICTION                = 30009,   // "座席策略限制"
    SPECIAL_VIOLATION_WORDS_DETECTED        = 30010,   // "检测到特殊违规词"
    TEL_DECRYPT_FAILED                      = 30011,   // "Tel解密失败"
    TEL_MUST_BE_ENCRYPTED                   = 30012,   // "Tel应该为密文"
    
    MEDIA_SERVER_OTHER_ERROR                = 39999,   // "其他异常"
    
    // 访问 RTC API 接口遇到的误码 ::::::::::::::::::::::::::::::::::::::-
    HTTP_REQUEST_500                        = 40000,   // "系统异常(500异常)"
    HOTLINE_NOT_CONFIG                      = 40001,   // "热线号码未配置"
    RTC_HTTP_API_FREQUENCY_LIMIT_EXCEEDED   = 40002,   // "接口频次超限"
    RTC_REGISTER_CONCURRENCY_LIMIT_EXCEEDED = 40003,   // "注册并发超限"
    RTC_CALL_CONCURRENCY_LIMIT_EXCEEDED     = 40004,   // "呼叫并发超限"
    ACCOUNT_DEACTIVATED                     = 40005,   // "账户状态异常:停机"
    ACCOUNT_CANCELED                        = 40006,   // "账户状态异常:注销"
    ENTERPRISE_NOT_EXIST                    = 40007,   // "企业不存在"
    NO_AVAILABLE_GATEWAY                    = 40008,   // "无可用 Gateway"
    SIGN_TIMESTAMP_HAS_EXPIRED              = 40009,   // "签名(sign)时间戳已过期"
    SIGN_VERIFICATION_FAILED                = 40010,   // "签名(sign)检验未通过"
    REQUEST_REPEAT                          = 40011,   // "重复请求"
    
    UNKNOWN_RTC_HTTP_API_ERROR              = 49999,   // "未知 RTC HTTP API 错误"
};

/// 网络状态
typedef NS_ENUM(NSInteger, TiCloudRtcNetwotkQuality)
{
    TiCloudRtcNetwotkQuality_Unknown,      // 网络质量未知
    TiCloudRtcNetwotkQuality_Good ,      // 网络质量较好
    TiCloudRtcNetwotkQuality_General ,    // 网络质量一般
    TiCloudRtcNetwotkQuality_Bad ,    // 网络质量较差
};

/// 呼叫场景
typedef NS_ENUM(NSInteger, TiCloudRtcScence)
{
    TiCloudRtcScence_AGENTSCENCE = 1,      // 客服场景
    TiCloudRtcScence_OUTCALLSCENCE = 6,    // 外呼场景
};

@interface TiCloudRTCEngineConfig : NSObject

// 平台地址
@property(nonatomic, copy, nonnull) NSString *rtcEndpoint;

// 企业ID
@property(nonatomic, assign) NSInteger enterpriseId;

// 用户ID
@property(nonatomic, copy, nonnull) NSString *userId;

// 登录接口返回的 accessToken
@property(nonatomic, copy, nonnull) NSString *accessToken;

// 预留扩展参数
@property(nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *advancedConnectConfig;

// 调试标识，true 为输出调试信息，false 为不输出调试信息
@property(nonatomic, assign) BOOL isDebug;

/**
 * 启动SDK端观测云，true 为启动观测云，false 为不启动观测云
 *
 * 注:
 * 1. 当设置该标识为 false 时, 关闭 SDK 的观测云初始化.
 *
 * 2. 当设置该标识为 true 时, 开启 SDK 的观测云初始化.
 *
 * 3. 如果 APP 端使用观测云, 则 isStartFTMobile 需要设置为 false.
 */
@property(nonatomic, assign) BOOL isStartFTMobile;

// 主叫号码（用于回呼）
@property(nonatomic, copy, nullable) NSString *callerNumber;

/**
 * 是否在对端挂断时播放预置挂机音频(注:通话错误导致的挂机不会播放音频)
 *
 * true: 播放音频(默认)
 * false: 不播放音频
 */
@property(nonatomic, assign) BOOL isPlayHangupAudio;

+ (instancetype _Nonnull)defaultConfig;

@end

@interface TiCloudRTCCallConfig : NSObject

// 外呼号码
@property(nonatomic, copy, nonnull) NSString *tel;

// 外显号码
@property(nonatomic, copy, nullable) NSString *clid;

// 指定外显区号
@property(nonatomic, copy, nullable) NSString *obClidAreaCode;

/// 指定外显号码池，使用此参数时obClid参数无效
@property (nonatomic, copy, nullable) NSString *obClidGroup;

// 坐席号
@property(nonatomic, copy, nullable) NSString *cno;

// 通话唯一标识 不填则有sdk内部生成
@property(nonatomic, copy, nullable) NSString *requestUniqueId;

// 自定义字段
@property(nonatomic, copy, nullable) NSString *userField;

// 呼叫场景 1:客服场景 6：外呼场景
@property(nonatomic, assign) TiCloudRtcScence type;

// 主叫号码（用于回呼,若不为空可覆盖初始化时传入的值）
@property(nonatomic, copy, nullable) NSString *callerNumber;

/**
 * 签名时间戳
 *
 * 注: 在加密模式下用到,不使用加密则不需要传入
 */
@property(nonatomic, assign) NSInteger timestamp;

/**
 * 参数签名
 *
 * 注: 在加密模式下用到,不使用加密则不需要传入
 *
 * 签名规则:
 *  1. 将参数 tel、callerNumber、clid、obClidAreaCode、obClidGroup、userField、type、timestamp 按照字典顺序排序，
 *      然后按照 key=value&key2=value2 的规则进行拼接(注意：如果没有传对应字段则不用参与拼接，requestUniqueId 不参与签名)
 *  2. 将企业 ID 拼接到拼接串开头，将企业 Token 拼接到拼接串结尾
 *  3. 将拼接串进行 SHA256 加密，最终得到的值就是签名(sign)
 *
 * 签名示例:
 *  假设企业 ID 为 7000002 , 企业 Token 为 token123456
 *  请求参数为
 *      tel: 13000000000
 *      callerNumber: 14000000000
 *      obClidGroup: 号码池1
 *      type: 6
 *      timestamp: 1735192796
 *
 *
 *  按照步骤开始计算签名
 *
 *  经过第一步计算之后得到  callerNumber=14000000000&obClidGroup=号码池1&tel=13000000000&timestamp=1735192796&type=6
 *
 *  经过第二步计算之后得到  7000002callerNumber=14000000000&obClidGroup=号码池1&tel=13000000000&timestamp=1735192796&type=6token123456
 *
 *  经过第三步计算之后得到  398db99bf641dbc489a61204257ea7e91ce2dd490a3f37862dc6c4992168c5dd
 *
 */
@property(nonatomic, copy, nullable) NSString *sign;

// 预留扩展参数
@property(nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *advancedConnectConfig;

+ (instancetype _Nonnull)defaultConfig;

@end

#endif /* TiCloudRTCDefines_h */

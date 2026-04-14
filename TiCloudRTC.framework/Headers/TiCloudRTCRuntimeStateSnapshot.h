#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TiCloudRTCRuntimeEnginePhase) {
    TiCloudRTCRuntimeEnginePhaseUninitialized = 0,
    TiCloudRTCRuntimeEnginePhaseReady,
    TiCloudRTCRuntimeEnginePhaseDestroying,
    TiCloudRTCRuntimeEnginePhaseDestroyed,
};

typedef NS_ENUM(NSInteger, TiCloudRTCRuntimeCallStatus) {
    TiCloudRTCRuntimeCallStatusNone = 0,
    TiCloudRTCRuntimeCallStatusStart,
    TiCloudRTCRuntimeCallStatusRinging,
    TiCloudRTCRuntimeCallStatusCalling,
};

typedef NS_ENUM(NSInteger, TiCloudRTCRuntimeCleanupMode) {
    TiCloudRTCRuntimeCleanupModeNone = 0,
    TiCloudRTCRuntimeCleanupModeCancelInvitation,
    TiCloudRTCRuntimeCleanupModeHangup,
};

typedef NS_ENUM(NSInteger, TiCloudRTCRuntimeCleanupDispatchState) {
    TiCloudRTCRuntimeCleanupDispatchStateNone = 0,
    TiCloudRTCRuntimeCleanupDispatchStatePending,
    TiCloudRTCRuntimeCleanupDispatchStateDispatched,
    TiCloudRTCRuntimeCleanupDispatchStateCompleted,
    TiCloudRTCRuntimeCleanupDispatchStateFailed,
    TiCloudRTCRuntimeCleanupDispatchStateTimedOut,
};

@interface TiCloudRTCRuntimeStateSnapshot : NSObject <NSCopying>

@property (nonatomic, assign, readonly) NSUInteger version;
@property (nonatomic, assign, readonly) long long capturedAtMs;
@property (nonatomic, assign, readonly) BOOL engineReady;
@property (nonatomic, assign, readonly) BOOL rtcReady;
@property (nonatomic, assign, readonly) BOOL rtmReady;
@property (nonatomic, assign, readonly) TiCloudRTCRuntimeEnginePhase enginePhase;
@property (nonatomic, assign, readonly) TiCloudRTCRuntimeCallStatus callStatus;
@property (nonatomic, assign, readonly) BOOL isLocalInvitation;
@property (nonatomic, assign, readonly) BOOL isRemoteCall;
@property (nonatomic, copy, readonly, nullable) NSString *requestUniqueId;
@property (nonatomic, copy, readonly, nullable) NSString *peerId;
@property (nonatomic, copy, readonly, nullable) NSString *gatewayUid;
@property (nonatomic, assign, readonly) NSInteger remoteUserId;
@property (nonatomic, assign, readonly) BOOL hasActiveTerminalContext;
@property (nonatomic, assign, readonly) TiCloudRTCRuntimeCleanupMode suggestedCleanupMode;
@property (nonatomic, assign, readonly) TiCloudRTCRuntimeCleanupDispatchState cleanupDispatchState;
@property (nonatomic, assign, readonly) NSInteger lastCleanupErrorCode;
@property (nonatomic, assign, readonly) BOOL rtmLogoutCompleted;

- (NSDictionary<NSString *, id> *)dictionaryRepresentation;

@end

NS_ASSUME_NONNULL_END

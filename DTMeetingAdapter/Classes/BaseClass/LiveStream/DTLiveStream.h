//
//  DTLiveStream.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/9/28.
//

#import <Foundation/Foundation.h>
#import "DTLiveStreamTypedef.h"
#import "DTLiveStreamNetworkInfo.h"
#import "DTLiveStreamConfig.h"
#import "DTLiveStreamAudioVolumeInfo.h"
#import "DTMeetingUserInfo.h"
#import "DTLiveStreamVideoInfo.h"
#import "DTLiveStreamAudioInfo.h"

NS_ASSUME_NONNULL_BEGIN
@class DTMeetingError;
@protocol DTLiveStreamDelegate <NSObject>
@optional

/**
 用户注册成功的回调

 @param uid 回调的uid
 @param error 为nil时加入channel成功
 */

- (void)onRegisteredWithStreamId:(NSString * _Nonnull)uid userAccount:(NSString * _Nonnull)userAccount withError:(DTMeetingError * _Nullable)error;

/// 加入channel完成
/// @param channel 加入的channel
/// @param error 异常
- (void)onJoinChannel:(NSString *)channel withUid:(NSString * _Nullable)uid withError:(DTMeetingError * _Nullable)error;


/// 进入频道后接收到他人加入频道的提醒
/// @param uid 加入的uid
/// @param error 为nil时加入channel成功
- (void)onJoinChannelWithUid:(NSString * _Nullable)uid withError:(DTMeetingError * _Nullable)error;



/// 离开channel
/// @param channel 离开的channel
/// @warning 回调此方法代表sdk已经释放摄像头、麦克风等资源
- (void)onLeaveChannel:(NSString *)channel;

/// 用户离线的回调
/// @param uid 用户id
/// @param reason 离线原因
- (void)onUserDidOfflineOfUid:(NSString *)uid reason:(DTUserOfflineReason)reason;


/// token即将过期的回调
/// @param token token
- (void)onDynamicTokenWillExpire:(NSString *)token;

/// 推流成功
/// @param streamId 流
/// @param channel  推流channel
- (void)onPublishStreamSuccess:(NSString * _Nullable)streamId channel:(NSString * _Nullable)channel;

/**
 推流停止或推流出错

 @param streamId 推流id
 @param channel 推流channel
 @param error 为nil时推流主动停止，不为nil时为推流出错
 @warning 内部会主动重试推流，不需要再次调用开始推流 @see -startPublish:;，再次推流成功后，会回调推流成功 @see-onPublishStreamSuccess:channel:;
 */
- (void)onPublishStreamStop:(NSString * _Nullable)streamId channel:(NSString * _Nullable)channel error:(DTMeetingError * _Nullable)error;

/**
回调推流停止或推流出错的所有错误
 
@param streamId 推流id
@param channel 推流channel
@param error 不为nil
*/
- (void)onPublishStreamError:(NSString * _Nullable)streamId channel:(NSString * _Nullable)channel error:(DTMeetingError * _Nullable)error;

/// 推流端 渲染完视频采集的首帧回调
- (void)onDidRenderLocalVideoFirstFrame;

/// 接收到音频首帧成功
/// @param streamId 拉流id
- (void)onRecvRemoteAudioFirstFrame:(NSString * _Nullable)streamId;

/// 接收到视频频首帧成功
/// @param streamId 拉流id
- (void)onRecvRemoteVideoFirstFrame:(NSString * _Nullable)streamId;

/**
渲染首帧成功

@param streamId 拉流id
@param channel 拉流channel
*/
- (void)onPlayRenderFirstFrame:(NSString * _Nullable)streamId channel:(NSString * _Nullable)channel;

/**
 拉流成功

 @param streamId 拉流id
 @param channel 拉流channel
 */
- (void)onPlayStreamSuccess:(NSString * _Nullable)streamId channel:(NSString * _Nullable)channel;

/**
 拉流停止或拉流出错

 @param streamId 拉流id
 @param channel 拉流channel
 @param error error 为nil时拉流主动停止，不为nil时为拉流出错
 @warning 内部会主动重试拉流，不需要再次调用开始拉流 @see -startPlayStream:inView:contentMode:;，再次拉流成功后，会回调拉流成功 @see -onPlayStreamSuccess:channel:;
 */
- (void)onPlayStreamStop:(NSString * _Nullable)streamId channel:(NSString * _Nullable)channel error:(DTMeetingError * _Nullable)error;

/**
 拉流停止或拉流出错的所有错误

 @param streamId 拉流id
 @param channel 拉流channel
 @param error error 不为nil
 @warning 内部会主动重试拉流，不需要再次调用开始拉流 @see -startPlayStream:inView:contentMode:;，再次拉流成功后，会回调拉流成功 @see -onPlayStreamSuccess:channel:;
 */
- (void)onPlayStreamError:(NSString * _Nullable)streamId channel:(NSString * _Nullable)channel error:(DTMeetingError * _Nullable)error;

///TODO:  这个应该是实时回调 待确认
/// 拉流的流质量信息回调
///
/// @param streamId streamId 拉流id
/// @param info info 流质量信息 @see DTLiveStreamVideoInfo
/// @warning 拉流成功后才会开始回调，拉流停止时停止回调
- (void)onRecvPlayVideoStream:(NSString *)streamId streamInfo:(DTLiveStreamVideoInfo * _Nullable)info;

///TODO:  这个应该是实时回调 待确认
/// 推流的的音频流质量信息回调
///
/// @param info info 流质量信息 @see DTLiveStreamAudioInfo
/// @warning 推流成功后才会开始回调，推流停止时停止回调
- (void)onRecvPublishAudioStreamInfo:(DTLiveStreamAudioInfo * _Nullable)info;

///TODO:  这个应该是实时回调 待确认
/// 推视频流的流质量信息回调
/// @param info info 流质量信息 @see DTLiveStreamVideoInfo
/// @warning 拉流成功后才会开始回调，拉流停止时停止回调
- (void)onRecvPublishStreamInfo:(DTLiveStreamVideoInfo * _Nullable)info;

/// 拉取的视频流状态更新的回调
/// @param streamId 流id
/// @param state 流的状态
/// @param reason 更新原因
- (void)onRecvPlayVideoStreamStateChanged:(NSString *)streamId state:(DTVideoRemoteState)state reason:(DTVideoRemoteReason)reason;

/// 拉取的音频频流状态更新的回调
/// @param streamId 流id
/// @param state 流的状态
/// @param reason 更新原因
- (void)onRecvPlayAudioStreamStateChanged:(NSString *)streamId state:(DTAudioRemoteState)state reason:(DTAudioRemoteReason)reason;

/// 拉取的音频流状态更新的回调
/// @param streamId 流id
/// @param muted muted/ unmuted
- (void)onRecvPlayAudioStreamMuteStateChanged:(NSString *)streamId audioMuted:(BOOL)muted;

/// 接收到推流中视频流状态的变化
/// @param state 状态
- (void)onRecvPublishVideoStreamStateChanged:(DTVideoLocalState)state meetingError:(DTMeetingError *)error;

/// 接收到推流中音频流状态的变化
/// @param state 状态
/// @param error 错误信息
- (void)onRecvPublishAudioStreamStateChanged:(DTAudioLocalState)state meetingError:(DTMeetingError *)error;

/**
 回调推流的流质量信息

 @param info 流质量信息 @see DTLiveStreamNetworkInfo
 @warning 推流成功后才会开始回调，推流停止时停止回调
 @warning 当liveStream类型为DTLiveStreamServiceTypeAgora时，没有fps、lostRate、delay数据
 */
- (void)onUpdatePublishNetWorkInfo:(DTLiveStreamNetworkInfo * _Nullable)info;

/// 流信息更新的回调
///
/// @param streamId 流id
/// @param userInfo 当前流的用户信息
- (void)onUpdateStreamWithUserId:(NSString *)streamId userInfo:(DTMeetingUserInfo * _Nullable)userInfo;

/**
 推流成功后，回调采集到的声音大小

 @param volume 声音大小，范围[0-100]
 */
- (void)onUpdatePublishAudioVolume:(NSUInteger)volume;

/**
 拉流成功后，回调拉流声音大小

 @param streamId 拉流id
 @param volume 声音大小，范围[0-100]
 */
- (void)onUpdatePlayStream:(NSString *)streamId audioVolume:(NSUInteger)volume;

/**
 设备出现错误

 @param device 出现错误的设备类型
 @param error 错误描述
 @warning 回调时，表示sdk内部无法获取到设备资源，需要重新leaveChannel，并将liveStream置空，再重新创建liveStream
 */
- (void)onOccurWarning:(DTLiveStreamDeviceType)device error:(DTMeetingError *)error;

/**
 设备出现错误

 @param device 出现错误的设备类型
 @param error 错误描述
 @warning 回调时，表示sdk内部无法获取到设备资源，需要重新leaveChannel，并将liveStream置空，再重新创建liveStream
 */
- (void)onOccurError:(DTLiveStreamDeviceType)device error:(DTMeetingError *)error;

/**
 拉流视频数据回调
 
 @param streamId 流id
*/
- (void)onPlayerVideoFrame:(NSString * _Nullable)streamId;

/**
 拉流音频数据回调
 
 @param streamId 流id
 */
- (void)onPlayerAudioFrame:(NSString * _Nullable)streamId;

/**
 拉流卡顿回调
 
 @param event 卡顿事件
 @param streamId 流id
 */
- (void)onPlayerBufferingEvent:(DTBufferingEvent)event streamId:(NSString * _Nullable)streamId;



- (void)onReportAudioVolumeIndicationOfSpeakers:(NSArray<DTLiveStreamAudioVolumeInfo *> * _Nonnull)speakers totalVolume:(NSInteger)totalVolume;
@end





@interface DTLiveStream : NSObject

/**
 liveStream的类型
 */
@property (nonatomic, assign) DTMeetingSDKServiceType liveStreamType;

/**
 liveStream代理
 */
@property (nonatomic, weak) id<DTLiveStreamDelegate>delegate;

/**
 是否已经进入channel（加入channel成功）
 */
@property (nonatomic, assign, getter=isInChannel) BOOL inChannel;

/**
 是否已经在推流（推流成功）
 */
@property (nonatomic, assign, getter=isPublishing) BOOL publishing;

/**
 获取对应流媒体类型的版本号
*/
+ (NSString *)versionFromLiveStreamType:(DTMeetingSDKServiceType)type;

/**
 初始化liveStream

 @param liveStreamType liveStream类型
 @param config liveStream的配置
 @return 实例化liveStream
 @brief 当需要初始化类型为DTLiveStreamServiceTypeTal的liveStream时，需要传入DTTalLiveStreamConfig，当需要初始化类型为DTLiveStreamServiceTypeZego的liveStream时，需要传入DTZegoLiveStreamConfig，当需要初始化类型为DTLiveStreamServiceTypeAgora的liveStream时，需要传入DTAgoraLiveStreamConfig
 @warning 当liveStream类型为DTLiveStreamServiceTypeAgora时，不能设置encodeResolution
 */
+ (instancetype)liveStreamWithLiveStreamType:(DTMeetingSDKServiceType)liveStreamType config:(DTLiveStreamConfig *)config;


/// 在入会之前更新配置信息中的访问令牌
- (void)updataStreamConfigWithDynamicTokenBeforeJoinChannel:(NSString *)dynamicToken;

/**
 加入某一channel

 @param channelId 需要加入的channelId
 @param userId 用户id
 @param userName 用户姓名
 @brief 是否加入channel成功@see -onJoinChannel:withError:;
 */
- (void)joinChannel:(NSString *)channelId userId:(NSString *)userId userName:(NSString * _Nullable)userName;


/**
 离开当前channel
 @brief 回调见@see -onLeaveChannel:;
 */
- (void)leaveChannel;

/**
 开始推流

 @param streamId 推流id
 @return 方法执行结果，是否推流成功@see -onPublishStreamSuccess:channel:;和@see -onPublishStreamStop:channel:error:;
 */
- (BOOL)startPublish:(NSString *)streamId;


/**
 停止推流
 @brief 回调见@see -onPublishStreamStop:channel:error:;
 */
- (void)stopPublish;


/**
 开始预览

 @param view 预览画面显示在此view上
 @param mode 预览显示模式
 */
- (void)startPreview:(UIView *)view contentMode:(DTRTCViewContentMode)mode;

/// 是否开启预览
/// @param enable 是否开启预览
/// 确定在关闭之前 已经在合适的时机完成预览view的绑定即
/// - (void)startPreview:(UIView *)view contentMode:(DTRTCViewContentMode)mode 这个方法正常调用过
- (BOOL)enablePreview:(BOOL)enable;

/**
 停止预览
 */
- (BOOL)stopPreview;

/**
 开始拉流

 @param streamId 拉流id
 @param view 拉流的画面显示在此view上
 @param mode 显示模式
 @return 方法执行结果，是否拉流成功@see -onPlayStreamSuccess:channel:;
 */
- (BOOL)startPlayStream:(NSString *)streamId inView:(UIView * _Nullable)view contentMode:(DTRTCViewContentMode)mode;

/**
 停止拉流

 @param streamId 拉流id
 @brief 回调见@see -onPlayStreamStop:channel:error:;
 */
- (void)stopPlayStream:(NSString *)streamId;


/**
 旋转预览方向
 
 @param orientaion 预览的方向
 @return 方法执行结果
 */
- (BOOL)rotateCaptureWithOrientation:(UIDeviceOrientation)orientaion;

/**
 设置采集摄像头位置
 
 @param cameraPosition 前后置摄像头
 */
- (BOOL)setCameraPosition:(DTCameraPosition)cameraPosition;

/**
 设置预览镜像模式
 
 @param mode 预览的镜像模式
 */
- (void)setMirrorMode:(DTMirrorMode)mode;


/**
 单独设置某个拉流的音量大小

 @param streamId 拉流id
 @param volume 音量[0-100]
 @warning 当liveStream类型为DTLiveStreamServiceTypeAgora时，此设置无效
 */
- (void)setAudioVolume:(NSString *)streamId voluem:(int)volume;

/**
 设置是否播放某个流的音频

 @param streamId 流id
 @param mute 是否播放
 */
- (void)setStream:(NSString *)streamId audioMute:(BOOL)mute;

/**
 设置是否显示某个流的视频

 @param streamId 流id
 @param mute 是否显示
 */
- (void)setStream:(NSString *)streamId videoMute:(BOOL)mute;


- (BOOL)setEnableSpeakerphone:(BOOL)enable;

/**
 是否允许录制音频

 @param micro 是否允许录制
 */
- (BOOL)enableMicrophone:(BOOL)micro;

/**
 是否允许录制视频

 @param enable 是否允许录制
 */
- (BOOL)enableCamera:(BOOL)enable;

/**
 开启/关闭 视频推流

 @param mute 是否停止
 */
- (BOOL)muteVideoStream:(BOOL)mute;

/**
 当前是否允许录制音频

 @return 是否允许录制音频
 */
- (BOOL)isEnableMicrophone;

/**
 当前是否允许录制视频
 
 @return 是否允许录制视频
 */
- (BOOL)isEnableCamera;

/**
 是否允许录制视频

 @param token 新的动态令牌
 */
- (void)renewToken:(NSString * _Nonnull)token;

/**
 切换摄像头
 */
- (BOOL)switchCamera;


/**
 配置视频流的加密方式
 
 @param encryptionMode 加密方式
 @param encryptionKey 加密密钥
 @param encryptionKdfSalt 盐
 @return 方法执行结果
 */
- (BOOL)encryptionMode:(DTEncryptionMode)encryptionMode
         encryptionKey:(NSString *)encryptionKey
     encryptionKdfSalt:(NSString *)encryptionKdfSalt;
/**
 释放资源
 */
- (void)destroyResource;

@end

NS_ASSUME_NONNULL_END

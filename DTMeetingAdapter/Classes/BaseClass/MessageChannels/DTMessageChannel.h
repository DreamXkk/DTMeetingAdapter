//
//  DTMettingError.h
//  DTMeetingAdapter
//
//  Created by hornet on 2023/10/2.
//

#import <Foundation/Foundation.h>
#import "DTMeetingChannelMessage.h"
#import "DTMessageChannelsTypedef.h"
#import "DTLiveStreamTypedef.h"
#import "DTMessageChannelUser.h"
#import "DTMeetingChanneLocalInvitation.h"
#import "DTMeetingChannelRemoteInvitation.h"
#import "DTMsgChannelUserOnlineStatus.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^MeetingRtmSendChannelMessageBlock)(DTMeetingMsgChannelChannelSendPeerMessageErrorCode errorCode);
typedef void (^MeetingRtCSendChannelMessageBlock)(MeetingRtcChannelMessageErrorCode errorCode);
typedef void (^MeetingMessageChannelLoginBlock)(DTMessageChannelLoginErrorCode errorCode);
typedef void (^MeetingMessageChannelRenewTokenBlock)(NSString * _Nonnull token, DTMessageChannelRenewTokenErrorCode errorCode);
typedef void (^MeetingMessageChannelLogoutBlock)(DTMeetingMessageChannelLogoutErrorCode errorCode);
typedef void (^MeetingMessageChannelGetMembersBlock)(NSArray< DTMessageChannelUser *> * _Nullable members, DTMeetingMessageChannelGetMembersErrorCode errorCode);
typedef void (^MeetingMessageChannelLocalInvitationSendBlock)(DTMeetingMessageChannelInvitationApiCallErrorCode errorCode);
typedef void (^MeetingMessageChannelLocalInvitationCancelBlock)(DTMeetingMessageChannelInvitationApiCallErrorCode errorCode);
typedef void (^MeetingMessageChannelRemoteInvitationRefuseBlock)(DTMeetingMessageChannelInvitationApiCallErrorCode errorCode);
typedef void (^MeetingMessageChannelRemoteInvitationAcceptBlock)(DTMeetingMessageChannelInvitationApiCallErrorCode errorCode);
typedef void (^MeetingMessageChannelQueryPeersOnlineBlock)(NSArray<DTMsgChannelUserOnlineStatus *> * _Nullable peerOnlineStatus, DTMessageChannelQueryPeersOnlineErrorCode errorCode);


@protocol DTMessageChannelDelegate <NSObject>

@optional

- (void)onMessageChannelReceived:(nonnull DTMeetingChannelMessage *)message fromMember:(DTMessageChannelUser *)member;

- (void)onMessageChannelReceived:(nonnull DTMeetingChannelMessage *)message fromPeer:(NSString * _Nonnull)peerId;
///加入消息通道完成
/// - Parameter code:执行结果枚举
- (void)onJoinMessageChannelCompletion:(DTMeetingMsgChannelJoinChannelErrorCode) code;

/// 离开消息通道完成
/// - Parameter code:执行结果枚举
- (void)onLeaveMessageChannelCompletion:(DTMeetingMsgChannelLeaveChannelErrorCode) code;

/// 用户加入消息通道回调
/// - Parameter messageChannelUser: 用户
- (void)onMessageChannelMemberJoined:(DTMessageChannelUser *)messageChannelUser;

/// 用户离开消息通道回调
/// - Parameter messageChannelUser: 用户
- (void)onMessageChannelMemberLeft:(DTMessageChannelUser *)messageChannelUser;

/// 消息通道内人数发生变化时回调
/// - Parameter memberCount: 通道内的总人数
- (void)onMessageChannelMembersChanged:(int)memberCount;

///主叫方邀请被接受
- (void)onLocalInvitationAccepted:(DTMeetingChanneLocalInvitation *)localInvitation withResponse:(NSString *)response;

///主叫方邀请被拒绝
- (void)onLocalInvitationRefused:(DTMeetingChanneLocalInvitation *)localInvitation withResponse:(NSString *)response;

///主叫方 取消邀请
- (void)onLocalInvitationCanceled:(DTMeetingChanneLocalInvitation *)localInvitation;

///主叫方 邀请失败
- (void)onLocalInvitationFailure:(DTMeetingChanneLocalInvitation *)localInvitation errorCode:(DTMeetingMessageChannelLocalInvitationErrorCode)errorCode;


- (void)onLocalInvitationReceivedByPeer:(DTMeetingChanneLocalInvitation *)localInvitation;


/// 收到主叫邀请
/// - Parameter localInvitation: 邀请信息
- (void)onRecvRemoteInvitation:(DTMeetingChannelRemoteInvitation *)remoteInvitation;

- (void)onRecvRemoteInvitationCanceled:(DTMeetingChannelRemoteInvitation *)remoteInvitation;

- (void)onRecvRemoteInvitationFailure:(DTMeetingChannelRemoteInvitation *)remoteInvitation errorCode:(DTMeetingMessageChannelRemoteInvitationErrorCode)errorCode;

- (void)onRecvRemoteInvitationRefused:(DTMeetingChannelRemoteInvitation *)remoteInvitation;

- (void)onRemoteInvitationAccepted:(DTMeetingChannelRemoteInvitation *)remoteInvitation;

/// 消息通道链接状态变化时回调
/// - Parameter state: 连接状态
/// - Parameter reason: 原因
- (void)onMessageChannelconnectionStateChanged:(DTMeetingMessageChannelConnectionState)state reason:(DTMeetingMessageChannelConnectionChangeReason) reason;

/// 消息通道的访问令牌失效
- (void)onMessageChannelTokenDidExpire;

@end


@interface DTMessageChannel : NSObject

@property (nonatomic, weak) id<DTMessageChannelDelegate> delegate;
@property (nonatomic, assign) DTMeetingSDKServiceType sdkServiceType;

+ (instancetype)messageChannelWithServiceType:(DTMeetingSDKServiceType)sdkServiceType;

/// 使用访问令牌链接消息通道服务
/// - Parameters:
///   - token: 访问令牌
///   - userId: 用户id
///   - completionBlock: 成功回调
- (void)loginByToken:(NSString * _Nullable)token
                user:(NSString * _Nonnull)userId
          completion:(MeetingMessageChannelLoginBlock _Nullable)completionBlock;

/// 加入某一channel
/// @param channelId 需要加入的channelId
/// @param userId 用户id
/// @param userName 用户姓名
- (void)joinMessageChannel:(NSString *)channelId userId:(NSString * _Nullable)userId userName:(NSString * _Nullable)userName;

/**
 离开当前channel
 @brief 回调见@see -onLeaveChannel:;
 */
- (void)leaveMessageChannel;

/// 更新访问令牌
/// @param token 访问令牌
/// @param completionBlock 完成回调
- (void)renewToken:(NSString * _Nonnull)token completion:(MeetingMessageChannelRenewTokenBlock _Nullable)completionBlock;

/// 主动退出消息通道
/// @param completionBlock 完成回调
- (void)logoutWithCompletion:(MeetingMessageChannelLogoutBlock _Nullable )completionBlock;

/// 给指定用户发送消息
/// @param message 消息体
/// @param peerId 用户id
/// @param completionBlock 完成回调
- (void)sendChannelMessage:(DTMeetingChannelMessage * _Nonnull)message toPeer:(NSString * _Nonnull)peerId completion:(MeetingRtmSendChannelMessageBlock _Nullable)completionBlock;

/// 在通道内发送广播
/// @param message 消息题
/// @param completionBlock 完成回调
- (void)sendBroadcastMessage:(DTMeetingChannelMessage * _Nonnull)message completion:(MeetingRtCSendChannelMessageBlock _Nullable)completionBlock;

///给被叫方发送邀请消息
- (void)sendLocalInvitation:(DTMeetingChanneLocalInvitation *)localInvitation completion:(MeetingMessageChannelLocalInvitationSendBlock)completion;

///给被叫方发送邀请消息
- (void)cancelLocalInvitation:(DTMeetingChanneLocalInvitation * _Nonnull)localInvitation completion:(MeetingMessageChannelLocalInvitationCancelBlock _Nullable)completion;

///拒绝主叫方的邀请
- (void)refuseRemoteInvitation:(DTMeetingChannelRemoteInvitation * _Nonnull)remoteInvitation completion:(MeetingMessageChannelRemoteInvitationRefuseBlock _Nullable)completion;

///接受主叫方邀请
- (void)acceptRemoteInvitation:(DTMeetingChannelRemoteInvitation * _Nonnull)remoteInvitation completion:(MeetingMessageChannelRemoteInvitationAcceptBlock _Nullable)completion;

/// 主动获取通道内的人员列表
/// - Parameter completionBlock: 完成回调
- (void)getMembersWithCompletion:(MeetingMessageChannelGetMembersBlock) completionBlock;

- (void)queryPeerOnline:(NSArray *)peers completion:(MeetingMessageChannelQueryPeersOnlineBlock _Nullable) completion;


/// 释放资源
- (void)destroyResource;
@end

NS_ASSUME_NONNULL_END

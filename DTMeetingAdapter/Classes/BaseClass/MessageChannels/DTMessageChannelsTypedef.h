//
//  DTMessageChannelsTypedef.h
//  Pods
//
//  Created by hornet on 2023/10/2.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, DTMeetingMsgChannelInvitationApiCallErrorCode) {
  DTMeetingMsgChannelInvitationApiCallErrorOk = 0,
  DTMeetingMsgChannelInvitationApiCallErrorInvalidAugment = 1,
  DTMeetingMsgChannelInvitationApiCallErrorNotStarted = 2,
  DTMeetingMsgChannelInvitationApiCallErrorAlreadyEnd = 3,
  DTMeetingMsgChannelInvitationApiCallErrorAlreadyAccept = 4,
  DTMeetingMsgChannelInvitationApiCallErrorAlreadySent = 5,
};

typedef NS_ENUM(NSInteger, MeetingChannelMessageType) {
    MeetingChannelMessageTypeUndefined = 0,
    MeetingChannelMessageTypeText = 1,
    MeetingChannelMessageTypeRaw = 2,
    MeetingChannelMessageTypeFile = 3,
    MeetingChannelMessageTypeImage = 4,
};

typedef NS_ENUM(NSInteger, DTMeetingMsgChannelChannelSendPeerMessageErrorCode) {
    DTMeetingMsgChannelChannelSendPeerMessageErrorOk = 0,
    DTMeetingMsgChannelChannelSendPeerMessageErrorFailure = 1,
    DTMeetingMsgChannelChannelSendPeerMessageErrorTimeout = 2,
    DTMeetingMsgChannelChannelSendPeerMessageErrorPeerUnreachable = 3,
    DTMeetingMsgChannelChannelSendPeerMessageErrorCachedByServer  = 4,
    DTMeetingMsgChannelChannelSendPeerMessageErrorTooOften = 5,
    DTMeetingMsgChannelChannelSendPeerMessageErrorInvalidUserId = 6,
    DTMeetingMsgChannelChannelSendPeerMessageErrorInvalidMessage = 7,
    DTMeetingMsgChannelChannelSendPeerMessageErrorIncompatibleMessage = 8,
    DTMeetingMsgChannelChannelSendPeerMessageErrorNotInitialized = 101,
    DTMeetingMsgChannelChannelSendPeerMessageErrorNotLoggedIn = 102,
    DTMeetingMsgChannelChannelSendPeerMessageErrorUnknow = 1000,
};

typedef NS_ENUM(NSInteger, MeetingRtcChannelMessageErrorCode) {
  MeetingRtcChannelMessageErrorOk = 0,
  MeetingRtcChannelMessageErrorFailure = 1,
  MeetingRtcChannelMessageErrorTimeout = 2,
  MeetingRtcChannelMessageTooOften = 3,
  MeetingRtcChannelMessageInvalidMessage = 4,
  MeetingRtcChannelMessageErrorNotInitialized = 101,
  MeetingRtcChannelMessageNotLoggedIn = 102,
  MeetingRtcChannelMessageErrorUnknow = 1000,
};

typedef NS_ENUM(NSInteger, DTMeetingMsgChannelJoinChannelErrorCode) {
    DTMeetingMsgChannelJoinChannelErrorOk = 0,
    DTMeetingMsgChannelJoinChannelErrorFailure = 1,
    DTMeetingMsgChannelJoinChannelErrorRejected = 2,
    DTMeetingMsgChannelJoinChannelErrorInvalidArgument = 3,
    DTMeetingMsgChannelJoinChannelErrorTimeout = 4,
    DTMeetingMsgChannelJoinChannelErrorExceedLimit = 5,
    DTMeetingMsgChannelJoinChannelErrorAlreadyJoined = 6,
    DTMeetingMsgChannelJoinChannelErrorTooOften = 7,
    DTMeetingMsgChannelJoinSameChannelErrorTooOften = 8,
    DTMeetingMsgChannelJoinChannelErrorNotInitialized = 101,
    DTMeetingMsgChannelJoinChannelErrorNotLoggedIn = 102,
    DTMeetingMsgChannelJoinChannelErrorUnknow = 1000,
};

typedef NS_ENUM(NSInteger, DTMeetingMsgChannelLeaveChannelErrorCode) {
    DTMeetingMsgChannelLeaveChannelErrorOk = 0,
    DTMeetingMsgChannelLeaveChannelErrorFailure = 1,
    DTMeetingMsgChannelLeaveChannelErrorRejected = 2,
    DTMeetingMsgChannelLeaveChannelErrorNotInChannel = 3,
    DTMeetingMsgChannelLeaveChannelErrorKicked = 4,
    DTMeetingMsgChannelLeaveChannelErrorNotInitialized = 101,
    DTMeetingMsgChannelLeaveChannelErrorNotLoggedIn = 102,
    DTMeetingMsgChannelLeaveChannelErrorUnknow = 1000,
};

typedef NS_ENUM(NSInteger, DTMessageChannelLoginErrorCode) {
    DTMessageChannelLoginErrorOk = 0,
    DTMessageChannelLoginErrorUnknown = 1,
    DTMessageChannelLoginErrorRejected = 2,
    DTMessageChannelLoginErrorInvalidArgument = 3,
    DTMessageChannelLoginErrorInvalidAppId = 4,
    DTMessageChannelLoginErrorInvalidToken = 5,
    DTMessageChannelLoginErrorTokenExpired = 6,
    DTMessageChannelLoginErrorNotAuthorized = 7,
    DTMessageChannelLoginErrorAlreadyLogin = 8,
    DTMessageChannelLoginErrorTimeout = 9,
    DTMessageChannelLoginErrorLoginTooOften = 10,
    DTMessageChannelLoginErrorLoginNotInitialized = 101,
};

typedef NS_ENUM(NSInteger, DTMessageChannelRenewTokenErrorCode) {
  DTMessageChannelRenewTokenErrorOk = 0,
  DTMessageChannelRenewTokenErrorFailure = 1,
  DTMessageChannelRenewTokenErrorInvalidArgument = 2,
  DTMessageChannelRenewTokenErrorRejected = 3,
  DTMessageChannelRenewTokenErrorTooOften = 4,
  DTMessageChannelRenewTokenErrorTokenExpired = 5,
  DTMessageChannelRenewTokenErrorInvalidToken = 6,
  DTMessageChannelRenewTokenErrorNotInitialized = 101,
  DTMessageChannelRenewTokenErrorNotLoggedIn = 102,
  DTMessageChannelRenewTokenErrorUnknow = 1000,
};

typedef NS_ENUM(NSInteger, DTMeetingMessageChannelLogoutErrorCode) {
    DTMeetingMessageChannelLogoutErrorOk = 0,
    DTMeetingMessageChannelLogoutErrorRejected = 1,
    DTMeetingMessageChannelLogoutErrorNotInitialized = 101,
    DTMeetingMessageChannelLogoutErrorNotLoggedIn = 102,
    DTMeetingMessageChannelLogoutErrorUnknow = 1000,
};

typedef NS_ENUM(NSInteger, DTMeetingMessageChannelGetMembersErrorCode) {
    DTMeetingMessageChannelGetMembersErrorOk = 0,
    DTMeetingMessageChannelGetMembersErrorFailure = 1,
    DTMeetingMessageChannelGetMembersErrorRejected = 2,
    DTMeetingMessageChannelGetMembersErrorTimeout = 3,
    DTMeetingMessageChannelGetMembersErrorTooOften = 4,
    DTMeetingMessageChannelGetMembersErrorNotInChannel = 5,
    DTMeetingMessageChannelGetMembersErrorNotInitialized = 101,
    DTMeetingMessageChannelGetMembersErrorNotLoggedIn = 102,
    DTMeetingMessageChannelGetMembersErrorCodeUnknow = 1000,
};

typedef NS_ENUM(NSInteger, DTMeetingMessageChannelConnectionState) {
    DTMeetingMessageChannelConnectionStateDisconnected = 1,
    DTMeetingMessageChannelConnectionStateConnecting = 2,
    DTMeetingMessageChannelConnectionStateConnected = 3,
    DTMeetingMessageChannelConnectionStateReconnecting = 4,
    DTMeetingMessageChannelConnectionStateAborted = 5,
    DTMeetingMessageChannelConnectionStateUnknow = 1000
};

typedef NS_ENUM(NSInteger, DTMeetingMessageChannelConnectionChangeReason) {
    DTMeetingMessageChannelConnectionChangeReasonLogin = 1,
    DTMeetingMessageChannelConnectionChangeReasonLoginSuccess = 2,
    DTMeetingMessageChannelConnectionChangeReasonLoginFailure = 3,
    DTMeetingMessageChannelConnectionChangeReasonLoginTimeout = 4,
    DTMeetingMessageChannelConnectionChangeReasonInterrupted = 5,
    DTMeetingMessageChannelConnectionChangeReasonLogout = 6,
    DTMeetingMessageChannelConnectionChangeReasonBannedByServer = 7,
    DTMeetingMessageChannelConnectionChangeReasonRemoteLogin = 8,
    DTMeetingMessageChannelConnectionChangeReasonTokenExpired = 9,
    DTMeetingMessageChannelConnectionChangeReasonUnknow = 1000,
};

typedef NS_ENUM(NSInteger, DTMeetingMessageChannelInvitationApiCallErrorCode) {
    DTMeetingMessageChannelInvitationApiCallErrorOk = 0,
    DTMeetingMessageChannelInvitationApiCallErrorInvalidAugment = 1,
    DTMeetingMessageChannelInvitationApiCallErrorNotStarted = 2,
    DTMeetingMessageChannelInvitationApiCallErrorAlreadyEnd = 3,
    DTMeetingMessageChannelInvitationApiCallErrorAlreadyAccept = 4,
    DTMeetingMessageChannelInvitationApiCallErrorAlreadySent = 5,
    DTMeetingMessageChannelInvitationApiCallErrorUnknow = 1000,
};

typedef NS_ENUM(NSInteger, DTMeetingMessageChannelLocalInvitationErrorCode) {
    DTMeetingMessageChannelLocalInvitationErrorOk = 0,
    DTMeetingMessageChannelLocalInvitationErrorRemoteOffline = 1,
    DTMeetingMessageChannelLocalInvitationErrorRemoteNoResponse = 2,
    DTMeetingMessageChannelLocalInvitationErrorExpire = 3,
    DTMeetingMessageChannelLocalInvitationErrorNotLoggedIn = 4,
    DTMeetingMessageChannelLocalInvitationErrorUnknow = 1000
};


typedef NS_ENUM(NSInteger, DTMeetingMessageChannelRemoteInvitationErrorCode) {
    DTMeetingMessageChannelRemoteInvitationErrorOk = 0,
    DTMeetingMessageChannelRemoteInvitationErrorLocalOffline = 1,
    DTMeetingMessageChannelRemoteInvitationErrorAcceptFailure = 2,
    DTMeetingMessageChannelRemoteInvitationErrorExpire = 3,
    DTMeetingMessageChannelRemoteInvitationErrorUnknow = 1000,
};

typedef NS_ENUM(NSInteger, DTMessageChannelPeerOnlineState) {
    DTMessageChannelPeerOnlineStateOnline = 0,
    DTMessageChannelPeerOnlineStateUnreachable = 1,
    DTMessageChannelPeerOnlineStateOffline = 2,
};

typedef NS_ENUM(NSInteger, DTMessageChannelQueryPeersOnlineErrorCode) {

    DTMessageChannelQueryPeersOnlineErrorOk = 0,
    DTMessageChannelQueryPeersOnlineErrorFailure = 1,
    DTMessageChannelQueryPeersOnlineErrorInvalidArgument = 2,
    DTMessageChannelQueryPeersOnlineErrorRejected = 3,
    DTMessageChannelQueryPeersOnlineErrorTimeout = 4,
    DTMessageChannelQueryPeersOnlineErrorTooOften = 5,
    DTMessageChannelQueryPeersOnlineErrorNotInitialized = 101,
    DTMessageChannelQueryPeersOnlineErrorNotLoggedIn = 102,
};

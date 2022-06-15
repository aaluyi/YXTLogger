//
//  YXTLoggerManager.h
//  YXTLogger
//
//  Created by 卢燚 on 2022/4/11.
//

/**
 管理logger的类，负责管理所有log文件
 */

#import <Foundation/Foundation.h>
#import "YXTConfig.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief YXT的log打印方法
 * isatty(STDOUT_FILENO)
 */
#define YXTDebug(frmt, ...) \
do {if (YXTLog) { if (isatty(STDOUT_FILENO)) { NSLog(frmt, ##__VA_ARGS__);} else {DDLogDebugToDDLog(YXTLog, frmt, ##__VA_ARGS__); [YXTManage setRecordMarkFileByRecordLevel: YXTLoggerRecordLevelDebug];}}} while(0)

#define YXTInfo(frmt, ...) \
do {if (YXTLog) { if (isatty(STDOUT_FILENO)) { NSLog(frmt, ##__VA_ARGS__);} else {DDLogInfoToDDLog(YXTLog, frmt, ##__VA_ARGS__); [YXTManage setRecordMarkFileByRecordLevel: YXTLoggerRecordLevelInfo];}}} while(0)

#define YXTWarn(frmt, ...) \
do {if (YXTLog) { if (isatty(STDOUT_FILENO)) { NSLog(frmt, ##__VA_ARGS__);} else {DDLogWarnToDDLog(YXTLog, frmt, ##__VA_ARGS__); [YXTManage setRecordMarkFileByRecordLevel: YXTLoggerRecordLevelWarn];}}} while(0)

#define YXTError(frmt, ...) \
do {if (YXTLog) { if (isatty(STDOUT_FILENO)) { NSLog(frmt, ##__VA_ARGS__);} else {DDLogErrorToDDLog(YXTLog, frmt, ##__VA_ARGS__); [YXTManage  setRecordMarkFileByRecordLevel: YXTLoggerRecordLevelError];}}} while(0)

/**
 * @brief SDK的log打印方法
 */

#define SDKDebug(frmt, ...) \
do {if (SDKLog) { if (isatty(STDOUT_FILENO)) { NSLog(frmt, ##__VA_ARGS__);} else {DDLogDebugToDDLog(SDKLog, frmt, ##__VA_ARGS__); [YXTManage setRecordMarkFileByRecordLevel: YXTLoggerRecordLevelDebug];}}} while(0)

#define SDKInfo(frmt, ...) \
do {if (SDKLog) { if (isatty(STDOUT_FILENO)) { NSLog(frmt, ##__VA_ARGS__);} else {DDLogInfoToDDLog(SDKLog, frmt, ##__VA_ARGS__); [YXTManage setRecordMarkFileByRecordLevel: YXTLoggerRecordLevelInfo];}}} while(0)

#define SDKWarn(frmt, ...) \
do {if (SDKLog) { if (isatty(STDOUT_FILENO)) { NSLog(frmt, ##__VA_ARGS__);} else {DDLogWarnToDDLog(SDKLog, frmt, ##__VA_ARGS__); [YXTManage setRecordMarkFileByRecordLevel: YXTLoggerRecordLevelWarn];}}} while(0)

#define SDKError(frmt, ...) \
do {if (SDKLog) { if (isatty(STDOUT_FILENO)) { NSLog(frmt, ##__VA_ARGS__);} else {DDLogErrorToDDLog(SDKLog, frmt, ##__VA_ARGS__); [YXTManage setRecordMarkFileByRecordLevel: YXTLoggerRecordLevelError];}}} while(0)


/**
 * 私有宏，接入时忽略
 */
#define YXTManage YXTLoggerManager.shareInstance

#define YXTLog [YXTManage yxtLog]

#define SDKLog [YXTManage sdkLog]

/**
 * 私有宏，接入时忽略
 * 设置log打印等级
 * static const DDLogLevel ddLogLevel = DDLogLevelAll;
 */
#define ddLogLevel [YXTLoggerManager.shareInstance returnDDLogLevel]

@interface YXTLoggerManager : NSObject

/**
 * 初始化单例对象
 */
+ (instancetype)shareInstance;

/**
 * @brief 设置日志目录，不设置会有默认路径，通过returnLogDir查看
 */
- (void)setLogDir:(NSString *)logDir;

/**
 * @brief 获取日志目录
 */
- (NSString *)returnLogDir;

/**
 * 设置记录等级
 */
- (void)setRecordLevel:(YXTLoggerRecordLevel)recordLevel;

/**
 * 返回记录等级
 */
- (YXTLoggerRecordLevel)returnRecoedLevel;

/**
 * 设置上传等级
 */
- (void)setUploadLevel:(YXTLoggerUploadLevel)uploadLevel;

/**
 * 返回上传等级
 */
- (YXTLoggerUploadLevel)returnUploadLevel;

/**
 * @brief 将loggerObject添加到manager，进行统一管理，要在
 * @param logModule 模块
 */
- (void)addLoggerWithLogModule:(YXTLoggerModule)logModule;

/**
 * @brief 回滚本地日志文件（删除）
 */
- (void)rollLogfiles;

/**
 * @brief 根据YXTLoggerUploadLevel与setRecordMarkFileByRecordLevel共同决定是否上传
 * @param uploadBlock 上传回调 needUpload：是否需要上传
 */
- (void)upload:(void (^)(BOOL needUpload))uploadBlock;

/**
 * 下面都是私有方法，接入时忽略
 */

/**
 * @brief 负责yxt日志的log
 */
- (DDLog *)yxtLog;

/**
 * @brief 负责sdk日志的log
 */
- (DDLog *)sdkLog;

/**
 * @brief 根据logModule返回对应log
 * @param logModule 模块
 */
- (DDLog *)log:(YXTLoggerModule)logModule;

/**
 * @brief 返回DDLogLevel
 */
- (DDLogLevel)returnDDLogLevel;

/**
 * @brief 日志记录等级的标记文件，用于决定是否需要上传
 * @param recordLevel 记录等级
 */
- (void)setRecordMarkFileByRecordLevel:(YXTLoggerRecordLevel)recordLevel;



@end

NS_ASSUME_NONNULL_END

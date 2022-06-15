//
//  YXTConfig.h
//  YXTLogger
//
//  Created by 卢燚 on 2022/4/11.
//

#ifndef YXTConfig_h
#define YXTConfig_h
#import <CocoaLumberjack/CocoaLumberjack.h>

/**
 日志模块
 */
typedef NS_ENUM(NSUInteger, YXTLoggerModule) {
    YXTLoggerModuleYXT = 0,//yxt模块
    YXTLoggerModuleSDK,//sdk-native模块
};

/**
 记录等级
 */
typedef NS_ENUM(NSUInteger, YXTLoggerRecordLevel) {
    YXTLoggerRecordLevelDebug = 0,
    YXTLoggerRecordLevelInfo,
    YXTLoggerRecordLevelWarn,
    YXTLoggerRecordLevelError
};

/**
 上传等级
 */
typedef NS_ENUM(NSUInteger, YXTLoggerUploadLevel) {
    YXTLoggerUploadLevelDebug = 0,
    YXTLoggerUploadLevelInfo,
    YXTLoggerUploadLevelWarn,
    YXTLoggerUploadLevelError
};


#endif /* YXTConfig_h */

//
//  DDJPExtension.m
//  DDReaderPlus
//
//  Created by 符现超 on 2016/10/26.
//  Copyright © 2016年 dangdang. All rights reserved.
//  http://blog.sunnyxx.com/2014/08/02/objc-weird-code/

#import "DDJPExtension.h"

#ifndef zd_keypath
#define zd_keypath(...) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-repeated-use-of-weak\"") \
metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))(zd_keypath1(__VA_ARGS__))(zd_keypath2(__VA_ARGS__)) \
_Pragma("clang diagnostic pop") \

#define zd_keypath1(PATH) ((strchr(# PATH, '.') + 1))

#define zd_keypath2(OBJ, PATH) ((# PATH))
#endif

@implementation DDJPExtension

+ (void)main:(JSContext *)context {
    context[@"RACObserve"] = ^RACSignal *(id zd_self, id target, id keyPath) {
        __weak id target_ = (target);
        RACSignal *signal = [target_ rac_valuesForKeyPath:@zd_keypath(target, keyPath) observer:zd_self];
        return signal;
    };
}

@end

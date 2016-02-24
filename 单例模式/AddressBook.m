//
//  AddressBook.m
//  单例模式
//
//  Created by 符现超 on 14-3-23.
//  Copyright (c) 2014年 符现超. All rights reserved.
//

#import "AddressBook.h"

static AddressBook *instance=nil;

@implementation AddressBook

//创建一个类的工厂方法，生成一个该类的实例
+ (AddressBook *)shareInstanse{
    if (instance==nil) {
        instance =[[AddressBook alloc]init];
        
    }
    return instance;
}

//限制方法，让这个类只能创建一个对象
+ (id)allocWithZone:(NSZone *)zone{
    if (instance==nil) {
        instance=[super allocWithZone:zone];
    }
    return instance;
}

- (id)copyWithZone:(NSZone *)zone{
    return self;
}

- (id)retain{
    return self;
}

- (oneway void)release{

}

- (NSUInteger)retainCount{
    return UINT64_MAX;
}

@end

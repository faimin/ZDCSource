//
//  AddressBook.h
//  单例模式
//
//  Created by 符现超 on 14-3-23.
//  Copyright (c) 2014年 符现超. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AddressBook : NSObject<NSCopying>

@property(nonatomic,copy)NSString *phone;

+(AddressBook *)shareInstanse;

@end
